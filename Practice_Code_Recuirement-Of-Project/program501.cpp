////////////////////////////////////////////////////////////////////////////////////////////////
//             Final code of Queue using Generic approach
////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

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
    
    if(first->next == NULL)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete temp;
    }
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

int main()
{
    Queue<int> * qobj = new Queue<int>();

    int iCoice = 0;
    int Value = 0;
    int iRet = 0;
    
    while(1)
    {
        cout<<"-------------------------------------------------------------------------------------------------\n";
        cout<<"Please select the option\n";
        cout<<"1 : Insert New Element into the Queue\n";
        cout<<"2 : Remove Element from the Queue\n";
        cout<<"3 : Display the element of the Queue\n";
        cout<<"1 : Count the number of element from the Queue\n";
        cout<<"0 : Exit the application\n";

        cin>>iCoice;
        cout<<"-------------------------------------------------------------------------------------------------\n";
    
        switch(iCoice)
        {
            case 1:
                cout<<"Enter the element that you want to insert : \n";
                cin>>Value;
                qobj->EnQueue(Value);
                cout<<"Element gets inserted succesfully\n";
                break;

            case 2:
                iRet = qobj->DeQueue();
                if(iRet != -1)
                {
                    cout<<"Element removed from queue is : "<<iRet<<"\n";
                    break;
                }

            case 3:
                cout<<"Element of the queue are : "<<iRet<<"\n";
                qobj->Display();
                break;
            
            case 4:
                iRet = qobj->Count();
                cout<<"Number of element in queue is : "<<iRet<<"\n";
                break;

            case 0:
                cout<<"Thank you for using our application\n";
                delete qobj;
                return 0;

            default:
                cout<<"Please enter the valid option\n";
                
            } // End of switch

    } // end of while

    return 0;
}   // ENd of main