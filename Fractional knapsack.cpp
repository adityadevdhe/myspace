//DAA A3
#include<bits/stdc++.h>
using namespace std;

void knapsack(int n,float weight[],float profit[],int capacity)
{
    float x[n],tp=0;
    int u=capacity;
    int i;
    for(i=0;i<n;++i)
    {
        x[i]=0.0;
    }
    for(i=0;i<n;++i)
    {
        if(weight[i]>u)
        {
            break;
        }else{
            x[i]=1.0;
            tp+=profit[i];
            u-=weight[i];
        }
    }
    if(i<n)
    {
        x[i]=u/weight[i];
    }
    tp=tp+x[i]*profit[i];
    cout<<"The result vector"<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<x[i]<<" ";
    }
    cout<<"Maximum profit is";
    cout<<tp;
}

int main()
{
    int n;
    cout<<"Enter number of elements"<<endl;
    cin>>n;
    float weight[n],profit[n],ratio[n];
    cout<<"\nEnter weights"<<endl;
    for(int i=0;i<n;++i)
    {
        cin>>weight[i];
    }
    cout<<"\nEnter profits"<<endl;
    for(int i=0;i<n;++i)
    {
        cin>>profit[i];
    }
    int capacity;
    cout<<"\nEnter Capacity\n";
    cin>>capacity;
    for(int i=0;i<n;++i)
    {
        ratio[i]=profit[i]/weight[i];
    }
    int temp;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(ratio[i]<ratio[j])
            {
             temp=ratio[j];
             ratio[j]=ratio[i];
             ratio[i]=temp;
             
             temp=weight[j];
             weight[j]=weight[i];
             weight[i]=temp;
             
             temp=profit[j];
             profit[j]=profit[i];
             profit[i]=temp;
            }
        }
    }
    knapsack(n,weight,profit,capacity);
    
}

