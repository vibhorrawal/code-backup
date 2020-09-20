/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// O(n) time | O(1) space
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head, *ptr = head;
        
        while(true){
            if(fast == NULL || fast -> next == NULL)
                return NULL;
            
            fast = fast -> next -> next;
            slow = slow -> next;
            
            if(fast == slow)
                break;
        }
        int count = 0;
        while(true){
            fast = fast -> next -> next;
            slow = slow -> next;
            count++;
            if(fast == slow)
                break;
        }
        while(count--) ptr = ptr->next;
        slow = head;
        while(slow != ptr) {
            ptr = ptr->next;
            slow = slow ->next;
        }
        return slow;
    }
};

// floyd hare and tortoise
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head, *ptr = head;
        // slow -> x
        // fast -> 2 * x
        // x =  |-d-| + p  [p = (loop - remaining) ; where length of list => d + loop]
        // 2x = 2d + 2p
        // but fast: d + p + r + p which is 2x
        // 2d + 2p = d + 2p + r
        // therefore r = d
        // move ptr from start -> d, slow from its position -> r :: intersect at origin of loop
        while(true){
            if(fast == NULL || fast -> next == NULL)
                return NULL;
            
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow)
                break;
        }
        
        while(ptr != slow) {
            ptr = ptr->next;
            slow = slow->next;
        }
        return ptr;
    }
};