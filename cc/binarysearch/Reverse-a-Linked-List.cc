// O(N) space time
// recursive
LLNode* solve(LLNode* node) {
    if(not node or not node->next) return node;
    LLNode* ptr = solve(node->next);
    node->next->next = node;
    node->next = NULL;
    return ptr;
}

// O(1) space
// iterative
LLNode* solve(LLNode* node) {
    LLNode *prev = NULL, *curr = node, *next;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}