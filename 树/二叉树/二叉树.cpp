#include <iostream>
#include <string>

using namespace std;

// 二叉树结点定义
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c) : data(c), left(nullptr), right(nullptr) {}
};

// 根据广义前序字符串创建二叉树
// 参数 s: 广义前序字符串，例如 "AB..C.."
// 参数 index: 当前处理的字符位置，需要引用传递以便递归中更新
TreeNode* createTree(const string& s, int& index) {
    if (index >= s.length()) return nullptr;  // 字符串结束
    char ch = s[index++];
    if (ch == '.') return nullptr;            // 空子树
    TreeNode* node = new TreeNode(ch);        // 创建根结点
    node->left = createTree(s, index);        // 递归构建左子树
    node->right = createTree(s, index);       // 递归构建右子树
    return node;
}

// 前序遍历
void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

// 中序遍历
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

// 后序遍历
void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main() {
    string s;
    cout << "请输入广义前序字符串（用 '.' 表示空子树）: ";
    cin >> s;
    int index = 0;
    TreeNode* root = createTree(s, index);
    
    cout << "前序遍历结果: ";
    preorder(root);
    cout << endl;
    
    cout << "中序遍历结果: ";
    inorder(root);
    cout << endl;
    
    cout << "后序遍历结果: ";
    postorder(root);
    cout << endl;
    
    // 可选：释放内存（简单示例可忽略，但良好实践）
    // 此处省略递归释放，可自行添加 destroyTree 函数
    
    return 0;
}