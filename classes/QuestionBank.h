#pragma once
#include "Question.h"
class QuestionBank {
private:
	int QB_id;
	Question** questions;
	int size;
public:
	QuestionBank();
	QuestionBank( Question **questions,int QB_id, int size);
	int getQB_id();
	Question** getquestions();
	int getsize();
	void addquestion(Question* question);
	void removequestion(int id);
	void view();

};