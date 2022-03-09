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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head ->next)
            return head;
        
        ListNode* dummy = new ListNode(999);
        ListNode* temp = dummy;
        
        while(head && head->next){
            if(head->val != head->next->val){
                temp->next = head;
                temp = temp->next;
                head = head->next;
            
            }
            else{ temp->next = NULL;
                int rep = head->val;
                while( head && head->val == rep )
                    head = head->next;
            }
        }
        if(head){
            temp->next = head;
            temp = temp->next;
        }
        return dummy->next;
    }
};