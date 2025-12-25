//Segemented Sieve: Generate prime numbers less than N
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void simpleSieve(ll limit, vector<ll>& prime){
    bool isPrime[limit+1];
    memset(isPrime, true, sizeof(isPrime));
    for(int i=2;i*i<limit;++i){
        if(isPrime[i]){
            for(int j=i*i;j<limit;j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(int i=2;i<limit;i++){
        if(isPrime[i]){
            cout<<i<<" ";
            prime.push_back(i);
        }
    }
}
void segmentedSieve(ll n){
    ll limit = sqrt(n)+1;
    vector<ll> prime;
    simpleSieve(limit,prime);
    ll low = limit;
    ll high = 2*limit;
    while(low<n){
        if(high>n){
            high = n;
        }
        bool mark[limit+1]; 
        memset(mark, true, sizeof(mark)); 
        for(int i=0;i<prime.size();++i){
            ll curPrime = prime[i];
            ll base = (low/curPrime)*curPrime;
            if(base<low){
                base = base + curPrime;
            }
            for(int j=base;j<high;j+=curPrime){
                mark[j-low] = false;
            }
            if(base==curPrime)
                mark[base-low] = true;
        }
        for(int i=low;i<high;i++){
            if(mark[i-low])
                cout<<i<<" ";
        }
        low = low + limit;
        high = high + limit;
    }
}

// Better version of code
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
    segmentedSieve(10000);

    int L = 110;
    int R = 130;
    vector<bool>ss = segSieve(L,R);
    for (int i = 0; i < ss.size(); i++)
    {
        if(ss[i]){
            cout<< i + L <<" ";
        }
    }
}
