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

	fibo(11);
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
	if (n == 0) {
		return 0; // f(0) = 0
	}
	else if (n == 1) {
		return 1; // f(1) = 1
	}
	else if (n > 1) {
		return fibo(n - 1) + fibo(n - 2); // f(n) = f(n—1) + f(n-2)
	}
	else {
		return -1; // Error condition
	}
}