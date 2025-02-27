#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyCL
{
    public:
        PNODE head;
        PNODE tail;
        int iCount;

        DoublyCL()
        {
            head = NULL;
            tail = NULL;
            iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(head == NULL && tail == NULL)
            {
                head = newn;
                tail = newn;
            }
            else 
            {
                newn->next = head;
                head->prev = newn;
                head = newn;
            }
            tail->next = head;
            head->prev = tail;

            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(head == NULL && tail == NULL)
            {
                head = newn;
                tail = newn;
            }
            else 
            {
                tail->next = newn;
                newn->prev = tail;
                tail = newn;
            }
            tail->next = head;
            head->prev = tail;

            iCount++;
        }

        void DeleteFirst()
        {
            if(head == NULL && tail == NULL)
            {
                return;
            }
            else if(head == tail)
            {
                delete(head);
                head = NULL;
                tail = NULL;
            }
            else
            {
                head = head->next;
                delete(head->prev);
                tail->next = head;
                head->prev = tail;
            }

            iCount--;
        }

        void DeleteLast()
        {
            if(head == NULL && tail == NULL)
            {
                return;
            }
            else if(head == tail)
            {
                delete(head);
                head = NULL;
                tail = NULL;
            }
            else
            {
                tail = tail->prev;
                delete(tail->next);
                tail->next = head;
                head->prev = tail;
            }

            iCount--;
        }

        void Display()
        {
            if(head == NULL && tail == NULL)
            {
                cout<<"Linked list is empty\n";
                return;
            }

            cout<<"Elements of Linked List are :\n";

            do 
            {
                cout<<"|"<<head->data<<"|<=>";
                head = head->next;
            }while(head != tail->next);

            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no , int ipos)
        {}

        void DeleteAtPos(int ipos)
        {}
};

int main()
{
    DoublyCL DCLobj;
    int iRet = 0;

    DCLobj.InsertFirst(51);
    DCLobj.InsertFirst(21);
    DCLobj.InsertFirst(11);

    DCLobj.InsertLast(101);
    DCLobj.InsertLast(111);
    DCLobj.InsertLast(121);

    DCLobj.Display();
    iRet = DCLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    DCLobj.DeleteFirst();

    DCLobj.Display();
    iRet = DCLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
    
    DCLobj.DeleteLast();

    DCLobj.Display();
    iRet = DCLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}