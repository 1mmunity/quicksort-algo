#pragma once

class Quicksorter
{
private:
	std::vector<int> result;
	bool logging;
	void quicksort(int start, int end);
	int partition(int start, int end);

public:
	std::vector<int> inputs;
	Quicksorter(std::vector<int> inputs, bool logging);

	std::vector<int> sort();
};

std::string join_result(std::vector<int> vec, std::string seperator);
