#include "Student.h"

Student::Student(int Num)
{
	cout << "�̸��� �Է� �Ͻÿ� : ";
	cin >> name;
	cout << "3������ ������ �Է��Ͻÿ�" << endl;
	cout << "���� : ";
	cin >> kor;
	cout << "���� : ";
	cin >> eng;
	cout << "���� : ";
	cin >> math;
	sum = kor + eng + math;
	num = Num;
	avg = (float)sum / 3;
	if (avg >= 90)
		Class = 'A';
	else if (avg >= 80)
		Class = 'B';
	else if (avg >= 70)
		Class = 'C';
	else if (avg >= 60)
		Class = 'D';
	else
		Class = 'F';
	return;
}


void Student::showStudent()
{
	cout << "----------------------" << endl;
	cout << num << "�� �л�" << endl;
	cout << "�̸� : " << name << endl;
	cout << "���� ���� : " << kor << endl << "���� ���� : " << math << endl << "���� ���� : " << eng << endl;
	cout << "�հ� ���� : " << sum << "\t ������� : " << avg << endl;
	cout << "��� : [ " << Class << "]" << endl << endl;
	return;
}

bool Student::FindNumber(int StudentNumber)
{
	if (this->num == StudentNumber)
		return true;
	return false;
}

bool Student::FindClass(char Class)
{
	if (this->Class == Class)
		return true;
	return false;
}

bool Student::FindName(string Name)
{
	if (this->name == Name)
		return true;
	return false;
}
Student::~Student()
{
}
