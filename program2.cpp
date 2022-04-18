#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[],int l,int r,int element,int &count)
{
    count++;
    if(r>=l)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]==element)
            return mid;
        if(arr[mid]>element)
            return binary_search(arr,l,mid-1,element,count);
        return binary_search(arr,mid+1,r,element,count);
    }
    return -1;
}
int main()
{
    int length,count=1;
    cout<<"enter length of array: ";
    cin>>length;
    int arr[length];
    for(int i=0;i<length;i++)
    {
        cin>>arr[i];
    }
    int element;
    cout<<"enter element to search: ";
    cin>>element;
    int result=binary_search(arr,0,length-1,element,count);
    if(result==-1)
        cout<<"Element not present."<<endl;
    else   
        cout<<"Element is present."<<endl;
    cout<<"Comparison: "<<count<<endl;
    
}