//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    
    void print(struct Node* node){
        while(node != nullptr){
        cout << node->data << " ";
        node = node->next;
        }
        cout << endl;
    } 
    
    Node* reverse(struct Node* node){
        Node* prev = nullptr;
        while(node){
            Node* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
    void rearrange(struct Node *odd)
    {
        //add code here
        Node* head = new Node(-1);
        Node* dummy = head;
        
        Node* prev = odd;
        while(odd){
            Node* upnext = nullptr;
            if(odd->next) {
                   upnext = odd->next->next;
            dummy->next = odd->next;
            dummy = dummy->next;
            dummy->next = nullptr;
            }
         
            odd->next = upnext;
            prev = odd;
            odd = odd->next;
        }
        
        // print(head);
        head = reverse(head->next);
        // print(head);
        
        while(head){
            prev->next = head;
            head = head->next;
            prev = prev->next;
        }
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends