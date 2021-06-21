#include<iostream>
#include<stdio.h>
#include<algorithm>
#include <string>
#include<stack>
#include<string.h>

using namespace std;

int bin_search(int arr[],int src,int n)
{
    int mid;
    int fornt = 0,rare = n-1;
    while(1)
    {
        mid = (fornt+rare)/2;

        if(arr[mid] == src)
        {
            return mid;
        }

        if(fornt>=rare)
        {
            cout<<"Not found"<<endl;
            return -1;
        }


        else if(src>arr[mid])
        {
            fornt = mid+1;
        }
        else if(src<arr[mid])
        {
            rare = mid-1;
        }
    }
    return 0;

}

int main()
{
    while(1)
    {
        int n;
        cin>>n;

        int arr[n];
        cout<<"Please input a sorted array:"<<endl;
        for(int i=0;i<n;i++)
            cin>>arr[i];

        int search_item;
        cout<<"What is the search item: ";
        cin>>search_item;

        int x=bin_search(arr,search_item,n);


        if(x!=-1) cout<<x+1<<" th element"<<endl;
    }



    return 0;
}
