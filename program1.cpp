#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int length,count=0,flag=0;
        cin>>length;
        int arr[length];
        for(int i=0;i<length;i++)
        {
            cin>>arr[i];
        }
        int element;
        cin>>element;
        for(int i=0;i<length;i++)
        {
            flag++;
            if(element==arr[i])
            {
                count=1;
                break;
            }
        }
        if(count==1)
            cout<<"Present "<<flag<<endl;
        else
            cout<<"Not present "<<flag<<endl;
    }
}