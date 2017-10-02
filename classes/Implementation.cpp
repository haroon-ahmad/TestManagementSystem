#include "Question.h"
#include "Mcq.h"
#include "Fillintheblanks.h"
#include "Descriptive.h"
#include "Programming.h"
#include "Puzzles.h"
#include "Course.h"
#include "Teacher.h"
#include "QuestionBank.h"
#include "ExamSection.h"
#include "Exam.h"
#include <utility>
#include <iostream>


int Question::question_id = 0;
//Question
Question::Question(string statement = " ", float total_marks = 0, float obt_marks = 0)
{
	this->statement = statement;
	this->total_marks = total_marks;
	this->obt_marks = obt_marks;
	questionid=question_id++;
}
float Question::gettotal_marks()
{
	return total_marks;
}


float Question::getquestionid()
{
	return questionid;
}
float Question::getobt_marks()
{
	return obt_marks;
}
string Question::getstatement()
{
	return statement;
}
void Question::setstatement(string statement)
{
	this->statement = statement;
}
void Question::settotal_marks(float marks)
{
	this->total_marks = marks;
}
void Question::setobt_marks(float marks)
{
	this->obt_marks = marks;
}
int Question::getquestion_id()
{
	return  question_id;
}
//MCQ
Mcq::Mcq(vector<string> options = {" "}, string statement = " ", float total_marks = 0.0, float obt_marks = 0.0, char correct_opt = ' ', char chosen_opt = ' ') :Question(statement, total_marks, obt_marks)
{
	this->options = options;
	this->correct_opt = correct_opt;
	this->chosen_opt = chosen_opt;
}
char Mcq::getcorrect_opt()
{
	return correct_opt;
}
char Mcq::getchosen_opt()
{
	return chosen_opt;
}
vector<string> Mcq::getoptions()
{
	return options;
}
void Mcq::setoptions(vector<string> options)
{
	this->options = options;
}
void Mcq::setcorrect_opt(char correct_opt)
{
	this->correct_opt = correct_opt;
}
void Mcq::setchosen_opt(char chosen_opt)
{
	this->chosen_opt = chosen_opt;
}
void Mcq::check(int marks=0)
{
	if (chosen_opt == correct_opt)
	{
		setobt_marks(gettotal_marks());
	}
	else
	{
		setobt_marks(0);
	}
}
//Fillintheblanks
fillintheblanks::fillintheblanks(string statement=" ", float total_marks=0.0, float obt_marks=0.0, string answer=" ", string attempted=" ", bool correct=false):Question(statement, total_marks, obt_marks)
{
	this->answer = answer;
	this->attempted = attempted;
	this->ifcorrect = ifcorrect;
}
string fillintheblanks::getanswer()
{
	return answer;
}
string fillintheblanks::getattempted()
{
	return attempted;
}
bool fillintheblanks::getifcorrect()
{
	return ifcorrect;
}
void fillintheblanks::setanswer(string answer)
{
	this->answer = answer;
}
void fillintheblanks::setattempted(string attempted)
{
	this->attempted = attempted;
}
void fillintheblanks::setifcorrect(bool ifcorrect)
{
	this->ifcorrect = ifcorrect;
}
void fillintheblanks::check(int marks = 0)
{
	if (getifcorrect())
	{
		setobt_marks(gettotal_marks());
	}
	else
	{
		setobt_marks(marks);
	}
}

//Descriptive
Descriptive::Descriptive(string statement=" ", float total_marks=0.0, float obt_marks=0.0, string answer=" ") :Question(statement, total_marks, obt_marks)
{
	this->answer = answer;
}
string Descriptive::getanswer()
{
	return answer;
}
void Descriptive::setanswer(string answer)
{
	this->answer = answer;
}
void Descriptive::check(int marks=0)
{
	setobt_marks(marks);
}

//Programming
Programming::Programming(string statement = " ", float total_marks = 0.0, float obt_marks = 0.0, string answer = " ") :Question(statement, total_marks, obt_marks)
{
	this->answer = answer;
}
string Programming::getanswer()
{
	return answer;
}
void Programming::setanswer(string answer)
{
	this->answer = answer;
}
void Programming::check(int marks = 0)
{
	setobt_marks(marks);
}

//Puzzles
Puzzles::Puzzles(string statement = " ", float total_marks = 0.0, float obt_marks = 0.0, string answer = " ") :Question(statement, total_marks, obt_marks)
{
	this->answer = answer;
}
string Puzzles::getanswer()
{
	return answer;
}
void Puzzles::setanswer(string answer)
{
	this->answer = answer;
}
void Puzzles::check(int marks = 0)
{
	setobt_marks(marks);
}

//Course
Course::Course(Exam exam,QuestionBank Question_Bank,int course_id=0, string name=" ", int credithrs=0)
{
	this->course_id = course_id;
	this->name = name;
	this->credithrs = credithrs;
	this->exam = exam;
	this->Question_Bank = Question_Bank;
}
int Course::getcourse_id()
{
	return course_id;
}
string Course::getname()
{
	return name;
}
int Course::getcredithrs()
{
	return credithrs;
}
void Course::setcourse_id(int id)
{
	this->course_id = id;
}
void Course::setname(string name)
{
	this->name = name;
}
void Course::setcredithrs(int credithrs)
{
	this->credithrs = credithrs;
}
QuestionBank  Course::getQuestion_Bank()
{
	return Question_Bank;
}
void Course::setexam(Exam exam)
{
	this->exam = exam;
}
Exam Course::getexam()
{
	return exam;
}
//Section

//Teacher
Teacher::Teacher(vector<Course> courses ,int teacher_id = 0,  string fname = " ", string lname = " ", string address = " ", string DOB = " ", string cnic = " ")
{
	this->teacher_id = teacher_id;
	this->courses = courses;
	this->fname = fname;
	this->address = address;
	this->lname = lname;
	this->DOB = DOB;
	this->cnic = cnic;
}
vector<Course> Teacher::getcourses()
{
	return courses;
}
string Teacher::getcnic()
{
	return cnic;
}
string Teacher::getname()
{
	return (fname + lname);
}
int Teacher::getid()
{
	return teacher_id;
}
string Teacher::getaddress()
{
	return address;
}
string Teacher::getDOB()
{
	return DOB;
}
void Teacher::setTeacher(vector<Course> courses, int teacher_id, string fname, string lname, string address, string DOB, string cnic)
{
	this->teacher_id = teacher_id;
	this->courses = courses;
	this->fname = fname;
	this->address = address;
	this->lname = lname;
	this->DOB = DOB;
	this->cnic = cnic;
}
void Teacher::createExam(Exam exam,Course course)
{
	int i;
	for (i = 0; i < courses.size(); i++)
	{
		if (courses[i].getcourse_id() == course.getcourse_id()){
			break;
		}
		
	}
	courses[i].setexam(exam);
}

//QuestionBank
QuestionBank::QuestionBank()
{
	size = 1;
}
QuestionBank::QuestionBank(Question **questions,int QB_id=0,int size=1)
{
	this->QB_id = QB_id;
	this->questions = questions;
	this->size = size;
}
int QuestionBank::getQB_id()
{
	return QB_id;
}
Question** QuestionBank::getquestions()
{
	return questions;
}
int QuestionBank::getsize()
{
	return size;
}
void QuestionBank::addquestion(Question* question)
{
	size = size + 1;
	Question **temp = new Question*[size];
	for (int i = 0; i <(size-1); ++i)
	{
		temp[i] = questions[i];
	}
	temp[size] = question;
	questions = temp;
	questions[size]=question;
}
void QuestionBank::view()
{
	//write code according to QT
	for(int i=0;i<size;i++)
	{
		cout<<questions[i]->getquestionid();
	}

}

//ExamSection
int Examsection::section_id = 0;

Examsection::Examsection(vector<Question*> questions)
{
	this->questions = questions;
	sectionid = section_id++;
}
void Examsection::addquestion(Question* question)
{
	questions.push_back(question);
}
void Examsection::removequestion(Question* question)
{
	int i;
	for (i = 0; i < questions.size(); i++)
	{
		if (questions[i]->getquestionid() == question->getquestionid()){
			questions.erase(questions.begin() + i);

			break;
		}
	}
}

//Exam
int Exam::exam_id = 0;
Exam::Exam()
{
	number = 0;

}
Exam::Exam(vector<Examsection> sections, int number=0)
{
	this->sections = sections;
	this->number = number;
	examid = exam_id++;
}
int Exam::getnumber()
{
	return number;
}
int Exam::getexamid()
{
	return examid;
}
void Exam::setnumber(int number)
{
	this->number = number;
}
vector<Examsection> Exam::getsections()
{
	return sections;
}