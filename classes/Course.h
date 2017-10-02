#pragma once
#include<string>
#include <vector>
#include "QuestionBank.h"
#include "Exam.h"
using namespace std;
class Course {
private:
	Exam exam;
	int course_id;
	string name;
	int credithrs;
	QuestionBank  Question_Bank;
public:
	Course(Exam exam,QuestionBank Question_Bank,int course_id, string name,int credithrs);
	int getcourse_id();
	string getname();
	int getcredithrs();
	void setcourse_id(int id);
	void setname(string name);
	void setcredithrs(int credithrs);
	void setexam(Exam exam);
	Exam getexam();
	QuestionBank  getQuestion_Bank();
};
