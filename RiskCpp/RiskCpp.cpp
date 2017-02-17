// RiskCpp.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "iostream"
#include "SimpleLinkedList.h"

using namespace std;
//===================================================================================
class Empty { };
void f();
bool IntAsSumOfTwoIntegers(int value);
void PrimeBetweenIntervals(int a, int b);
bool checkPrime(int n);
int fibo(int n);
void printPowerSet(char *set, int set_size);
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
	PrimeBetweenIntervals(1, 201);

	cout << "=======================" << endl;
	cout << "Fibonacci series" << endl;
	for (size_t i = 1; i < 10; i++)
	{
		cout << " " << fibo(i);
	}

	cout << "=======================" << endl;
	cout << "PowerSet series" << endl;
	char set[] = { 'a','b','c' };
	printPowerSet(set, 3);

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


//===================================================================================
// Prime Numbers Between two Intervals
//===================================================================================
void PrimeBetweenIntervals(int a, int b)
{
	bool flag;

	for (int i = a + 1; i < b; ++i)
	{
		// If i is a prime number, flag will be equal to 1
		flag = checkPrime(i);

		if (flag)
			cout << i << " ";
	}
}

//===================================================================================
// Check prime number
//===================================================================================

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

bool isPrime(int n, int d)
{
	if (n < 2)
		return false;

	if (d == 1)
		return true;

	else
	{
		if (n % d == 0)
			return false;
		else
			return isPrime(n, d - 1);
	}


}

//===================================================================================
// Write a method to generate the nth Fibonacci number
//===================================================================================
int fibo(int n) 
{
	if ((n == 1) || (n == 0))
	{
		return(n);
	}

	else if (n > 1) {
		return fibo(n - 1) + fibo(n - 2); // f(n) = f(n—1) + f(n-2)
	}
	else {
		return -1; // Error condition
	}
}

//===================================================================================
// Write a method to generate the nth Fibonacci number
//===================================================================================
void printPowerSet(char *set, int set_size)
{
	/*set_size of power set of a set with set_size
	n is (2**n -1)*/
	unsigned int pow_set_size = pow(2, set_size);
	int counter, j;

	/*Run from counter 000..0 to 111..1*/
	for (counter = 0; counter < pow_set_size; counter++)
	{
		for (j = 0; j < set_size; j++)
		{
			/* Check if jth bit in the counter is set
			If set then pront jth element from set */
			if (counter & (1 << j))
				printf("%c", set[j]);
		}
		printf("\n");
	}
}