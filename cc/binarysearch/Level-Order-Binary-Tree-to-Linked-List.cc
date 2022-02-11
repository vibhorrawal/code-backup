// O(N) space time
LLNode* solve(Tree* root) {
    LLNode *dummy = new LLNode;
    queue<Tree*> q;
    q.push(root);
    LLNode *ptr = dummy;
    while(!q.empty()){
        root = q.front(); q.pop();
        if(not root) continue;
        ptr -> next = new LLNode(root->val);
        ptr = ptr->next;
        q.push(root->left);
        q.push(root->right);
    }
    return dummy->next;
}