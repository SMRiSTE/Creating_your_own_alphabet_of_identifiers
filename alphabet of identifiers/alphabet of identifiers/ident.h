#pragma once

#include <iostream>
#include <string>
#include <algorithm>

class ident {
public:
	std::string Summery(const std::string& identifier);
private:
	const char letters[19] = { 'A', 'B', 'C', 'E', 'H', 'I', 'K', 'L', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'W', 'X', 'Y', 'Z' };
	const char nums[9] = { '1','2','3','4','5','6','7','8','9' };
	const int fact_let_size = sizeof(letters) / sizeof(letters[0]);
	const int fact_num_size = sizeof(nums) / sizeof(nums[0]);

	int find_index(const char arr[], char value, int size);
};