#include "binary_tree.cpp"

static TreeNode *root;
/*查找节点*/
TreeNode *search(int num)
{
    TreeNode *cur = root;
    while (cur != nullptr)
    {
        if (cur->val < num)
            cur = cur->right;
        if (cur->val > num)
            cur = cur->left;
        else
            break;
    }
    return cur;
}

/*插入节点*/
void insert(int num)
{
    // 若树未初始化，初始化root
    if (root == nullptr)
    {
        root = new TreeNode(num);
        return;
    }
    // pre记录上一个节点
    TreeNode *cur = root, *pre = nullptr;
    while (cur != nullptr)
    {
        if (cur->val == num)
            return;
        pre = cur;
        if (cur->val < num)
            cur = cur->right;
        if (cur->val > num)
            cur = cur->left;
    }
    TreeNode *node = new TreeNode(num);
    if (pre->val < num)
        pre->right = node;
    else
        pre->left = node;
}

void remove(int num)
{
    // 树为空时直接返回
    if (root == nullptr)
        return;
    TreeNode *cur = root, *pre = nullptr;
    // 循环查找，越过叶节点后跳出
    while (cur != nullptr)
    {
        // 找到待删除节点，跳出循环
        if (cur->val == num)
            break;
        pre = cur;
        // 待删除节点在 cur 的右子树中
        if (cur->val < num)
            cur = cur->right;
        // 待删除节点在 cur 的左子树中
        else
            cur = cur->left;
    }
    // 无待删除节点，直接返回
    if (cur == nullptr)
        return;
    // 子节点数量0或1，可以直接删除
    // 子节点数量为2时，需要中序遍历该节点的左子树最小或者右子树最大的节点
    if (cur->left == nullptr || cur->right == nullptr)
    {
        TreeNode *child = cur->left == nullptr ? cur->right : cur->left;
        if (cur != root)
        {
            if (pre->left == cur)
                pre->left = child;
            else
                pre->right = child;
        }
        else
        {
            // 删除节点为根节点，需要重新指定根节点
            root = child;
        }
        delete cur;
    }
    else
    {
        // 这里使用右子树最小节点
        TreeNode *tmp = cur->right;
        while (tmp->left != nullptr)
        {
            tmp = tmp->left;
        }
        int tmpVal = tmp->val;
        remove(tmp->val);
        cur->val = tmpVal;
    }
}