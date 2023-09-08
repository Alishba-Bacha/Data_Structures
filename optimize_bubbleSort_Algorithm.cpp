//Implementation of optimize bubble sort algorithm
#include<iostream>
using namespace std;

void optimize_bubble_Sort(int arr[])
{
    for(int i = 0; i < 5; i++)
    {
        bool flag = false;
        for(int j = 0; j < 5-i-1; j++)
        {
            if(arr[j] > arr[j+1])     //For descending order use "<" sign
            {
                flag = true;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(flag == false)        //means array is already sorted
        {
            break;
        }
    }
}
int main()
{
    system("cls");
    int arr[5];
    cout<<"\nEnter five integers:"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cin>> arr[i];
    }
    cout<<"\nUnsorted array:"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    optimize_bubble_Sort(arr);

    cout<<"\nSorted array:"<<endl;
    for(int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}