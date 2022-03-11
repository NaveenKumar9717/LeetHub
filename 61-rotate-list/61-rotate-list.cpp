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
    int Listlen(ListNode* head, int & l){
        //int l = 0;
        while(head){
            head = head->next;
            l++; 
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0 || head->next == NULL)
            return head;
        int len = 0;
        Listlen(head,len);
        int keff = (k%len);
        if(keff == 0)
            return head;
        
        ListNode* nexthead = NULL;
        ListNode* newhead = NULL;
        ListNode* temp = head;
        int pos = 1;
        while(pos < (len - keff)){
          temp = temp->next;
          pos++;
        }
        nexthead = temp->next;
        temp->next = NULL;

        //reaching to the last node second remaing list
        temp = nexthead;
        while(temp->next)
          temp = temp->next;
        
        temp->next = head;

        return nexthead;
    }
};