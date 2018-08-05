/**
* ��Ŀ��C++ʵ�ֵ���ģʽ
* ʱ�䣺2018-08-05 16:13
* ���ߣ�����
* ��Դ����ָoffer P31
* �ѵ㣺
*/

#include <iostream>
#include <string>
#include <mutex>

///����ģʽ������Ҫʵ����ʱ�򴴽���ֻ����һ��
class Singleton1{
public:
	static Singleton1* GetInstance(){
		if (instance == nullptr){
			std::lock_guard<std::mutex> lock(mtx);
			if (instance == nullptr){
				instance = new Singleton1;
			}
		}
		return instance;
	}
	
private:
	Singleton1(){}
	Singleton1(Singleton1 &s) = delete;

private:
	static Singleton1* instance;
	static std::mutex mtx;
};

Singleton1* Singleton1::instance = nullptr;
std::mutex Singleton1::mtx;