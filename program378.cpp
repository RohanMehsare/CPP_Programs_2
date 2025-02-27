#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;

class stack
{
    public:
        PNODE head;
        int iCount;

        stack()
        {
            head = NULL;
            iCount = 0;
        }

        void push(int no)  
        {}

        int pop()
        {}

        void Display()
        {}

        int Count()
        {
            return iCount;
        }
};

int main()
{

    return 0;
}