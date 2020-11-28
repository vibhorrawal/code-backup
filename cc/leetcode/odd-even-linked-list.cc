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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *ptr = head, *odd = new ListNode, *even = new ListNode;
        ListNode *eptr = even, *optr = odd;
        int i = 1;
        while(ptr){
            if(i++ & 1){
                optr -> next = ptr;
                optr = optr -> next;
            }
            else{
                eptr -> next = ptr;
                eptr = eptr -> next;
            }
            ptr = ptr -> next;
        }
        optr -> next = even -> next;
        eptr->next = NULL;
        return odd -> next;
    }
};
