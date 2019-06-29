/* Given a linked list of N nodes. The task is to check if the the linked list has a loop. Linked list can contain self loop. */

#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
void push(struct Node **head_ref, int new_data) {
    struct Node *new_Node = new Node(new_data);
    new_Node->next = (*head_ref);

    (*head_ref) = new_Node;
}
int detectloop(struct Node *list);

int main() {

    freopen("input.txt","r",stdin);
    int t, n, c, x, i;
    cin >> t;
    while (t--) {

        cin >> n;
        struct Node *head = NULL;
        struct Node *temp;
        struct Node *s;
        cin >> x;
        push(&head, x);
        s = head;
        for (i = 1; i < n; i++) {
            cin >> x;
            push(&head, x);
        }

        cin >> c;
        if (c > 0) {
            c = c - 1;
            temp = head;
            while (c--) temp = temp->next;
            s->next = temp;
        }
        int g = detectloop(head);
        if (g)
            cout << "True";
        else
            cout << "False";
        
        cout << '\n';
    }
    return 0;
}


//function to detect loop
int detectloop(Node *head) {
    unordered_set<Node*> abc;
    while(head != NULL){

        if(abc.find(head)==abc.end()){
            abc.insert(head);
        }else{
            return 1;
        }
        head = head->next;
    }

    return 0;
}