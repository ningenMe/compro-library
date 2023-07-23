---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: snippet/main.go
    title: snippet/main.go
  _extendedRequiredBy:
  - icon: ':warning:'
    path: snippet/main.go
    title: snippet/main.go
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: go
  _verificationStatusIcon: ':warning:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.12/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.12/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/user_defined.py\"\
    , line 68, in bundle\n    raise RuntimeError('bundler is not specified: {}'.format(str(path)))\n\
    RuntimeError: bundler is not specified: snippet/model/file_node.go\n"
  code: "package model\n\nimport (\n\t\"strings\"\n)\n\ntype FileNode struct {\n\t\
    Path          string\n\tDirectoryName string\n\tFiles         []string\n\tFileNodes\
    \     []FileNode\n}\n\nconst (\n\tstraight     = \"\u2502  \"\n\tnormalBranch\
    \ = \"\u251C\u2500\u2500\"\n\tlastBranch   = \"\u2514\u2500\u2500\"\n\tblank \
    \       = \"   \"\n)\n\nfunc (fileNode *FileNode) GetTreeStrings() []string {\n\
    \ttreeStrings := []string{}\n\ttreeStrings = append(treeStrings, fileNode.DirectoryName)\n\
    \n\tfileNode.addTreeString(&treeStrings, \"\")\n\treturn treeStrings\n}\n\nfunc\
    \ (fileNode *FileNode) addTreeString(treeStringsPointer *[]string, prefix string)\
    \ {\n\n\tfileLength := len(fileNode.Files)\n\tdirectoryLength := len(fileNode.FileNodes)\n\
    \texistDirectory := directoryLength > 0\n\tfor index, file := range fileNode.Files\
    \ {\n\t\t*treeStringsPointer = append(*treeStringsPointer, prefix+getFileBranch(index,\
    \ fileLength, existDirectory)+\" \"+file)\n\t}\n\tfor index, childrenFileNode\
    \ := range fileNode.FileNodes {\n\t\t*treeStringsPointer = append(*treeStringsPointer,\
    \ prefix+getDirectoryBranch(index, directoryLength)+\" \"+childrenFileNode.DirectoryName)\n\
    \n\t\tif strings.HasPrefix(childrenFileNode.DirectoryName, \".\") {\n\t\t\tcontinue\n\
    \t\t}\n\n\t\tchildrenFileNode.addTreeString(treeStringsPointer, prefix+getAdditionalPrefix(index,\
    \ directoryLength))\n\t}\n}\n\nfunc getFileBranch(index int, length int, existDirectory\
    \ bool) string {\n\tif existDirectory {\n\t\treturn normalBranch\n\t}\n\tif index+1\
    \ != length {\n\t\treturn normalBranch\n\t}\n\treturn lastBranch\n}\n\nfunc getDirectoryBranch(index\
    \ int, length int) string {\n\tif index+1 != length {\n\t\treturn normalBranch\n\
    \t}\n\treturn lastBranch\n}\n\nfunc getAdditionalPrefix(index int, length int)\
    \ string {\n\tif index+1 != length {\n\t\treturn straight\n\t}\n\treturn blank\n\
    }\n\nfunc (fileNode *FileNode) GetPathStrings() []string {\n    pathStrings :=\
    \ []string{}\n\n    fileNode.addPathString(&pathStrings)\n    return pathStrings\n\
    }\n\n\nfunc (fileNode *FileNode) addPathString(pathStringsPointer *[]string) {\n\
    \n    for _, file := range fileNode.Files {\n        *pathStringsPointer = append(*pathStringsPointer,\
    \ fileNode.Path + \"/\" + file)\n    }\n    for _, childrenFileNode := range fileNode.FileNodes\
    \ {\n        if strings.HasPrefix(childrenFileNode.DirectoryName, \".\") {\n \
    \           continue\n        }\n        childrenFileNode.addPathString(pathStringsPointer)\n\
    \    }\n}\n"
  dependsOn:
  - snippet/main.go
  isVerificationFile: false
  path: snippet/model/file_node.go
  requiredBy:
  - snippet/main.go
  timestamp: '2023-07-24 01:09:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippet/model/file_node.go
layout: document
redirect_from:
- /library/snippet/model/file_node.go
- /library/snippet/model/file_node.go.html
title: snippet/model/file_node.go
---
