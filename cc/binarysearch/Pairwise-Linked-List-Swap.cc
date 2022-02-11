// O(N) space time
LLNode* solve(LLNode* root) {
    if(not root) return NULL;
    if(not root->next) return root;
    int t = root->val;
    root->val = root->next->val;
    root->next->val = t;
    solve(root->next->next);
    return root;
}

// O(N) time | O(1) space
// list-> [0,1,3,4]
LLNode* solve(LLNode* node) {
    LLNode *dummy = new LLNode(-1);
    dummy->next = node;
    LLNode *ptr = dummy;
    while(ptr && ptr->next && ptr->next->next) {
        LLNode 
            *next_to_next_to_next = ptr->next->next->next, // 3
            *next_to_next = ptr->next->next, // 1
            *next = ptr->next; // 0
        
        ptr->next = next_to_next;
        next_to_next->next = next;
        next->next = next_to_next_to_next;
        ptr = next;
    }
    return dummy->next;
}

// cleaner
LLNode* solve(LLNode* node) {
    LLNode *dummy = new LLNode(-1);
    dummy->next = node;
    LLNode *ptr = node;
    while(ptr && ptr->next) {
        swap(ptr->val, ptr->next->val);
        ptr = ptr->next->next;
    }
    return dummy->next;
}