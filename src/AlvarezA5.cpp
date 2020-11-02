//============================================================================
// Name        : AlvarezA5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "AlvarezA5.h"

using namespace std;

int main()
{
	Stack <string> s(5);
	string st;
	bool b;
	cout << "main: start of part 1" << endl;
	cout << "main: pushing five elements" << endl;
	st = "aaaaa";
	s.push(st);
	st = "bbbbb";
	s.push(st);
	st = "ccccc";
	s.push(st);
	st = "ddddd";
	s.push(st);
	st = "eeeee";
	s.push(st);
	b = s.pop(st);
	cout << "main: first pop retrieved->" << st << endl;
	b = s.pop(st);
	cout << "main: second pop retrieved->" << st << endl;
	b = s.top(st);
	cout << "main: top after second pop->" << st << endl;
	b = s.pop(st);
	cout << "main: third pop retrieved->" << st << endl;
	b = s.pop(st);
	cout << "main: fourth pop retrieved->" << st << endl;
	b = s.pop(st);
	cout << "main: fifth pop retrieved->" << st << endl;
	cout << "main: attempting sixth pop" << endl;
	b = s.pop(st);
	if (b)
	{
		string error;
		error = "main: after sixth pop, stack non-empty when it should be empty";
		throw s;
	}
	else{
		cout << "main: after sixth pop, stack correctly non-empty" << endl;
	}
	cout << endl << "main: start of part 2" << endl;
	st = "aaaaa";
	// 1st element 1st array
	s.push(st);
	//cout << "here" << endl;
	st = "bbbbb";
	s.push(st);
	//cout << "here2" << endl;
	st = "ccccc";
	s.push(st);
	//cout << "here3" << endl;
	st = "ddddd";
	s.push(st);
	//cout << "here4" << endl;
	st = "eeeee";
	s.push(st);
	//cout << "here5" << endl;
	st = "fffff";
	// 1st element 2nd array
	s.push(st);
	//cout << "here 6" << endl;
	st = "ggggg";
	s.push(st);
	//cout << "here  7" << endl;
	st = "hhhhh";
	s.push(st);
	//cout << "here 8" << endl;
	st = "iiiii";
	s.push(st);
	//cout << "here 9" << endl;
	st = "jjjjj";
	s.push(st);
	//cout << "here 10" << endl;
	st = "kkkkk";
	// 1st element 3rd array
	s.push(st);
	//cout << "here11" << endl;
	cout << "main: before while loop " << endl;
	b = s.pop(st);
	while (b)
	{
		cout << "main: element of stack retrieved via pop " << st << endl;
		b=s.pop(st);
	}
	cout << "main: after while loop" << endl;
	cout << "main: before destroy"<< endl;
	s.destroy();
	cout << "main: after destroy"<< endl;
	st = "zzzzz";
	s.push(st);
	b=s.top(st);
	cout << "main: new top of stack " << st << endl;
	s.destroy();
	cout << "main: ending" << endl;
	/* spring 2020 - correct output
	 * main: start of part 1
	 * main: pushing five elements
	 * main: first pop retrieved->eeeee
	 * main: second pop retrieved->ddddd
	 * main: top after second pop->ccccc
	 * main: third pop retrieved->ccccc
	 * main: fourth pop retrieved->bbbbb
	 * main: fifth pop retrieved->aaaaa
	 * main: attempting sixth pop
	 * main: after sixth pop, stack correctly non-empty
	 * main: start of part 2
	 * main: before while loop
	 * main: element of stack retrieved via pop kkkkk
	 * main: element of stack retrieved via pop jjjjj
	 * main: element of stack retrieved via pop iiiii
	 * main: element of stack retrieved via pop hhhhh
	 * main: element of stack retrieved via pop ggggg
	 * main: element of stack retrieved via pop fffff
	 * main: element of stack retrieved via pop eeeee
	 * main: element of stack retrieved via pop ddddd
	 * main: element of stack retrieved via pop ccccc
	 * main: element of stack retrieved via pop bbbbb
	 * main: element of stack retrieved via pop aaaaa
	 * main: after while loop
	 * main: before destroy
	 * main: after destroy
	 * main: new top of stack zzzzz
	 * main: ending*/
	return 0;
}
