/*
从今天开始写树的算法题
反思写在word里面了 

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
