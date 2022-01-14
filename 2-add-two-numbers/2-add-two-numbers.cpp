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
//     void makelist(ListNode*l1,ListNode*head,ListNode*tail){
        
//     }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*head = NULL;
        ListNode*tail = NULL;
        int carry = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            ListNode* temp = new ListNode(sum%10);
            if(head == NULL)
            {
              head = temp;
              tail = temp;
            }
            else{
             tail->next = temp;
             tail = tail->next;
            }
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1){
            int sum = l1->val + carry;
            ListNode* temp = new ListNode(sum%10);
            if(head == NULL)
            {
              head = temp;
              tail = temp;
            }
            else{
             tail->next = temp;
             tail = tail->next;
            }
            carry = sum/10;
            l1 = l1->next;
        }
        while(l2){
            int sum = l2->val + carry;
            ListNode* temp = new ListNode(sum%10);
            if(head == NULL)
            {
              head = temp;
              tail = temp;
            }
            else{
             tail->next = temp;
             tail = tail->next;
            }
            carry = sum/10;
            l2 = l2->next;
        }
        if(carry){
            ListNode* temp = new ListNode(carry);
            if(head == NULL)
            {
              head = temp;
              tail = temp;
            }
            else{
             tail->next = temp;
             tail = tail->next;
            }
        }
        return head;
    }
};