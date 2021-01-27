#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"
#include "Allitem.hpp"
class List {
private:
	Node* head;
	Node * tail ;
	Node * temp ;// a dummy pointer 
public:
	// return head of the linked list 
	// return the tail of the linked list
	Node * getHead ();
	Node * getTail ();
	Node * getTemp () ;
	bool isEmpty();
	void  virtual insert(Allitem *item)   ;
    void virtual  insertEnd ( Allitem *item );
	bool search (Allitem  item);
	Allitem *  deleteFirst() ;
	void virtual print();
	void orderedInsert(Allitem * item );
	List( );
    List ( const List &obj);
};
#endif
