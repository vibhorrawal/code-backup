// O(N) time | O(1) space
// modifying i/p
LLNode *findMid(LLNode *node){
    LLNode *fast = node, *slow = node;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

LLNode* reverse(LLNode *node){
    LLNode *curr = node, *prev = NULL, *next;
    while(curr){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void print(LLNode* node){ 
    if(node == NULL){
        cout<<endl;
        return;
    }
}
bool solve(LLNode* node) {
    LLNode *mid = findMid(node);
    cout<<mid->val<<endl;
    LLNode *rev = reverse(mid);
    // print(rev);
    for(LLNode *i = node, *j = rev; i && j; i = i->next, j = j->next){
        if(i->val != j->val)
            return false;
    }
    return true;
}

// without modifying
// O(N) space
LLNode *buildList(LLNode *node) {
    LLNode *list_ptr = new LLNode(-1);
    LLNode *ptr = list_ptr;
    while(node) {
        ptr->next = new LLNode(node->val);
        ptr = ptr->next;
        node = node->next;
    }
    return list_ptr;
}

LLNode *reverseList(LLNode *node) {
    node = buildList(node);
    LLNode *prev = NULL, *curr = node, *next = NULL;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool solve(LLNode* node) {
    LLNode *reverse = reverseList(node);
    while(node) {
        if(node->val != reverse->val) return false;
        node = node->next;
        reverse = reverse->next;
    }
    return true;
}

// cleaner O(N)
LLNode *reverseList(LLNode *node) {
    LLNode *ptr = NULL;
    while(node) {
        LLNode *temp = new LLNode(node->val);
        temp->next = ptr;
        ptr = temp;
        node = node->next;
    }
    return ptr;
}

bool solve(LLNode* node) {
    LLNode *reverse = reverseList(node);
    while(node) {
        if(node->val != reverse->val) return false;
        node = node->next;
        reverse = reverse->next;
    }
    return true;
}

// even cleaner
bool solve(LLNode* node) {
    LLNode *ptr = node;
    stack<LLNode *> st;
    while(ptr) {
        st.push(ptr);
        ptr = ptr->next;
    }
    while(node) {
        ptr = st.top(); st.pop();
        if(node->val != ptr->val) return false;
        node = node->next;
    }
    return true;
}