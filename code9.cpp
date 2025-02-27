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

        void InsertAtPos(int no , int ipos)
        {}
        void DeleteAtPos(int ipos)
        {}

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

    DLLobj.DeleteFirst();

    DLLobj.Display();
    iRet = DLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    DLLobj.DeleteLast();

    DLLobj.Display();
    iRet = DLLobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
    
    return 0;
}