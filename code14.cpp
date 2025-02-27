#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyCL
{
    public:
        PNODE head;
        PNODE tail;
        int iCount;

        SinglyCL()
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

            if((head == NULL) && (tail == NULL))
            {
                head = newn;
                tail = newn;
            }
            else 
            {
                newn->next = head;
                head = newn; 
            }
            tail->next = head;
            
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if((head == NULL) && (tail == NULL))
            {
                head = newn;
                tail = newn;
            }
            else 
            {
                tail->next = newn;
                tail = newn;
            }
            tail->next = head;

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
                free(head);
                head = NULL;
                tail = NULL;
            }
            else
            {
                head = head->next;
                delete(tail->next);
                tail->next = head;
            }

            iCount--;
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(head == NULL && tail == NULL)
            {
                return;
            }
            else if(head == tail)
            {
                free(head);
                head = NULL;
                tail = NULL;
            }
            else
            {
                temp = head;

                while(temp->next != tail)
                {
                    temp = temp->next;
                } 

                delete(temp->next);
                tail = temp;
                tail->next = head;
            }

            iCount--;
        }

        void Display()
        {
            if(head == NULL && tail == NULL)
            {
                cout<<"Linked List is empty\n";
                return;
            }

            cout<<"Elements of Linked List are : \n";

            do 
            {
                cout<<"|"<<head->data<<"|->";
                head = head->next;
            }while(head != tail->next);

            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }

        void InsertAtPos(int no , int ipos)
        {
            int i = 0;

            PNODE newn = NULL;
            PNODE temp = NULL;

            if(ipos < 1 || ipos > iCount+1)
            {
                cout<<"Invalid position\n";
                return;
            }

            else if(ipos == 1)
            {
                InsertFirst(no);
            }
            else if(ipos == iCount+1)
            {
                InsertLast(no);
            }
            else
            {
                newn = new NODE;

                newn->data = no;
                newn->next = NULL;

                temp = head;

                for(i = 1 ; i < ipos-1 ; i++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                temp->next = newn;

                iCount++;
            }
        }

        void DeleteAtPos(int ipos)
        {
            int i = 0;

            PNODE temp = NULL;
            PNODE target = NULL;

            if(ipos < 1 || ipos > iCount)
            {
                cout<<"Invalid position\n";
                return;
            }

            else if(ipos == 1)
            {
                DeleteFirst();
            }
            else if(ipos == iCount)
            {
                DeleteLast();
            }
            else
            {
                temp = head;

                for(i = 1 ; i < ipos-1 ; i++)
                {
                    temp = temp->next;
                }

                target = temp->next;

                temp->next = target->next;
                delete(target);

                iCount--;
            }
        }
};


int main()
{
    SinglyCL SCLobj;
    int iRet = 0;

    SCLobj.InsertFirst(51);
    SCLobj.InsertFirst(21);
    SCLobj.InsertFirst(11);

    SCLobj.InsertLast(101);
    SCLobj.InsertLast(111);
    SCLobj.InsertLast(121);

    SCLobj.Display();
    iRet = SCLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    
    SCLobj.InsertAtPos(75 , 4);
    SCLobj.Display();
    iRet = SCLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    
    SCLobj.DeleteAtPos(4);
    SCLobj.Display();
    iRet = SCLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}