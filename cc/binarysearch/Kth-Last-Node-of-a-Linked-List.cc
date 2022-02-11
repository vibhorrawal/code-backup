// O(N) time | O(1) space
int solve(LLNode* node, int k) {
    LLNode *ptr = node;
    while(k-- >= 0) ptr = ptr->next;
    while(ptr){
        ptr = ptr->next;
        node = node->next;
    }
    return node->val;
}