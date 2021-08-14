#include <vector>
#include <iostream>
#include <string>
#include "quicksort.h"

// global
int step_index;

// Quicksorter class
Quicksorter::Quicksorter(std::vector<int> inputs, bool logging)
{
	this->inputs = inputs;
	this->result = inputs;
	this->logging = logging;
}

std::vector<int> Quicksorter::sort()
{
	quicksort(0, this->inputs.size() - 1);
	return this->result;
}

// private
void Quicksorter::quicksort(int start, int end)
{
	if (end <= start) return;
	int pivot = this->partition(start, end);
	this->quicksort(start, pivot - 1);
	this->quicksort(pivot + 1, end);
	++step_index;
	if (this->logging) {
		std::cout << join_result(this->result, " ") << " | Step " << step_index << "\n";
	}
}

int Quicksorter::partition(int start, int end)
{
	int pivot = this->result[end];
	int i = start - 1;

	for (int j = start; j <= end; j++) {
		if (this->result[j] < pivot) {
			i++;
			int temp = this->result[i];
			this->result[i] = this->result[j];
			this->result[j] = temp;
		}
	}
	i++;
	int temp = this->result[i];
	this->result[i] = this->result[end];
	this->result[end] = temp;

	return i;
}

// End Quicksorter class

std::string join_result(std::vector<int> vec, std::string seperator)
{
	std::string res;
	int nums_size = vec.size();
	for (int i = 0; i < nums_size; i++) {
		std::string n = std::to_string(vec[i]);
		if (i < nums_size - 1) {
			res += (n + seperator);
		}
		else {
			res += n;
		}
	}
	return res;
}
