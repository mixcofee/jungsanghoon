#pragma once
#include"Mecro.h"
#include"Munser.h"
class Interface
{
public:
	Munser* GetMunser() { return CreateMunser(); }
	virtual ~Interface() { cout << "인터페이스 소멸자" << endl; }
protected:
	virtual Munser* CreateMunser() = 0;
};

