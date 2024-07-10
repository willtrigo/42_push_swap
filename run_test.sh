#!/bin/bash

rm -rf test-out.txt
>> test-out.txt
rm -rf valgrind-out.txt
>> valgrind-out.txt

echo -e "TEST: 1\n--------------------------------------------------------------------------------\n" | tee -a test-out.txt valgrind-out.txt
echo -e "./push_swap 1 2 3" | tee -a test-out.txt
valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --log-fd=9 9>>valgrind-out.txt ./push_swap 1 2 3 1> /dev/null 2>> test-out.txt

echo -e "\nTEST: 2\n--------------------------------------------------------------------------------\n" | tee -a test-out.txt valgrind-out.txt
echo -e "./push_swap 2 1 3" | tee -a test-out.txt
valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --log-fd=9 9>>valgrind-out.txt ./push_swap 2 1 3 1> /dev/null 2>> test-out.txt

echo -e "\nTEST: 3\n--------------------------------------------------------------------------------\n" | tee -a test-out.txt valgrind-out.txt
echo -e "./push_swap 3 2 1" | tee -a test-out.txt
valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --log-fd=9 9>>valgrind-out.txt ./push_swap 3 2 1 1> /dev/null 2>> test-out.txt

echo -e "\nTEST: 4\n--------------------------------------------------------------------------------\n" | tee -a test-out.txt valgrind-out.txt
echo -e "./push_swap 88 23 53 3 2 1" | tee -a test-out.txt
valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --log-fd=9 9>>valgrind-out.txt ./push_swap 88 23 53 3 2 1 1> /dev/null 2>> test-out.txt
