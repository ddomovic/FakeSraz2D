#pragma once

#include <vector>

class QuestionDB {
private:
	std::string _file_name;
	std::string _delimiter;
	std::vector<class Question*> _questions;
public:
	QuestionDB(const std::string &file_name);
	std::string& get_file_name();
	std::string& get_delimiter();
	std::vector<class Question*> get_questions();
	void set_file_name(std::string &file_name);
	void set_delimiter(std::string &delimiter);
	void print_questions();
	bool read_questions();
	class Question* get_random_question();
};