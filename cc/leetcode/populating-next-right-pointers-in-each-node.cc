// O(n) time | O(log(n)) space
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL || root->left == NULL || root->right == NULL)
            return root;
        
        root->left->next = root->right;
        if(root->next)
            root->right->next = root->next->left;
        
        connect(root->left);
        connect(root->right);
        return root;
    }
};

// O(n) time | O(n) space

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> que;
        Node *head = root;
        que.push(root);
        while(!que.empty()){
            int level = que.size();
            Node *prev = NULL;
            while(level--){
                root = que.front(); que.pop();
                if(root == NULL)
                    continue;
                if(prev == NULL)
                    prev = root;
                else{
                    prev-> next = root;
                    prev = root;
                }
                que.push(root->left);
                que.push(root->right);
            }
        }
        return head;
    }
};
