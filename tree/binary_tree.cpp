#include <queue>
#include <vector>

using namespace std;

static vector<int> vec;

/* 二叉树节点结构体 */
struct TreeNode
{
    int val;         // 节点值
    TreeNode *left;  // 左子节点指针
    TreeNode *right; // 右子节点指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
};

/*层序遍历（广度优先遍历）*/
vector<int> levelOrder(TreeNode *root)
{
    // 初始化队列。加入根节点
    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        TreeNode *node = queue.front();
        queue.pop();
        vec.push_back(node->val);
        if (node->left != nullptr)
            queue.push(node->left);
        if (node->right != nullptr)
            queue.push(node->right);
    }
    return vec;
}

/*深度优先遍历*/

/*前序遍历*/
void preOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    vec.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}

/*中序遍历*/
void inOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    vec.push_back(root->val);
    inOrder(root->right);
}

/*后序遍历*/
void postOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    vec.push_back(root->val);
}
