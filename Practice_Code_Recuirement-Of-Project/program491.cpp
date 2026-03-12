#include<iostream>
using namespace std;

class Stacknode
{
    public:
        int data;
        Stacknode * next;

        Stacknode(int no)
        {
            this->data = no;
            this->next = NULL;
        }
};

class Stack
{
    private:
        Stacknode * first;
        int iCount;

    public:
        Stack();
        void Push(int);           // InsertFirst
        int Pop();                // DeleteFirst
        int Peep();
        void Display();
        int Count();
};

Stack::Stack()
{}
void Stack::Push(int)
{}
int Stack::Pop()
{}
int Stack::Peep()
{
    return 0;
}
void Stack::Display()
{
    Stacknode * temp = NULL;
    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" -> |";
        temp = temp->next;
    }
    cout<<"\n";
}
int Stack::Count()
{
    return iCount;
}

int main()
{
    Stack * sobj = new Stack();

    delete sobj;

    return 0;
}