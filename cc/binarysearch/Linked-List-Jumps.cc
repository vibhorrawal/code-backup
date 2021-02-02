/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
// O(n) time | O(1) space
LLNode* solve(LLNode* node) {
    LLNode *dummy = new LLNode;
    dummy -> val = 1;
    dummy -> next = node;
    int jump;
    LLNode *ptr = dummy;
    while(ptr){
        ptr = ptr->next;
        if(ptr == NULL) break;
        LLNode *temp = ptr;
        jump = ptr->val - 1;
        while(ptr && jump-- > 0) ptr = ptr->next;
        temp -> next = ptr ? ptr -> next : NULL;
    }
    return dummy -> next;
}

LLNode* solve(LLNode* head) {
    LLNode *ptr = head;
    while(ptr){
        int jump = ptr->val;
        LLNode *curr = ptr;
        while(jump-- > 0 and ptr) ptr = ptr-> next;
        curr -> next = ptr;
    }
    return head;
}
