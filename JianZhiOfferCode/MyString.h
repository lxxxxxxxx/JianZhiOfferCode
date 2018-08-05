/**
* ��Ŀ��ʵ��MyStringΪMyString����Ӹ�ֵԤ���
* ʱ�䣺2018-08-04 11:33
* ���ߣ�����
* ��Դ����ָoffer P24
* �ѵ㣺��ֵ����������Ϊ�������ã�����ֵΪ*this����������Ϊ�������ͣ�Ϊ��������ֵ��
*/


//test git

#include <iostream>
#include <string>

#define INCREASE_STEP 16

class MyString{
public:
	explicit MyString(const char *pData = nullptr);   //���캯����Ĭ�Ϲ��캯��
	MyString(const MyString& str) :MyString(str.data()){}  //�������캯��
	bool operator==(const MyString& str);  //�е�
	MyString& operator=(const MyString& str);   //��ֵ���������
	const size_t size() const{ return length; }  //ȡ����
	const char* data() const { return m_pData; }  //ȡֵ
	~MyString(void);  //��������

private:
	char* m_pData;  //������
	size_t length;  //����
	size_t capacity;  //����
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
	if (this != &str){
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
	}
	return *this;

}

MyString::~MyString(){
	if (m_pData != nullptr){
		delete m_pData;
		m_pData = nullptr;
	}
}
