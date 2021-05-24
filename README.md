# Basic-Student-Manager
2021年春季《面向对象程序设计》大作业。

非常基础非常简单的一个项目设计，没有什么实用价值。

所使用知识均为课堂教授内容，没有在算法及构思上进行过多拓展。

可以用于预习浏览或复习补救，有一定的教学意义（某话唠老师狂喜？）。

UML类图如下：

![UML class](https://user-images.githubusercontent.com/40351071/119335636-393ce680-bcbf-11eb-832a-0ae0ffdcb004.jpeg)

Shipai、Nanhai、UT三个派生类属于为了强行使用多态整上去的，实际增加成员数据即可，会更加遍历简单。

一个人的工作量确实有点大，只是简单测试了一会没有优化，可能会存在一些奇奇妙妙的显示BUG和代码冗余情况。

用户手册：

1.	LinkedList

成员函数

LinkedList()	构造函数

void New(Student* data) 	增加新学生数据

void Del(int position) 	根据位置删除结点

int Find(Student* data)

int Find(int studentNum)

int Find(string studentName)	根据所输入数据类型为完整学生数据、学生学号、学生姓名等进行调用查找，返回结点位置

void PrintSingle(int position)	根据位置输出单一结点数据

void Initialize()	初始化链表

void Print()	将学生全部输出

void SortStoL()	将学生数据按学号从小到大排序并输出

void SortLtoS()	将学生数据按学号从大到小排序并输出

int GetLength()	得到链表长度

Node* GetHead()	得到头结点

Node* GetTail()	得到尾结点

void Clear()	清空链表

~LinkedList()	析构函数

数据成员

Node* head	头结点，链表必须拥有的数据

Node* tail	尾结点，方便增加新数据

int length	链表长度

2.	Student

成员函数

virtual void ShowInfo() = 0;	纯虚函数，在其派生类中多态应用，用于显示学生个人信息

virtual string GetCampusName() = 0; 	纯虚函数，在其派送类中多态应用，用于以校区编号获得校区名称

数据成员

int m_Id	学生学号

string m_Name	学生姓名

string m_Major	学生专业

int m_CampusId	校区编号

说明：Student类为抽象类，Student派生出Shipai、Nanhai、UT类，分别代表石牌校区、南海校区、大学城校区学生，类内无新增成员数据，且功能相同，故不再赘述。
 
3.	StudentManager

成员函数

StudentManager()	构造函数

void ShowMenu() 	显示菜单，有初步页面交互显示作用

void AddStudent()	增加新学生

void Save()	保持数据到文件中

int GetNumber()	从已保持文件中获取学生数量

void InitStudent()	初始化学生，用于读取文件数据

void ShowStudent()	显示所有学生数据

void DelStudent()	删除学生

void FindStudent()	查找学生并显示

void FindinName(string studentName)	按照姓名查找，应用于查找学生中的选择姓名查找

void SortStudent()	将学生以学号排序

void CleanFile()	清空文件及相关数据

~StudentManager()	析构函数

数据成员

LinkedList StudentList	用链表保存学生数据

bool m_FileIsEmpty	判断文件是否为空
