#include"UT.h"

UT::UT(int id, string name, string major, int cId) {
	m_Id = id;
	m_Name = name;
	m_Major = major;
	m_CampusId = cId;
}

void UT::ShowInfo() {
	cout << "学号:" << m_Id
		<< "\t学生姓名：" << m_Name
		<< "\t专业：" << m_Major
		<< "\t校区：" << GetCampusName()  //大学城校区编号为3
		<< endl;
}

string UT::GetCampusName() {
	return string("大学城校区");
}
