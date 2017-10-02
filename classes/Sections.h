#pragma once
#include "Course.h"
class Student;
class Sections {
private:
	int section_id;
	Course course;
	Student* students;
	int capacity;
	int size;
public:
	Sections(Student* student, Course course, int section_id,int capacity,int size);
	Course getcourse();
	Student* getstudents();
	int getsection_id();
	int getsize();
	int getcapacity();
	void setsection_id();
	void setstudents(Student students, int size);
	void addstudent(Student student);
	void setcourse(Course course);
	
};