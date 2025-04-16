#include "ident.h"

std::string ident::Summery(const std::string& identifier) {
	std::string str = identifier;
	if (identifier.length() > 29) {
		std::cout << "Вы привысили допустимую длину\n";
		return " ";
	}
	else if (identifier.length() == 29) {
		int score = 0;
		for (int i = 0; i < identifier.length(); i++) {
			if (identifier[i] == 'Z' || identifier[i] == '9') {
				score += 1;
			}
		}
		if (score == 20) {
			std::cout << "Вы достигли лимита\n";
			return " ";
		}
	}
	if (identifier[identifier.length() - 2] == 'Z' && identifier[identifier.length() - 1] == '9') {
		int len = identifier.length();
		int act_let_pos = str.length() - 2;
		int act_num_pos = str.length() - 1;

		while (true) {
			if (identifier[act_let_pos] == 'Z' && identifier[act_num_pos] == '9' && act_let_pos != 0) {
				str[act_let_pos] = 'A';
				str[act_num_pos] = '1';
			}
			else if (identifier[act_num_pos] == '9' && act_let_pos != 0) {
				int let_pos = find_index(letters, identifier[act_let_pos], fact_let_size);
				str[act_let_pos] = letters[let_pos + 1];
				str[str.length() - 1] = '1';
				return str;
			}
			else if (act_let_pos != 0) {
				int num_pos = find_index(nums, identifier[act_num_pos], fact_num_size);
				str[act_num_pos] = nums[num_pos + 1];

				return str;
			}
			else {
				int num_pos = find_index(nums, identifier[act_num_pos], fact_num_size);
				str[act_num_pos] = nums[num_pos + 1];

				return str;
			}
			if (act_let_pos == 0 && str[act_let_pos] == 'Z' && str[act_num_pos] == '9') {
				str[act_let_pos] = 'A';
				str[act_num_pos] = '1';
				str += "-A1";
				return str;
			}
			act_let_pos -= 3;
			act_num_pos -= 3;
		}
		return str;
	}
	else if (identifier[identifier.length() - 1] == '9') {
		int let_pos = find_index(letters, identifier[identifier.length() - 2], fact_let_size);
		str[str.length() - 2] = letters[let_pos + 1];
		str[str.length() - 1] = '1';
		return str;
	}
	else {
		int num_pos = find_index(nums, identifier[identifier.length() - 1], fact_num_size);
		str[str.length() - 1] = nums[num_pos + 1];

		return str;
	}
	return "Что-то пошло не так:(";
}

int ident::find_index(const char arr[], char value, int size) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == value) {
			return i;
		}
	}
	return -1;
}