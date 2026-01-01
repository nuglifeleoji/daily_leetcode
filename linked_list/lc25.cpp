class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* cur = head;
            for (int i = 0; i < k; i++) {
                if (cur == nullptr) return head;
                cur = cur->next;
            }
            ListNode* nextGroup = reverseKGroup(cur, k);
            ListNode* prev = nullptr;
            ListNode* curr = head;
            for (int i = 0; i < k; i++) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head->next = nextGroup;
            return prev;
        }
    };