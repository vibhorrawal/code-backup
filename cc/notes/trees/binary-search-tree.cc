#include<bits/stdc++.h>
using namespace std;

template<typename T> class BST {
    class Node {
    public:
        T data;
        Node *left, *right;

        Node(T elem){
            data = elem;
            left = right = nullptr;
        }

        Node(T elem, Node *left, Node *right){
            data = elem;
            this->left = left;
            this->right = right;
        }
    };

    Node *root = nullptr;
    int node_count = 0;

    int compare(T &a, T &b){
        if(a < b) return -1;
        if(a == b) return 0;
        return 1;
    }

    Node *add(Node *node, T &elem){
        if(node == nullptr)
            return new Node(elem);
        if(compare(elem, node->data) < 0)
            node->left = add(node->left, elem);
        else
            node->right = add(node->right, elem);
        return node;
    }

    Node *remove(Node *node, T &elem){
        if(node == nullptr) return nullptr;
        if(compare(elem, node->data) < 0){
            node->left = remove(node->left, elem);
        }
        else if(compare(elem, node->data) > 0){
            node->right = remove(node->right, elem);
        }
        else{
            if(node->left == nullptr){ // either child node or right tree
                Node *right_child = node->right;
                free(node);
                return right_child;
            }
            else if(node->right == nullptr){
                Node *left_child = node->left;
                free(node);
                return left_child;
            }
            else{
                Node *temp = find_min(node->right); // Node *temp = find_max(node->left);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }
        return node;
    }

    Node *find_min(Node *node){
        while(node->left) node = node->left;
        return node;
    }

    Node *find_max(Node *node){
        while(node->right) node = node->right;
        return node;
    }

    bool contains(Node *node, T &elem){
        if(node == nullptr) return false;
        if(compare(elem, node->data) < 0)
            return contains(node->left, elem);
        if(compare(elem, node->data) > 0)
            return contains(node->right, elem);
        return true;
    }

    int height(Node *node){
        if(node == nullptr) return 0;
        return max(height(node->left), height(node->right)) + 1;
    }

    bool is_bst(Node *node, T &min_elem, T &max_elem){
        if(node == nullptr) return true;
        if(not (min_elem < node->data and node->data < max_elem))
            return false;
        return is_bst(node->left, min_elem, node->data)
            and is_bst(node->right, node->data, max_elem);
    }
public:
    int size(){ return node_count; }
    bool empty(){ return node_count == 0; }
    bool contains(T elem) { return contains(root, elem); }
    int height() { return height(root); }
    bool is_bst(T min_elem, T max_elem) { return is_bst(root, min_elem, max_elem); }

    bool add(T elem){
        if(contains(elem)) return false;
        root = add(root, elem);
        node_count++;
        return true;
    }

    bool remove(T elem){
        if(not contains(elem)) return false;
        root = remove(root, elem);
        node_count--;
        return true;
    }

    vector<T> preorder() {
        if(node_count == 0) return {};
        stack<Node *> st;
        vector<T> res;
        st.push(root);
        while(st.size()){
            Node *node = st.top(); st.pop();
            res.push_back(node->data);

            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return res;
    }

    vector<T> inorder(){
        stack<Node *> st;
        vector<T> res;
        Node *node = root;
        while(node or st.size()){
            while(node){
                st.push(node);
                node = node->left;
            }
            node = st.top(); st.pop();
            res.push_back(node->data);
            node = node->right;
        }
        return res;
    }

    vector<T> postorder(){
        if(node_count == 0) return {};
        stack<Node *> st;
        vector<T> res;
        st.push(root);
        while(st.size()){
            Node *node = st.top(); st.pop();
            res.push_back(node->data);

            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<T> levelorder(){
        if(node_count == 0) return {};
        queue<Node *> q;
        q.push(root);
        vector<T> res;
        while(q.size()){
            Node *node = q.front(); q.pop();
            res.push_back(node);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return res;
    }
};

int32_t main(int argc, char const *argv[]){
    BST<int> tree;
    for(int i : {5,-1,5,4,2,5,3,5,5}) tree.add(i);

    tree.remove(3);
    tree.remove(50);

    for(int d : tree.inorder()) cout<<d<<' '; cout<<endl;

    for (int i = 0; i < 1e6; i++) {
        tree.add(i * i);
        tree.add(-i);
        tree.remove(i);
        if(i % 1000) cout<<"iter: "<<i<<endl;
    }

    cout<<tree.height()<<endl;
    assert(tree.is_bst(INT_MIN, INT_MAX));

    return 0;
}
