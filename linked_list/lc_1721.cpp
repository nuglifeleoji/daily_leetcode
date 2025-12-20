class Solution {
    public:
        ListNode* swapNodes(ListNode* head, int k) {
            ListNode* dummy=new ListNode();
            dummy->next=head;
            ListNode* cur1=dummy;
            for(int i=0;i<k;i++){
                cur1=cur1->next;
            }
            ListNode* slow=dummy;
            ListNode* fast=dummy;
            for(int i=0;i<k;i++){
                fast=fast->next;
            }
            while(fast->next!=nullptr){
                fast=fast->next;
                slow=slow->next;
            }
            int g=cur1->val;
            cur1->val=slow->next->val;
            slow->next->val=g;
            return head;
        }
    };