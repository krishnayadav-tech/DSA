//Problem Statement
/* Find the kth node from end */
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

int getNthFromLast(struct Node* head, int n);
int main()
{
  int T,i,n,l,k;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
    printf("%d", getNthFromLast(head, k));
    cout << endl;
    }
    return 0;
}


//Real function
int getNthFromLast(Node *head, int n)
{
    int count = 0;
    Node* temp = head;
    while(head!=NULL)
    {
        count++;
        head = head->next;
    }
    
    int nth = count - n + 1;
    
    if(nth < 0)
    {
        return -1;
    }
    for(int i=1;i<nth;i++)
    {
        temp = temp->next;
    }
    return temp->data;
}