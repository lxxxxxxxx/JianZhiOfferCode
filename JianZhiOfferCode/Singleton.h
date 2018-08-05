/**
* 题目：C++实现单例模式
* 时间：2018-08-05 16:13
* 作者：李祥
* 来源：剑指offer P31
* 难点：
*/

#include <iostream>
#include <string>
#include <mutex>

///懒汉模式：在需要实例的时候创建，只创建一次
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