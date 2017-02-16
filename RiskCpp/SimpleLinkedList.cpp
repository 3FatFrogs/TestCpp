#include "stdafx.h"
#include "iostream"
#include "SimpleLinkedList.h"

using namespace std;

void SimpleLinkedList::display(Node * p)
{
	while (p)
	{
		cout << p->name << endl;
		p = p->next;
	}
}

int SimpleLinkedList::insertHead(Node ** head, int value)
{
	struct Node *current;
	current = new struct Node();

	if (current == NULL)
		return 1;
	else {
		current->name = value;
		current->next = *head;
		*head = current;

		return 0;
	}
}

int SimpleLinkedList::insertTail(Node ** head, int value)
{
	struct Node *current;
	current = new struct Node();
	if (current == NULL)	
		return 1;
	else 
	{
		current->name = value;
		current->next = NULL;

		struct Node *temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = current;
		return 0;
	}
}

bool SimpleLinkedList::findCircular(Node * head)
{
	Node *slower, *faster;
	slower = head;
	faster = head->next; //start faster one node ahead
	while (true) 
	{
		// if the faster pointer encounters a NULL element
		if (!faster || !faster->next)
			return false;
		//if faster pointer ever equals slower or faster's next
		//pointer is ever equal to slow then it's a circular list
		else if (faster == slower || faster->next == slower)
			return true;
		else 
		{
			// advance the pointers
			slower = slower->next;
			faster = faster->next->next;
		}
	}
}

SimpleLinkedList::SimpleLinkedList()
{
}


SimpleLinkedList::~SimpleLinkedList()
{
}
