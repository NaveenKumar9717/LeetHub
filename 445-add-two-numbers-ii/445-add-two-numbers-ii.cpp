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
    ListNode* make_list(string num1, string num2){
        // if(num[0] == '0')
        // return NULL;
        ListNode* head = NULL;
        ListNode* temp = NULL;
        ListNode* prev = NULL;
        int start_i  =  0; 
        int start_j  =  0;
        int carry = 0;
        while(start_i < num1.length() && start_j < num2.length()){
            int res = stoi(num1.substr(start_i,1)) + stoi(num2.substr(start_j,1)) + carry;
            temp = new ListNode(res%10);
            temp ->next = prev;
            prev = temp;
            carry = res/10;
            start_i++;
            start_j++;
        }
        
        while(start_i < num1.length()){
            int res = stoi(num1.substr(start_i,1)) + carry;
            temp = new ListNode(res%10);
            temp ->next = prev;
            prev = temp;
            carry = res/10;
            start_i++;
        }
        
        while(start_j < num2.length()){
            int res = stoi(num2.substr(start_j,1)) + carry;
            temp = new ListNode(res%10);
            temp ->next = prev;
            prev = temp;
            carry = res/10;
            start_j++;
        }
        
        if(carry){
          temp = new ListNode(1);      
          temp->next = prev;
        }
        
        return temp;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string num1 = "";
        string num2 = "";
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        
        
        while(head1){
            num1 += to_string(head1->val);
            head1 = head1->next;
        }
        
        while(head2){
            num2 += to_string(head2->val);
            head2 = head2->next;
        }
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        //return NULL;
        //string num_str = to_string(res);
        return make_list(num1,num2);
    }
};