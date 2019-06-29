#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


Node* mergeSort(Node* head);

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("");
}
void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int main() {

    freopen("input.txt","r",stdin);
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}

//incomplete function
// Node* sortedMerge(struct Node* head,int left,int middle,int right)
// {
//     struct Node* head;
//     struct Node* head2;
//     struct Node* final = NULL;
//     struct Node* temp = NULL;
//     struct Node* prep = NULL;
//     while (head!=NULL && head2!=NULL) 
//     { 
//         if (head->data <= head2->data) 
//         { 
//             if(final == NULL)
//                 final = new Node(head->data); 
//             else
//                 prep->next = new Node(head->data);
//             head = head->next;
//         } 
//         else
//         { 
//             if(final == NULL)
//                 final = new Node(head2->data); 
//             else
//                 prep->next = new Node(head2->data);
//             head2 = head2->next;
//         } 
        
        
//         if(temp==NULL){
//             temp = final;
//             prep = final;
//         }else{
//             prep = prep->next;
//         }
        
//     } 
  
    
//     while (head != NULL) 
//     { 
//         prep->next = new Node(head->data);
//         head = head->next; 
        
//         if(temp==NULL){
//             temp = final;
//             prep = final;
//         }else{
//             prep = prep->next;
//         }
//     } 
  
   
//     while (head2 != NULL) 
//     { 
//         prep->next = new Node(head2->data);
//         head2 = head2->next;
        
//         if(temp==NULL){
//             temp = final;
//             prep = final;
//         }else{
//             prep = prep->next;
//         }
//     } 
    
//     return temp;
// }

// void mergeSort(Node* head, int l, int r) 
// { 
//     if (l < r) 
//     { 
//         int m = l+(r-l)/2;  
//         mergeSort(head, l, m); 
//         mergeSort(head, m+1, r); 
//         sortedMerge(head, l, m, r);
//     } 
// } 


//complete and bullshit solution 
Node* mergeSort(Node* head) {
    vector<int> abc;
    while(head!=NULL){
        abc.push_back(head->data);
        head = head->next;
    }

    sort(abc.begin(),abc.end());
    Node* node = new Node(abc[0]);
    Node* temp = node;
    for(int i=1;i<abc.size();i++){
        node->next = new Node(abc[i]);
        node = node->next;
    }
    return temp;
}
