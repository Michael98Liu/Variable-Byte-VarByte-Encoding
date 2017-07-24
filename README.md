# Variable-Byte-VarByte-Encoding
Compress numerical data using variable byte encoding.

### Compress Efficiency
Decompress: 10.28MB/s

```michael916@moa:~/Variable-Byte-VarByte-Encoding$ g++ decompress_test.cpp -std=c++11 -o test.out
michael916@moa:~/Variable-Byte-VarByte-Encoding$ ./test
-bash: ./test: No such file or directory
michael916@moa:~/Variable-Byte-VarByte-Encoding$ g++ decompress_test.cpp -std=c++11 -o test.out
michael916@moa:~/Variable-Byte-VarByte-Encoding$ ./test.out 
Decompressed in: 2.52863 seconds.
michael916@moa:~/Variable-Byte-VarByte-Encoding$ ls -l
total 27328
-rw-rw-r-- 1 michael916 michael916     1630 Jul 24 18:39 build.cpp
-rwxrwxr-x 1 michael916 michael916    62705 Jul 24 18:39 build.out
-rw-rw-r-- 1 michael916 michael916     1630 Jul 24 18:42 decompress_test.cpp
-rw-rw-r-- 1 michael916 michael916    35141 Jul 24 17:21 LICENSE
-rw-rw-r-- 1 michael916 michael916       87 Jul 24 17:21 README.md
-rw-rw-r-- 1 michael916 michael916 27796432 Jul 24 18:45 test_data
-rwxrwxr-x 1 michael916 michael916    62715 Jul 24 18:45 test.out
-rw-rw-r-- 1 michael916 michael916     1712 Jul 24 17:21 varByte.cpp
```
Compress: 

