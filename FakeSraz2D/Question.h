#pragma once

#include <string>

class Question {
private:
	std::string _question;
	std::string _correct_answer;
	std::string _wrong_answer1;
	std::string _wrong_answer2;
	std::string _wrong_answer3;
public:
	Question();
	Question(std::string question, std::string correct_answer, std::string wrong_answer1, std::string wrong_answer2, std::string wrong_answer3);
	std::string get_question();
	std::string get_correct_answer();
	std::string get_wrong_answer1();
	std::string get_wrong_answer2();
	std::string get_wrong_answer3();
	void set_question(std::string question);
	void set_correct_answer(std::string answer);
	void set_wrong_answer1(std::string answer);
	void set_wrong_answer2(std::string answer);
	void set_wrong_answer3(std::string answer);
	std::string for_file_writing();
	std::string to_string();
};
