//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{ 
public:

void print(Node* head , string k = "")
{
    cout << k << " ";
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    
}

    void merge(Node* head, Node* head1 , Node* head2){
        head = new Node(-1);
        while(head1 || head2){
            if(head1){
                head->next = head1;
                head1 = head1->next;
                head = head->next;
            }
            
            if(head2){
                head->next = head2;
                head2 = head2->next;
                head = head->next;
            }
        }
        
        head = head->next;
    }
    
    Node* reverse(Node* head){
        // Node* dummy = new Node(-1);
        Node* prev = nullptr;
        
        while(head){
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
    void reorderList(Node* head) {
        // Your code here
        if(head->next == nullptr || head->next->next == nullptr) return;
        Node* head1 = head;
        Node* head2 = head;
        Node* prev = nullptr;
        
        while(head && head->next){
            prev = head2;
            head2 = head2->next;
            head = head->next->next;
        }
        
        if(head != nullptr ){
            prev = head2;
        head2 = head2->next;
        }
        
        prev->next = nullptr;
        
        // print(head1 , "h1 ->");
        // print(head2 , "h2 ->");
        head2 = reverse(head2);
        // /**/print(head2 , "Reverse h2 ->");
        
        merge(head , head1 , head2);
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends