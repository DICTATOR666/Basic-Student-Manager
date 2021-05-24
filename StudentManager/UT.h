//大学城校区学生
#pragma once
#include<iostream>
using namespace std;
#include"student.h"

class UT :public Student {
public:
	UT(int id, string name, string major, int cId);  //构造函数

	void ShowInfo();  //显示个人信息

	string GetCampusName();  //获取专业名称
};
