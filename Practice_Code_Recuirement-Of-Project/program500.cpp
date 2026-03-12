///////////////////////////////////////////////////////////////////
//   Generalished Data Structure Library
///////////////////////////////////////////////////////////////////

/*
-------------------------------------------------------------------------------------------------------------
    Type                 Name of class for node             Name of class for Functionality     Status
-------------------------------------------------------------------------------------------------------------
    Singly Linear       SinglyLLLnode                        SinglyLLL                          Done
    Singly Circular     SinglyCLLnode                        SinglyCLL                          Done
    Doubly Linear       DoyblyLLLnode                        Doublynode                         Done
    Doubly Circular     DoublCLLnode                         Doublynode                         Done
    Stack               Stacknode                            Stack                              Done
    Queue               Queuenode                            Queue                              Done
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
//          Singly ircular Linked list using Generic approach
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name : SinglyCLLnode
//  Description    : Represents a node of Singly Circular Linked List
//  Template Type  : T (Generic data type)
//  Members        :
//      data  - Stores value of type T
//      next  - Pointer to next node
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode<T> *next;
};

////////////////////////////////////////////////////////////////////////////////
//
//  Class Name   : SinglyCLL
//  Description  : Generic (template-based) Singly Circular Linked List.
//                 The last node points back to the first node.
//                 Supports insertion, deletion, traversal, and counting
//                 operations for any data type.
//  Author       : Vivek Bhauraj Gautam
//  Date         : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyCLL
{
    private:
        struct SinglyCLLnode<T> * first;
        struct SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
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
//  Constructor Name : SinglyCLL
//  Description      : Initializes an empty Singly Circular Linked List.
//  Author           : Vivek Bhauraj Gautam
//  Date             : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Inserts a new node at the beginning of the circular linked list.
//  Input         : T no → Data to be inserted
//  Output        : Linked list is modified by adding node at first position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : Inserts a new node at the end of the circular linked list.
//  Input         : T no → Data to be inserted
//  Output        : Linked list is modified by adding node at last position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;
        last->next = first;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : Deletes the first node of the circular linked list.
//  Input         : void
//  Output        : Removes first node and deallocates its memory
//  Author        : Vivek Bhauraj Gautam
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : Deletes the last node of the circular linked list.
//  Input         : void
//  Output        : Removes last node and deallocates its memory
//  Author        : Vivek Bhauraj Gautam
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteLast()
{
    struct SinglyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }

        delete last;
        last = temp;
        last->next = first;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Displays all elements of the singly circular linked list.
//  Input         : void
//  Output        : Prints all node data of type T on screen
//  Author        : Vivek Bhauraj Gautam
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    struct SinglyCLLnode<T> * temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    } while(temp != last->next);

    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Returns total number of nodes present in the circular linked list.
//  Input         : void
//  Output        : Integer value representing count of nodes
//  Author        : Vivek Bhauraj Gautam
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : Deletes a node from the specified position in the circular linked list.
//  Input         : int pos → Position of node to be deleted
//  Output        : Linked list is modified by removing the node from given position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * target = NULL;
    int i = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
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
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete target;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Description   : Inserts a new node at the specified position in the circular linked list.
//  Input         : T no   → Data to be inserted
//                  int pos → Position at which node is to be inserted
//  Output        : Linked list is modified by inserting node at given position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * newn = NULL;
    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;
        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          Doubly Circular Linked list using Generic approach
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma pack(1)

////////////////////////////////////////////////////////////////////////
//
// Structure Name : DoublyCLLnode
// Description    : Represents a single node of Doubly Circular Linked List.
// Template Type  : T (Generic data type)
// Members        :
//      data  - Stores data of generic type
//      next  - Pointer to next node
//      prev  - Pointer to previous node
//
////////////////////////////////////////////////////////////////////////
template <class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> *next;
    struct DoublyCLLnode<T> *prev;
};

////////////////////////////////////////////////////////////////////////
//
// Class Name  : DoublyCLL
// Description : Implements Doubly Circular Linked List operations.
// Features    :
//      - Insert node at first, last, and specific position
//      - Delete node from first, last, and specific position
//      - Display list elements
//      - Count total number of nodes
//
////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyCLL
{
    private:
        struct DoublyCLLnode<T> * first;   // Pointer to first node
        struct DoublyCLLnode<T> * last;    // Pointer to last node
        int iCount;                        // Stores number of nodes

    public:
        DoublyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Constructor Name : DoublyCLL
// Description      : Initializes an empty doubly circular linked list.
// Input            : void
// Output           : Sets first and last pointers to NULL
// Author           : Vivek Bhauraj Gautam
// Date             : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Object of DoublyCLL gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Displays all elements of the doubly circular linked list
//                 in forward circular manner.
// Input         : void
// Output        : Prints all node data on console
// Author        : Vivek Bhauraj Gautam
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::Display()
{
    struct DoublyCLLnode<T> * temp = first;

    if(first == NULL && last == NULL)
    {
        cout<<"Linked list is empty\n";
        return;
    }

    cout<<" <=> ";

    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }while(temp != last->next);

    cout<<"\n";
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
int DoublyCLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Description   : Inserts a new node at the beginning of doubly circular linked list.
// Input         : T no → Data to be inserted
// Output        : Linked list is updated
// Author        : Vivek Bhauraj Gautam
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    struct DoublyCLLnode<T> * newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last;

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Description   : Inserts a new node at the end of doubly circular linked list.
// Input         : T no → Data to be inserted
// Output        : Linked list is updated
// Author        : Vivek Bhauraj Gautam
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    struct DoublyCLLnode<T> * newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->prev = last;
        last->next = newn;
        last = newn;
    }

    last->next = first;
    first->prev = last;

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Description   : Inserts a new node at the specified position.
// Input         : T no  → Data to be inserted
//                 int pos → Position for insertion
// Output        : Linked list is updated
// Author        : Vivek Bhauraj Gautam
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertAtPos(T no,int pos)
{
    int iCnt = 0;

    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalid position\n";
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
        struct DoublyCLLnode<T> * newn = new struct DoublyCLLnode<T>;
        struct DoublyCLLnode<T> * temp = first;

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
// Description   : Deletes the first node from doubly circular linked list.
// Input         : void
// Output        : Linked list is updated
// Author        : Vivek Bhauraj Gautam
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        last->next = first;
        first->prev = last;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Description   : Deletes the last node from doubly circular linked list.
// Input         : void
// Output        : Linked list is updated
// Author        : Vivek Bhauraj Gautam
// Date          : 04/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;
        last->next = first;
        first->prev = last;
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
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
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
        struct DoublyCLLnode<T> * temp = first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//          
//          Stak using Generic approach
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//          
//          Queue using Generic approach
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> * next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Queue
{
    private:
        Queuenode<T> * first;
        Queuenode<T> * last;
        int iCount;

    public:
        Queue();
        void EnQueue(T);         
        T DeQueue();           
        void Display();
        int Count();
};

template <class T>
Queue<T>::Queue()
{
    cout<<"Queue gets Created succesfully\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void Queue<T>::EnQueue(T no)
{
    Queuenode<T> * newn = NULL;
 
    newn = new Queuenode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }
    this->iCount++;

}

template <class T>
T Queue<T>:: DeQueue()
{
    int Value = 0;
    Queuenode<T> *temp = NULL;
    temp = this->first;

    if(this->first == NULL && this->last == NULL)
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
template <class T>
void Queue<T>::Display()
{
    Queuenode<T> * temp = NULL;
    temp = this->first;

    if(this->first == NULL && this->last == NULL)
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

template <class T>
int Queue<T>::Count()
{
    return iCount;
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
    SinglyLLL<int> obj;
    int iRet;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteLast();
    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.InsertAtPos(105,4);
    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteAtPos(4);
    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";


    ////////////////////////////////////////////////////////////////////////////////////

    DoublyLLL<int> obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.InsertAtPos(105,4);

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    SinglyCLL<int> sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);
    
    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);
    
    sobj.InsertAtPos(105,5);

    sobj.Display();
    
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.DeleteAtPos(5);
    sobj.Display();
    
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.DeleteFirst();
    sobj.Display();
    
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.DeleteLast();
    sobj.Display();
    
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    DoublyCLL<int> obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteLast();
    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.InsertAtPos(105,4);
    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteAtPos(4);
    obj.Display();

    iRet = obj.Count();
    cout<<"total node in linked list is : "<<iRet<<"\n";



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Stack<char> * stobj = new Stack<char>();
stobj->Push('A');
stobj->Push('B');
stobj->Push('C');
stobj->Push('D');

stobj->Display();
cout<<"Number of elemnts in Stack are : "<<stobj->Count()<<"\n";

cout<<"Return value of Peep is : "<<stobj->Peep()<<"\n";
stobj->Display();
cout<<"Number of elemnts in Stack are : "<<stobj->Count()<<"\n";

cout<<"Popped element is : "<<stobj->Pop()<<"\n";
stobj->Display();
cout<<"Number of elemnts in Stack are : "<<stobj->Count()<<"\n";

cout<<"Popped element is : "<<stobj->Pop()<<"\n";
stobj->Display();
cout<<"Number of elemnts in Stack are : "<<stobj->Count()<<"\n";

stobj->Push('#');

stobj->Display();
cout<<"Number of elemnts in Stack are : "<<stobj->Count()<<"\n";


    delete stobj;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Queue<int> * qobj = new Queue<int>();
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




































////////////////////////////////////////// Thank You //////////////////////////////////////////////////////////