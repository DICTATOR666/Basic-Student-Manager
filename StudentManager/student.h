#pragma once
#include<iostream>
using namespace std;
#include<string>

class Student {  //抽象学生类
public:
	virtual void ShowInfo() = 0;  //显示个人信息

	virtual string GetCampusName() = 0;  //获取专业名称

	int m_Id;  //学号
	string m_Name;  //姓名
	string m_Major;  //专业
	int m_CampusId;  //校区编号
	
};
