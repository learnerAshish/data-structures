#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int first,int mid,int last)
{
    int b[50];
    int i,j,k;
    i=first;
    j=mid+1;
    k=first;
    while(i<=mid && j<=last)
    {
        if(arr[i]<=arr[j])
            b[k++]=arr[i++];
        else
            b[k++]=arr[j++];
    }
    if(i>mid)
    {
        while(j<=last)
            b[k++]=arr[j++];
    }
    else
    {
        while(i<=mid)
            b[k++]=arr[i++];    
    }
    for(i=first;i<=last;i++)
    {
        arr[i]=b[i];
    }
}

void mergeSort(int arr[],int first,int last)
{
    int mid;
    if(first<last)
    {
        mid=(first+last)/2;
        mergeSort(arr,first,mid);
        mergeSort(arr,mid+1,last);
        merge(arr,first,mid,last);
    }
}

int duplicate(int arr[],int n)
{
    int i,count=0;
    for(i=0;i<n;i++)
    {
        if (arr[i]==arr[i+1])
            count=1;
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
        mergeSort(arr,0,n-1);
        // for(int i=0;i<n;i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        int result=duplicate(arr,n);
        if(result==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}