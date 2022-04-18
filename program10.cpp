#include<bits/stdc++.h>
using namespace std;
int comparison=0;
int inversion=0;
void merge(int arr[],int first,int mid,int last)
{
    int b[50];
    int i,j,k;
    i=first;
    j=mid+1;
    k=first;
    while(i<=mid && j<=last)
    {
        comparison++;
        if(arr[i]<=arr[j])
        {
            inversion++;
            b[k++]=arr[i++];
        }
        else
        {
            b[k++]=arr[j++];
        }
    }
    if(i>mid)
    {
        inversion++;
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
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<"Comparison: "<<comparison<<endl;
        cout<<"Inversion: "<<inversion<<endl;
    }
}