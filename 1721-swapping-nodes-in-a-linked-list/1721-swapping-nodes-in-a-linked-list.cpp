/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
      ListNode* first = head;
      ListNode* second = head;
      
      ListNode* temp = head; 
      int steps = 1;
      while(temp){
          if(steps < k){
            first = first->next;  
          }
          
          if(steps > k){
             second = second->next; 
          }
          steps++;
          temp = temp->next;
      }
      int tm = first->val;  
      first->val = second->val;
      second->val = tm;
        
      return head;  
        
    }
};