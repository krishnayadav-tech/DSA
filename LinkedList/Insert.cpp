/*
Given a key (or data) to be inserted into the linked list of size N. The task is to insert the element at head or tail of the linked list depending on the input just before it p. If p is 0, then insert the element at beginning else insert at end.
*/

#include <iostream>
using namespace std;
/*Struct of linked list*/
struct Node {
  int data;
  struct Node *next;
  Node(int x) { //the constructor
    data = x;
    next = NULL;
  }
};
void printList(Node *head) { //function to print list
    Node *node = head;
    while (node != NULL) {
      cout << node -> data << ' ';
      node = node -> next;
    }
    cout << endl;
}
Node *insertAtBegining(Node *head, int newData);
Node *insertAtEnd(Node *head, int newData);
int main() {
  int test;
  cin >> test; //number of testcases input
  while (test--) { //while we have testcases we run the loop
    int n, ch, tmp;
    Node *head = NULL; //initially head is null as linked list is empty
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> tmp >> ch; 
      if (ch) head = insertAtEnd(head, tmp); 
      else head = insertAtBegining(head, tmp);
    }
    printList(head);
  }
  return 0;
}

Node *insertAtBegining(Node *head, int newData) {
   Node *tempnode = new  Node(newData);
   tempnode->next = head;
   head = tempnode;
   
   return head;
}
// function appends the data at the end of the list
Node *insertAtEnd(Node *head, int newData)  {
   Node *first = head;
   Node *tempnode = new Node(newData);

   if(head==NULL)
   {
       head = tempnode;
       first = head;
   }else{
       while(head->next != NULL){
        head = head->next;
       }
       head->next = tempnode;
   }
    
   return first;
}