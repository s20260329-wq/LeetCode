/*
反转链表采用两种方法一种双指针,一种递归算法 
1.关于递归算法有以下思考:
是在操作完再调用递归函数还是先调用递归函数再去操作需要思考
一般是考虑操作内容有没有需要利用后边的信息这样的话必须先递归再操作
比如树里面的后序遍历递归,否则反之.
2.关于递归函数返回值需要思考
3.关于if判断x||y这x,y在某些情况下是有顺序表要求的,能利用短路原理去处理
4. 
 
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

