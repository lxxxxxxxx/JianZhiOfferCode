/**
* 题目：实现MyString为MyString类添加赋值预算符
* 时间：2018-08-04 11:33
* 作者：李祥
* 来源：剑指offer P24
*/


//test git

#include <iostream>
#include <string>

#define INCREASE_STEP 10

class MyString{
public:
	explicit MyString(const char *pData = nullptr);   //构造函数、默认构造函数
	MyString(const MyString& str) :MyString(str.data()){}  //拷贝构造函数
	bool operator==(const MyString& str);  //判等
	MyString& operator=(const MyString& str);   //赋值运算符重载
	const size_t size() const{ return length; }  //取长度
	const char* data() const { return m_pData; }  //取值
	~MyString(void);  //析构函数

private:
	char* m_pData;  //存数据
	size_t length;  //长度
	size_t capacity;  //容量
};


MyString::MyString(const char *pData){
	if (pData == nullptr){
		length = 0;
		capacity = INCREASE_STEP;
		m_pData = new char[capacity];
		memset(m_pData, 0, capacity);
	}
	else{
		length = strlen(pData);
		capacity = (length > INCREASE_STEP) ? (INCREASE_STEP*(length / INCREASE_STEP + 1)) : INCREASE_STEP;
		m_pData = new char[capacity];
		memset(m_pData, 0, capacity);
		strcpy_s(m_pData, length + 1, pData);
	}
}

bool MyString::operator==(const MyString& str){
	return ((length == str.size()) && ((m_pData == nullptr &&nullptr == str.data())
		|| (strcmp(m_pData, str.data()) == 0)) ? true : false);
}

MyString& MyString::operator=(const MyString& str){
	if (*this == str){
		return *this;
	}
	length = str.size();
	capacity = str.capacity;
	if (m_pData != nullptr){
		delete[] m_pData;
		m_pData = nullptr;
	}
	m_pData = new char[capacity];
	memset(m_pData, 0, capacity);
	if (str.data() != nullptr){
		strcpy_s(m_pData, length + 1, str.data());
	}
	return *this;
}

MyString::~MyString(){
	if (m_pData != nullptr){
		delete m_pData;
		m_pData = nullptr;
	}
}
