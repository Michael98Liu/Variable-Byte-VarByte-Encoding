# Variable-Byte-VarByte-Encoding
Compress numerical data using variable byte encoding.

### Test
I test the algorithm with first 10000 documents from [ClueWeb09B dataset](https://lemurproject.org/clueweb09/).

### Speed
*Decompress*: 10.28MB/s

```
michael916@moa:~/Variable-Byte-VarByte-Encoding$ g++ decompress_test.cpp -std=c++11 -o test.out
michael916@moa:~/Variable-Byte-VarByte-Encoding$ ./test.out 
Decompressed in: 2.59266 seconds.
michael916@moa:~/Variable-Byte-VarByte-Encoding$ ls -l
total 27260
-rw-rw-r-- 1 michael916 michael916     1630 Jul 24 18:42 decompress_test.cpp
-rw-rw-r-- 1 michael916 michael916    35141 Jul 24 17:21 LICENSE
-rw-rw-r-- 1 michael916 michael916       87 Jul 24 17:21 README.md
-rw-rw-r-- 1 michael916 michael916 27796432 Jul 24 18:50 test_data
-rwxrwxr-x 1 michael916 michael916    62715 Jul 24 18:49 test.out
-rw-rw-r-- 1 michael916 michael916     1712 Jul 24 17:21 varByte.cpp
```

