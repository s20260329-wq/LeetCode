/*
反转链表采用两种方法一种双指针,一种递归算法 
1.关于递归算法有以下思考:
是在操作完再调用递归函数还是先调用递归函数再去操作需要思考
一般是考虑操作内容有没有需要利用后边的信息这样的话必须先递归再操作
比如树里面的后序遍历递归,否则反之.
2.关于递归函数返回值需要思考
3.关于if判断x||y这x,y在某些情况下是有顺序表要求的,能利用短路原理去处理
4. 重排链表的感悟,就是有些情况最简单的方法就是从单链表从后往前找信息,但但碍于单链表只有一个指针与无法实现,但我们可以在不影响背景的情况下,让单链表逆置去寻找信息
还有关于重排链表在实现合并的时候确保中点处会断开,因为不断开很可能会形成一个环,聪儿陷入死循环里面
5.关于双指针卡出一个区间长度后边的指针不用非要指向下一个节点,有时候直接指向该组的尾节点会有更好的判断条件(k组反转一个链表)
 6.关于重新按照一定规则排列链表这个问题,大多数排完一个不用断开,但还是建议排一个断开一个,防止形成环形链表
*/
//----------------206反转链表--------------- 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL) return NULL;
    //创建虚拟头节点
   struct  ListNode*L=(struct ListNode*)malloc(sizeof(struct ListNode));
   L->next=head;
    //双指针法
    struct ListNode* p, *q;
    p=L;
    q=L->next;
    L->next=NULL;
    while(q!=NULL){
        struct ListNode*temp=q->next;
        q->next=p->next;
        p->next=q;
        q=temp;
    }
    return L->next;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //递归算法
 struct ListNode*niZhi(struct ListNode*up,struct ListNode*down){
    //判断递归结束条件以及返还什么
    if(up==NULL) return down->next;
    //判断先递归后操作还是先操作后递归
    struct ListNode*temp=up->next;
    up->next=down->next;
    down->next=up;
    return niZhi(temp,down);
 }
//-----------------力扣92反转链表二-------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    //创建虚拟头节点因为有可能改变头指针的位置
    struct ListNode*L=(struct ListNode*)malloc(sizeof(struct ListNode));
    L->next=head;
    //计算区间长度再加二
    int leng=right-left+2;
    struct ListNode*lHead=L;
    struct ListNode*rHead=L;
    while(leng--&&rHead!=NULL){
        rHead=rHead->next;
    }
    //利用区间窗口去找到要反转的链表
    int x=left-1;
    while(x--&&rHead!=NULL){
         lHead=lHead->next;
         rHead=rHead->next;
    }
    //进行反转操作
    struct ListNode*LL=lHead;
    struct ListNode*q=LL->next;
    struct ListNode*p=LL->next;
    LL->next=NULL;
    while(p!=rHead){
        struct ListNode*temp=p->next;
        p->next=LL->next;
        LL->next=p;
        p=temp;
    }
    q->next=rHead;
    return L->next;
}
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL||head->next==NULL) return head;
   //创建虚拟头节点
   struct  ListNode*L=(struct ListNode*)malloc(sizeof(struct ListNode));
   L->next=head;
   struct ListNode*up=L->next;
   struct ListNode*down=L;
   L->next=NULL;
   struct ListNode*t=niZhi(up,down);
   return t;
}
//-----------------力扣25k个一组反转链表----------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    //创建虚拟头节点
struct ListNode* L=(struct ListNode*)malloc(sizeof(struct ListNode));
L->next = head;
//遍历链表长度
int len=0;
struct ListNode*p=L->next;
while(p!=NULL){
    p=p->next;
    len++;
}
//取余运算
int length=len%k;
int length1=len/k;
if(length1==0) return head;
struct ListNode*l=L;
struct ListNode*r=L;
int number=k+1;
int a=number;
while(a--&&r!=NULL){
   r=r->next;
}
while(length1--){
   struct ListNode*pl=l->next;
   struct ListNode*pll=l->next;
   l->next=NULL;
   while(pl!=r){
   struct ListNode*temp=pl->next;
   pl->next=l->next;
   l->next=pl;
   pl=temp;
   }
   pll->next=r;
   int data=k;
   while(l!=NULL&&r!=NULL&&data--){
      l=l->next;
      r=r->next;
   }
}
return L->next;
}
//-----------------力扣143重排链表------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //排序函数
void reverse(struct ListNode*head){
    //判断边界条件
    if(head==NULL||head->next==NULL||head->next->next==NULL) return;
    //把头节点当虚拟头节点
    struct ListNode*L=head;
    struct ListNode*p=head->next;
    L->next=NULL;
    while(p!=NULL){
            struct ListNode*temp=p->next;
            p->next=L->next;
            L->next=p;
            p=temp;
    }
 }
void reorderList(struct ListNode* head) {
   if(head==NULL||head->next==NULL||head->next->next==NULL) return ;
   //寻找中间节点
   struct ListNode*L=head;
   struct ListNode*fast=head;
   struct ListNode*slow=head;
   struct ListNode*temp;
   while(fast!=NULL&&fast->next!=NULL){
    fast=fast->next->next;
    temp=slow;
    slow=slow->next;
   }
   if(fast==NULL){
    reverse(temp);
   }
   else{
    reverse(slow);
   }
    struct ListNode*l=head->next;
    struct ListNode*r;
    if(fast==NULL) {r=temp->next;temp->next=NULL;}
    else {r=slow->next;slow->next=NULL;}
    head->next=NULL;
    while(r!=NULL&&l!=NULL){
        struct ListNode*pl=l->next;
        struct ListNode*pr=r->next;
        L->next=r;
        L=L->next;
        L->next=l;
        L=L->next;
        r=pr;
        l=pl;
        
    }
    if(r!=NULL){
        L->next=r;
    }
    else if(l!=NULL){
        L->next=l;
    }
}
//-------------------力扣328奇偶链表--------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    //判断边界的条件确保前三个节点存在
    if(head==NULL||head->next==NULL||head->next->next==NULL) return head;
    //创建虚拟头节点
    struct ListNode*L=(struct ListNode*)malloc(sizeof(struct ListNode));
   L=head;
   //三个指针
   struct ListNode*l, *r, *pr;
   l=head->next->next;
   r=pr=head->next;
   L->next=NULL;
   while(l!=NULL&&r!=NULL){
    L->next=l;
    r->next=l->next;
    r=r->next;
    if(r==NULL) l==NULL;
    else{
        l=r->next;
    }
    L=L->next;
    L->next=NULL;
   }
   L->next=pr;
   return head;
}
