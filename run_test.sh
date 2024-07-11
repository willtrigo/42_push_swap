#!/bin/bash

rm -rf test-out.txt
>> test-out.txt
rm -rf valgrind-out.txt
>> valgrind-out.txt

test_cases=(
	"1 2 3"
	"2 1 3"
	"3 2 1"
	"88 23 53 3 2 1"
)

for test_case in "${test_cases[@]}"; do
	echo -e "TEST: ${test_case}\n--------------------------------------------------------------------------------\n--------------------------------------------------------------------------------\n" | tee -a test-out.txt valgrind-out.txt
	echo -e "./push_swap $test_case" | tee -a test-out.txt
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --log-fd=9 9>>valgrind-out.txt ./push_swap ${test_case} > /dev/null 2>&1
	./push_swap $test_case | ./checker_linux $test_case >> test-out.txt
	echo -e "\n--------------------------------------------------------------------------------" | tee -a test-out.txt valgrind-out.txt
done
