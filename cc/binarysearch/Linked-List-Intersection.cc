// O(N + M) space time
LLNode* solve(LLNode* l0, LLNode* l1) {
    LLNode *dummy = new LLNode(-1);
    LLNode *ptr = dummy;
    while(l0 and l1) {
        if(l0->val == l1->val) {
            ptr->next = new LLNode(l0->val);
            ptr = ptr->next, l0 = l0->next, l1 = l1->next;
        } else if(l0->val < l1->val) {
            l0 = l0->next;
        } else {
            l1 = l1->next;
        }
    }
    return dummy->next;
}

// O(1) space by mutating i/p
LLNode* solve(LLNode* l0, LLNode* l1) {
    LLNode *dummy = new LLNode(-1);
    LLNode *ptr = dummy;
    while(l0 and l1) {
        if(l0->val == l1->val) {
            ptr->next = l0;
            ptr = ptr->next, l0 = l0->next, l1 = l1->next;
        } else if(l0->val < l1->val) {
            l0 = l0->next;
        } else {
            l1 = l1->next;
        }
    }
    ptr->next = NULL;
    return dummy->next;
}