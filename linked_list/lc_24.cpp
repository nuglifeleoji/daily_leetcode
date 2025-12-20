class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if(head==nullptr || head->next==nullptr) return head;
            ListNode* next=swapPairs(head->next->next);
            ListNode* m1=head->next;
            m1->next=head;
            head->next=next;
            return m1;
        }
    };