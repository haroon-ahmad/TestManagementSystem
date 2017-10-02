#pragma once
#include "Question.h"
#include <vector>
class Examsection {
private:
	static int section_id;
	int sectionid;
	vector<Question*> questions;
public:
	Examsection(vector<Question*> questions);
	void addquestion(Question* question);
	void removequestion(Question* question);
};