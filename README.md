# Variable-Byte-VarByte-Encoding
Compress numerical data using variable byte encoding.

## Test
I test the algorithm with first 10000 documents from [ClueWeb09B dataset](https://lemurproject.org/clueweb09/).

## Speed
**Compress**: 7.40MB/s
```
michael916@moa:~/Variable-Byte-VarByte-Encoding$ g++ compress_test.cpp -std=c++11 -o comp.out
michael916@moa:~/Variable-Byte-VarByte-Encoding$ ./comp.out 
Compressed in: 3.57952 seconds.
michael916@moa:~/Variable-Byte-VarByte-Encoding$ ls -l
total 37624
-rwxrwxr-x 1 michael916 michael916    37731 Jul 24 19:15 comp.out
-rw-rw-r-- 1 michael916 michael916     1162 Jul 24 19:08 compress_test.cpp
-rw-rw-r-- 1 michael916 michael916     1632 Jul 24 19:06 decompress_test.cpp
-rw-rw-r-- 1 michael916 michael916    35141 Jul 24 17:21 LICENSE
-rw-rw-r-- 1 michael916 michael916      923 Jul 24 19:06 README.md
-rw-rw-r-- 1 michael916 michael916 10565973 Jul 24 19:15 test_comp
-rwxrwxr-x 1 michael916 michael916    62715 Jul 24 19:13 test.out
-rw-rw-r-- 1 michael916 michael916 27796432 Jul 24 19:13 test_uncomp
-rw-rw-r-- 1 michael916 michael916     1712 Jul 24 17:21 varByte.cpp
```

**Decompress**: 10.28MB/s

```
michael916@moa:~/Variable-Byte-VarByte-Encoding$ g++ decompress_test.cpp -std=c++11 -o test.out
michael916@moa:~/Variable-Byte-VarByte-Encoding$ ./test.out 
Decompressed in: 2.55497 seconds.
michael916@moa:~/Variable-Byte-VarByte-Encoding$ ls -l
total 37624
-rwxrwxr-x 1 michael916 michael916    37731 Jul 24 19:08 comp.out
-rw-rw-r-- 1 michael916 michael916     1162 Jul 24 19:08 compress_test.cpp
-rw-rw-r-- 1 michael916 michael916     1632 Jul 24 19:06 decompress_test.cpp
-rw-rw-r-- 1 michael916 michael916    35141 Jul 24 17:21 LICENSE
-rw-rw-r-- 1 michael916 michael916      923 Jul 24 19:06 README.md
-rw-rw-r-- 1 michael916 michael916 10565973 Jul 24 19:08 test_comp
-rwxrwxr-x 1 michael916 michael916    62715 Jul 24 19:13 test.out
-rw-rw-r-- 1 michael916 michael916 27796432 Jul 24 19:13 test_uncomp
-rw-rw-r-- 1 michael916 michael916     1712 Jul 24 17:21 varByte.cpp
```

