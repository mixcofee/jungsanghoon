#include<iostream>
#include<vector>
#include<string>
#define MAX_X 13
#define MAX_Y 13
using namespace std;

void main()
{
	vector<string> v;
	if (v.empty())//������ ����ٸ� �����Ҵ�
		v.reserve(MAX_X*MAX_Y);
	vector<string>::iterator iter;
	for (int i = 0; i < (MAX_X*MAX_Y); ++i)//����ü�� "��"�� �ʱ�ȭ
		v.push_back("��");
	try
	{
		v.at(13) = "��";
		v.at(14) = "��";
		for (vector<int>::size_type i = 27; i < 35; ++i)
			v[i] = "��";
		for (vector<int>::size_type i = 42; i < 100; i += 13)
		{
			v.at(i) = "��";
			iter = v.begin() + i;
		}
		for (vector<int>::size_type i = 0; i < 6; i++)
			*++iter = "��";
		for (vector<int>::size_type i = 100; i < v.size(); i += 13)
			v.at(i) = "��";
	}
	catch (out_of_range)
	{
		cout << "���� �̻�����";
	}
	iter = v.begin();
	while (iter != v.end())
	{
		for (vector<int>::size_type i = 0; i < v.size(); ++i)
		{
			cout << *iter++;
			if (i != 0 && (i + 1) % MAX_X == 0)//i�� 13�϶� �ٹٲ�
				cout << endl;
		}
	}
	v.clear();
}