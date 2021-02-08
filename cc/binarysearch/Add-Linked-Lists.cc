LLNode* solve(LLNode* l0, LLNode* l1) {
    LLNode *head = new LLNode;
    LLNode *ptr = head;
    int carry = 0, sum = 0;
    while(l0 or l1){
        if(not l0){
            sum = l1->val + carry;
            l1 = l1->next;
        }
        else if(not l1){
            sum = l0->val + carry;
            l0 = l0->next;
        }
        else {
            sum = l0->val + l1->val + carry;
            l0 = l0->next;
            l1 = l1->next;
        }
        carry = sum / 10;
        sum %= 10;
        ptr->next = new LLNode(sum);
        ptr = ptr->next;
    }
    if(carry) ptr->next = new LLNode(carry);
    return head->next;
}

// iterative
LLNode* solve(LLNode* l0, LLNode* l1) {
    int carry = 0;
    LLNode *dummy = new LLNode(), *ptr = dummy;
    while(l0 or l1 or carry) {
        int d = (l0 ? l0->val : 0) + (l1 ? l1->val : 0) + carry;
        carry = d / 10;
        ptr-> next = new LLNode(d % 10);
        ptr = ptr->next;
        if(l0) l0 = l0->next;
        if(l1) l1 = l1->next;
    }
    return dummy->next;
}

// recursive
LLNode* add(LLNode* l0, LLNode* l1, int carry) {
    if (not l0 and not l1 and not carry) return nullptr;
    int d = (l0 ? l0->val : 0) + (l1 ? l1->val : 0) + carry;
    carry = d / 10;

    return new LLNode(d % 10, add((l0 ? l0->next : l0), (l1 ? l1->next : l1), carry));
}

LLNode* solve(LLNode* l0, LLNode* l1) {
    return add(l0, l1, 0);
}
