/*
Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.
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
		Node *head = NULL;
                Node *temp = head;
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
    Node* temp = root;
    Node* prep = root;
    while(root->next!=NULL){
        
        prep = root;
        root = root->next;
        if(prep->data == root->data)
        {
            while(prep->data == root->data && root->next != NULL){
                root = root->next;
            }
            
            if(root->next==NULL){
                if(root->data  == prep->data)
                    prep->next = NULL;
                else
                    prep->next = root;
            }else{
                prep->next = root;
            }
            
        }
    }
    
    return temp;
}