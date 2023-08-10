//Implementation of linear search Algorithm
#include<iostream>
using namespace std;

void linear_search_algorithm(int a[], int n)
{
    int temp = -1;
    for(int i = 0; i < 5; i++)
    {
        if(a[i] == n)
        {
            cout<<"Element found at location  "<< i<< endl;
            temp = 0;
        }
    }
    if(temp == -1)
    {
        cout<<"Element not found"<< endl;
    }
}

int main()
{
    system("cls");
    int element;
    int arr[5];
    cout<<"Enter 5 elements of array:"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cin>>arr[i];
    }
    cout<<"Please enter an element to search"<< endl;
    cin>> element;
    linear_search_algorithm(arr, element);

    return 0;
}