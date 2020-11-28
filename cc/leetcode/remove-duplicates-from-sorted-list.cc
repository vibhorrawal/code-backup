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
// O(n) time | O(1) space
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *ptr = dummy;
        dummy->next = head;
        while(ptr){
            ListNode *nxt = ptr;
            while(nxt and ptr->val == nxt->val) nxt = nxt->next;
            ptr->next = nxt;
            ptr = ptr->next;
        }
        return dummy->next;
    }
};
