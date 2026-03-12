#include<iostream>
using namespace std;

#pragma pack(1)

template <class T>
class node
{
    public:
        T data;
        node *next;

        node(T no)
        {
            this->data = no;
            this->next == NULL;
        }
};

template <class T>
class SinglyLLL
{
    private:                        // IMPORTANT
        node<T> * first;                // head
        int iCount;

    public:
        SinglyLLL();
        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

};

template <class T>
SinglyLLL<T>::SinglyLLL()
{
    cout<<"Object of SinglyLL get created.\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Displays all elements of the singly linked list.
//  Input         : void
//  Output        : Prints all node data on screen
//  Author        : Vivek Bhauraj Gautam
//  Date          : 23/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::Display()          // Updated
{
    int iCnt = 0;
    node<T> * temp = NULL;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)      // Updated
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }

    cout<<" NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Returns total number of nodes present in linked list.
//  Input         : void
//  Output        : Integer count of nodes
//  Author        : Vivek Bhauraj Gautam
//  Date          : 23/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyLLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Inserts a new node at the beginning of linked list.
//  Input         : int no → Data to be inserted
//  Output        : Modifies linked list by adding node at first position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 23/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertFirst(T no)                // Updated
{
    node<T> * newn = NULL;

    newn = new node<T>(no);

    if(newn == NULL)
    {
        cout<<"Unable to alocate memory \n";
        return;
    }

    newn->next = this->first;
    this->first = newn;
    

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : Inserts a new node at the end of linked list.
//  Input         : int no → Data to be inserted
//  Output        : Modifies linked list by adding node at last position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 23/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertLast(T no)
{
    node<T> * newn = NULL;
    node<T> * temp = NULL;

    newn = new node<T>(no);

    if(newn == NULL)
    {
        cout<<"Unable to alocate memory \n";
        return;
    }

    if(this->iCount == 0)             // Updated
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

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Description   : Inserts a new node at a specific position in linked list.
//  Input         : int no  → Data to be inserted
//                  int pos → Position where node is to be inserted
//  Output        : Modifies linked list by inserting node at given position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 23/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertAtPos(T no,int pos)
{
    int iCnt = 0;

    node<T> * newn = NULL;
    node<T> * temp = NULL;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new node<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
    
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : Deletes the first node of linked list.
//  Input         : void
//  Output        : Removes first node and frees its memory
//  Author        : Vivek Bhauraj Gautam
//  Date          : 23/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteFirst()
{
    node<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)            // if(this->iCount == 1)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        
        this->first = this->first->next;
        delete temp;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : Deletes the last node of linked list.
//  Input         : void
//  Output        : Removes last node and frees its memory
//  Author        : Vivek Bhauraj Gautam
//  Date          : 23/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteLast()
{
    node<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)            // if(this->iCount == 1)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        
        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : Deletes node from a specific position in linked list.
//  Input         : int pos → Position of node to be deleted
//  Output        : Removes node from given position and frees its memory
//  Author        : Vivek Bhauraj Gautam
//  Date          : 23/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    int iCnt = 0;

    node<T> * temp = NULL;
    node<T> * target = NULL;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

int main()
{
    SinglyLLL<int> * obj = new SinglyLLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();

    iRet = obj->Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj->DeleteFirst();

    obj->Display();

    iRet = obj->Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj->DeleteLast();

    obj->Display();

    iRet = obj->Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj->InsertAtPos(105,4);

    obj->Display();

    iRet = obj->Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj->DeleteAtPos(4);

    obj->Display();

    iRet = obj->Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    return 0;
}

