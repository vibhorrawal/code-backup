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

// O(n) time | O(1) space iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev, *curr, *next;
        prev = NULL;
        curr = head;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

// recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if( head == NULL || head->next == NULL)
            return head;
        ListNode *node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
};