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
    void print( Node* head){
        while(head){
            if(head->random)
            cout<<head->val<<" rand--> "<<head->random->val<<endl;
            else
             cout<<head->val<<" rand--> "<<"null"<<endl;
            head = head->next;
        }
    }
    Node* copyRandomList(Node* head) {
        Node*dummy = new Node(55555);
        Node* temp =  dummy;
        unordered_map<Node*,Node*>mp;
        Node*last = dummy;
        Node* head1 = head;
        
        while(head1){
          temp->next  = new Node(head1->val);
          temp = temp ->next;
          mp[head1] = temp;
          head1 = head1->next;
        }
        head1 = head;
        while(head1){
          if(head1->random != NULL){
             // cout<<"came inside "<<mp[head1]->val<<endl;
              mp[head1]->random = mp[head1->random];
          }
          head1 = head1->next;  
        }
        //print(dummy->next);
        return dummy->next;
    }
};