// O(N ^ 2) time and O(N) space
Tree *t;

bool check(Tree *target, Tree *tt){
   if(target == NULL)
       return tt == NULL;
   if(tt == NULL) return false;
   if(target->val != tt->val)
       return false;

   return (check(target->left, tt->left) && check(target->right, tt->right))
       || (check(target->left, tt->right) && check(target->right, tt->left));

}
bool dfs(Tree *target){
   if(target == NULL)
       return t == NULL;
   if(check(target, t)) return true;
   return dfs(target->left) || dfs(target->right);
}
bool solve(Tree* source, Tree* target) {
   t = source;
   return dfs(target);
}
