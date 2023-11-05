//DAA A4
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of elements\n";
    cin>>n;
    
    int wt[n+1],val[n+1];
    cout<<"\nEnter Weights\n";
    for(int i=0;i<=n;++i)
    {
        cin>>wt[i];
    }
    cout<<"\nEnter Profits\n";
    for(int i=0;i<=n;++i)
    {
        cin>>val[i];
    }
    int w;
    cout<<"\nEnter Capacity\n"
    cin>>w;
    int dp[n+1][w+1];
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=w;++j)
        {
            if(i==0|| j==0)
            {
                dp[i][j]=0;
            }
            else if(wt[i]<=j)
            {
                dp[i][j]=max(dp[i-1][j],val[i]+dp[i-1][j-wt[i]]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n-1][w-1];
}

