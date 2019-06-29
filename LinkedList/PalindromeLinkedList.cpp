#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
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
bool isPalindrome(Node *head);

int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

#include <vector>
using namespace std;
bool palindrome(vector<int> arr) 
{ 
    int n = arr.size();
    int flag = 0; 
    for (int i = 0; i <= n / 2 && n != 0; i++) { 
        if (arr[i] != arr[n - i - 1]) { 
            flag = 1; 
            break; 
        } 
    } 
  
   
    if (flag == 1) 
        return false;
    else
        return true;
} 


bool isPalindrome(Node* head)
{
    vector<int> abc;
    while(head!=NULL)
    {
        abc.push_back(head->data);
        head = head->next;
    }

    return palindrome(abc);
}