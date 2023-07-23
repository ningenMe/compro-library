---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: snippet/model/file_node.go
    title: snippet/model/file_node.go
  _extendedRequiredBy:
  - icon: ':warning:'
    path: snippet/model/file_node.go
    title: snippet/model/file_node.go
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: go
  _verificationStatusIcon: ':warning:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.12/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.12/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/user_defined.py\"\
    , line 68, in bundle\n    raise RuntimeError('bundler is not specified: {}'.format(str(path)))\n\
    RuntimeError: bundler is not specified: snippet/main.go\n"
  code: "package main\nimport (\n    \"bufio\"\n    \"fmt\"\n\t\"github.com/ningenMe/compro-library/snippet/model\"\
    \n    \"io/ioutil\"\n    \"log\"\n    \"os\"\n    \"path/filepath\"\n    \"strings\"\
    \n)\nfunc main() {\n\tfmt.Println(\"start making snippet\")\n\n    //\u30D5\u30A1\
    \u30A4\u30EB\u306E\u4E00\u89A7\u3092\u53D6\u5F97\n\tfileNode := GetFileNode(\"\
    ../lib\",\"./\")\n\n    //\u30ED\u30B0\u7528\u306Btree\u51FA\u529B\n    for _,\
    \ value := range fileNode.GetTreeStrings() {\n        fmt.Println(value)\n   \
    \ }\n\n    pwd, err := os.Getwd()\n    if err != nil {\n        log.Fatalln(err)\n\
    \    }\n    pwd = pwd + \"/\"\n    for _, path := range fileNode.GetPathStrings()\
    \ {\n        fmt.Println(path)\n\n        //  \u30D5\u30A1\u30A4\u30EB\u306E\u4E2D\
    \u8EAB\u3092\u53D6\u5F97\n        libraryFile, err := os.Open(pwd+path)\n    \
    \    if err != nil {\n            log.Fatalln(err)\n        }\n\n        scanner\
    \ := bufio.NewScanner(libraryFile)\n\n        var texts []string\n        for\
    \ scanner.Scan() {\n            texts = append(texts, scanner.Text())\n      \
    \  }\n\n        fileName := GetLastString(strings.Split(path,\"/\"))\n       \
    \ fileNameWithoutExtension := strings.Split(fileName,\".\")[0]\n\n        snippetFile,\
    \ err := os.Create(pwd+\"/tmp/\"+fileNameWithoutExtension+\".code-snippets\")\n\
    \        if err != nil {\n            log.Fatalln(err)\n        }\n        snippetTextPrefix\
    \ := []string{\n            \"{\",\n            \"\\t\\\"\"+ fileNameWithoutExtension\
    \ +\"\\\": {\",\n            \"\\t\\t\\\"scope\\\": \\\"cpp\\\",\",\n        \
    \    \"\\t\\t\\\"prefix\\\": \\\"\"+fileNameWithoutExtension+\"\\\",\",\n    \
    \        \"\\t\\t\\\"body\\\": [\",\n        }\n        for _, text := range snippetTextPrefix\
    \ {\n            _, err := snippetFile.WriteString(text+\"\\n\")\n           \
    \ if err != nil {\n                log.Fatalln(err)\n            }\n        }\n\
    \n        for _, text := range texts {\n            text = strings.ReplaceAll(text,\"\
    \\\"\",\"\\\\\\\"\")\n            _, err := snippetFile.WriteString(\"\\t\\t\\\
    t\\\"\"+text+\"\\\",\\n\")\n            if err != nil {\n                log.Fatalln(err)\n\
    \            }\n        }\n\n        snippetTextSuffix := []string{\n        \
    \    \"\\t\\t],\",\n            \"\\t}\",\n            \"}\",\n        }\n   \
    \     for _, text := range snippetTextSuffix {\n            _, err := snippetFile.WriteString(text+\"\
    \\n\")\n            if err != nil {\n                log.Fatalln(err)\n      \
    \      }\n        }\n    }\n\n\t//for {\n\n\t//  \u30B9\u30CB\u30DA\u30C3\u30C8\
    \u3092\u4F5C\u6210\n\t//}\n\t//\n\tfmt.Println(\"end making snippet\")\n}\n\n\
    func GetLastString(strings []string) string {\n    sz := len(strings)\n    return\
    \ strings[sz-1]\n}\n\n\nfunc GetFileNode(path string, directoryName string) model.FileNode\
    \ {\n\tfiles, err := ioutil.ReadDir(path)\n\tif err != nil {\n        log.Fatalln(err)\n\
    \t}\n\n\tfileNode := model.FileNode{\n\t\tPath:          path,\n\t\tDirectoryName:\
    \ directoryName,\n\t\tFiles:         []string{},\n\t\tFileNodes:     []model.FileNode{},\n\
    \t}\n\n\tfor _, file := range files {\n\t\tfileName := file.Name()\n\n\t\tnextPath\
    \ := filepath.Join(path, fileName)\n\t\tif file.IsDir() {\n\t\t\tchildFileNode\
    \ := GetFileNode(nextPath, fileName)\n\t\t\tfileNode.FileNodes = append(fileNode.FileNodes,\
    \ childFileNode)\n\t\t} else {\n\t\t\tfileNode.Files = append(fileNode.Files,\
    \ fileName)\n\t\t}\n\t}\n\treturn fileNode\n}\n"
  dependsOn:
  - snippet/model/file_node.go
  isVerificationFile: false
  path: snippet/main.go
  requiredBy:
  - snippet/model/file_node.go
  timestamp: '2023-07-24 01:09:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/main.go
layout: document
redirect_from:
- /library/snippet/main.go
- /library/snippet/main.go.html
title: snippet/main.go
---
