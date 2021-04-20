#include <iostream>
#include <vector>
#include <thread>

using namespace std;

void czy_pierwsza(int x) 
{
	cout<<"\nLiczby pierwsze: \n";
	for(int j=1; j<=x; j++) 
	{
		for(int i=2; i<=j/2; i++) 
		{
			if(j%i==0) 
			{
				break;
			}
			if(i==j/2) 
			{
				cout<<j<<", ";
			}
		}
		
	}
}

int fibonacci(int n) 
{
	if(n<3) 
	{
		return 1;
	}
	return fibonacci(n-2)+fibonacci(n-1);	
}

void fib(int x) 
{
	cout<<"\nCiag Fibonacciego: \n";
	int i;
	int j=1;
	do{
		i=fibonacci(j);
		cout<<i<<", ";
		j++;
	}while(i>x);
}

int main()
{
    vector <thread *> threads1;

    thread *watek = new thread(czy_pierwsza, 1e9);
    threads1.push_back(watek);


    thread *watek2 = new thread(fib, 100);
    threads1.push_back(watek2);

    for (vector<thread *>::iterator it = threads1.begin(); it != threads1.end(); ++it) 
	{
        (*it)->join(); 
        delete *it;
    }

    return 0;
