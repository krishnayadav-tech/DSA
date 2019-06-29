//Problem Statement
/* Given a singly linked list of size N, and an integer K, you need to swap the Kth node from beginning and Kth node from end in linked list.
Note: You need to swap the nodes and not change the content of the nodes. */


#include <iostream>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
void append(Node** head_ref, Node **tail_ref, int new_data)
{
    Node* newnode = new Node(new_data);
    
    if(*head_ref == NULL)
        *head_ref = newnode;
    else
        (*tail_ref)->next = newnode;
    *tail_ref = newnode;
}
Node *swapkthnode(Node* head, int num, int K);
void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}
bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K;
        cin>>num>>K;
        int temp;
        Node* head = NULL;
        Node* tail = NULL;
        for(int i = 0; i<num; i++){
            cin>>temp;
            append(&head, &tail, temp);
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}

Node *swapkthnode(Node* head, int N, int K)
{
    
    // if K is greater than N simply return head
    if(K > N){
        return head;
    }


    int kthe = N - K + 1;
    int kths = K;
    
    int mine = min(kthe,kths);
    int maxe = max(kthe,kths);
    
    
    
    Node* minp = head;
    for(int i=0;i<mine-2;i++){
        minp = minp->next;
    }
    
    Node* maxp = head;
    for(int i=0;i<maxe-2;i++){
        maxp = maxp->next;
    }
    
    if(mine==1){

        Node* temp = maxp->next;
        temp->next = head->next;
        maxp->next = head;
        maxp->next->next = NULL;
        head = temp;

    }else{

        Node* temp = maxp->next;
        Node* temp2 = minp->next;
        Node* temp3 = minp->next->next;
        Node* temp4 = maxp->next->next;
        minp->next = temp;
        minp->next->next = temp3;
        maxp->next = temp2;
        maxp->next->next = temp4;

    }
    return head;
}
