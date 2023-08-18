//Implementation of Insertion Sort Algorithm 
#include<iostream>
using namespace std;

void insertion_Sort(int arr[])
{
    int  key, j;
    for(int i = 1; i < 5; i++)
    {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j -1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[5];
    cout<<"Enter five integers:"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cin>> arr[i];
    }
    cout<<"Unsorted array:"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    insertion_Sort(arr);

    cout<<"\nSorted array:"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}