/*
从今天开始写树的算法题
反思写在word里面了 
突然发现word文档上传完不能更改那以后反思写道这里吧
关于路径总和他的返回值处理学到新的东西,相对于树最大深度返回返回值最大值加1而说他返回值是一个状态值而不是一个纯数字的处理那么相对而言这个处理的逻辑就不同
对于返回值的处理只是判断是否进行下一层递归进行的钥匙,而不是需要这个值,所以说这个值多处用到判断即if语句里面而不是直接返回出去,还有这道题的是我除了kmp算法外第一次接触到回溯这个思想
*/
//-----------100题相同树----------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //递归终止条件
    if(p==NULL&&q!=NULL) return false;
    if(p!=NULL&&q==NULL) return false;
    if(p==NULL&&q==NULL) return true;
    if(p->val!=q->val)  return false;
    //如果相等才进行递归遍历
    //采用先序遍历
    //返回值怎么写
    return  isSameTree( p->left, q->left)&&isSameTree( p->right, q->right);
} 
//-----------------101对成树------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool tOf(struct TreeNode*r,struct TreeNode*l){
    //采用先序遍历
    //判断递归终止条件
    //判断先操作后递归还是先递归后操作
    if(r==NULL&&l!=NULL) return false;
    if(l==NULL&&r!=NULL) return false;
    if(r==NULL&&l==NULL) return true;
    if(r->val!=l->val) return false;
    tOf(r->right,l->left);
    tOf(r->left,l->right);
    return  tOf(r->right,l->left)&&tOf(r->left,l->right);
 }
bool isSymmetric(struct TreeNode* root) {
    return tOf(root->right,root->left);

}
//-------------110平衡树-----------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 #include<stdlib.h>
 #define MAX(a, b) ((a) > (b) ? (a) : (b))
 int isBalancedd(struct TreeNode*root)
 {
    //判断递归结束条件
    if(root==NULL) return 0;
    //采用后序遍历
     int a=isBalancedd(root->left);
     if(a==-1) return -1;
    int b=isBalancedd(root->right);
    if(b==-1) return -1;
    //先递归再操作
    if(abs(a-b)>1) return -1;
    else{
        return MAX(a,b)+1;
    }
 }
bool isBalanced(struct TreeNode* root) {
    int a=isBalancedd(root);
    if(a!=-1) return true;
    else return false;
}
//---------------226反转二叉树------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    //判断递归结束条件
    if(root==NULL) return NULL;
    //先序遍历,交换指针
    struct TreeNode*temp=root->left;
    root->left=root->right;
    root->right=temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
} 
//--------------------力扣112路径总和----------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
bool hasPathSumm(struct TreeNode* root, int count)
{
    //判断终止条件为叶子节点并且count为0错误count不为零而是叶子节点的值
    if(root->left==NULL&&root->right==NULL&&count==root->val) return true;
    if(root->left==NULL&&root->right==NULL&&count!=root->val) return false;
    if(root->left) {
        if(hasPathSumm(root->left,count-root->val)) return true;
       // hasPathSumm(root->left,count-root->val);
        //return true;
    }//if语句内自动判度是否有一个路径成立
    if(root->right) {
        if(hasPathSumm(root->right,count-root->val)) return true;
        //下面这为错误解法忘记判断下一层递归的返回值是否正确hasPathSumm(root->right,count-root->val);
        //return true;
    }
    return false;
}
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root==NULL) return false;
    return hasPathSumm(root,targetSum);
}
