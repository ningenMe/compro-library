---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: md/util/ZobristHash.md
    document_title: ZobristHash - Zobrist Hashing
    links: []
  bundledCode: "#line 1 \"lib/00-util/ZobristHash.cpp\"\n/*\n * @title ZobristHash\
    \ - Zobrist Hashing\n * @docs md/util/ZobristHash.md\n */\ntemplate<class T> class\
    \ ZobristHash {\npublic:\n    class Table {\n        class XorShift64{\n     \
    \       unsigned long long s;\n        public:\n            XorShift64():s(17364570149295320492UL){}\n\
    \            unsigned long long rand() {\n                s = s ^ (s<<13);\n \
    \               s = s ^ (s>>7);\n                s = s ^ (s<<17);\n          \
    \      return s;\n            }\n        };\n        XorShift64 xor_shift;\n \
    \       map<T, unsigned long long> table;\n    public:\n        Table():xor_shift(){}\n\
    \        void set(const T val) {\n            if(table.count(val)) return;\n \
    \           table[val] = xor_shift.rand();\n        }    \n        size_t count(const\
    \ T val) const {\n            return table.count(val);\n        }\n        unsigned\
    \ long long get(const T val) {\n            return table[val];\n        }\n  \
    \  };\n    class Set {\n        Table& table;\n        unsigned long long hash;\n\
    \        set<unsigned long long> st;\n    public:        \n        Set(Table&\
    \ table):table(table),hash(0){}\n        void insert(const T val) {\n        \
    \    assert(table.count(val));\n            unsigned long long key = table.get(val);\n\
    \            if(st.count(key)) return;\n            st.insert(key);\n        \
    \    hash ^= key;\n        }\n        void erase(const T val) {\n            assert(table.count(val));\n\
    \            unsigned long long key = table.get(val);\n            if(!st.count(key))\
    \ return;\n            st.erase(key);\n            hash ^= key;\n        }\n \
    \       unsigned long long get() {\n            return hash;\n        }\n    };\n\
    };\n"
  code: "/*\n * @title ZobristHash - Zobrist Hashing\n * @docs md/util/ZobristHash.md\n\
    \ */\ntemplate<class T> class ZobristHash {\npublic:\n    class Table {\n    \
    \    class XorShift64{\n            unsigned long long s;\n        public:\n \
    \           XorShift64():s(17364570149295320492UL){}\n            unsigned long\
    \ long rand() {\n                s = s ^ (s<<13);\n                s = s ^ (s>>7);\n\
    \                s = s ^ (s<<17);\n                return s;\n            }\n\
    \        };\n        XorShift64 xor_shift;\n        map<T, unsigned long long>\
    \ table;\n    public:\n        Table():xor_shift(){}\n        void set(const T\
    \ val) {\n            if(table.count(val)) return;\n            table[val] = xor_shift.rand();\n\
    \        }    \n        size_t count(const T val) const {\n            return\
    \ table.count(val);\n        }\n        unsigned long long get(const T val) {\n\
    \            return table[val];\n        }\n    };\n    class Set {\n        Table&\
    \ table;\n        unsigned long long hash;\n        set<unsigned long long> st;\n\
    \    public:        \n        Set(Table& table):table(table),hash(0){}\n     \
    \   void insert(const T val) {\n            assert(table.count(val));\n      \
    \      unsigned long long key = table.get(val);\n            if(st.count(key))\
    \ return;\n            st.insert(key);\n            hash ^= key;\n        }\n\
    \        void erase(const T val) {\n            assert(table.count(val));\n  \
    \          unsigned long long key = table.get(val);\n            if(!st.count(key))\
    \ return;\n            st.erase(key);\n            hash ^= key;\n        }\n \
    \       unsigned long long get() {\n            return hash;\n        }\n    };\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: lib/00-util/ZobristHash.cpp
  requiredBy: []
  timestamp: '2023-07-22 10:12:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/00-util/ZobristHash.cpp
layout: document
redirect_from:
- /library/lib/00-util/ZobristHash.cpp
- /library/lib/00-util/ZobristHash.cpp.html
title: ZobristHash - Zobrist Hashing
---
### ZobristHash
- https://trap.jp/post/1594/
- [提出](https://atcoder.jp/contests/abc250/submissions/43812649)