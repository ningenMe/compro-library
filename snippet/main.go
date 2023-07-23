package main
import (
    "bufio"
    "fmt"
	"github.com/ningenMe/compro-library/snippet/model"
    "io/ioutil"
    "log"
    "os"
    "path/filepath"
    "strings"
)
func main() {
	fmt.Println("start making snippet")

    //ファイルの一覧を取得
	fileNode := GetFileNode("../lib","./")

    //ログ用にtree出力
    for _, value := range fileNode.GetTreeStrings() {
        fmt.Println(value)
    }

    pwd, err := os.Getwd()
    if err != nil {
        log.Fatalln(err)
    }
    pwd = pwd + "/"
    for _, path := range fileNode.GetPathStrings() {
        fmt.Println(path)

        //  ファイルの中身を取得
        libraryFile, err := os.Open(pwd+path)
        if err != nil {
            log.Fatalln(err)
        }

        scanner := bufio.NewScanner(libraryFile)

        var texts []string
        for scanner.Scan() {
            texts = append(texts, scanner.Text())
        }

        fileName := GetLastString(strings.Split(path,"/"))
        fileNameWithoutExtension := strings.Split(fileName,".")[0]

        snippetFile, err := os.Create(pwd+"/.vscode/"+fileNameWithoutExtension+".code-snippets")
        if err != nil {
            log.Fatalln(err)
        }
        snippetTextPrefix := []string{
            "{",
            "\t\""+ fileNameWithoutExtension +"\": {",
            "\t\t\"scope\": \"cpp\",",
            "\t\t\"prefix\": \""+fileNameWithoutExtension+"\",",
            "\t\t\"body\": [",
        }
        for _, text := range snippetTextPrefix {
            _, err := snippetFile.WriteString(text+"\n")
            if err != nil {
                log.Fatalln(err)
            }
        }

        for _, text := range texts {
            text = strings.ReplaceAll(text,"\"","\\\"")
            _, err := snippetFile.WriteString("\t\t\t\""+text+"\",\n")
            if err != nil {
                log.Fatalln(err)
            }
        }

        snippetTextSuffix := []string{
            "\t\t],",
            "\t}",
            "}",
        }
        for _, text := range snippetTextSuffix {
            _, err := snippetFile.WriteString(text+"\n")
            if err != nil {
                log.Fatalln(err)
            }
        }
    }

	//for {

	//  スニペットを作成
	//}
	//
	fmt.Println("end making snippet")
}

func GetLastString(strings []string) string {
    sz := len(strings)
    return strings[sz-1]
}


func GetFileNode(path string, directoryName string) model.FileNode {
	files, err := ioutil.ReadDir(path)
	if err != nil {
        log.Fatalln(err)
	}

	fileNode := model.FileNode{
		Path:          path,
		DirectoryName: directoryName,
		Files:         []string{},
		FileNodes:     []model.FileNode{},
	}

	for _, file := range files {
		fileName := file.Name()

		nextPath := filepath.Join(path, fileName)
		if file.IsDir() {
			childFileNode := GetFileNode(nextPath, fileName)
			fileNode.FileNodes = append(fileNode.FileNodes, childFileNode)
		} else {
			fileNode.Files = append(fileNode.Files, fileName)
		}
	}
	return fileNode
}
