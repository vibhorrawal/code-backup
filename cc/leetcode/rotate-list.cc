// O(n) time | O(1) space
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL || head -> next == NULL)
            return head;
        ListNode *tail, *newHead, *newTail;
        tail = head;
        int len = 1;
        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }
        k = k % len;
        k = len - k;
        tail->next = head;
        newTail = head;
        if(k == 0) return head;
        k--;
        while(k--) newTail = newTail ->next;
        newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};
