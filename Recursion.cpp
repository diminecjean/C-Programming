#include <iostream>
using namespace std;

void CountDown (int num)
{
	if (num==0)
		cout << "Blastoff!"	;
	else
	{
		cout << num << "...\n";
		CountDown(num-1);
	}
}

int factorial(int n)
{
	if (n==0)
		return 1; // base case
	else
		return n*factorial(n-1);
}

int numChars (char search, string str, int subscript) // case sensitive
{
	if (subscript >= str.length()) // base case
	{
		return 0;
	}
	else if (str[subscript] == search) // if found, increase return value by 1
	{
		return 1+numChars(search, str, subscript+1);
	}
	else
	{
		return numChars(search, str, subscript+1);
	}
}

int fibonacci(int n)
{
	if (n<=0)
		return 0; 			// base case
	else if (n==1)
		return 1;			// base case 2
	else 
		return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
	CountDown(5);
	cout << endl <<factorial (5);
	cout << endl << numChars('h',"Hello World",0);
	cout << endl ;
	for (int i=0;i<10;i++)
	{
		cout << fibonacci(i) <<" ";
	}
	cout << fibonacci(9);
	return 0;
}
