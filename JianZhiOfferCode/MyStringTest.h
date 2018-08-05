/**
* 题目：测试MyString
* 时间：2018-08-04 11:33
* 作者：李祥
* 来源：剑指offer P24
*/



#include "MyString.h"

void testMyString(){
	MyString myStr1("123456");
	MyString myStr2(myStr1);
	MyString myStr3 = myStr2;
	MyString myStr4;
	myStr4 = myStr1 = myStr2 = myStr3;

	std::cout << "myStr1\n  length:" << myStr1.size() << "\n  content:"
		<< myStr2.data() << std::endl;
	std::cout << "myStr2\n  length:" << myStr2.size() << "\n  content:"
		<< myStr2.data() << std::endl;
	std::cout << "myStr3\n  length:" << myStr3.size() << "\n  content:"
		<< myStr3.data() << std::endl;
	std::cout << "myStr4\n  length:" << myStr4.size() << "\n  content:"
		<< myStr4.data() << std::endl;

	MyString myStr5;
	myStr5 = myStr5;
	std::cout << "myStr5;\n  length:" << myStr5.size() << "\n  content:"
		<< myStr5.data() << std::endl;
}