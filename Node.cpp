#include "Node.hpp"

Node* Node::getNext() { return next; }
void Node::setNext(Node* next) { this->next = next; }
Allitem* Node::getData() { return data;}
void Node::print() { cout << data->value()<< endl; }
Node::Node(Allitem * datum) { this->data = datum ; this->next = NULL;}
Node::Node () { this->data=NULL ;  this->next = NULL;}
