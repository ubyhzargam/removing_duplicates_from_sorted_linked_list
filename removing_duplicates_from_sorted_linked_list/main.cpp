//
//  main.cpp
//  removing_duplicates_from_sorted_linked_list
//
//  Created by Uby H on 18/07/23.
//

#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*last=NULL;
void create(int x)
{
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=t;
        last=t;
    }
    else
    {
        last->next=t;
        last=t;
    }
}
void display(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void remdup(struct Node *p)
{
    struct Node *last;
    struct Node *q;
    last=p;
    int x=p->data;
    p=p->next;
    while(p!=NULL)
    {
        if(x==p->data)
        {
            q=p;
            p=p->next;
            continue;
        }
        else
        {
            x=p->data;
            last->next=p;
            last=p;
            p=p->next;
        }
    }
    if(q->data==x)
        last->next=NULL;
}
int main()
{
    int n,x;
    cout<<"Enter the number of elements in the linked list : "<<endl;
    cin>>n;
    cout<<"Enter the elements in the linked list : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;create(x);
    }
    cout<<"The original array is given by : "<<endl;
    display(first);
    cout<<"The updated array is given by : "<<endl;
    remdup(first);
    display(first);
    return 0;
}
