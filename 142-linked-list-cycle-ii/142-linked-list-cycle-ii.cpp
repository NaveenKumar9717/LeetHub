/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycleH(ListNode *head){
        unordered_map<ListNode*,int>mp;
        int i = 0 ;
        ListNode* temp = head ;
        while(temp){
             mp[temp]  = i;
           // cout<<temp->val<<endl;
            if(mp.find(temp->next) != mp.end()){
                return temp->next;
            }
            temp = temp->next;
            i++;
        }
        //ListNode* ans = new ListNode(-1);
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        return detectCycleH(head);
    }
};