/*
从今天开始写树的算法题
反思写在word里面了 
突然发现word文档上传完不能更改那以后反思写道这里吧
关于路径总和他的返回值处理学到新的东西,相对于树最大深度返回返回值最大值加1而说他返回值是一个状态值而不是一个纯数字的处理那么相对而言这个处理的逻辑就不同
对于返回值的处理只是判断是否进行下一层递归进行的钥匙,而不是需要这个值,所以说这个值多处用到判断即if语句里面而不是直接返回出去,还有这道题的是我除了kmp算法外第一次接触到回溯这个思想
98题验证二叉搜索树上传了两个版本一个是错误版一个正确版之所以上传错误版第一是因为他错误太典型局限思维只比较相邻的左右子树;第二个原因是虽然这个思想是错误的但能按照这个思想写出来清晰的理解递归的层次,
知道返回值怎么写.写到哪人,怎么利用上一层的返回值我感觉这是这几天的知识点整合起来的感觉.
关于正确版,首先学了二叉搜索树的中序遍历就是从小到大排序,第二学到了中序遍历处理问题的细节之前一直是前序遍历和后序遍历,再一个知道树怎么比较大小,对中序遍历有了更深刻理解,在中序遍历处理信息的时候每个节点其实都是左节点
700题二叉搜索树搜索这一题正常写不用二叉搜索树的性质也能写出来,这一题滤清思路了,干干净净写出来
235二叉搜索树的最近公共祖先,这一题的薄弱点还是不能熟悉利用二叉搜索的性质.
236二叉树的最近公共祖先第一点两种情况第一种情况包含另一种情乱,第二其实搜索的时候还是用的先序遍历,所谓后序遍历其实不过是把信息给返回,
第三的话,就是这个题的返回值也值得推敲,这个返回值能凭直觉写出来,但细想可能就写不出来了,他能保证返回的节一直是那个父节点,即使有一个为空,两个会合后,会返回真正的值
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
//------------------力扣98验证二叉搜索树-----------------
//---------------错误版----------------------
long long minval=LLONG_MIN;//头文件里面的宏定义
bool isValidBST(struct TreeNode* root) {
  //判断终止条件
  if(root==NULL) return true;
  //采用中序遍历
  bool left=isValidBST(root->left);
  if(minval<root->val) minval=root->val;
  else return false;
  bool right=isValidBST(root->right);
  return left&&right;
}
//---------------------正确版---------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 long long minval=LLONG_MIN;//头文件里面的宏定义
bool isValidBST(struct TreeNode* root) {
  //判断终止条件
  if(root==NULL) return true;
  //采用中序遍历
  bool left=isValidBST(root->left);
  if(minval<root->val) minval=root->val;
  else return false;
  bool right=isValidBST(root->right);
  return left&&right;
}
//-----------力扣700二叉树搜索树的搜索----------- 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    //判断终止条件
    if(root==NULL) return NULL;
    if(root->val==val) return root;
    struct TreeNode*p=searchBST(root->left,val);
    struct TreeNode*q=searchBST(root->right,val);
    if(p!=NULL) return p;
    else if(q!=NULL) return q;
    else return NULL;

}
//----------235二叉搜索树的的最近公共祖先--------------------- 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root==NULL) return NULL;
    if(root->val>p->val&&root->val>q->val)
    {
        struct TreeNode*left=lowestCommonAncestor(root->left,p,q);
        if(left) return left;
    }
    if(root->val<p->val&&root->val<q->val){
        struct TreeNode*right=lowestCommonAncestor(root->right,p,q);
        if(right) return right;
    }
     return root;
}
//-------------------力扣236二叉树的最近公共祖先---------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    //判断终止条件两个一个是成功条件,一个是失败条件
    if(root==NULL) return NULL;
    if(root==p||root==q)  return root;
    //进行先序遍历搜索
    struct TreeNode*left=lowestCommonAncestor(root->left,p,q);
    struct TreeNode*right=lowestCommonAncestor(root->right,p,q);
    //对返回值处理进行返回值这里的返回值挺有意思的
    if(left!=NULL&&right!=NULL) return root;
    if(left!=NULL&&right==NULL) return left;
    if(left==NULL&&right!=NULL) return right;
    return NULL;
}
//----------------------------222完全二叉树的节点个数--------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root) {
    if(root==NULL) return 0;
    int left=countNodes(root->left);
    int right=countNodes(root->right);
    return (left+right)+1;
}
