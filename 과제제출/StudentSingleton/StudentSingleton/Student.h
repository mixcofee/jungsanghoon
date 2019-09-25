#include<iostream>
#include<string>
#define max_len 100
using namespace std;

class Student
{
private:
	string name;
	int kor, eng, math, sum;
	float avg;
	int num;
	char Class;
public:
	Student(int Num);
	bool FindNumber(int StudentNumer);
	bool FindName(string Name);
	bool FindClass(char Class);
	void SetStudent(int _num);
	void showStudent();

	~Student();
};

