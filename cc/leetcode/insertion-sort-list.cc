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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(INT_MIN);
        ListNode *ptr, *loopPtr = head;
        while(loopPtr) {
            ptr = loopPtr;
            loopPtr = loopPtr->next;

            ListNode *toPlace = dummy;
            while(toPlace->next && toPlace->next-> val < ptr->val) toPlace = toPlace->next;
            ListNode *temp = toPlace->next;
            toPlace->next = ptr;
            ptr->next = temp;
        }
        return dummy->next;
    }
};
