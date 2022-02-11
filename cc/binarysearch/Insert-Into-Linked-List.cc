// O(N) time | O(1) space
LLNode* solve(LLNode* head, int pos, int val) {
    LLNode *dummy = new LLNode(-1), *ptr;
    dummy->next = head;
    ptr = dummy;
    while(pos-- > 0) ptr = ptr->next;
    LLNode* ins = new LLNode(val);
    ins->next = ptr->next;
    ptr->next = ins;
    return dummy->next;
}