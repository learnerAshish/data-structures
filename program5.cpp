#include<bits/stdc++.h>
using namespace std;

void search(int arr[],int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(arr[k]==arr[i]+arr[j])
                {
                    cout<<i<<" "<<j<<" "<<k<<" "<<endl;
                    count=1;
                    break;
                }
            }
        }
    }
    if(count==0)
        cout<<"Sequence not found."<<endl;
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
        search(arr,n);
    }
}