#pragma once
#include <string>
#include <vector>
class Teacher {
private:
	int teacher_id;
	string fname;
	string lname;
	string address;
	string DOB;
	string cnic;
	vector<Course> courses;
public:
	Teacher(vector<Course> courses,int teacher_id,string fname, string lname, string address, string DOB, string cnic);
	vector<Course> getcourses();
	string getcnic();
	string getname();
	int getid();
	string getaddress();
	string getDOB();
	void setTeacher(vector<Course> courses, int teacher_id, string fname, string lname, string address, string DOB, string cnic);
	void createExam(Exam exam,Course course);
};

