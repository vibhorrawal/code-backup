/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */

// O(N) time | O(N) recursive stack space
LLNode* solve(LLNode* node) {
    if(not node or not node->next) return node;
    
    LLNode *ptr = node;
    while(ptr->next->next) ptr = ptr->next;
    LLNode *t = ptr->next;
    ptr->next = NULL;
    t->next = node;
    node->next = solve(node->next);
    return t;
}


// cleaner & O(1) space if reverse and interleave is done iterative (trivial)
LLNode *reverse(LLNode *node){
    if(not node or not node->next) return node;
    
    LLNode *ptr = reverse(node->next);
    node->next->next = node;
    node->next = NULL;
    return ptr;
}

LLNode *interleave(LLNode *m, LLNode *n){
    if(not n) return m;
    if(not m) return n;
    
    LLNode *ptr = m->next;
    m->next = n;
    n->next = interleave(ptr, n->next);
    return m;
}

LLNode *cut_middle(LLNode *node){
    LLNode *slow = node, *fast = node;
    while(fast and fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    LLNode *ptr = slow->next;
    slow->next = NULL;
    return ptr;
}

LLNode* solve(LLNode* node) {
    if(not node or not node->next) return node;
    
    LLNode *ptr = cut_middle(node);
    ptr = reverse(ptr);
    return interleave(ptr, node);
}