#include <iostream>
#include <string>
#include<stack>
using namespace std;
struct TreeNode{
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c) : data(c), left(nullptr), right(nullptr) {}
};

TreeNode* createTree(const string& s, int& index) {
    if (index >= s.length()) return nullptr;  // 字符串结束
    char ch = s[index++];
    if (ch == '#') return nullptr;            // 空子树
    TreeNode* node = new TreeNode(ch);        // 创建根结点
    node->left = createTree(s, index);        // 递归构建左子树
    node->right = createTree(s, index);       // 递归构建右子树
    return node;
}

void visit(TreeNode* p){
    cout<<(p->data)<<" ";
}

void preOrder(TreeNode* root){
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* p = st.top();
        st.pop();
        visit(p);
        if (p->right) st.push(p->right);
        if (p->left) st.push(p->left);
    }
    
}

void inOrder(TreeNode* root){
    stack<TreeNode*>st;
    TreeNode* p=root;
    while(p!=nullptr||!st.empty){
        while(p!=nullptr){
            st.push(p);
            p=p->left;
        }
        p=st.top();
        st.pop();
        visit(p);
        p=p->right;
    }
}

void postOrder(TreeNode* root){
    if (root == nullptr) return;
    stack<TreeNode*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        TreeNode* p = s1.top();
        s1.pop();
        s2.push(p);               
        if (p->left) s1.push(p->left);   
    }
    while (!s2.empty()) {
        visit(s2.top());
        s2.pop();
    }
}


int main() {
    string s;
    cin >> s;
    int index = 0;
    TreeNode* root = createTree(s, index);
    preOrder(root);
    cout << endl;      
    return 0;
}