//南海校区学生
#pragma once
#include<iostream>
using namespace std;
#include"student.h"

class Nanhai :public Student {
public:
	Nanhai(int id, string name, string major, int cId);  //构造函数

	void ShowInfo();  //显示个人信息

	string GetCampusName();  //获取专业名称
};
