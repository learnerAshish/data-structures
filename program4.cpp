#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int n,int x)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int x;
        cin>>x;
        int result=search(arr,n,x);
        cout<<x<<"-"<<result<<endl;
    }
}