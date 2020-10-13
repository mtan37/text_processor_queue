#!/bin/bash
echo "test 1: long string\n"
./run < testFiles/testFile
echo "test 2: blank line\n"
./run < testFiles/testFile2
echo "test 3: multiple null char"
./run < testFiles/testFile3
echo "test 4: empty file"
./run < testFiles/testFile4
echo "test 5: large file"
./run < testFiles/testFile5
