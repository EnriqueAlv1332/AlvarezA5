/*
 * LinkedList.h
 *
 *  Created on: Mar 8, 2020
 *      Author: Enrique Alvarez412-1
 */

#ifndef LINKEDLIST_H_
#include <string>
#include <iostream>

using namespace std;




template <class T>
class LL
{
private:
	struct LLnode
	{
		struct LLnode * fwdPtr;
		T theData;
	};

	LLnode * header;

public:

LL()
{header = nullptr;}

void push_front(T);
void push_back(T);
int list_length();
T retrieve_front();
T retrieve_back();
void display_list();
void destroy_list();
bool search_list(int);
bool delete_node(int);
bool delete_back();


};


template <class T>
void LL<T>::push_front(T s){
		LLnode * temp;
			temp = header;

			LLnode * newFront;
			newFront = new LLnode;
			newFront -> theData = s;
			header = newFront;
			newFront -> fwdPtr = temp;
	}
template <class T>
void LL<T>::push_back(T s){
		LLnode * endNode;
		LLnode * nodeptr;

		endNode = new LLnode;
		endNode ->theData = s;
		endNode -> fwdPtr = nullptr;


			//LLnode * cLooper;
			nodeptr = header;
			while(nodeptr->fwdPtr != nullptr){
				nodeptr = nodeptr->fwdPtr;
			}
			nodeptr->fwdPtr = endNode;
	}
template <class T>
	int LL<T>::list_length(){
		LLnode * temp;
			temp = header;
			int counter =0;
				while(temp != nullptr)
					{

						temp = temp ->fwdPtr;
						counter++;
					}
				return counter;
	}

template <class T>
T LL<T>::retrieve_front(){
		LLnode * frontPtr;
		frontPtr = header;
		return frontPtr->theData;
	}
template <class T>
T LL<T>::retrieve_back(){
		LLnode * looper;
		LLnode * prev;
		looper = header;
		while(looper != nullptr)
		{
			prev = looper;
			looper = looper->fwdPtr;
		}
		return prev->theData;
	}
template <class T>
void LL<T>::display_list(){
		cout << "nodes listed from 0 onwards" << endl;
				LLnode * temp;
				temp = header;
				if(header == nullptr)
				{
					cout<< "the list contains no elements"<< endl;
				}
					while(temp != nullptr)
						{
							cout  << " " <<  temp->theData.studentID << "   " << temp ->theData.studentName << "  " << temp-> fwdPtr<< endl;
							temp = temp -> fwdPtr;
						}
	}
template <class T>
void LL<T>::destroy_list(){

	LLnode * temp = header;
	if (temp != nullptr){
		while(temp!= nullptr){
			temp = temp -> fwdPtr;
			delete header;
			header = temp;
		}
		delete temp;
	}
	else{
		cout<< " empty list" << endl;
	}
	header = nullptr;

}

template <class T>
bool LL<T>:: search_list(int sID){
	LLnode * temp = header;
	if(header == nullptr)
		cout << "empty list" << endl;
	while(temp != nullptr){
		if(temp -> theData.studentID == sID)
			return true;
		temp = temp -> fwdPtr;
	}
	return false;
}

template <class T>
bool LL<T>:: delete_node(int sID){
	LLnode * temp = header;
	LLnode * tempTrail;
	if(header == nullptr)
		cout << "empty list" << endl;
	while(temp -> fwdPtr != nullptr){
		tempTrail = temp;
		temp = temp -> fwdPtr;
		if(temp ->theData.studentID == sID){
			tempTrail -> fwdPtr = temp ->fwdPtr;
			delete temp;
			return true;
		}
	}
	return false;
}

template <class T>
bool LL<T>:: delete_back(){

	LLnode * temp = header;
	//LLnode * tempTrail;
	if(header == nullptr){
		return false;
	}
	if(header->fwdPtr == nullptr){
		delete header->theData;
		header = nullptr;
		return true;
	}
	while(temp -> fwdPtr -> fwdPtr != nullptr){
		temp = temp -> fwdPtr;
	}
		delete [] temp->fwdPtr->theData;
		temp -> fwdPtr = nullptr;
		return true;

}








#endif /* LINKEDLIST_H_ */
