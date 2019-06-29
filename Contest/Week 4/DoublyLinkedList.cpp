/*
Given a doubly linked with each of the previous pointer assigned to null. Your task is to assign previous pointer to each of previous nodes respectively.

Input Format : 
First line of input contains number of testcases T.  For each testcase, first line of input contains length of linked list N and next line contains elements of linked list L[i].

Output Format : 
For each testcase, print linked list in reverse order as per sample output shown below.

Task : Given all the other driver and utility  functions. Your task is to complete function to convert to doubly.



*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    
};
struct Node *newNode(int key){
    struct Node *temp=new Node;
    temp->data=key;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
struct Node *insertNode(struct Node *head,int key)
{
    if(head==NULL)
    head=newNode(key);
    else
    {
        head->next=insertNode(head->next,key);
    }
    return head;
}
void makeDoubly(struct Node *);
void traverse(struct Node *head)
{
    for(struct Node *temp=head;temp!=NULL;temp=temp->next)
    cout<<temp->data<<" ";
    cout<<endl;
}
void printBack(struct Node *head)
{
    if(head==NULL)
    return;
    struct Node *temp=head;
    while(temp->next)
    temp=temp->next;
    
    while(temp!=head)
    {
        cout<<temp->data<<" <- ";
        temp=temp->prev;
    }
    cout<<temp->data;
    cout<<endl;
}
int main() {

    freopen("input.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
	    struct Node *head=NULL;
	    int n;
	    cin>>n;
	    while(n--)
	    {
	        int x;
	        cin>>x;
	        head=insertNode(head,x);
	    }
	    // traverse(head);
	    makeDoubly(head);
	    printBack(head);
	    
	}
	return 0;
}

void makeDoubly(struct Node *head)
{
    Node* prev = NULL;
    Node* temp = head;
    while(head!=NULL)
    {
        head->prev = prev;
        prev = head;
        head = head->next;
    }
}


/*

Input:
1
5
1 2 3 4 5
Output:
5 <- 4 <- 3 <- 2 <- 1 (single spaces on back and rear of each arrow)


*/