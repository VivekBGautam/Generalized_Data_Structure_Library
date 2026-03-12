///////////////////////////////////////////////////////////////////
//   Generalished Data Structure Library
///////////////////////////////////////////////////////////////////

/*
-------------------------------------------------------------------------------------------------------------
    Type                 Name of class for node             Name of class for Functionality
-------------------------------------------------------------------------------------------------------------
    Singly Linear       SinglyLLLnode                        SinglyLLL
    Singly Circular     SinglyCLLnode                        SinglyCLL
    Doubly Linear       DoyblyLLLnode                        Doublynode
    Doubly Circular     DoublCLLnode                         Doublynode
-------------------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std; 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//          
//          Singly Linear Linked list using Generic approach
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name : SinglyLLLnode
//  Description    : Represents a node of Singly Linear Linked List
//  Template Type  : T (Generic data type)
//  Members        :
//      data  - Stores value of type T
//      next  - Pointer to next node
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
struct SinglyLLLnode
{
    T data;
    struct SinglyLLLnode<T> *next;
};

////////////////////////////////////////////////////////////////////////////////
//
//  Class Name   : SinglyLLL
//  Description  : Generic (template-based) Singly Linear Linked List.
//                 Supports insertion, deletion, traversal, and counting
//                 operations for any data type.
//  Author       : Vivek Bhauraj Gautam
//  Date         : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyLLL
{
    private:
        struct SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name : SinglyLLL
//  Description      : Initializes linked list with zero nodes.
//  Author           : Vivek Bhauraj Gautam
//  Date             : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////
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
//  Description   : Displays all elements of the singly linear linked list
//                  from first node to last node.
//  Input         : void
//  Output        : Prints all node data of type T on screen
//  Author        : Vivek Bhauraj Gautam
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::Display()
{
    if(first == NULL)
    {
        return;
    }

    struct SinglyLLLnode<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    }
    
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Returns total number of nodes present in the linked list.
//  Input         : void
//  Output        : Integer value representing count of nodes
//  Author        : Vivek Bhauraj Gautam
//  Date          : 06/01/2026
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
//  Description   : Inserts a new node at the beginning of the linked list.
//  Input         : T no → Data to be inserted
//  Output        : Linked list is modified by adding a node at first position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertFirst(T no)
{
    struct SinglyLLLnode<T> * newn = NULL;

    newn = new struct SinglyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : Inserts a new node at the end of the linked list.
//  Input         : T no → Data to be inserted
//  Output        : Linked list is modified by adding a node at last position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertLast(T no)
{
    struct SinglyLLLnode<T> * newn = NULL;
    struct SinglyLLLnode<T> * temp = NULL;

    newn = new struct SinglyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(this->iCount == 0)
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
//  Description   : Inserts a new node at the specified position in the linked list.
//  Input         : T no   → Data to be inserted
//                  int pos → Position at which node is to be inserted
//  Output        : Linked list is modified by inserting node at given position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertAtPos(T no,int pos)
{
    int iCnt = 0;

    struct SinglyLLLnode<T> * newn = NULL;
    struct SinglyLLLnode<T> * temp = NULL;

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
        newn = new struct SinglyLLLnode<T>;
        newn->data = no;
        newn->next = NULL;

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
//  Description   : Deletes the first node of the linked list.
//  Input         : void
//  Output        : Removes first node and deallocates its memory
//  Author        : Vivek Bhauraj Gautam
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteFirst()
{
    struct SinglyLLLnode<T> *  temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
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
//  Description   : Deletes the last node of the linked list.
//  Input         : void
//  Output        : Removes last node and deallocates its memory
//  Author        : Vivek Bhauraj Gautam
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteLast()
{
    struct SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
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
//  Description   : Deletes a node from the specified position in the linked list.
//  Input         : int pos → Position of node to be deleted
//  Output        : Linked list is modified by removing the node from given position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    int iCnt = 0;

    struct SinglyLLLnode<T> * temp = NULL;
    struct SinglyLLLnode<T> * target = NULL;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          Doubly Linear Linked list using Generic approach
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
//
// Structure Name : DoublyLLLnode
// Description    : Represents a single node of a Doubly Linear Linked List.
// Template Type  : T (Generic data type)
// Members        :
//      data  - Stores data of generic type
//      next  - Pointer to next node
//      prev  - Pointer to previous node
//
////////////////////////////////////////////////////////////////////////
template <class T>
struct DoublyLLLnode
{
    T data;
    struct DoublyLLLnode<T> *next;
    struct DoublyLLLnode<T> *prev;
};

////////////////////////////////////////////////////////////////////////
//
// Class Name  : DoublyLLL
// Description : Provides functionality to manage Doubly Linear Linked List.
// Features    :
//      - Insertion at first, last, and specific position
//      - Deletion from first, last, and specific position
//      - Display list elements
//      - Count total number of nodes
//
////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyLLL
{
    private:
        struct DoublyLLLnode<T> * first;    // Pointer to first node
        int iCount;                         // Stores number of nodes

    public:
        DoublyLLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

////////////////////////////////////////////////////////////////////////
//
// Constructor Name : DoublyLLL
// Description      : Initializes an empty doubly linked list.
//
////////////////////////////////////////////////////////////////////////
template <class T>
DoublyLLL<T>::DoublyLLL()
{
    cout<<"Object of DoublyLLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Displays all elements of the doubly linked list
//                 in forward direction.
// Input         : void
// Output        : Prints node data on console
// Author        : Vivek Bhauraj Gautam
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::Display()
{
    struct DoublyLLLnode<T> * temp = first;

    cout<<"\n NULL <=> ";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Returns total number of nodes present in the linked list.
// Input         : void
// Output        : Integer value representing node count
// Author        : Vivek Bhauraj Gautam
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyLLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Description   : Inserts a new node at the beginning of the linked list.
// Input         : T no → Data to be inserted
// Output        : Linked list is updated
// Author        : Vivek Bhauraj Gautam
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    struct DoublyLLLnode<T> * newn = new struct DoublyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Description   : Inserts a new node at the end of the linked list.
// Input         : T no → Data to be inserted
// Output        : Linked list is updated
// Author        : Vivek Bhauraj Gautam
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertLast(T no)
{
    struct DoublyLLLnode<T> * newn = new struct DoublyLLLnode<T>;
    struct DoublyLLLnode<T> * temp = NULL;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Description   : Inserts a node at the specified position.
// Input         : T no  → Data to be inserted
//                 int pos → Position for insertion
// Output        : Linked list is updated
// Author        : Vivek Bhauraj Gautam
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertAtPos(T no,int pos)
{
    int iCnt = 0;

    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct DoublyLLLnode<T> * newn = new struct DoublyLLLnode<T>;
        struct DoublyLLLnode<T> * temp = first;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Description   : Deletes the first node from the linked list.
// Input         : void
// Output        : Linked list is updated
// Author        : Vivek Bhauraj Gautam
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct DoublyLLLnode<T> * temp = first;
        first = first->next;
        first->prev = NULL;
        delete temp;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Description   : Deletes the last node from the linked list.
// Input         : void
// Output        : Linked list is updated
// Author        : Vivek Bhauraj Gautam
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct DoublyLLLnode<T> * temp = first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Description   : Deletes a node from the specified position.
// Input         : int pos → Position of node to delete
// Output        : Linked list is updated
// Author        : Vivek Bhauraj Gautam
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct DoublyLLLnode<T> * temp = first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        struct DoublyLLLnode<T> * target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete target;

        iCount--;
    }
}

///////////////////////////////End of Library/////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
//
// Entry Point Function : main
// Description          : Demonstrates all operations of
//
////////////////////////////////////////////////////////////////////////
int main()
{
    return 0;
}