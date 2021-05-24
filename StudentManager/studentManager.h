#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include"linkedlist.h"
#include"student.h"
#include"shipai.h"
#include"nanhai.h"
#include"UT.h"

#define FILENAME "studentFile.txt"

class StudentManager {  //学生管理类
public:
	StudentManager(); //构造函数

	void ShowMenu();  //显示菜单

	void AddStudent();  //增加学生

	void ExitSystem();  //退出系统

	void Save();  //保存数据

	int GetNumber();  //获取文件中学生数量

	void InitStudent();  //初始化学生，用于读取文件数据

	void ShowStudent();  //显示学生数据

	void DelStudent();  //删除学生

	void FindStudent();  //查找学生并显示

	void FindinName(string studentName);  //按照姓名查找

	void SortStudent();  //将学生以学号进行排序

	void CleanFile();  //清空文件及相关数据

	~StudentManager();  //析构函数


	LinkedList m_StudentList;  //存储学生数据的链表

	bool m_FileIsEmpty;  //文件是否为空标志
};
