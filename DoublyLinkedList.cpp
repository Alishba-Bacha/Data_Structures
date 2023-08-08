#include<iostream>
using namespace std;

class Node
{
    public:
        int key, data;
        Node* prev;
        Node* next;

        Node()
        {
            key = 0;
            data = 0;
            prev = NULL;
            next = NULL;
        }

        Node(int k, int d)
        {
            key = k;
           data = d;
        }
};
class DoublyLinkedList
{
    public:
        Node* head;

        DoublyLinkedList()
        {
            head = NULL;
        }
        DoublyLinkedList(Node* n)
        {
            head = n;
        }

        //Check if Node exist
        Node * nodeExists(int k)
        {
            Node* temp = NULL;
            Node* ptr = head;
            while(ptr != NULL)
            {
                if(ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            }
            return temp;
        }

        //Append Node at end
        void append(Node* n)
        {
            if(nodeExists(n->key) != NULL)
            {
                cout<<"Node already exists with this key"<<endl;
                cout<<"Append Another node if you want"<<endl;
            }
            else
            {
                if(head == NULL)
                {
                    head = n;
                    cout<<"Node Appended as head Node"<< endl;
                }
                else
                {
                    Node* ptr = head;
                    while(ptr != NULL)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    n->prev = ptr;
                    cout<<"Node Appended"<< endl;
                }
            }
        }

        //Prepend Node
        void prependNode(Node* n)
        {
            if(head == NULL)
            {
                head = n;
                cout<<"Node Appended as head Node"<< endl;
            }
            else
            {
                if(head == NULL)
                {
                    head = n;
                    cout<<"Node prepended as head Node"<< endl;
                }
                else
                {
                    head->prev = n;
                    n->next = head;
                    head = n;
                    cout<<"Node Prepended"<< endl;
                }
            }
        }

        //Insert a Node after particular Node
        void insertNode(int k, Node* n)
        {
            Node* ptr = nodeExists(k);
            if(ptr == NULL)
            {
                cout<<"No node exists with this key"<<endl;
            }
            else
            {
                Node* nextnode = ptr->next;
                //Append at end
                if(nextnode == NULL)
                {
                    ptr->next = n;
                    n->prev = ptr;
                    cout<<"Node Inserted at end"<< endl;
                }
                //Appending In Between
                else
                {
                    n->next = nextnode;
                    nextnode->prev = n;
                    n->prev = ptr;
                    ptr->next = n;
                    cout<<"Node Inserted In between"<<endl;   
                }
            }
        }

        //Deleting a Node by key
        void deleteNode(int k)
        {
            Node* ptr = nodeExists(k);
            if(ptr == NULL)
            {
                cout<<"No Node exist with this key "<<endl;
            }
            else
            {

                if(head == NULL)
                {
                    cout<<"Doubly linked list is already Empty"<<endl;
                }
                else if(head != NULL)
                {
                    if(head->key = k)
                    {
                        head = head->next;
                        cout<<"Node UNlinked with key value "<<k<< endl;
                    }
                    else
                    {
                        Node* nextnode = ptr->next;
                        Node* prevnode = ptr->prev;
                        //Deleting at end
                        if(nextnode == NULL)
                        {
                            prevnode->next = NULL;
                            cout<<"Node deleted at end"<<endl;
                        }
                        //Deleting in between
                        else
                        {
                            prevnode->next = nextnode;
                            nextnode->prev = prevnode;
                            cout<<"Node Deleted In between"<<endl;
                        }
                    }
                }
            }
        }

        //Update Node
        void updatenode(int k, int d)
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

        //Print Doubly Linked List
        void printingList()
        {
            if(head == NULL)
            {
                cout<<"No node in Doubly list exist "<<endl;
            }
            else
            {
                cout<<"\nDoubly Linked list values are "<<endl;
                Node* temp = head;
                while(temp!= NULL) 
                {
                    cout<<"("<< temp->key<< ","<< temp->data<< ")<-->"<< " ";
                    temp = temp->next;
                }
            }
        }

};
int main()
{
    system("cls");
    DoublyLinkedList d1;
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
                d1.append(n1);
                break;
            case 2:
                cout<<"Enter key and data to prepend node "<<endl;
                cin>>key1;
                cin>>data1;
                n1->key = key1;
                n1->data = data1;
                d1.prependNode(n1);
                break;
            case 3:
                cout<<"Enter key of existing node after which you want to prepend node:"<< endl;
                cin>> k1;
                cout<<"Enter key and data to prepend node "<<endl;
                cin>>key1;
                cin>>data1;
                n1->key = key1;
                n1->data = data1;
                d1.insertNode(k1, n1);
                break;
            case 4:
                cout<<"Enter key to delete key"<< endl;
                cin>>k1;
                d1.deleteNode(k1);
                break;
            case 5:
                cout<<"Enter key and new data to update node"<<endl;
                cin>>key1;
                cin>> data1;
                d1.updatenode(key1,data1);
                break;
            case 6:
                d1.printingList();
                break;
            case 7:
                
                break;
            default:
                cout<<"Choose proper option"<< endl;

        }
    }while(option != 7);

    return 0;
}