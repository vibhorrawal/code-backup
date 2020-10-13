/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    string res;
    vector<int> v;
    void dfs(TreeNode *root){
        if(root == NULL) return;
        res += to_string(root->val) + ',';
        dfs(root->left);
        dfs(root->right);
    }
    void buildBST(TreeNode *node, int val){
        if(val < node->val) {
            if(node->left) buildBST(node->left, val);
            else node->left = new TreeNode(val);
        }
        else{
            if(node->right) buildBST(node->right, val);
            else node->right = new TreeNode(val);
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        res = "";
        dfs(root);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;
        stringstream ss(data);
        string t;
        while(getline(ss, t, ',')){
            v.push_back(stoi(t));
        }
        TreeNode *root = new TreeNode(v[0]);
        for(int i = 1; i < v.size(); i++){
            buildBST(root, v[i]);
        }
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
