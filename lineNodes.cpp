#include "LineNodes.hpp"
#include<string>
lineNodes* lineNodes::getNext() { return next; }
void lineNodes::setNext(lineNodes* next) { this->next = next; }
string  lineNodes::getData() { return data;}
void lineNodes::print() { cout << data<< endl; }
lineNodes::lineNodes(string  datum) { this->data = datum ; this->next = NULL;}
lineNodes::lineNodes () { this->data="" ;  this->next = NULL;}
