<#pragma once
#include <string>
using namespace std;
#include"student.h"

typedef struct Node{
	Student* dataPtr;
	Node* next;
	Node(Student* x) :dataPtr(x), next(NULL) {}
}Node;

class LinkedList{
public:
	LinkedList();  //构造函数
	
	void New(Student* data);  //增加新数据
	
	void Del(int position);  //删除结点

	int Find(Student* data);  //查找结点位置

	int Find(int studentNum);

	int Find(string studentName);

	void PrintSingle(int position);  //输出单一数据
	
	void Initialize();  //初始化

	void Print();  //打印链表

	void SortStoL();  //将链表从小到大排序

	void SortLtoS();  //将链表从大到小排序

	int GetLength();  //得到链表长度

	Node* GetHead();  //得到链表头结点

	Node* GetTail();  //得到链表尾结点

	void Clear();  //清空链表

	~LinkedList();  //析构函数
private:
	Node* head;
	Node* tail;
	int length;
};>
