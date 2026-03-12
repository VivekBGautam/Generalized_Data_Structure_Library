#include<iostream>
using namespace std;

# pragma pack(1)

template <class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> * next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Stack
{
    private:
        Stacknode<T> * first;
        int iCount;

    public:
        Stack();
        void Push(T);        
        T Pop();   
        T Peep();
        void Display();
        int Count();
};

template <class T>
Stack<T>::Stack()
{
    cout<<"Stack gets Created succesfully\n";
    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void Stack<T>::Push(T no)
{
    Stacknode<T> * newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

template <class T>
T Stack<T>::Pop()
{
    T Value = 0;
    Stacknode<T> *temp = NULL;
    temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }
   
    Value = this->first->data;
    this->first = this->first->next;

    delete temp;

    this->iCount--;

    return Value; 
}

//--------------------------------------------------------------------------------------------------------------
template <class T>
T Stack<T>::Peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }
   
    Value = this->first->data;

    return Value; 
}

//---------------------------------------------------------------------------------------------------------------
template <class T>
void Stack<T>::Display()
{
    Stacknode<T> * temp = NULL;
    temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<" \t|\n";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

int main()
{
    Stack<int> * sobj = new Stack<int>();
    sobj->Push(11);
    sobj->Push(21);
    sobj->Push(51);
    sobj->Push(101);

    sobj->Display();
    cout<<"Number of elemnts in Stack are : "<<sobj->Count()<<"\n";

    cout<<"Return value of Peep is : "<<sobj->Peep()<<"\n";
    sobj->Display();
    cout<<"Number of elemnts in Stack are : "<<sobj->Count()<<"\n";

    cout<<"Popped element is : "<<sobj->Pop()<<"\n";
    sobj->Display();
    cout<<"Number of elemnts in Stack are : "<<sobj->Count()<<"\n";

    cout<<"Popped element is : "<<sobj->Pop()<<"\n";
    sobj->Display();
    cout<<"Number of elemnts in Stack are : "<<sobj->Count()<<"\n";

    sobj->Push(121);

    sobj->Display();
    cout<<"Number of elemnts in Stack are : "<<sobj->Count()<<"\n";


    delete sobj;

    return 0;
}