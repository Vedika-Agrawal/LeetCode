//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *oh= NULL, *ot = NULL, *th, *tt , *curr, *fwd=NULL;
    
    void addFirst(struct node* root){
        root->next= NULL;
        if(tt==NULL){
            th = root;
            tt = root;
        
        }
        else{
            root->next = th;
        th = root;
        }
        
        
    }
    
    struct node *reverse (struct node *head, int k)
    { 
        curr = head;
        int ok = k ;
        while(curr){
           th=NULL, tt=NULL;
            k = ok;
            while(curr && k-- ){
                fwd = curr->next;
                addFirst(curr);
                curr = fwd;
            }
            if(oh==NULL){
                oh = th;
                ot= tt;
            }
            else{
                ot->next = th;
                ot = tt;
            }
        }
        return oh;
        
        
        
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends