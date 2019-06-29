/*
Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Input Format:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list and next line contains linked list elements and last line contains k, by which linked list is to be rotated.

Output Format:
For each testcase, print the rotated linked list.

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
Node *rotate(struct Node *head, int k);
Node *insert() {
    int n, i, value;
    struct Node *temp, *head = NULL;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> value;
        if (i == 0) {
            head = new Node(value);
            temp = head;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
    return head;
}
void printList(Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("");
}
int main(void) {
    int t, k;
    scanf("%d", &t);
    while (t--) {
        Node *head = insert(); // insert function to build linked list
        scanf("%d", &k);
        head = rotate(head, k); // rotate linked list anti-clockwise  by k nodes
        printList(head);        // print linked list after rotation
    }
    return (0);
}

Node* rotate(Node* head, int k) {

    int count = 1;
    Node* temp = head;
    Node* temp2 = NULL;
    Node* temp3 = NULL;
    
    Node* forcount = head;
    while(forcount->next!=NULL ){
        forcount = forcount->next;
        count++;
    }
    
    
    k = k % count;
    
    if(k==0)
        return temp;
    
    count = 1;
    while(head->next!=NULL ){
        
        if(count==k){
            temp2 = head;
            temp3 = head->next;
        }
        head = head->next;
        count++;
    }
    
    head->next = temp;
    temp2->next = NULL;
    return temp3;
    
}


/*
Sample Input 

2
8
1 2 3 4 5 6 7 8
4
5
2 4 7 8 9
3

*/


/*
Output

5 6 7 8 1 2 3 4
8 9 2 4 7

*/