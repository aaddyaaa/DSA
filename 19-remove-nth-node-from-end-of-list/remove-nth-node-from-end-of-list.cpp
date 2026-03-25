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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        for (int i = 0;i<n ;i++){
            first = first->next; //n+1th node from start if n=2 then 3rd node
        }
        if(first == NULL) return head->next;
        while(first->next){
            second = second->next; // 1 node prior to nth node from last
            first = first->next;
        }
        second->next = second->next->next;
        return head;

    }
};