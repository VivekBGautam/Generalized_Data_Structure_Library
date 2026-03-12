#include<iostream>
using namespace std;

class Queuenode
{
    public:
        int data;
        Queuenode * next;

        Queuenode(int no)
        {
            this->data = no;
            this->next = NULL;
        }
};

class Queue
{
    private:
        Queuenode * first;
        int iCount;

    public:
        Queue();
        void EnQueue(int);           // InsertLast
        int DeQueue();                // DeleteFirst
        void Display();
        int Count();
};

Queue::Queue()
{
    cout<<"Queue gets Created succesfully\n";
    this->first = NULL;
    this->iCount = 0;
}

void Queue::EnQueue(int no)
{
    Queuenode * newn = NULL;
    Queuenode * temp = NULL;

    newn = new Queuenode(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    this->iCount++;

}

int Queue:: DeQueue()
{
    int Value = 0;
    Queuenode *temp = NULL;
    temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Queue is Empty\n";
        return -1;
    }
   
    Value = this->first->data;
    this->first = this->first->next;

    delete temp;

    this->iCount--;

    return Value; 
}

//---------------------------------------------------------------------------------------------------------------
void Queue::Display()
{
    Queuenode * temp = NULL;
    temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Queue is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp->next;
    }
    cout<<"\n";
}

int Queue::Count()
{
    return iCount;
}

int main()
{
    Queue * qobj = new Queue();
    qobj->EnQueue(11);
    qobj->EnQueue(21);
    qobj->EnQueue(51);
    qobj->EnQueue(101);

    qobj->Display();
    cout<<"Number of elemnts in Queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->DeQueue()<<"\n";
    qobj->Display();
    cout<<"Number of elemnts in Queue are : "<<qobj->Count()<<"\n";

    cout<<"Removed element is : "<<qobj->DeQueue()<<"\n";
    qobj->Display();
    cout<<"Number of elemnts in Queue are : "<<qobj->Count()<<"\n";

    qobj->EnQueue(121);

    qobj->Display();
    cout<<"Number of elemnts in Queue are : "<<qobj->Count()<<"\n";


    delete qobj; 

    return 0;
}