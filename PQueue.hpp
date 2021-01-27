#ifndef PQUEUE_HPP
#define PQUEUE_HPP



#include "Queue.hpp"
#include "Events.hpp"
#include <iostream> 
using namespace std ;


class PQueue : public Queue {
    private:
    //Events event;
    Queue *AQueue ;
    public:
    PQueue(){AQueue = new Queue ();  };
    void push(Events * event );
    Events * pop() ;/// should return the next object based on priority 
    bool isEmpty() ;
    void print () ;

};
#endif