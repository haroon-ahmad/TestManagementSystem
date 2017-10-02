#pragma once
#include <string>
using namespace std;
class Question {
private:
	static int question_id;
	int questionid;
	string statement;
	float total_marks;
	float obt_marks;
public:
	Question(string statement,float total_marks,float obt_marks);
	float gettotal_marks();
	float getquestionid();
	float getobt_marks();
	string getstatement();
	void setstatement(string statement);
	void settotal_marks(float marks);
	void setobt_marks(float marks);
	virtual void check(int marks) = 0;
	int getquestion_id();
};
