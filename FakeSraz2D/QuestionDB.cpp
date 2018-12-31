#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Question.h"
#include "QuestionDB.h"

QuestionDB::QuestionDB(const std::string &file_name) : _file_name(file_name), _delimiter("#") {
	this->_file_name = file_name;
}

std::string& QuestionDB::get_file_name() {
	return this->_file_name;
}

std::string& QuestionDB::get_delimiter() {
	return this->_delimiter;
}

std::vector<Question*> QuestionDB::get_questions() {
	return this->_questions;
}

void QuestionDB::set_file_name(std::string &file_name) {
	this->_file_name = file_name;
}

void QuestionDB::set_delimiter(std::string &delimiter) {
	this->_delimiter = delimiter;
}

void QuestionDB::print_questions() {
	for (std::vector<Question*>::iterator it = this->_questions.begin(); it != this->_questions.end(); ++it) {
		std::cout << (*it)->to_string();
	}

	std::cout << std::endl;
}

bool QuestionDB::read_questions() {
	std::ifstream f(this->_file_name, std::ios::in | std::ios::binary);
	if (!f) {
		std::cerr << "File not present!\n";
		return false;
	}
	int magic_number;
	f.read(reinterpret_cast<char*>(&magic_number), sizeof(int));
	if (magic_number == 262) {
		int size_of_question;
		while (f.read(reinterpret_cast<char*>(&size_of_question), sizeof(int))) {
			char *temp = new char[size_of_question + 1];
			f.read(temp, size_of_question);
			temp[size_of_question] = '\0';
			std::string aux(temp);
			delete[] temp;
			std::string token;
			size_t pos = 0;
			std::vector<std::string> str_vector;
			while ((pos = aux.find(this->_delimiter)) != std::string::npos) {
				token = aux.substr(0, pos);
				str_vector.push_back(token);
				aux.erase(0, pos + this->_delimiter.length());
			}
			str_vector.push_back(aux);
			this->_questions.push_back(new Question(str_vector[0], str_vector[1], str_vector[2], str_vector[3], str_vector[4]));
		}
	}
	else {
		std::cerr << "ERROR! Wrong magic number!" << std::endl;
		return false;
	}

	return true;
}

Question* QuestionDB::get_random_question() {
	return this->_questions[rand() % this->_questions.size()];
}