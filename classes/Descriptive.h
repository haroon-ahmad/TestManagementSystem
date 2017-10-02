#pragma once
#include "Question.h"
class Descriptive :public Question {
private:
	string answer;
public:
	Descriptive(string statement, float total_marks, float obt_marks, string answer);
	string getanswer();
	void setanswer(string answer);
	void check(int marks);
};