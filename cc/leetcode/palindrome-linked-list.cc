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
O(n) time | O(1) space
class Solution {
    int length(ListNode* head){
        int l = 0;
        while(head){
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode *reverse(ListNode *head){
        ListNode *next,*prev,*curr;
        curr = head;
        prev = NULL;
        while(curr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        int l = length(head);
        ListNode *ptr = head;
        if(l & 1) l++;
        l /= 2;
        l--;
        while(l--) ptr = ptr->next;
        ptr->next = reverse(ptr->next);
        ptr = ptr->next;
        while(ptr){
            if(head->val != ptr->val)
                return false;
            head = head->next;
            ptr = ptr->next;
        }
        return true;
    }
};
