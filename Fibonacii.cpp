#include<bits/stdc++.h>
using namespace std;
int rsteps=0;
int recursive(int n)
{
    rsteps++;
    if(n<0) return 0;
    if(n==1 ||n==0) return 1;
    return recursive(n-1)+recursive(n-2);
}

int iterative(int n)
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    for(int i=2;i<n;++i)
    {
        v.push_back(v[i-2]+v[i-1]);
    }
    return n;
}

int main()
{
    int n;
    cout<<"Enter number of elements\n";
    cin>>n;
    cout<<"VAlues"<<recursive(n)<<endl;
    cout<<"Steps for iterative"<<iterative(n)<<endl;
    cout<<"steps for recursion"<<recursive(n)<<endl;
}
