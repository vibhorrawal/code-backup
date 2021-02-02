int solve(LLNode* node) {
    int num = 0;
    while(node){
        num = num << 1;
        num = num | node->val;
        node = node->next;
    }
    return num;
}
