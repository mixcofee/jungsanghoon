#include "Std_Manager.h"

Std_manager::Std_manager()
{
	m_iStudentCount = 1;
}

void Std_manager::display() {
	int sel;
	while (true)
	{
		cout << "=========================" << endl;
		cout << "   1.학생 등록" << endl;
		cout << "   2.전체 학생정보 출력" << endl;
		cout << "   3.학생 번호 검색" << endl;
		cout << "   4.학생 이름 검색" << endl;
		cout << "   5.등급별 출력" << endl;
		cout << "   0.종료" << endl;
		cout << "=========================" << endl;
		cin >> sel;
		switch (sel) {
		case 1:
			Singleton::Getinstance()->setStudent();
			break;
		case 2:
			Singleton::Getinstance()->showStudent();
			break;
		case 3:
			Singleton::Getinstance()->findNumber();
			break;
		case 4:
			Singleton::Getinstance()->findname();
			break;
		case 5:
			Singleton::Getinstance()->findClass();
			break;
		case 0:return;
		default:cout << "잘못 입력 " << endl;
		}
		system("pause"); system("cls");
	}
}

void Std_manager::setStudent()
{
	if (m_iStudentCount >= 30)
		cout << "학생이 전원 등록 되었습니다." << endl;
	else
	{
		m_vectorStudentList.push_back(new Student(m_iStudentCount));
		m_iStudentCount++;
	}
}

void Std_manager::showStudent()
{
	for (auto iter = m_vectorStudentList.begin(); iter != m_vectorStudentList.end(); ++iter)
		(*iter)->showStudent();
}

void Std_manager::findNumber()
{
	int Count = 0;
	int _find;
	cout << "찾을 학생의번호를 입력 하시오";
	cin >> _find;
	for (auto iter = m_vectorStudentList.begin(); iter != m_vectorStudentList.end(); ++iter)
		if ((*iter)->FindNumber(_find) == true)
		{
			(*iter)->showStudent();
			Count++;
		}
	if (Count == 0)
		cout << endl << "해당 번호의 학생이 없습니다." << endl;
}

void Std_manager::findname()
{
	string _find;
	int find_num = 0;
	cout << "찾을 학생의이름을 입력 하시오";
	cin >> _find;
	for (auto iter = m_vectorStudentList.begin(); iter != m_vectorStudentList.end(); ++iter)
	{
		if ((*iter)->FindName(_find) == true)
			(*iter)->showStudent();
		else
			cout << "해당 이름의 학생이 없습니다." << endl;
	}
}

void Std_manager::findClass()
{
	int _find = 0;
	cout << "========= [ A ] =========" << endl;
	for (auto iter = m_vectorStudentList.begin(); iter != m_vectorStudentList.end(); ++iter)
	{
		if ((*iter)->FindClass('A') == true)
		{
			(*iter)->showStudent();
			_find++;
		}
	}
	cout << "총 " << _find << "명" << endl;
	cout << "=========================" << endl << endl << endl;
	_find = 0;
	cout << "========= [ B ] =========" << endl;
	for (auto iter = m_vectorStudentList.begin(); iter != m_vectorStudentList.end(); ++iter)
	{
		if ((*iter)->FindClass('B') == true)
		{
			(*iter)->showStudent();
			_find++;
		}
	}
	cout << "총 " << _find << "명" << endl;
	cout << "=========================" << endl;
	_find = 0;
	cout << "========= [ C ] =========" << endl;
	for (auto iter = m_vectorStudentList.begin(); iter != m_vectorStudentList.end(); ++iter)
	{
		if ((*iter)->FindClass('C') == true)
		{
			(*iter)->showStudent();
			_find++;
		}
	}
	cout << "총 " << _find << "명" << endl;
	cout << "=========================" << endl;
	_find = 0;
	cout << "========= [ D ] =========" << endl;
	for (auto iter = m_vectorStudentList.begin(); iter != m_vectorStudentList.end(); ++iter)
	{
		if ((*iter)->FindClass('D') == true)
		{
			(*iter)->showStudent();
			_find++;
		}
	}
	cout << "총 " << _find << "명" << endl;
	cout << "=========================" << endl;
	_find = 0;
	cout << "========= [ F ] =========" << endl;
	for (auto iter = m_vectorStudentList.begin(); iter != m_vectorStudentList.end(); ++iter)
	{
		if ((*iter)->FindClass('F') == true)
		{
			(*iter)->showStudent();
			_find++;
		}
	}
	cout << "총 " << _find << "명" << endl;
	cout << "=========================" << endl;

}
Std_manager::~Std_manager()
{
	for (auto iter = m_vectorStudentList.begin(); iter != m_vectorStudentList.end(); ++iter)
		delete(*iter);
}