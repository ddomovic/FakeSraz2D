#include "stdafx.h"
#include "Question.h"

Question::Question() : _question(""), _correct_answer(""), _wrong_answer1(""), _wrong_answer2(""), _wrong_answer3("") {
}

Question::Question(std::string question, std::string correct_answer, std::string wrong_answer1, std::string wrong_answer2, std::string wrong_answer3) :
	_question(question), _correct_answer(correct_answer), _wrong_answer1(wrong_answer1), _wrong_answer2(wrong_answer2), _wrong_answer3(wrong_answer3) {
}

std::string Question::get_question() {
	return this->_question;
}
std::string Question::get_correct_answer() {
	return this->_correct_answer;
}
std::string Question::get_wrong_answer1() {
	return this->_wrong_answer1;
}
std::string Question::get_wrong_answer2() {
	return this->_wrong_answer2;
}
std::string Question::get_wrong_answer3() {
	return this->_wrong_answer3;
}
void Question::set_question(std::string question) {
	this->_question = question;
}
void Question::set_correct_answer(std::string answer) {
	this->_correct_answer = answer;
}
void Question::set_wrong_answer1(std::string answer) {
	this->_wrong_answer1 = answer;
}
void Question::set_wrong_answer2(std::string answer) {
	this->_wrong_answer2 = answer;
}
void Question::set_wrong_answer3(std::string answer) {
	this->_wrong_answer3 = answer;
}

std::string Question::for_file_writing() {
	return this->_question + "#" + this->_correct_answer + "#" + this->_wrong_answer1 + "#" + this->_wrong_answer2 + "#" + this->_wrong_answer3;
}

std::string Question::to_string() {
	return "Q: " + this->_question + "\na) " + this->_correct_answer + "\nb) " + this->_wrong_answer1 +
		"\nc) " + this->_wrong_answer2 + "\nd) " + this->_wrong_answer3 + "\n";
}
