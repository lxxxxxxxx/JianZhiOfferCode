/**
* ��Ŀ������Singleton
* ʱ�䣺2018-08-05 16:38
* ���ߣ�����
* ��Դ����ָoffer P31
*/


#include "Singleton.h"

void testSingleton(){
	Singleton1* single = Singleton1::GetInstance();
	std::cout << "instance1 offset: " << single << std::endl;
	std::cout << "instance2 offset: " << Singleton1::GetInstance() << std::endl;
}

