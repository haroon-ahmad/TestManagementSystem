#pragma once
#include "Question.h"
class Programming :public Question {
private:
	string answer;
public:
	Programming(string statement, float total_marks, float obt_marks, string answer);
	string getanswer();
	void setanswer(string answer);
	void check(int marks);
};