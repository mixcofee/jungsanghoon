#include<iostream>
#include<vector>
#include<string>
#define MAX_X 13
#define MAX_Y 13
using namespace std;

void main()
{
	vector<string> v;
	if (v.empty())//공간이 비었다면 공간할당
		v.reserve(MAX_X*MAX_Y);
	vector<string>::iterator iter;
	for (int i = 0; i < (MAX_X*MAX_Y); ++i)//맵전체를 "■"로 초기화
		v.push_back("■");
	try
	{
		v.at(13) = "□";
		v.at(14) = "□";
		for (vector<int>::size_type i = 27; i < 35; ++i)
			v[i] = "□";
		for (vector<int>::size_type i = 42; i < 100; i += 13)
		{
			v.at(i) = "□";
			iter = v.begin() + i;
		}
		for (vector<int>::size_type i = 0; i < 6; i++)
			*++iter = "□";
		for (vector<int>::size_type i = 100; i < v.size(); i += 13)
			v.at(i) = "□";
	}
	catch (out_of_range)
	{
		cout << "범위 이상접근";
	}
	iter = v.begin();
	while (iter != v.end())
	{
		for (vector<int>::size_type i = 0; i < v.size(); ++i)
		{
			cout << *iter++;
			if (i != 0 && (i + 1) % MAX_X == 0)//i가 13일때 줄바꿈
				cout << endl;
		}
	}
	v.clear();
}