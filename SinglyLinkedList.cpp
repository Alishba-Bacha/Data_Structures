#include<iostream>
using namespace std;

class Node
{
    public:
       int key;
       int data;
       Node* next;

       Node()
       {
           data = 0;
           key = 0;
           next = NULL;
       }
       Node(int k, int d)
       {
            key = k;
            data = d; 
       }
};

class Singly_Linked_List
{
    public:
        Node* head;

        Singly_Linked_List()
        {
            head = NULL;
        }
        Singly_Linked_List(Node *n)
        {
            head = n;
        }
        
        //Check if node exist
        Node* nodeExists(int k)
        {
            Node* temp = NULL;
            Node* ptr = head;
            while(ptr != NULL)
            {
                if(ptr->key = k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            }
            return temp;
        }
        
        //Append node to the list
        void appendNode(Node *n)
        {
            if(nodeExists(n-> key) != NULL)
            {
                cout<<"Node exists with key value"<<n->key<<endl;
                cout<<"Append another code if you want"<<endl;
            }
            else
            {
                if(head == NULL)
                {
                    head = n;
                    cout<<"Node appended"<<endl;
                }
                else
                {
                    Node *ptr = head;
                    while(ptr->next != NULL)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    cout<<"Node Appended"<< endl;
                }
            }
        }

        //Prepend Node(Node always attached as head)
        void prependNode(Node* n)
        {
            if(nodeExists(n-> key) != NULL)
            {
                cout<<"Node exists with key value"<<n->key<<endl;
                cout<<"Prepend another code if you want"<<endl;
            }
            else
            {
                n->next = head;
                head = n;
                cout<<"Node Prepended"<<endl;
            }
        }

        //Inserting a node at specific position
        void insertNode(int k, Node* n)
        {
            Node *ptr = nodeExists(k);
            if(ptr == NULL)
            {
                cout<<"No node exist with key value"<<k<<endl;
            }
            else
            {
                if(nodeExists(n-> key) != NULL)
                {
                    cout<<"Node exists with key value"<<n->key<<endl;
                }
                else
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    cout<<"Node Inserted"<<endl;
                }
            }
        }

        //Deleting node by key
        void deleteNode(int k)
        {
            if(head == NULL)
            {
                cout<<"Singly Linked List already empty"<<endl;
            }
            else if(head != NULL)
            {
                if(head->key == k)
                {
                    head = head->next;
                    cout<<"Node Unlinked with key value"<< k<< endl;
                }
                else
                {
                    Node *temp = NULL;
                    Node *prevptr = head;
                    Node *currentptr = head->next;
                    while(currentptr != NULL)
                    {
                        if(currentptr->key == k)
                        {
                            temp = currentptr;
                            currentptr = NULL;
                        }
                        else 
                        {
                            prevptr = prevptr->next;
                            currentptr = currentptr->next;
                        }
                    }
                    if(temp != NULL)
                    {
                        prevptr->next = temp->next;
                        cout<<"Node Unlinked with key value"<< k << endl;
                    }
                    else
                    {
                        cout<<"Node doesn't exist"<< endl;
                    }
                }
            }
        }

        //Update Node by key
        void updateNode(int k, int d)
        {
            Node* ptr = nodeExists(k);
            if(ptr != NULL)
            {
                ptr->data = d;
                cout<<"Node data updated successfully"<< endl;
            }
            else
            {
                cout<<"Node doesn't exist with key value "<< k <<endl;
            }
        }

        //Print List
        void printingList()
        {
            if(head == NULL)
            {
                cout<<"No node in singly list exist "<<endl;
            }
            else
            {
                cout<<"\nSingly Linked list values are "<<endl;
                Node* temp = head;
                while(temp!= NULL) 
                {
                    cout<<"("<< temp->key<< ","<< temp->data<< ")-->"<< endl;
                    temp = temp->next;
                }
            }
        }
};
int main()
{
    system("cls");
    Singly_Linked_List s1;
    int option, key1, k1, data1;
    do
    {
        cout<<"1: Append Node"<<endl;
        cout<<"2: Prepend Node"<<endl;
        cout<<"3: Insert Node"<<endl;
        cout<<"4: delete Node"<<endl;
        cout<<"5: Update Node"<<endl;
        cout<<"6: Display Node"<<endl;
        cout<<"7: Quit"<<endl;
        cout<<"Choose option: "<<endl;
        cin>> option;

        Node* n1 = new Node();     //dynamic memory allocation
        switch(option)
        {
            case 1:
                cout<<"Enter key and data to append node"<< endl;
                cin>> key1;
                cin>> data1;
                n1->key = key1;
                n1->data = data1;
                s1.appendNode(n1);
                break;
            case 2:
                cout<<"Enter key and data to prepend node "<<endl;
                cin>>key1;
                cin>>data1;
                n1->key = key1;
                n1->data = data1;
                s1.prependNode(n1);
                break;
            case 3:
                cout<<"Enter key of existing node after which you want to prepend node:"<< endl;
                cin>> k1;
                cout<<"Enter key and data to prepend node "<<endl;
                cin>>key1;
                cin>>data1;
                n1->key = key1;
                n1->data = data1;
                s1.insertNode(k1, n1);
                break;
            case 4:
                cout<<"Enter key to delete key"<< endl;
                cin>>k1;
                s1.deleteNode(k1);
                break;
            case 5:
                cout<<"Enter key and new data to update node"<<endl;
                cin>>key1;
                cin>> data1;
                s1.updateNode(key1,data1);
                break;
            case 6:
                s1.printingList();
                break;
            case 7:
                
                break;
            default:
                cout<<"Choose proper option"<< endl;

        }
    }while(option != 7);
    return 0;
}