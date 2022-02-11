/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */

// O(N) time and space; recursive
LLNode* solve(LLNode* node, int target) {
    if(not node) return node;
    if(node->val == target) return solve(node->next, target);
    node->next = solve(node->next, target);
    return node;
}

// O(N) time | O(1) space; iterative
LLNode* solve(LLNode* node, int target) {
    LLNode *dummy = new LLNode;
    dummy->next = node;
    node = dummy;
    while(node){
        if(node->next and node->next->val == target)
            node->next = node->next->next;
        else node = node->next;
    }
    return dummy->next;
}