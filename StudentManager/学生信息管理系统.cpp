#include<iostream>
using namespace std;
#include"studentManager.h"

int main(){

	StudentManager sm;
	int choice;  //用户选项

	while (1) {
		sm.ShowMenu();

		cout << "请输入需要使用功能的数字" << endl;
		cin >> choice;

		switch (choice) {
		case 0:  //退出系统
			sm.ExitSystem();
			break;
		case 1:  //增加学生
			sm.AddStudent();
			break;
		case 2:  //显示学生
			sm.ShowStudent();
			break;
		case 3:  //删除学生
			sm.DelStudent();
			break;
		case 4:  //查找学生
			sm.FindStudent();
			break;
		case 5:  //排序学生
			sm.SortStudent();
			break;
		case 6:  //清空文档
			sm.CleanFile();
			break;
		default:
			system("cls");
			cout << "输入有误，请重新输入0~6的数字" << endl;
			system("pause");
			break;
		}
	}

	return 0;

}
