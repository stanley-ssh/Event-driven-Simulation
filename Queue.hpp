#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "List.hpp"
#include "Node.h"
#include "Allitem.hpp"
class Queue : public List {
    private:
        Node * end =NULL ;
        Node* top = NULL ;
    public:
        Allitem * peek ();
        Allitem * pop ();
        void   enQueue(Allitem  *val );
    	void  print();

    //void virtual  insertEnd ( int val );
    
    Queue () : List(){};
	//Queue() ;
};
#endif
