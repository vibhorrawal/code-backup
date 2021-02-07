// this is alternative to
/*
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
   if(not root or root == p or root == q) return root;
   TreeNode *l = lowestCommonAncestor(root->left, p, q);
   TreeNode *r = lowestCommonAncestor(root->right, p, q);
   if(l and r) return root;
   if(l) return l;
   return r;
}
*/

https://github.com/williamfiset/Algorithms/blob/master/src/main/java/com/williamfiset/algorithms/graphtheory/treealgorithms/LowestCommonAncestorEulerTour.java
