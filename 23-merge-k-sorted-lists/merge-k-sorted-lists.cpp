class Solution {
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <ListNode* , vector<ListNode*> , Compare> pq;
        for (ListNode* node : lists){
            if (node) pq.push(node);
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next){
                pq.push(node->next);
            }
        }
        return dummy.next;
    }
};