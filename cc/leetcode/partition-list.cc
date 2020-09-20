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
    ListNode* partition(ListNode* head, int x) {
        ListNode *less = new ListNode(-1), *greater = new ListNode(-1);
        ListNode *ptr = head;
        ListNode *lh = less, *gh = greater;
        while(ptr != NULL){
            if(ptr->val < x){
                less->next = ptr;
                less = less->next;
            }
            else{
                greater->next = ptr;
                greater = greater->next;
            }
            ptr = ptr->next;
        }
        greater->next = NULL;
        less->next = gh->next;
        head = lh->next;
        return head;
    }
};
