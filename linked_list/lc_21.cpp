class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* cur1=list1;
            ListNode* cur2=list2;
            ListNode* dummy=new ListNode();
            ListNode* cur=dummy;
            while(cur1!=nullptr && cur2!=nullptr){
                if(cur1->val < cur2->val){
                    ListNode* next=cur1->next;
                    cur1->next=nullptr;
                    cur->next=cur1;
                    cur=cur->next;
                    cur1=next;
                }
                else{
                    ListNode* next=cur2->next;
                    cur2->next=nullptr;
                    cur->next=cur2;
                    cur=cur->next;
                    cur2=next;
                }
            }
            while(cur1!=nullptr){
                ListNode* next=cur1->next;
                    cur1->next=nullptr;
                    cur->next=cur1;
                    cur=cur->next;
                    cur1=next;
            }
            while(cur2!=nullptr){
                 ListNode* next=cur2->next;
                    cur2->next=nullptr;
                    cur->next=cur2;
                    cur=cur->next;
                    cur2=next;
            }
            return dummy->next;
        }
    };