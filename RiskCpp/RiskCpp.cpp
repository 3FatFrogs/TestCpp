// RiskCpp.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "iostream"
#include "SimpleLinkedList.h"

using namespace std;
//===================================================================================
class Empty { };
void f();
bool IntAsSumOfTwoIntegers(int value);
bool checkPrime(int n);
//===================================================================================
int main()
{
	struct Node *head = NULL;
	SimpleLinkedList pippo;

	for (size_t i = 0; i < 10; i++)
	{
		pippo.insertHead(&head, i);
	}

	pippo.findCircular(head);

	pippo.display(head);


	IntAsSumOfTwoIntegers(20);
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

//===================================================================================
// Check Whether a Number can be Expressed as a Sum of Two Prime Numbers
//===================================================================================
bool IntAsSumOfTwoIntegers(int value)
{
	bool flag = false;

	for (int i = 1; i <= value / 2; ++i)
	{
		if (checkPrime(i))
		{
			if (checkPrime(value - i))
			{
				cout << value << " = " << i << " + " << value - i << endl;
				flag = true;
			}
		}
	}

	return flag;
}

// Check prime number
bool checkPrime(int n)
{
	int i;
	bool isPrime = true;

	for (i = 2; i <= n / 2; ++i)
	{
		if (n % i == 0)
		{
			isPrime = false;
			break;
		}
	}

	return isPrime;
}
