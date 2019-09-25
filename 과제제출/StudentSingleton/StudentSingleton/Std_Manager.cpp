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
		cout << "   1.�л� ���" << endl;
		cout << "   2.��ü �л����� ���" << endl;
		cout << "   3.�л� ��ȣ �˻�" << endl;
		cout << "   4.�л� �̸� �˻�" << endl;
		cout << "   5.��޺� ���" << endl;
		cout << "   0.����" << endl;
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
		default:cout << "�߸� �Է� " << endl;
		}
		system("pause"); system("cls");
	}
}

void Std_manager::setStudent()
{
	if (m_iStudentCount >= 30)
		cout << "�л��� ���� ��� �Ǿ����ϴ�." << endl;
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
	cout << "ã�� �л��ǹ�ȣ�� �Է� �Ͻÿ�";
	cin >> _find;
	for (auto iter = m_vectorStudentList.begin(); iter != m_vectorStudentList.end(); ++iter)
		if ((*iter)->FindNumber(_find) == true)
		{
			(*iter)->showStudent();
			Count++;
		}
	if (Count == 0)
		cout << endl << "�ش� ��ȣ�� �л��� �����ϴ�." << endl;
}

void Std_manager::findname()
{
	string _find;
	int find_num = 0;
	cout << "ã�� �л����̸��� �Է� �Ͻÿ�";
	cin >> _find;
	for (auto iter = m_vectorStudentList.begin(); iter != m_vectorStudentList.end(); ++iter)
	{
		if ((*iter)->FindName(_find) == true)
			(*iter)->showStudent();
		else
			cout << "�ش� �̸��� �л��� �����ϴ�." << endl;
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
	cout << "�� " << _find << "��" << endl;
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
	cout << "�� " << _find << "��" << endl;
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
	cout << "�� " << _find << "��" << endl;
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
	cout << "�� " << _find << "��" << endl;
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
	cout << "�� " << _find << "��" << endl;
	cout << "=========================" << endl;

}
Std_manager::~Std_manager()
{
	for (auto iter = m_vectorStudentList.begin(); iter != m_vectorStudentList.end(); ++iter)
		delete(*iter);
}