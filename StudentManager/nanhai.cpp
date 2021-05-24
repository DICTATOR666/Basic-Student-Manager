#include"nanhai.h"

Nanhai::Nanhai(int id, string name, string major, int cId) {
	m_Id = id;
	m_Name = name;
	m_Major = major;
	m_CampusId = cId;
}

void Nanhai::ShowInfo() {
	cout << "学号:" << m_Id
		<< "\t学生姓名：" << m_Name
		<< "\t专业：" << m_Major
		<< "\t校区：" << GetCampusName()  //南海校区编号为2
		<< endl;
}
string Nanhai::GetCampusName() {
	return string("南海校区");
}
