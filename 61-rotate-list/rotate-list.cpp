class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k==0) return head;
        int len = 1;
        ListNode* temp = head;
        while(temp->next){
            temp = temp->next;
            len++;
        }
        temp->next = head;
        k = k%len;
        int step = len - k;

        ListNode* newtail = head;
        for(int i = 1;i<step;i++){
            newtail = newtail->next;
        }
        ListNode* newhead = newtail->next;
        newtail->next = NULL;
        return newhead;
    }
};