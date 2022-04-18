#include<bits/stdc++.h>
using namespace std;

void insertion(int arr[],int n)
{
    int j;
    for(int i=0;i<n;i++)
    {
        int key=arr[i];
        for(j=i-1;j>=0;j--)
        {
            if(key<arr[j])
            {
                arr[j+1]=arr[j];
            }
            else
                break;
        }
        if((j+1)!=i)
        {
            arr[j+1]=key;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
         insertion(arr,n);
    }
}