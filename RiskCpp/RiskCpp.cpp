// RiskCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "SimpleLinkedList.h"

using namespace std;


//===================================================================================
class Empty { };
void f();

//===================================================================================
int main()
{
	struct Node *head = NULL;
	SimpleLinkedList pippo;
	for (size_t i = 0; i < 10; i++)
	{
		pippo.insertHead(&head, i);
	}

	bool test = pippo.findCircular(head);

	cout << "Test = " << test << endl;

	pippo.display(head);
	return 0;
}


//===================================================================================
void f()
{
	Empty a, b;
	if (&a == &b) 
		cout<< "impossible: report error to compiler supplier";

	Empty* p1 = new Empty;
	Empty* p2 = new Empty;
	if (p1 == p2) 
		cout<< "impossible: report error to compiler supplier";
}


