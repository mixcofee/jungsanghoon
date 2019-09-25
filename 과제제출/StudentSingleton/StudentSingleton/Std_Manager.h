#pragma once
#include "Student.h"
#include<vector>
#include"Singleton.h"

class Std_manager :public Singleton<Std_manager>
{
	vector<Student*> m_vectorStudentList;
	int m_iStudentCount;

public:
	Std_manager();
	void display();
	void setStudent();
	void showStudent();
	void findNumber();
	void findname();
	void findClass();
	~Std_manager();

};

