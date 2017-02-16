#include "stdafx.h"
#include "LinkedListExample.h"
#include<iostream>
using namespace std;


LinkedListExample::LinkedListExample()
{
	start = NULL;
}


LinkedListExample::~LinkedListExample()
{
}



/*
* Creating Node
*/
node* LinkedListExample::create_node(int value)
{
	struct node *temp, *s;
	temp = new(struct node);
	if (temp == NULL)
	{
		cout << "Memory not allocated " << endl;
		return 0;
	}
	else
	{
		temp->info = value;
		temp->next = NULL;
		return temp;
	}
}
/*
* Inserting element in beginning
*/
void LinkedListExample::insert_begin()
{
	int value;
	cout << "Enter the value to be inserted: ";
	cin >> value;
	struct node *temp, *p;
	temp = create_node(value);
	if (start == NULL)
	{
		start = temp;
		start->next = NULL;
	}
	else
	{
		p = start;
		start = temp;
		start->next = p;
	}
	cout << "Element Inserted at beginning" << endl;
}

/*
* Inserting Node at last
*/
void LinkedListExample::insert_last()
{
	int value;
	cout << "Enter the value to be inserted: ";
	cin >> value;
	struct node *temp, *s;
	temp = create_node(value);
	s = start;
	while (s->next != NULL)
	{
		s = s->next;
	}
	temp->next = NULL;
	s->next = temp;
	cout << "Element Inserted at last" << endl;
}

/*
* Insertion of node at a given position
*/
void LinkedListExample::insert_pos()
{}

/*
* Sorting Link List
*/
void LinkedListExample::sort()
{
	struct node *ptr, *s;
	int value;
	if (start == NULL)
	{
		cout << "The List is empty" << endl;
		return;
	}
	ptr = start;
	while (ptr != NULL)
	{
		for (s = ptr->next;s != NULL;s = s->next)
		{
			if (ptr->info > s->info)
			{
				value = ptr->info;
				ptr->info = s->info;
				s->info = value;
			}
		}
		ptr = ptr->next;
	}
}

/*
* Delete element at a given position
*/
void LinkedListExample::delete_pos()
{

}

/*
* Update a given Node
*/
void LinkedListExample::update()
{
}

/*
* Reverse Link List
*/
void LinkedListExample::reverse()
{
	struct node *ptr1, *ptr2, *ptr3;
	if (start == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	if (start->next == NULL)
	{
		return;
	}
	ptr1 = start;
	ptr2 = ptr1->next;
	ptr3 = ptr2->next;
	ptr1->next = NULL;
	ptr2->next = ptr1;
	while (ptr3 != NULL)
	{
		ptr1 = ptr2;
		ptr2 = ptr3;
		ptr3 = ptr3->next;
		ptr2->next = ptr1;
	}
	start = ptr2;
}

/*
* Display Elements of a link list
*/
void LinkedListExample::display()
{
	struct node *temp;
	if (start == NULL)
	{
		cout << "The List is Empty" << endl;
		return;
	}
	temp = start;
	cout << "Elements of list are: " << endl;
	while (temp != NULL)
	{
		cout << temp->info << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

bool LinkedListExample::findCircular(node * head)
{
	node *slower, *faster;
	slower = head;

	faster = head->next; //start faster one node ahead
	while (true) {

		// if the faster pointer encounters a NULL element
		if (!faster || !faster->next)
			return false;
		//if faster pointer ever equals slower or faster's next
		//pointer is ever equal to slow then it's a circular list
		else if (faster == slower || faster->next == slower)
			return true;
		else {
			// advance the pointers
			slower = slower->next;
			faster = faster->next->next;
		}
	}
}
