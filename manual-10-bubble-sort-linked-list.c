#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node* next;
} *head=NULL;


void insert(int value)
{
    struct Node *newNode;
    newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data=value;

    if(head == NULL)
    {
        newNode->next=NULL;
        head=newNode;
    }
    else
    {
        newNode->next=head;
        head=newNode;
    }
}

void printList()
{
    if(head == NULL)
    {
        printf("\n List is empty !!");
    }
    else
    {
        struct Node *temp=head;

        while(temp->next != NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
}



void swap(struct Node *a, struct Node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

/***
void bubble_sort()
{
    int swapped;

    struct Node *temp;
    struct Node *lptr=NULL;

    if(head==NULL)
        return;


    do
    {
        swapped=0;
        temp=head;

        while(temp->next != lptr)
        {
            if(temp->data > temp->next->data)
            {
                swap(temp,temp->next);

                swapped=1;
            }

            temp=temp->next;
        }

        lptr=temp;

    }
    while(swapped);

}
**/

void bubble_sort(int n)
{
    int i,j;

    struct Node *temp;


    for(i=0;i<=n;i++)
    {
        temp=head;

        for(j=0;j< n-i-1;j++)
        {
            struct Node *p1=temp;
            struct Node *p2=p1->next;

            if(p1->data > p2->data)
            {
                swap(p1,p2);

            }
            temp=temp->next;
        }

    }

}


int main()
{
    int n,data,i;
    printf("Enter the list size: ");
    scanf("%d",&n);

    for (i=0; i<n; i++)
    {
        scanf("%d",&data);
        insert(data);
    }


    printf("Unsorted list: ");
    printList();

    bubble_sort(n);

    printf("\n\nSorted list: ");
    printList();

    return 0;
}


