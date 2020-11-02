/*
 * AlvarezA5.h
 *
 *  Created on: Mar 7, 2020
 *      Author: Enrique Alvarez412-1
 */

#ifndef ALVAREZA5_H_
#define ALVAREZA5_H_
#include "LinkedList.h"
#include <string>
#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:

	int dSize;
	int topElement;
	LL <T*> theList;

public:

Stack(int d)
{
	dSize = d;
	topElement = 0;
	T* baseArray;
	baseArray = new T[dSize];
	theList.push_front(baseArray);
}

Stack()
{

}
void push(T);
bool top(T &);
bool pop(T &);
void destroy();

};

template <class T>
void Stack<T>::push(T data){
	if(topElement == dSize){
		T* nextArray;
		nextArray = new T[dSize];
		theList.push_back(nextArray);
		topElement = 0;
		nextArray[topElement] = data;
		topElement++;
		cout << nextArray[topElement] << endl;
	}
	else{
		theList.retrieve_back()[topElement] = data;
		topElement++;
	}

}

template <class T>
bool Stack<T>::top(T &data){
	if(topElement == 0 && theList.list_length()==1){
			return false;
	}
	else{
		data= theList.retrieve_back()[topElement-1];
	}
	return true;
}

template <class T>
bool Stack<T>::pop(T &data){
	if(topElement == 0 && theList.list_length() == 1){
			return false;
			//cout<< "here!" << endl;
		}
	else if(topElement == 0){
		//	delete [] theList.retrieve_back();
			theList.delete_back();
		//	data = theList.retrieve_back()[dSize-1];
			topElement = dSize;
			//cout << "here?" << endl;
			//cout << "just popped this in if   " <<theList.retrieve_back()[topElement] << endl;
	}
		data = theList.retrieve_back()[topElement-1];
		topElement--;
		//cout << "here" << endl;
		//cout << "just popped this in else   " <<theList.retrieve_back()[topElement] << endl;

	return true;
}

template <class T>
void Stack<T>::destroy(){
	while(theList.list_length()!=1){
		theList.delete_back();
	}
	topElement = dSize;
}


#endif /* ALVAREZA5_H_ */
