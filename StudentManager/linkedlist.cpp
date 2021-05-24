#include"linkedlist.h"

LinkedList::LinkedList(){
	head = NULL;
	tail = NULL;
	length = 0;
}

void LinkedList::New(Student* data){
	Node* newNode = new Node(data);
	if (head == NULL) {
		head = tail = newNode;
		length++;
	}
	else {
		tail->next = newNode;
		tail = newNode;
		length++;
	}
}

void LinkedList::Del(int position) {
	if (position == -1) {
		cout << "无该学生，删除失败" << endl;
		return;
	}

	if (position == 1) {
		head = head->next;
		length--;
		return;
	}

	int index = 2;
	Node* temp = head;

	while (index < position) {
		temp = temp->next;
	}

	temp->next = temp->next->next;
	length--;
	cout << "删除学生成功" << endl;
}

int LinkedList::Find(Student* data){
	Node* temp = head;
	int position = 1;

	while (temp != NULL){

		if (temp->dataPtr->m_Name == data->m_Name && temp->dataPtr->m_Id == data->m_Id) {
			return position;
		}
			
		temp = temp->next;
		position++;
	}
	return -1; 
}

int LinkedList::Find(int studentNum) {
	Node* temp = head;
	int position = 1;

	while (temp != NULL) {

		if (temp->dataPtr->m_Id == studentNum) {
			return position;
		}

		temp = temp->next;
		position++;
	}
	return -1;
}

int LinkedList::Find(string studentName) {
	Node* temp = head;
	int position = 1;

	while (temp != NULL) {

		if (temp->dataPtr->m_Name == studentName) {
			return position;
		}

		temp = temp->next;
		position++;
	}
	return -1;
}

void LinkedList::PrintSingle(int position) {
	if (position == -1) {
		cout << "查无此人" << endl;
		return;
	}

	int index = 1;
	Node* temp = head;

	while (index < position) {
		temp = temp->next;
	}

	temp->dataPtr->ShowInfo();
}

void LinkedList::Initialize() {
	head = NULL;
	tail = NULL;
	length = 0;
}

void LinkedList::Print(){
	if (head == NULL){
		cout << "链表为空" << endl;
		return;
	}

	Node* temp = head;

	while (temp != NULL){
		temp->dataPtr->ShowInfo();
		temp = temp->next;
	}
	cout << endl;
}

void LinkedList::SortStoL() {
	if (head == NULL || head->next == NULL) {
		return;
	}

	Node* p = head;  //工作指针

	for (int i = 0; i < length; i++) {  //冒泡排序
		p = head;
		for (int j = 0; j < length - i - 1; j++) {
			if (p->dataPtr->m_Id > p->next->dataPtr->m_Id) {
				Student* temp = p->dataPtr;
				p->dataPtr = p->next->dataPtr;
				p->next->dataPtr = temp;
			}
			p = p->next;
		}
	}
}

void LinkedList::SortLtoS() {
	if (head == NULL || head->next == NULL) {
		return;
	}

	Node* p = head;  //工作指针

	for (int i = 0; i < length; i++) {  //冒泡排序
		p = head;
		for (int j = 0; j < length - i - 1; j++) {
			if (p->dataPtr->m_Id < p->next->dataPtr->m_Id) {
				Student* temp = p->dataPtr;
				p->dataPtr = p->next->dataPtr;
				p->next->dataPtr = temp;
			}
			p = p->next;
		}
	}
}

int LinkedList::GetLength() {
	return length;
}

Node* LinkedList::GetHead() {
	return head;
}

Node* LinkedList::GetTail() {
	return tail;
}

void LinkedList::Clear() {
	Node* temp;

	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
	}

	head = NULL;
	tail = NULL;
	length = 0;
}

LinkedList::~LinkedList() {
	Node* temp;

	while (head != tail) {
		temp = head;
		head = head->next;
		delete temp;
	}
}
