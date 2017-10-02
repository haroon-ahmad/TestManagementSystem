#pragma once
#include "Course.h"
#include "ExamSection.h"
#include <vector>
class Exam {
private:
	static int exam_id;
	int examid;
	vector<Examsection> sections;
	int number;//number of sections
public:
	Exam();
	Exam(vector<Examsection> sections,int number);
	int getnumber();
	int getexamid();
	void setnumber(int number);
	vector<Examsection> getsections();
};
