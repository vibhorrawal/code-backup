#include<bits/stdc++.h>
using namespace std;

class AVL {
    class Node {
    public:
        int balance_factor, value, height;
        Node *left, *right;
        Node(int val) : value(val), left(nullptr), right(nullptr), height(0) {}
        Node(int val, Node *l, Node *r) : value(val), left(l), right(r), height(0) {}
    };

    Node *root = nullptr;
    int node_count = 0;

    int compare(int a, int b){
        if(a < b) return -1;
        if(a == b) return 0;
        return 1;
    }

    bool contains(Node *node, int val){
        if(node == NULL) return false;
        int cmp = compare(val, node->value);
        if(cmp < 0) return contains(node->left, val);
        if(cmp > 0) return contains(node->right, val);
        return true;
    }

    Node *insert(Node *node, int val){
        if(node == nullptr){
            return new Node(val);
        }

        if(compare(val, node->value) < 0)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);

        update(node);
        return balance(node);
    }

    void update(Node *node){
        int left_node_height = node->left ? node->left->height : -1;
        int right_node_height = node->right ? node->right->height : -1;

        node->height = 1 + max(left_node_height, right_node_height);
        node->balance_factor = right_node_height - left_node_height;
    }

    Node *balance(Node *node){
        if(node->balance_factor == -2){ // left heavy
            if(node->left->balance_factor <= 0) // left left case
                return left_left_case(node);
            else
                return left_right_case(node);
        }
        else if(node->balance_factor == 2){
            if(node->right->balance_factor >= 0)
                return right_right_case(node);
            else
                return right_left_case(node);
        }
        return node; // has bf == -1 or 0 or +1
    }

    Node *left_left_case(Node *node) { return right_rotation(node); }
    Node *right_right_case(Node *node) { return left_rotation(node); }
    Node *left_right_case(Node *node){
        node->left = left_rotation(node->left);
        return right_rotation(node);
    }
    Node *right_left_case(Node *node){
        node->right = right_rotation(node->right);
        return left_rotation(node);
    }

    Node *left_rotation(Node *node){
        Node *new_parent = node->right;
        node->right = new_parent->left;
        new_parent->left = node;
        update(node);
        update(new_parent);
        return new_parent;
    }

    Node *right_rotation(Node *node){
        Node *new_parent = node->left;
        node->left = new_parent->right;
        new_parent->right = node;
        update(node);
        update(new_parent);
        return new_parent;
    }

    Node *remove(Node *node, int val){
        if(node == nullptr) return node;
        int cmp = compare(val, node->value);
        if(cmp < 0){
            node->left = remove(node->left, val);
        }
        else if(cmp > 0){
            node->right = remove(node->right, val);
        }
        else {
            if(node->left == nullptr) {
                Node *node_child = node->right;
                delete(node);
                return node_child;
            }
            else if(node->right == nullptr) {
                Node *node_child = node->left;
                delete(node);
                return node_child;
            }
            else{
                if(node->left->height > node->right->height){
                    int successor_val = find_max(node->left);
                    node->value = successor_val;
                    node->left = remove(node->left, successor_val);
                }
                else{
                    int successor_val = find_min(node->right);
                    node->value = successor_val;
                    node->right = remove(node->right, successor_val);
                }
            }
        }
        update(node);
        return balance(node);
    }

    int find_max(Node *node){
        while(node->right) node = node->right;
        return node->value;
    }

    int find_min(Node *node){
        while(node->left) node = node->left;
        return node->value;
    }

    bool validate(Node *node){
        if(node == nullptr) return true;
        if(node->left and node->value < node->left->value)
            return false;
        if(node->right and node->value > node->right->value)
            return false;
        return validate(node->left) and validate(node->right);
    }
public:

    AVL(){ node_count = 0; root = NULL; }
    int height(){
        if(root == nullptr) return 0;
        return root->height;
    }

    int size() { return node_count; }
    bool contains(int val) { return contains(root, val); }

    bool insert(int val){
        if(contains(val)) return false;
        root = insert(root, val);
        node_count++;
        return true;
    }

    bool remove(int val){
        if(not contains(val)) return false;
        root = remove(root, val);
        node_count--;
        return true;
    }

    bool validate_BST_invariant(){
        return validate(root);
    }

    vector<int> inorder(){
        cout << "inorder" << endl;
        stack<Node *> st;
        vector<int> res;
        Node *node = root;
        while(node or st.size()){
            while(node){
                st.push(node);
                node = node->left;
            }
            node = st.top(); st.pop();
            res.push_back(node->value);
            node = node->right;
        }
        return res;
    }
};

int32_t main(int argc, char const *argv[]){
    AVL t;
    for (int i = -5e2; i < 5e6; i++) {
        t.insert(i);
        t.insert(i * i);
        t.remove(i);
    }
    // db(t.size());
    // db(t.inorder());
    assert(t.validate_BST_invariant());
    return 0;
}
