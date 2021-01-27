#include <iostream>
#ifndef LINENODES_HPP
#define LINENODES_HPP
#include "Allitem.hpp"
#include<string>
using namespace  std ;

class lineNodes {
    private:
    string    data;
	lineNodes* next;

    public:
	lineNodes* getNext();
	void setNext(lineNodes* next);
	string   getData();
	void print();
	lineNodes(string  data );//:data(data),next(NULL ) {};
	lineNodes();

};
#endif