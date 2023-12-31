//Here is implementation of binary search algorithm through simple code
#include<iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(arr[mid] == x)
        {
            return mid;
        }
        else if(arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}
int main()
{
    system("cls");
    int num;
    int arr[10];
    int output;
    cout<<"Enter 10 integers in Ascending order: "<<endl;
    for(int i = 0; i < 10; i++)
    {
        cin>> arr[i];
    }
    cout<<"Enter a number you want to search: "<< endl;
    cin>> num;
    output = binarySearch(arr, 0, 9, num);
    if(output == -1)
    {
        cout<<"No match found"<<endl;
    }
    else
    {
        cout<<"Match found at index: "<<output<<endl;
    }
    return 0;
}