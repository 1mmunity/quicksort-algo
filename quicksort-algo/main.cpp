#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include "quicksort.h"

std::vector<int> split_to_int(std::string s, std::string delimiter);
std::string trim(std::string str);
std::string parse_input_file(std::string file_name);

int main()
{
    // prompter
    std::string input;
    std::cout << "Welcome to Quicksorter (C++)!\n";
    // check for input file
    try {
        input = parse_input_file("input.txt");
        if (input == "") throw std::exception("No input file found.");
        std::cout << "Detected input file\n" << input << "\n";
    }
    catch (...) {
        std::string message = "No input file found! (./input.txt), inputting through console\n"
            "Enter your input to be sorted (integers splitted by 1 space): ";
        std::cout << message;
        std::getline(std::cin, input);
    }
    input = trim(input);
    std::vector<int> inputs;
    try {
        inputs = split_to_int(input, " ");
    } catch (...) {
        std::cout << "Inputs must be integers or you have an extra whitespace!\n";
        return 0;
    }

    std::string sbslogging;
    std::cout << "Do you want a step-by-step logging (this will be much slower)? (y/n): ";
    std::getline(std::cin, sbslogging);
    sbslogging = std::tolower(sbslogging[0]);
    bool usesbslogging = false;
    if (sbslogging == "y") usesbslogging = true;

    auto start = std::chrono::high_resolution_clock::now();
    Quicksorter qs(inputs, usesbslogging);
    std::vector<int> sorted = qs.sort();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << join_result(sorted, " ") << " | Result\n"
        << "Sort executed in " << duration.count() << " microseconds. (C++ is super fast, so couldnt be recorded in miliseconds)\n";
    return 0;
}

std::string parse_input_file(std::string file_name)
{
    std::ifstream ifs(file_name);
    std::string content((std::istreambuf_iterator<char>(ifs)),
        (std::istreambuf_iterator<char>()));
    return content;
}

std::vector<int> split_to_int(std::string s, std::string delimiter)
{
    std::vector<int> res;
    int pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        // below error will be handled in prompt
        int inted_token = std::stoi(token);
        res.push_back(inted_token);
        s.erase(0, pos + delimiter.length());
    }
    // below error will be handled in prompt
    res.push_back(std::stoi(s));
    return res;
}

std::string trim(std::string str)
{
    const char* typeOfWhitespaces = " \t\n\r\f\v";
    str.erase(str.find_last_not_of(typeOfWhitespaces) + 1);
    str.erase(0, str.find_first_not_of(typeOfWhitespaces));
    return str;
}
