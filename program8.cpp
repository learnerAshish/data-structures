#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n)
{
    int min,loc,comparison=0,swap=0;
    for(int i=0;i<n-1;i++)
    {
        min=arr[i];
        loc=i;
        for(int j=i+1;j<n;j++)
        {
            comparison++;
            if(min>arr[j])
            {
                min=arr[j];
                loc=j;
            }
        }
        swap++;
        int temp;
        temp=arr[i];
        arr[i]=arr[loc];
        arr[loc]=temp;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Comparison: "<<comparison<<endl;
    cout<<"Swap: "<<swap<<endl;
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
        selectionSort(arr,n);
    }
}