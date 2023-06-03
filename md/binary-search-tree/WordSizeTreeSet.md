### WordSizeTreeSet
- 64分木
- セグ木の要領でデータを管理するが、葉の部分を u64 の bitで管理することでメモリが小さく高速
- `[0,1<<24)` の区間の整数データしか管理できない

### reference
- https://ningenme.net/compro-category/topic/topic_7F5IZI/problem