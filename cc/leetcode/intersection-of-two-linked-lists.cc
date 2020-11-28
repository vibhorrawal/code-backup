/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// O(n) time | O(1) space | modifying the given list
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1 = headA, *l2 = headB;
        if(!l1 || !l2) return NULL;
        while(headA) {
            headA->val *= -1;
            headA = headA -> next;
        }
        ListNode *ans;
        while(headB){
            if(headB -> val < 0) {
                if(!ans) ans = headB;
            }
            headB = headB -> next;
        }
        headA = l1;
        while(headA) {
            headA->val *= -1;
            headA = headA -> next;
        }
        return ans;
    }
};


// O(n) time | O(1) space
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA;
        ListNode *pb = headB;
        if(!pa || !pb) return NULL;
        while(pa->next) pa = pa->next;
        while(pb->next) pb = pb->next;
        if(pa != pb) return NULL;
        pa = headA;
        pb = headB;
        while (pa != pb) {
            pa = (pa->next != NULL) ? pa->next : headB;
            pb = (pb->next != NULL) ? pb->next : headA;
        }
        return pa;
    }
};
