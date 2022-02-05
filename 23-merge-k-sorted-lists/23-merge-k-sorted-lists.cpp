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
struct CompareHeight {
    bool operator()(ListNode* p1, ListNode* p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1->val >= p2->val;
    }
};

class Solution {
public:
    void print(priority_queue<ListNode*, vector<ListNode*>, CompareHeight>& qu){
    ListNode* head = qu.top();
   while(qu.empty() == false){
       cout<<qu.top()->val<<endl;
       qu.pop();
   }
 
}
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         ListNode* head = NULL;
        if(lists.size() == 0)
            return head;
      
        priority_queue<ListNode*, vector<ListNode*>, CompareHeight> qu;
       for(int i  =0; i<lists.size();i++){
           if(lists[i])
           qu.push(lists[i]);
       }
     //  print(qu); 
        ListNode*curr = NULL;
      while(qu.empty() == false){
         
          if(head ==NULL){
              head = qu.top();
              curr = head;
              }
            else{
                curr->next = qu.top();
                curr = curr->next;
            }
          qu.pop();
          if(curr != NULL && curr->next != NULL)
             qu.push(curr->next);
      }  
     return head;
    }
};