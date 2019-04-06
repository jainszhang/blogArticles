
1.二叉树节点和创建
2.二叉树前序、中序、后序遍历
3.层次遍历

1.1 二叉树节点定义
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

1.2 二叉树的创建
TreeNode *createBTree()
    {
        TreeNode * T;
        int value;
        cin>>value;
        if(value!=-1)
        {
            T = (TreeNode*)malloc(sizeof(TreeNode));
            T->val = value;
            T->left = createBTree();
            T->right = createBTree();
        } else{
            T = nullptr;
        }
        return T;
    }

2.1.二叉树的前序遍历

//递归版本
void preOrderRec(TreeNode *T)
{
    if(T== nullptr)
        return;
    if (T!=nullptr)
    {
        cout<<T->val<<" ";
        preOrderRec(T->left);
        preOrderRec(T->right);
    }
}
//非递归版本
对于任一结点P：

 1)访问结点P，并将结点P入栈;

 2)判断结点P的左孩子是否为空，若为空，则取栈顶结点并进行出栈操作，并将栈顶结点的右孩子置为当前的结点P，循环至1);若不为空，则将P的左孩子置为当前的结点P;

 3)直到P为NULL并且栈为空，则遍历结束。

















