# Quicksorter
A quicksorting algorithm in c++

# Quick start
An example to use quicksort in a c++ script would be:
```c++
#include <iostream>
#include <vector>
#include <string>
#include "quicksort.h"

int main()
{
	std::vector<int> unordered_nums = { 5, 2, 3, 1, 4 };
	Quicksorter qs(unordered_nums, false /* step-by-step logging */); /* Only accepts vector<int> (for now) */
	std::vector<int> sorted = qs.sort();

	// You can join the results to string with the provided join_result(std::vector<int> vec, std::string seperator) function
	std::string joined = join_result(sorted, " ");
	std::cout << joined << std::endl; // 1 2 3 4 5

	return 0;
}
```
Or you can just use the console application provided. (main.cpp)
