#pragma once
#include"Mecro.h"
#include"Munser.h"
class Interface
{
public:
	Munser* GetMunser() { return CreateMunser(); }
	virtual ~Interface() { cout << "�������̽� �Ҹ���" << endl; }
protected:
	virtual Munser* CreateMunser() = 0;
};

