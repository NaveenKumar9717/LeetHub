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
    ListNode* Merge(ListNode* head1, ListNode* head2){
         ListNode* newhead = NULL ;
         ListNode* temp1 = head1;
         ListNode* temp2 = head2;
         ListNode* temp =   NULL;
        while(temp1 && temp2){
        if(temp1->val < temp2->val){
        if(newhead == NULL){
            newhead = temp1;
            temp = temp1 ;
            temp1 = temp1->next;
        }
        else{
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
            }       
        }
        else{
             if(newhead == NULL){
              newhead = temp2;
              temp = temp2 ;
              temp2 = temp2->next;
            }
        else{
            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
            }                
         }   
        }
        
    while(temp1){
        temp->next = temp1;
        temp = temp->next;
        temp1 = temp1->next;
    } 
      while(temp2){
        temp->next = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }    
        
        return newhead;
    }
    ListNode* MergeSort(ListNode* head){
       if(head == NULL || head->next == NULL)
           return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && slow && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* nexthead = slow->next; 
        slow->next = NULL;
        
        ListNode* left  =  MergeSort(head);
        ListNode* right =  MergeSort(nexthead);
        return Merge(left,right);
    }
    ListNode* sortList(ListNode* head) {
        return MergeSort(head);
    }
};