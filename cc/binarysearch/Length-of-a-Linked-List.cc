/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
// O(n) time | O(1) space
int solve(LLNode* node) {
    int count = 0;
    while(node){
        node = node->next;
        count++;
    }
    return count;
}

// O(n) time and space
int solve(LLNode* node) {
    if(not node) return 0;
    return 1 + solve(node->next);
}
