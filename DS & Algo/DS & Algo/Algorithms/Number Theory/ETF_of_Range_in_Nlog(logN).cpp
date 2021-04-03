//Calculating ETF of a number in SQRT(N) time

#include<bits/stdc++.h>
using namespace std;
int phi[1000001];

void preprocess(int n)
{
    for(int i=1;i<=n;i++)
        phi[i]=i;
    for(int i=2;i<=n;i++)
    {
        if(i==phi[i])
        {
            for(int j=i;j<=n;j+=i)
            {
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}


int main()
{

    int n;
    cin>>n;
     preprocess(n);
    for(int i=1;i<=n;i++)
    {
        cout<<"ETF("<<i<<")is "<<phi[i]<<"\n";
    }

}
