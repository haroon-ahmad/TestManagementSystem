#pragma once
#include "Question.h"
#include <vector>
class Mcq :public Question{
private:
	vector<string> options;
	char correct_opt;
	char chosen_opt;
public:
	Mcq(vector<string> options,string statement, float total_marks, float obt_marks, char correct_opt,char chosen_opt);
	char getcorrect_opt();
	char getchosen_opt();
	vector<string> getoptions();
	void setoptions(vector<string> options);
	void setcorrect_opt(char correct_opt);
	void setchosen_opt(char chosen_opt);
	void check(int marks);
};
