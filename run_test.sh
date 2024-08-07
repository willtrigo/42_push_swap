#!/bin/bash

rm -rf test-out.txt
> test-out.txt
rm -rf valgrind-out.txt
> valgrind-out.txt

test_cases=("")
while IFS= read -r line; do
    test_cases+=("$line")
done < comb_three.txt
while IFS= read -r line; do
    test_cases+=("$line")
done < comb_four.txt
while IFS= read -r line; do
    test_cases+=("$line")
done < comb_five.txt
while IFS= read -r line; do
    test_cases+=("$line")
done < comb_six.txt
while IFS= read -r line; do
    test_cases+=("$line")
done < comb_seven_pt1.txt

declare -i i=0

for test_case in "${test_cases[@]}"; do
	i+=1
	echo -e "TEST ${i}:\n--------------------------------------------------------------------------------\n--------------------------------------------------------------------------------\n" | tee -a valgrind-out.txt
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --log-fd=9 9>>valgrind-out.txt ./push_swap ${test_case} > /dev/null 2>&1
	checker=$(./push_swap $test_case | ./checker_linux $test_case)
	operations=$(./push_swap $test_case | wc -l)
	echo "\\tTEST ${i}: command(./push_swap $test_case) / checker: ${checker} / number of operations: ${operations}\\n" >> test-out.txt
	echo -e "\n--------------------------------------------------------------------------------\n--------------------------------------------------------------------------------\n" | tee -a test-out.txt valgrind-out.txt
done
