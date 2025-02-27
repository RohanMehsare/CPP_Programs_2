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
typedef struct node** PPNODE;

class DoublyLL
{
    public:
        PNODE head;
        int iCount;

        DoublyLL()
        {
            head = NULL;
            iCount = 0;
        }

        void InsertFirst(int no )
        {
            PNODE newn = NULL;

            newn = new NODE; 

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                newn->next = head;
                head->prev = newn;   //$
                head = newn;
            }

            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE; 

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                temp = head;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = newn;
                newn->prev = temp;   //$
                
            }
            iCount++;
        }

        void DeleteFirst()
        {
           PNODE temp = NULL;

           if(head == NULL)
           {
              return;
           }
           else if(head->next == NULL)
           {
              delete head;
              head = NULL;
           }
           else
           {
              temp = head;

              head = head->next;
              head->prev = NULL;   //$
              delete temp;
           }

           iCount--;

           /*  we can also use This else part without using temp pointer
    
              else
              {
                 *head = (*head)->next;
                 free((*head)->prev);
                 (*head)->prev = NULL;
              }
       
           */
        }

        void DeleteLast()
        {
            PNODE temp = NULL;

            if(head == NULL)
            {
              return;
            }
            else if(head->next == NULL)
            {
              delete head;
              head = NULL;
            }
            else
            {
                temp = head;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }

                delete temp->next;
                temp->next = NULL;
            }
            iCount--;
        }

        void Display()
        {
            PNODE temp = NULL;

            temp = head;

            cout<<"NULL <=>";

            while(temp != NULL)
            {
                cout<<"|"<<temp->data<<"| <=>";
                temp = temp->next;
            }

            cout<<"NULL\n";
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

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            if(ipos < 1 || ipos > iCount+1)
            {
                cout<<"Invalid position \n";
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
                temp = head;

                for(i = 1 ; i < ipos-1 ; i++)
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

        void DeleteAtPos(int ipos)
        {
            int i = 0;

            PNODE temp = NULL;
            PNODE target = NULL;
            
            if(ipos < 1 || ipos > iCount)
            {
                cout<<"Invalid position \n";
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
                temp->next = temp->next->next;
                temp->next->prev = temp;
                delete target;
                
                iCount--;
            }
        }

};

int main()
{
    DoublyLL DLLobj;
    int iRet = 0;
    
    DLLobj.InsertFirst(51);
    DLLobj.InsertFirst(21);
    DLLobj.InsertFirst(11);

    DLLobj.InsertLast(101);
    DLLobj.InsertLast(111);
    DLLobj.InsertLast(121);

    DLLobj.Display();
    iRet = DLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    DLLobj.InsertAtPos(71 , 4);

    DLLobj.Display();
    iRet = DLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    DLLobj.DeleteAtPos(4);

    DLLobj.Display();
    iRet = DLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}