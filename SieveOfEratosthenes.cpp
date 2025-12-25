#include <iostream>
#include <stdbool.h>
#include <cstring>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
	long int i,p;
	bool arr[n+1];
	memset(arr,true,sizeof(arr));
	for(i=2;i*i<=n;i++)
	{
		if(arr[i]==true)
		{
			for(p=i*i;p<=n;p=p+i)
			{
				arr[p]=false;
			}
		}
	}
	for(i=2;i<=n;i++)
	{
		if(arr[i]==true)
		cout<<i<<endl;
	}
}


vector<bool> Sieve(int n){ // return sieve array and take n & n size sieve
// create a sieve array of N size telling isPrime
    vector<bool>sieve(n+1, true);
    sieve[0] = sieve[1] = false;
    // for (int i = 2; i <= n; i++)
    for (int i = 2; i*i<= n; i++) // optimization 2 on outer loop
    {
        if (sieve[i] == true) // jo prime h unke multiple ko non prime mark kr do
        {
            // int j=i*2; // find multiple

            int j = i*i; // optimization 1 on inner loop
            // first unmarked number would be i*i, as other have been marked by 2 to (i-1)  

            while (j<=n)
            {
                sieve[j]=false;
                j += i;
            }
            
        }
        
    }
    return sieve;
}

vector<bool> segSieve(int L, int R){
    // get me prime array, i will use it to ,ark seg sieve
    vector<bool>sieve=Sieve(sqrt(R));
    // make base priime to mark sieve
    vector<int>basePrimes;
    for (int i = 0; i < sieve.size(); i++)
    {
        if(sieve[i]){
            basePrimes.push_back(i);
        }
    }
    vector<bool>segSieve(R-L+1, true);
    if(L == 1 || L == 0){
        segSieve[L] = false;
    }
    for(auto prime : basePrimes){
        int first_multiple = (L / prime) * prime ;
        if(first_multiple < L){
            first_multiple += prime;
        }
        int j = max(first_multiple, prime*prime);
        while(j <= R){
            // segSieve[j] = false;
            segSieve[j-L] = false;
            j += prime; 
        }
    }
    return segSieve;
}

int main()
{
	// long int x;
	// cin>>x;
	// SieveOfEratosthenes(x);
	// getch();

	// vector<bool>sieve=Sieve(25); // take n= 25
    // for (int i = 0; i <= 25; i++)
    // {
    //     if (sieve[i])
    //     {
    //         cout<<i<<" ";
    //     }
        
    // }
    
    int L = 110;
    int R = 130;
    vector<bool>ss = segSieve(L,R);
    for (int i = 0; i < ss.size(); i++)
    {
        if(ss[i]){
            cout<< i + L <<" ";
        }
    }
	
	return (0);
}

