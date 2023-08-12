//Implementation of Selection Sort Algorithm 
#include<iostream>
using namespace std;

void selection_Sort(int arr[])
{
    for(int i = 0; i < 4; i++)
    {
        int min = i;
        for(int j = i+1; j < 5; j++)
        {
            if(arr[j] < arr[i])    //This is for Ascending and For descending order just change sign to ">"
            {
                min = j;
            }
        }
        //Swaping values
        if(min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
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
    selection_Sort(arr);

    cout<<"\nSorted array:"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}