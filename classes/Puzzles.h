#pragma once
#include "Question.h"
class Puzzles :public Question {
private:
	string answer;
public:
	Puzzles(string statement, float total_marks, float obt_marks, string answer);
	string getanswer();
	void setanswer(string answer);
	void check(int marks);
};
