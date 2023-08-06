//Basic Implementation of Queue in data structures
#include<iostream>
using namespace std;

class Queue
{
    private:
        int rear;
        int front;
        int arr[5];

    public:

       Queue()
       {
            rear = -1;
            front = -1;
            for(int i = 0; i < 5; i++)
            {
                arr[i] = 0;
            }
       }

       bool isEmpty()
       {
            if(front == -1 && rear == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
       }

       bool isFull()
       {
        //For circular queue we will use if((rear+1) % N == front) where N is size of array
        if(rear == 4)
        {
            return true;
        }
        else
        {
            return false;
        }
       }
       
       void enqueue(int val)
       {
            if(isFull())
            {
                cout<<"Queue is full"<<endl;
            }
            else if(isEmpty())
            {
                rear = 0;
                front = 0;
                arr[rear] = val;
            }
            else
            {
                rear++;
                //For circular queue we will use "rear = (rear+1) % N" where N is size of array
                arr[rear] = val;
            }
       }

       int dequeue()
       {
        int x = 0;
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        else if(front == rear)
        {
            x = arr[front];
            arr[front] = 0;
            front = -1;
            rear = -1;
            return x;
        }
        else{
            x = arr[front];
            arr[front] = 0;
            front++;
            //For circular queue we will write  "front = (front+1) % N" where N is size of array
            //rear--;
            return x;
        }
       }

       int count()
       {
            return (rear-front + 1);
       }
       
       void display()
       {
            cout<<"Queue values are:"<<endl;
            for(int i = 0; i < 5; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
       }
};

int main()
{
    system("cls");
    Queue q1;
    int option, value;
    do
    {
        cout<<"1: Enqueue"<<endl;
        cout<<"2: Dequeue"<<endl;
        cout<<"3: Display"<<endl;
        cout<<"4: Is Empty"<<endl;
        cout<<"5: Is Full"<<endl;
        cout<<"6: Count"<<endl;
        cout<<"7: Quit"<<endl;
        cout<<"Choose option: "<<endl;
        cin>> option;

        switch(option)
        {
            case 1:
                cout<<"Enter a number to enqueue in queue"<< endl;
                cin>> value;
                q1.enqueue(value);
                break;
            case 2:
                cout<<"Dequeued Value: "<<q1.dequeue()<<endl;
                break;
            case 3:
                q1.display();
                break;
            case 4:
                if(q1.isEmpty())
                {
                    cout<<"Queue is empty"<< endl;
                }
                else
                {
                    cout<<"Queue is not empty"<< endl;
                }
                break;
            case 5:
                if(q1.isFull())
                {
                    cout<<"Queue is full"<< endl;
                }
                else
                {
                    cout<<"Queue is not full"<< endl;
                }
                break;
            case 6:
                cout<<"Queue count is:"<< q1.count()<< endl;
                break;
            case 7:
                
                break;
            default:
                cout<<"Choose proper option"<< endl;

        }
    }while(option != 7);
    return 0;
}