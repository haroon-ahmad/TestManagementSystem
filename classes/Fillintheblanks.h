#pragma once
#include "Question.h"
class fillintheblanks:public Question {
private:
	string answer;//correct answer
	string attempted;//answer which student attempted
	bool ifcorrect;//true for correct
public:
	fillintheblanks(string statement, float total_marks, float obt_marks, string answer, string attempted,bool correct);
	string getanswer();
	string getattempted();
	bool getifcorrect();
	void setanswer(string answer);
	void setattempted(string attempted);
	void setifcorrect(bool ifcorrect);
	void check(int marks);

};