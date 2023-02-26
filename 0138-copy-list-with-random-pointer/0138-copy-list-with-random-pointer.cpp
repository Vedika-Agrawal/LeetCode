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
    void copyll(Node* & head){
        if(!head) return ;
        Node* node = head;
        // while(curr){
        //     Node * node = new Node(curr->val);
        //     node->next = curr->next;
        //     curr->next = node;
        //     curr = node->next;
        // }
        while(node){
        Node* temp=node->next;
        node->next=new Node(node->val);
        node->next->next=temp;
        node=temp;
    }
    }
    void copyrp(Node* & head){
        if(!head)return ;
        Node* node = head;
        // while(curr){
        //     curr->next->random = curr->random ? curr->random->next:NULL;
        //     curr= curr->next->next;
        // }
        while(node){
            if(node->random)
            node->next->random=node->random->next;
           node=node->next->next; // go to next old node
        }
}
        
    
    Node* copyRandomList(Node* head) {
        copyll(head); 
        copyrp(head);
        
//         Node*ori =head;
//         Node* clone = head->next ,* nhead = head->next;
        
//         while(ori){
//             ori->next=ori->next->next;
//             clone->next = clone->next? clone->next->next: NULL;
//             ori = ori->next;
//             clone = clone->next;
//         }
        
//         return nhead;
        
        Node* ans=new Node(0); // first node is a dummy node
        Node* helper=ans;

        while(head){
            // Copy the alternate added nodes from the old linklist
            helper->next=head->next;
            helper=helper->next;

            // Restoring the old linklist, by removing the alternative newly added nodes
            head->next=head->next->next;
            head=head->next; // go to next alternate node   
        }
        return ans->next; 
    }
};