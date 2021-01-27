#include "List.hpp"
#include "Node.h"
#include "Allitem.hpp"
#include <cstdlib>
List::List()
{
	this->head  = NULL;
	this->tail  = NULL;
	this->temp = NULL;
}
void List::orderedInsert(Allitem *item)
{
	if (isEmpty())
	{
		insert(item);
	}

	else
	{

		Node *prev = NULL;

		Node *curr = head;
		while (curr != NULL && curr->getData()->compare(item))
		{

			prev = curr;

			curr = curr->getNext();
		}

		if (prev != NULL)
		{ // if the node is not the fits nde

			Node *newNode = new Node(item);
			newNode->setNext(curr);
			prev->setNext(newNode);
		}
		else
		{
			// if we want to order insert into the fron of the list

			Node *newNode = new Node(item);
			newNode->setNext(curr);
			head = newNode;
		}
	}
}

Allitem *List::deleteFirst()
{
	temp = head;
	Allitem *curr = NULL; // to store the nodein the head before deleting it
	if (head == NULL)
	{ // check if the list empty
		//
		curr = NULL; // themethod would return null oif th list is empty
	}
	else
	{
		// check if the head node is not the last  node
		if (temp->getNext() != NULL)
		{ //
			curr = head->getData();

			temp = temp->getNext();

			free(head);
			head = temp;
		}
		else
		{
			curr = head->getData();
			free(head);
			head = NULL;
		}
	}

	return curr;
}
Node *List::getHead()
{
	return head;
}
Node *List::getTemp()
{
	return temp;
}
void List::print()
{
	Node *currNode = head;
	Node *lastNode = tail;

	while (currNode != NULL)
	{
		currNode->print();
		cout << " ";
		currNode = currNode->getNext();
	}

	cout << endl;
}

void List::insert(Allitem *item)
{
	Node *newNode = new Node(item);
	newNode->setNext(head);
	head = newNode;
}
void List::insertEnd(Allitem *item)
{
	// add a new element to the head of the linked list if its empty

	if (head == NULL)
	{
		Node *newNode = new Node(item);
		head = newNode;

		tail = head;
	}
	// add new element to the end of the list
	else
	{
		Node *newNode = new Node(item);
		tail->setNext(newNode);
		tail = tail->getNext();
	}
}
bool List::isEmpty()
{
	return head == NULL;
}

bool List::search(Allitem item)
{
	bool found = false;
	Node *currNode = head;
	while (currNode != NULL && !found)
	{
		found = (currNode->getData()->equals(item));
		currNode = currNode->getNext();
	}
	return found;
}
