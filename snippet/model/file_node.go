package model

import (
	"strings"
)

type FileNode struct {
	Path          string
	DirectoryName string
	Files         []string
	FileNodes     []FileNode
}

const (
	straight     = "│  "
	normalBranch = "├──"
	lastBranch   = "└──"
	blank        = "   "
)

func (fileNode *FileNode) GetTreeStrings() []string {
	treeStrings := []string{}
	treeStrings = append(treeStrings, fileNode.DirectoryName)

	fileNode.addTreeString(&treeStrings, "")
	return treeStrings
}

func (fileNode *FileNode) addTreeString(treeStringsPointer *[]string, prefix string) {

	fileLength := len(fileNode.Files)
	directoryLength := len(fileNode.FileNodes)
	existDirectory := directoryLength > 0
	for index, file := range fileNode.Files {
		*treeStringsPointer = append(*treeStringsPointer, prefix+getFileBranch(index, fileLength, existDirectory)+" "+file)
	}
	for index, childrenFileNode := range fileNode.FileNodes {
		*treeStringsPointer = append(*treeStringsPointer, prefix+getDirectoryBranch(index, directoryLength)+" "+childrenFileNode.DirectoryName)

		if strings.HasPrefix(childrenFileNode.DirectoryName, ".") {
			continue
		}

		childrenFileNode.addTreeString(treeStringsPointer, prefix+getAdditionalPrefix(index, directoryLength))
	}
}

func getFileBranch(index int, length int, existDirectory bool) string {
	if existDirectory {
		return normalBranch
	}
	if index+1 != length {
		return normalBranch
	}
	return lastBranch
}

func getDirectoryBranch(index int, length int) string {
	if index+1 != length {
		return normalBranch
	}
	return lastBranch
}

func getAdditionalPrefix(index int, length int) string {
	if index+1 != length {
		return straight
	}
	return blank
}

func (fileNode *FileNode) GetPathStrings() []string {
    pathStrings := []string{}

    fileNode.addPathString(&pathStrings)
    return pathStrings
}


func (fileNode *FileNode) addPathString(pathStringsPointer *[]string) {

    for _, file := range fileNode.Files {
        *pathStringsPointer = append(*pathStringsPointer, fileNode.Path + "/" + file)
    }
    for _, childrenFileNode := range fileNode.FileNodes {
        if strings.HasPrefix(childrenFileNode.DirectoryName, ".") {
            continue
        }
        childrenFileNode.addPathString(pathStringsPointer)
    }
}
