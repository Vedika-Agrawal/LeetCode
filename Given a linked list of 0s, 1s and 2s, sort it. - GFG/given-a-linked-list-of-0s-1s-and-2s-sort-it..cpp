//{ Driver Code Starts
#include <bits/stdc++.h>

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

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
   Node* segregate(Node *head) {
        
        // Add code here
        Node* zh=NULL,*zt=NULL,*oh=NULL,*ot=NULL,*th=NULL,*tt=NULL;
        while(head){
            if(head->data==1){
                Node* t=head->next;
                if(!oh){
                    oh=head;
                    ot=head;
                }
                else{
                    ot->next=head;
                    ot=head;
                }
                ot->next=NULL;
                head=t;
            }
            else if(head->data==2){
                Node* t=head->next;
                if(!th){
                    th=head;
                    tt=head;
                }
                else{
                    tt->next=head;
                    tt=head;
                }
                tt->next=NULL;
                head=t;
            }
            else{
                Node* t=head->next;
                if(!zh){
                    zh=head;
                    zt=head;
                }
                else{
                    zt->next=head;
                    zt=head;
                }
                zt->next=NULL;
                head=t;
            }
        }
        if(zt){
            zt->next=oh;
        }
        if(ot){
            ot->next=th;
        }
        if(!ot && zt){
            zt->next=th;
        }
        if(tt)
            tt->next=NULL;
        if(zh){
            return zh;
        }
        if(oh){
            return oh;
        }
        return th;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends