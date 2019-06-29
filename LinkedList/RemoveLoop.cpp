/* You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present.

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


void removeTheLoop(Node *head);

 Node* insert(Node* head, int data)
{
    if (head == NULL)
        head = new Node(data);
    else
        head->next = insert(head->next, data);
    return head;
}
 void makeLoop(Node* head, int x)
{
    if (x == 0)
        return;
    Node* curr = head;
    Node* last = head;
    int counter = 0;
    while (counter < x)
    {
        curr = curr->next;
        counter++;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = curr;
}
 int detectloop(Node* head)
{
    Node* hare = head->next;
    Node* tortoise = head;
    while (hare != tortoise && hare != NULL && tortoise != NULL)
    {
        hare = hare->next;
        tortoise = tortoise->next;
        if (hare != NULL && hare->next != NULL)
            hare = hare->next;
        if (hare == tortoise)
            return 1;
    }
    if (hare == tortoise)
        return 1;
    return 0;
}
 int length(Node* head, bool hasloop)
{
    int len = 0;
    if (hasloop == false)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    else
    {
        Node* hare = head->next;
        Node* tortoise = head;
        while (hare != tortoise)
        {
            hare = hare->next;
            tortoise = tortoise->next;
            hare = hare->next;
            if (hare == tortoise)
                break;
        }
       
        int looplen = 0;
        while (hare->next!=tortoise)
        {
            hare = hare->next;
            looplen++;
        }
        
        looplen++;
        Node* begin = head;
        int startlen = 0;
        tortoise = tortoise->next;
        while (begin != tortoise)
        {
            
            begin = begin->next;
            tortoise = tortoise->next;
            startlen++;
        }
        
        return looplen + startlen;
        
    }
}

int main() {

    freopen("input.txt","r",stdin);
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *head=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
            head=insert(head,arr[i]);
            
        }
        int x;
        cin>>x;
        makeLoop(head,x);
        int lengthll=0;
        if(detectloop(head)==1)
        lengthll=length(head,true);
        else
        lengthll=length(head,false);
        
        removeTheLoop(head);
        
        if (detectloop(head) == 0 && lengthll == length(head, false))
        {
            cout<<1<<endl;
        }
        else
        cout<<0<<endl;
    }
	return 0;
}

//functional problem

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


newdata detectloop2(Node *head) {
    unordered_set<Node*> abc;
    Node* prev = head;
    int count = 1;
    while(head != NULL){

        if(abc.find(head)==abc.end()){
            abc.insert(head);
        }else{
            
            return newdata(prev,count);
        }
        
        count++;
        prev = head;
        head = head->next;
        
    }
    return newdata(head,0);
}




void removeTheLoop(Node *head)
{
     auto got = detectloop2(head);
     if(got.count == 0)
        return;
     while(head!=got.node)
     {
         head = head->next;
     }

     head->next = NULL;
}