/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            if (a != nullptr) {
                a = a->next;
            } else {
                a = headB; // switch to head of B after finishing A
            }

            if (b != nullptr) {
                b = b->next;
            } else {
                b = headA; // switch to head of A after finishing B
            }
        }

        return a; // can be nullptr or the intersection node
    }
        
};