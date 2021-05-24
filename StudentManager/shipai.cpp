#include"shipai.h"

Shipai::Shipai(int id, string name, string major, int cId) {
	m_Id = id;
	m_Name = name;
	m_Major = major;
	m_CampusId = cId;
}

void Shipai::ShowInfo() {
	cout << "学号:" << m_Id
		<< "\t学生姓名：" << m_Name
		<< "\t专业：" << m_Major
		<< "\t校区：" << GetCampusName()  //石牌校区编号为1
		<< endl;
}

string Shipai::GetCampusName() {
	return string("石牌校区");
}
