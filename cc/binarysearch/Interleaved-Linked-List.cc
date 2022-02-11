// O(N) time | O(1) space
// iterative
LLNode* solve(LLNode* l0, LLNode* l1) {
    if(not l0) return l1;
    LLNode *head = l0;
    l0 = l0->next;
    LLNode *ptr = head;
    while(l0 and l1){
        ptr->next = l1;
        l1 = l1->next;
        ptr = ptr->next;
        
        ptr->next = l0;
        l0 = l0->next;
        ptr = ptr->next;
    }
    if(l0) ptr->next = l0;
    if(l1) ptr->next = l1;
    return head;
}

// recursive O(N) space
LLNode* solve(LLNode* l0, LLNode* l1) {
    if(!l0) return l1;
    if(!l1) return l0;
    LLNode *next = l0->next;
    l0->next = l1;
    solve(l1, next);
    return l0;
}

// cleaner recursive
LLNode* solve(LLNode* l0, LLNode* l1) {
    if(!l0 || !l1) return l0 ? l0 : l1;
    solve(l1, l0->next);
    l0->next = l1;
    return l0;
}

// oomphf 
LLNode* solve(LLNode* l0, LLNode* l1) {
    if(!l0 || !l1) return l0 ? l0 : l1;
    l0->next = solve(l1, l0->next);
    return l0;
}