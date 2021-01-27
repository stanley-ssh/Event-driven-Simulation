
#include "Allitem.hpp"
#include "Queue.hpp"

// Queue::Queue() {
//     value =0 ;
// }

void Queue:: enQueue(Allitem  *item ) {	
	insertEnd(item); 
}
// peek methosd is to return the first node in the queue without changing the head 
Allitem * Queue:: peek(){
    Allitem * ret = NULL ;
    //<< "It got here"<< endl;
    if (getHead()!=NULL ) {
        ret = getHead() ->getData();
               // cout<< "after if statemnet"<< ret ->getData()->value()<<endl;

    }
    
    return ret  ;

}

//pop method is to return and remove the head node in the queue if its not emoty 
Allitem *  Queue:: pop(){
   
  
    return deleteFirst() ;
}
void Queue:: print () {
      List::print();
    //cout<<"print in Queue" <<endl;// << List:: print() << endl;
}



