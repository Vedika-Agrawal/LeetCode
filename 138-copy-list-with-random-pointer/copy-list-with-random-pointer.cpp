/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    void copyll ( Node* head){
        if(!head)return ;
        Node* curr = head;
        while(curr){
            Node* temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }
    }
    
    void copyrp(Node* head){
        if(!head)return ;
        Node * curr = head;
      
        
        while(curr){
            if(curr->random)
            curr->next->random=curr->random->next;
           curr=curr->next->next; 
        }
        
    }
    
    
    
    
    
    Node* copyRandomList(Node* head) {
        
        
        copyll(head); 
        copyrp(head);
        
        Node* curr = head;
        Node* dummy = new Node(0);
        Node* curr2 =  dummy;
        
        while(curr){
            curr2->next = curr->next;
            curr2 = curr2->next;
            curr->next = curr->next->next;
            curr = curr->next;
        }
        
        return dummy->next;
        
        
    }
};