class Solution {
    public:
        ListNode* deleteMiddle(ListNode* head) {
            ListNode* dummy=new ListNode();
            if(head->next==nullptr){
                return nullptr;
            }
            dummy->next=head;
            ListNode* prev=dummy;
            ListNode* fast=head;
            ListNode* slow=head;
            while(fast!=nullptr && fast->next!=nullptr){
                fast=fast->next->next;
                slow=slow->next;
                prev=prev->next;
            }
            prev->next=prev->next->next;
            return head;
        }
    };