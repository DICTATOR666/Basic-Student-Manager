#include"studentManager.h"

StudentManager::StudentManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	m_StudentList.Initialize();

	//文件不存在的情况
	if (!ifs.is_open()) {  
		m_FileIsEmpty = true;
		ifs.close();
		
		return;
	}

	//文件存在但是数据为空的情况
	char test;
	ifs >> test;
	if (ifs.eof()) {
		m_FileIsEmpty = true;
		ifs.close();

		return;
	}

	//文件存在且记录了数据
	InitStudent();

	m_FileIsEmpty = false;
}

void StudentManager::ShowMenu() {
	cout << "--------------------------------------------" << endl;
	cout << "------------欢迎使用学生管理系统------------" << endl;
	cout << "-------------  0.退出管理程序  -------------" << endl;
	cout << "-------------  1.增加学生信息  -------------" << endl;
	cout << "-------------  2.显示学生信息  -------------" << endl;
	cout << "-------------  3.删除学生信息  -------------" << endl;
	cout << "-------------  4.查找学生信息  -------------" << endl;
	cout << "-------------  5.按照编号排序  -------------" << endl;
	cout << "-------------  6.清空所有文档  -------------" << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
}

void StudentManager::AddStudent() {
	int n;
	cout << "请输入需要添加学生的数量" << endl;
	cin >> n;

	if (n <= 0) {
		cout << "输入数据有误，请检查后重新调用该功能" << endl;
		return;
	}

	for (int i = 1; i <= n; i++) {
		int id;  //学号
		string name;  //姓名
		string major;  //专业
		int campusId;  //校区编号

		cout << "请输入第" << i << "个学生的学号" << endl;
		cin >> id;

		cout << "请输入第" << i << "个学生的姓名" << endl;
		cin >> name;

		cout << "请输入第" << i << "个学生的专业" << endl;
		cin >> major;

		cout << "请输入第" << i << "个学生的校区编号" << endl;
		cin >> campusId;

		Student* newStudent = NULL;

		switch (campusId){
		case 1:
			newStudent = new Shipai(id, name, major, 1);
			break;
		case 2:
			newStudent = new Nanhai(id, name, major, 2);
			break;
		case 3:
			newStudent = new UT(id, name, major, 3);
			break;
		default:
			cout << "校区信息有误，本条学生信息未能成功输入" << endl;
			system("pause");
			system("cls");
			break;
		}

		if (newStudent == NULL) {
			continue;
		}

		m_StudentList.New(newStudent);
		cout << "添加新学生成功" << endl;
		m_FileIsEmpty = false;  //更新文件不为空的标志
		system("pause");
		system("cls");
	}

	Save();
}

void StudentManager::ExitSystem() {
	system("cls");
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void StudentManager::Save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (Node* temp = m_StudentList.GetHead(); temp != NULL; temp = temp->next) {
		ofs << temp->dataPtr->m_Id << " "
			<< temp->dataPtr->m_Name << " "
			<< temp->dataPtr->m_Major << " "
			<< temp->dataPtr->m_CampusId << endl;
	}

	ofs.close();
}

int StudentManager::GetNumber() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	string major;
	int cID;

	int num = 0;  //统计人数
	while (ifs >> id && ifs >> name && ifs >> major && ifs >> cID) {
		num++;
	}
	return num;
}

void StudentManager::InitStudent() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	string major;
	int cId;

	while (ifs >> id && ifs >> name && ifs >> major && ifs >> cId) {
		Student* newStudent = NULL;

		if (cId == 1) {  //石牌校区学生
			newStudent = new Shipai(id, name, major, cId);
		}
		else if (cId == 2) {  //南海校区学生
			newStudent = new Nanhai(id, name, major, cId);
		}
		else  {  //大学城校区学生
			newStudent = new UT(id, name, major, cId);
		}
		m_StudentList.New(newStudent);
	}
	ifs.close();
}

void StudentManager::ShowStudent() {
	if (m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");

		return;
	}

	m_StudentList.Print();
	system("pause");
	system("cls");
}

void StudentManager::DelStudent() {
	if (m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");

		return;
	}

	int choice;
	cout << "请输入删除的方式" << endl;
	cout << "输入1键按学号删除" << endl;
	cout << "输入2按姓名删除" << endl;
	cin >> choice;

	if (choice == 1) {
		int tempNum;
		int position;

		cout << "请输入需要删除的学生学号" << endl;
		cin >> tempNum;

		position = m_StudentList.Find(tempNum);
		m_StudentList.Del(position); 
	}
	
	else if (choice == 2) {
		string tempName;
		int position;

		cout << "请输入需要删除的学生姓名" << endl;
		cin >> tempName;

		while (1) {
			position = m_StudentList.Find(tempName);

			if (position == -1) {
				break;
			}

			m_StudentList.Del(position);
		}		
	}
	else {
		cout << "输入有误，请确认输入后重新调用该功能" << endl;
	}
	
	Save();
	system("pause");
	system("cls");
}

void StudentManager::FindStudent() {
	if (m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");

		return;
	}

	int choice;
	cout << "请输入查找的方式" << endl;
	cout << "输入1键按学号查找" << endl;
	cout << "输入2按姓名查找" << endl;
	cin >> choice;

	if (choice == 1) {
		int tempNum;
		int position;
		cout << "请输入所查找学生的学号" << endl;
		cin >> tempNum;

		position = m_StudentList.Find(tempNum);
		cout << "该学生信息如下：" << endl;
		m_StudentList.PrintSingle(position);
	}
	else if (choice == 2) {
		string tempName; 
		cout << "请输入查找的姓名" << endl;
		cin >> tempName;

		FindinName(tempName);
	}
	system("pause");
	system("cls");
}

void StudentManager::FindinName(string studentName) {
	bool flag = false;  //用于标志是否找到

	Node* temp = m_StudentList.GetHead();

	while (temp != NULL) {
		if (temp->dataPtr->m_Name == studentName) {
			cout << "该学生信息如下：" << endl;
			temp->dataPtr->ShowInfo();
			flag = true;
		}
		temp = temp->next;
	}

	if (flag == false) {
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

void StudentManager::SortStudent() {
	if (m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");

		return;
	}

	int choice;

	cout << "请选择排序方式" << endl;
	cout << "1.按学号升序排序" << endl;
	cout << "2.按学号降序排序" << endl;
	cin >> choice;

	if (choice == 1) {
		m_StudentList.SortStoL();
	}
	else if (choice == 2) {
		m_StudentList.SortLtoS();
	}
	else {
		cout << "输入有误，请检查输入后重新调用该功能" << endl;
		system("pause");
		system("cls");

		return;
	}

	cout << "排序完成，排序后所有学生如下显示：" << endl;
	m_StudentList.Print();
	Save();

	system("pause");
	system("cls");
}

void StudentManager::CleanFile() {
	int choice;

	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "其余键返回" << endl;

	cin >> choice;

	if (choice == 1) {
		ofstream ofs(FILENAME, ios::trunc);  //删除文件后重新创建
		ofs.close();

		if (!m_FileIsEmpty) {
			m_StudentList.Clear();
			m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}

	system("pause");
	system("cls");
}

StudentManager::~StudentManager() {
	m_StudentList.~LinkedList();
	m_StudentList.Initialize();
}
