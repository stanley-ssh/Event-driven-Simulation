#include <iostream>
#ifndef NODE_HPP
#define NODE_HPP
#include "Allitem.hpp"
using namespace  std ;

class Node {
    private:
    Allitem *  data;
	Node* next;

    public:
	Node* getNext();
	void setNext(Node* next);
	Allitem * getData();
	void print();
	Node(Allitem * data );//:data(data),next(NULL ) {};
	Node();

};
#endif