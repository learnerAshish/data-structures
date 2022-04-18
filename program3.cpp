#include<bits/stdc++.h>
using namespace std;

int jumpSearch(int arr[],int x, int n)
{
    int start=0;
    int end=sqrt(n);
    while(arr[end]<=x && end<n)
    {
        start=end;
        end=end+sqrt(n);
        if(end>n-1)
            end=n;
    }
    for(int i=start;i<end;i++)
    {
        if(arr[i]==x)
            return i;
    }
    return -1;
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
        int result=jumpSearch(arr,x,n);
        if(result>=0)
            cout<<"Present"<<endl;
        else
            cout<<"Not Present"<<endl;
    }
}