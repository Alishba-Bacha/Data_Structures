//Basic Implementation of Stack in Data Structures
#include<iostream>
#include<string>

using namespace std;

class Stack
{
    private:
       int top;
       int arr[5];
    
    public:
        Stack()
        {
            top = -1;
            for(int i = 0; i <= 4; i++)
            {
                arr[i] = 0;
            }
        }

        bool isEmpty()
        {
            if(top == -1)
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
            if(top == 4)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        void push(int value)
        {
            if(isFull())
            {
                cout<<"Stack Overflow" << endl;
            }
            else
            {
                top++;
                arr[top] = value;
            }
        }

        int pop()
        {
            if(isEmpty())
            {
                cout<<"Stack is Underflow"<< endl;
                return 0;
            }
            else
            {
                int popvalue = arr[top];
                arr[top] = 0;
                top--;
                return popvalue;
            }
        }

        int count()
        {
            return top+1;
        }

        int peek(int index)
        {
            if(isEmpty())
            {
                cout<<"Stack Underflow"<< endl;
                return 0;
            }
            else
            {
                return arr[index];
            }
        }

        void change(int index, int value)
        {
            arr[index] = value;
            cout<<"Value at "<<index<<" is changed"<< endl;
        }

        void display()
        {
            cout<<"All Values in stack are: "<< endl;
            for(int i = 4; i <= 0; i--)
            {
                cout<<arr[i]<<endl;
            }
        }
       
};

int main()
{
    system("cls");
    Stack s1;
    int option, position, value;

    do
    {
        cout<<"1: Push"<<endl;
        cout<<"2: Pop"<<endl;
        cout<<"3: Change"<<endl;
        cout<<"4: Display"<<endl;
        cout<<"5: Is Empty"<<endl;
        cout<<"6: Is Full"<<endl;
        cout<<"7: Count"<<endl;
        cout<<"8: peek"<<endl;
        cout<<"9: Quit"<<endl;
        cout<<"Choose option: "<<endl;
        cin>> option;

        switch(option)
        {
            case 1:
                cout<<"Enter a number to push"<<endl;
                cin>> value;
                s1.push(value);
                break;
            case 2:
                cout<<"Pop Function called"<< endl;
                cout<<"Pop Value: "<<s1.pop()<< endl;
                break;
            case 3:
                cout<<"Enter the position to change value:"<<endl;
                cin>> position;
                cout<<"Enter the new value:"<<endl;
                cin>>value;
                s1.change(position, value);
                break;
            case 4:
                s1.display();
                break;
            case 5:
                if(s1.isEmpty())
                {
                    cout<<"Stack is Empty"<<endl;
                }
                else
                {
                    cout<<"Stack is not Empty"<<endl;
                }
                break;
            case 6:
                if(s1.isFull())
                {
                    cout<<"Stack is full"<<endl;
                }
                else
                {
                    cout<<"Stack is not full"<<endl;
                }
                break;
            case 7:
                cout<<"Count:"<<s1.count()<<endl;
                break;
            case 8:
                cout<<"Enter position to display its value:"<< endl;
                cin>> position;
                cout<<"Value at "<<position<< " is "<<s1.peek(position)<< endl;
                break;
            case 9:
                break;
            default:
                cout<<"Enter appropriate option"<<endl;
        }
    }while(option != 0);

    cout<<"Thank You!"<< endl;

    return 0;
}