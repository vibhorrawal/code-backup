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
        ListNode *early, *late, *dummy = new ListNode();
        dummy -> next = head;
        early = dummy;
        while(n--) early = early -> next;

        late = dummy;
        while(early->next){
            early = early -> next;
            late = late -> next;
        }
        late -> next = late -> next -> next;
        return dummy-> next;
    }
};
