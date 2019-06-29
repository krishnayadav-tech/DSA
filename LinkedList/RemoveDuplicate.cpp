/*
Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. If all the nodes in the linked list are equal, then remove n-1 nodes.
*/


#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}
Node* removeDuplicates(Node *root);
int main() {
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}



Node *removeDuplicates(Node *root)
{
    vector<int> abc;
    while(root!=NULL){
        abc.push_back(root->data);
        root = root->next;
    }
    
    Node* curr = new Node(abc[0]);
    Node* temp = curr;
    for(int i=1;i<abc.size();i++){
        for(int j=0;j<i;j++){
            if(abc[j]==abc[i]){
                break;
            }
            if(j==i-1){
                temp->next = new Node(abc[i]);
                temp = temp->next;
            }
        }
    }
    
    return curr;
}