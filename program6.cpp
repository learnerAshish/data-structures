 #include<bits/stdc++.h>
 using namespace std;

void difference(int arr[],int n,int key)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(key== arr[i]-arr[j] || key==arr[j]-arr[i])
            {
                count++;
            }
        }
    }
    cout<<count<<endl;
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
         int key;
         cin>>key;
        difference(arr,n,key);
     }
 }