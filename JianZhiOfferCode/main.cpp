#include"MyString.h"
#include "Singleton.h"
#include "FindInVector2D.h"
#include "ReplaseBlankSpace.h"


void foo(char str[]){
	std::cout << sizeof(str) << std::endl;
	std::cout << strlen(str) << std::endl;
}


int main(){
	//testMyString();
	//testSingleton();
	//testFindInVector2D();

	TestReplaseBlanckSpace();
	//foo("a");


	system("pause");
	return 0;
}