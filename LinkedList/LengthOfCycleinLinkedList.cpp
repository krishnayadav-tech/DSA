/*
Given a linked list of size N. The task is to complete the function countNodesinLoop() that checks whether a given Linked List contains loop or not and if loop is present then return the count of nodes in loop or else return 0.
*/

#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
void append(struct Node** headRef, int data)
{
	struct Node* new_node = new Node (data);
	struct Node *last = *headRef;
	
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}
void printList(struct Node *tmp){
    while(tmp){
        cout<<tmp->data<<' ';
        tmp=tmp->next;
    }
    cout<<endl;
}
int countNodesinLoop(struct Node *head);

int main()
{
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        int n, tmp;
        cin>>n;
        struct Node *head = NULL;
        struct Node* temp;
        struct Node *s;
        struct Node *t;
        cin>>tmp;
        append(&head, tmp);
        s=head;
        for(int i=1; i<n; i++){
            cin>>tmp;
            append(&head, tmp);
        }
        
        int c;
        cin>>c;
        if(c>0){
           
            temp=head;
            t = head;
            while(t->next)t=t->next;
            while(c--)temp=temp->next;
            t->next=temp;
           
        }

        cout<<countNodesinLoop(head)<<endl;
	}
    return 0;
}

//Real Solution
struct newdata{
    int count = 0;
    Node* node;
    newdata(Node* node,int key)
    {
        count = key;
        this->node = node;
    }
};


newdata detectloop(Node *head) {
    unordered_set<Node*> abc;
    int count = 1;
    while(head != NULL){

        if(abc.find(head)==abc.end()){
            abc.insert(head);
        }else{
            
            return newdata((*abc.find(head)),count);
        }
        
        count++;
        head = head->next;
        
    }
    return newdata(head,0);
}

int countNodesinLoop(Node* head)
{
    auto data = detectloop(head);
    if(data.count == 0)
    {
        return 0;
    }
    int count = 0;
    while(head!=data.node)
    {
        head = head->next;
        count++;
    }
    return data.count - count - 1;
}
