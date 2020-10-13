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
// mergesort O(nlogn) time | O(logn) space
class Solution {
    int depth(ListNode *head){
        int l = 0;
        while(head != NULL){
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode *findMid(ListNode *head){
        int m = depth(head)/2;
        if(m == 0) return head;
        ListNode *ptr = head;
        m--;
        while(m-- > 0) ptr = ptr->next;
        head = ptr->next;
        ptr->next = NULL;
        return head;
    }
    ListNode *merge(ListNode *p1, ListNode *p2){
        ListNode *head = new ListNode(-1);
        ListNode *ptr = head;
        while(p1 && p2){
            if(p1->val < p2->val){
                ptr->next = p1;
                p1 = p1->next;
            }
            else{
                ptr->next = p2;
                p2 = p2->next;
            }
            ptr = ptr->next;
        }
        if(p1) ptr->next = p1;
        if(p2) ptr->next = p2;
        return head->next;
    }
    void display(ListNode *head){
        if(head == NULL) return;
        cout<<head->val<<' ';
        display(head->next);
    }

    ListNode *mergesort(ListNode *head){
        if(head == NULL || head->next == NULL) return head;
        ListNode *mid = findMid(head);
        head = mergesort(head);
        mid = mergesort(mid);
        return merge(head, mid);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};

// bottom up / iterative
class Solution {
    ListNode *tail = new ListNode();
    ListNode *nextSubList = new ListNode();

     int getCount(ListNode* head) {
        int cnt = 0;
        ListNode* ptr = head;
        while (ptr) {
            ptr = ptr->next;
            cnt++;
        }
        return cnt;
    }

    void merge(ListNode *p1, ListNode *p2){
        ListNode *head = new ListNode(-1);
        ListNode *ptr = head;
        while(p1 && p2){
            if(p1->val < p2->val){
                ptr->next = p1;
                p1 = p1->next;
            }
            else{
                ptr->next = p2;
                p2 = p2->next;
            }
            ptr = ptr->next;
        }
        if(p1) ptr->next = p1;
        if(p2) ptr->next = p2;
        tail->next = head->next;
        while(tail->next) tail = tail->next;
    }
    ListNode *split(ListNode *start, int size){
        ListNode *mid_prev = start, *end = start->next;
        for(int i = 1; i < size && (mid_prev->next || end->next); i++){
            if(end->next) end = (end->next->next) ? end->next->next : end->next;
            if(mid_prev->next) mid_prev = mid_prev->next;
        }
        ListNode *mid = mid_prev->next;
        nextSubList = end -> next;
        mid_prev -> next = NULL;
        end->next = NULL;
        return mid;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        int n = getCount(head);
        ListNode *start = head, *dummyHead = new ListNode(0);
        for(int size = 1; size < n; size *= 2){
            tail = dummyHead;
            while(start){
                if(start->next == NULL){
                    tail->next = start;
                    break;
                }
                ListNode *mid = split(start, size);
                merge(start, mid);
                start = nextSubList;
            }
            start = dummyHead -> next;
        }
        return dummyHead->next;
    }
};
