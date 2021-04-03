// SEGMENTED SIEVE TO FIND PRIMES IN RANGE L to R

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(V) V.begin(),V.end()
using namespace std;


int primes[100001];
vector<ll> prime;

void sieve()
{
    primes[0]=primes[1]=1;

    for(int i=2;i*i<=100000;i++)
    {
        if(!primes[i])
        {
            for(int j=i*i;j<=100000;j+=i)
            {
                primes[j]=1;
            }
        }
    }
    for(int i=0;i<100001;i++)
    {
        if(!primes[i])
            prime.pb(i);
    }
    /*for(ll p: prime)
        cout<<p<<" ";*/
}

void solve(ll m,ll n)
{
    if(m==1)m++;
    ll arr[n-m+1];
    memset(arr,0,sizeof arr);
    for(ll  p: prime )
    {
        if(p*p<=n){
            ll j= (m/p)*p;
        if(j<m)j+=p;
        for(;j<=n;j+=p)
        {
            if(j!=p)
                arr[j-m]=1;
        }
        }

    }

    for(ll k=0;k<(n-m+1);k++)
    {
        if(!arr[k])
            cout<<m+k<<"\n";
    }
}

int main()
{
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    sieve();
    while(t--)
    {
        ll m,n;
        cin>>m>>n;
        solve(m,n);
        cout<<"\n";

    }
    return 0;
}

