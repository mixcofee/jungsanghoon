#include"InterfaceTemplate.h"
#include"MunserExcel.h"
#include"MunserHangle.h"
void main()
{
	InterfaceTemplate<MunserExcel> Excel;
	InterfaceTemplate<MunserHangle> Hangle;
	Munser* Emunser = Excel.GetMunser();
	Emunser->Print();

	Munser* Hmunser = Hangle.GetMunser();
	Hmunser->Print();

	delete Emunser;
	delete Hmunser;

}