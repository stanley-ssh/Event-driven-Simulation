#ifndef LINES_HPP
#define LINES_HPP

#include "lineNodes.hpp"
#include<string>
class LInes {
private:
	lineNodes* head;
	lineNodes * tail ;
	lineNodes * temp ;// a dummy pointer 
public:
	// return head of the linked list 
	// return the tail of the linked list
	lineNodes * getHead ();
	lineNodes * getTail ();
	lineNodes * getTemp () ;
	bool isEmpty();
    void virtual  insertEnd ( string  item );
	string   deleteFirst() ;
	void virtual print();
	LInes( );
};
#endif
