#pragma once
#include"Interface.h"
template <typename T>
class InterfaceTemplate : public Interface
{
public:
	virtual ~InterfaceTemplate() { cout << "���ø� �������̽� �Ҹ�" << endl; }
private:
	Munser* CreateMunser() { return new T; }

};

