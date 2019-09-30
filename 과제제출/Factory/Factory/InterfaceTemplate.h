#pragma once
#include"Interface.h"
template <typename T>
class InterfaceTemplate : public Interface
{
public:
	virtual ~InterfaceTemplate() { cout << "ÅÛÇÃ¸´ ÀÎÅÍÆäÀÌ½º ¼Ò¸ê" << endl; }
private:
	Munser* CreateMunser() { return new T; }

};

