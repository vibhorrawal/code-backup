// O(N) space time
bool solve(Tree* root0, Tree* root1) {
        if (root0 == NULL && root1 == NULL) return true;
        if (root0 == NULL || root1 == NULL) return false;
        if (root0->val != root1->val) return false;
        return solve(root0->left, root1->left) && solve(root0->right, root1->right);
}