
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node to simplify edge cases
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;
        ListNode* curr = head;

        while (true) {
            // Check if there are at least k nodes left to reverse
            ListNode* temp = curr;
            for (int i = 0; i < k; i++) {
                if (!temp) return dummy.next;
                temp = temp->next;
            }

            // Reverse k nodes
            ListNode* prev = NULL;
            ListNode* tail = curr;  // Will become the tail after reverse

            for (int i = 0; i < k; i++) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Connect previous group with newly reversed group
            prevGroup->next = prev;
            tail->next = curr;

            // Move prevGroup pointer to the tail of the newly reversed group
            prevGroup = tail;
        }

        return dummy.next;
        
    }
};