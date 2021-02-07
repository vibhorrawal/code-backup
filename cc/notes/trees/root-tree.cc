class TreeNode {
public:
    int val;
    TreeNode *parent;
    vector<TreeNode *> child;

    TreeNode(int index) {
        val = index;
    }

    TreeNode(int index, TreeNode *parent_){
        val = index;
        parent = parent_;
    }
}

TreeNode *build_tree(vvi g, TreeNode *root, TreeNode *parent){
    for(int v : g[root->val]) {
        if(parent and v == parent->val) continue;
        TreeNode *child = new TreeNode(v, root);
        root->child.push_back(child);
        build_tree(g, child, root);
    }
    return root;
}
TreeNode *root_tree(vvi g, int u){
    TreeNode *root = new TreeNode(u);
    return build_tree(g, root, NULL);
}
