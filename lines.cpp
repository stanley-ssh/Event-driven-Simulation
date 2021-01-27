#include "lineNodes.hpp"
#include "lInes.hpp"
#include<string>
#include<cstdlib>

LInes::LInes( ) {
	 this->head =NULL; 
	 this->tail = NULL  ;
	 this ->temp = NULL;
}
 


 
string    LInes:: deleteFirst() {
	temp = head ;
	string  curr = ""  ;// to store the nodein the head before deleting it 
	if (head== NULL ){// check if the list empty 
		// 
        
		curr = "" ; // themethod would return null oif th list is empty 
	}
	else {
		// check if the head node is not the last  node
		if (temp->getNext()!= NULL ){// 
			curr = head->getData() ;


			temp= temp->getNext() ;

			free (head );
			head = temp;
			
		}
		else {
			curr = head->getData() ;
			free ( head );
			head = NULL ;

		}

	}


	return curr ;
}
lineNodes* LInes:: getHead(){
    return head;
}
lineNodes * LInes:: getTemp() {
	return temp ;
}
void   LInes::print() {
	lineNodes* currNode = head;
	lineNodes * lastNode = tail;

	while (currNode != NULL) {
		currNode->print();
		cout << " ";
		currNode = currNode->getNext();
	}

	cout << endl;
}


void LInes::insertEnd (string item ){
	// add a new element to the head of the linked list if its empty 

	if ( head == NULL ){
		lineNodes * newNode = new lineNodes(item );
		head = newNode ;

		tail = head;


	}
	// add new element to the end of the list 
	else {
		lineNodes * newNode = new lineNodes ( item);
		tail->setNext(newNode);
		tail = tail->getNext();
		
	}
   

}
bool LInes::isEmpty(){
	return head == NULL ;
}



