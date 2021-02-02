// O(n) time | O(1) space
bool solve(LLNode* head) {
    int prev = INT_MIN;
    while(head){
        if(head->val <= prev) return false;
        prev = head->val;
        head = head->next;
    }
    return true;
}
