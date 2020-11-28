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
// O(n + m) time | O(n + m) space
class Solution {
    int len(ListNode *root){
        if(root == NULL) return 0;
        return 1 + len(root->next);
    }
public:
    ListNode* add(ListNode *l1, ListNode *l2, int carry){
        if(l2 == NULL){
            if(carry){
                if(l1 == NULL) return new ListNode(carry);
                int d = l1->val + carry;
                carry = d / 10;
                l1 -> val = d % 10;
                l1->next = add(l1->next,l2,carry);
                return l1;
            }
            return l1;
        }
        int d = l1->val + l2->val + carry;
        carry = d / 10;
        d %= 10;
        l1 -> val = d;
        l1->next = add(l1->next, l2->next, carry);
        return l1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(len(l1) > len(l2)) return add(l1,l2,0);
        else return add(l2,l1,0);
    }
};
