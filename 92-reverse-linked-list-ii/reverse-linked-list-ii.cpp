class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        dummy->next = head;
        for(int i = 1;i<left;i++){
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        ListNode* prevv = NULL;
        ListNode* tail = curr;
        for(int i =0; i<right-left+1;i++){
            ListNode* front = curr->next;
            curr->next = prevv;
            prevv = curr;
            curr = front;
        }
        prev-> next = prevv;
        tail-> next = curr; // if this was simple reverse my curr would have been null
        return dummy->next;
    }
};