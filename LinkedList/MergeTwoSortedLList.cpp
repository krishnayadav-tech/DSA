/*
Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
Note: It is strongly recommended to do merging in-place using O(1) extra space.
 */

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
Node* sortedMerge(struct Node* a, struct Node* b);
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
int main()
{
    int T,i,n1,n2,l,k;
    cin>>T;
    while(T--)
    {
        struct Node *head1 = NULL,  *tail1 = NULL;
        struct Node *head2 = NULL,  *tail2 = NULL;
        cin>>n1>>n2;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

Node* sortedMerge(struct Node* head, struct Node* head2)
{
    struct Node* final = NULL;
    struct Node* temp = NULL;
    struct Node* prep = NULL;
    while (head!=NULL && head2!=NULL) 
    { 
        if (head->data <= head2->data) 
        { 
            if(final == NULL)
                final = new Node(head->data); 
            else
                prep->next = new Node(head->data);
            head = head->next;
        } 
        else
        { 
            if(final == NULL)
                final = new Node(head2->data); 
            else
                prep->next = new Node(head2->data);
            head2 = head2->next;
        } 
        
        
        if(temp==NULL){
            temp = final;
            prep = final;
        }else{
            prep = prep->next;
        }
        
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (head != NULL) 
    { 
        prep->next = new Node(head->data);
        head = head->next; 
        
        if(temp==NULL){
            temp = final;
            prep = final;
        }else{
            prep = prep->next;
        }
    } 
  
    /* Copy the remaining elements of R[], if there 
      are any */
    while (head2 != NULL) 
    { 
        prep->next = new Node(head2->data);
        head2 = head2->next;
        
        if(temp==NULL){
            temp = final;
            prep = final;
        }else{
            prep = prep->next;
        }
    } 
    
    return temp;
}
