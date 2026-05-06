/*以下代码除了判断段链表是否相交简洁使用快慢指针外
均直接采用快慢指针 来进行解题
所以有以下反思
1.当链表是环是应当考虑快慢指针进行解题
2.当链表的解题关键与长度息息相关时候应考虑快慢指针   26.05.06
*/
//------------------力扣876寻找链表中间节点----------------- 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    //处理特殊节点
    if(head==NULL) return NULL;
    struct ListNode*fast=head;
    struct ListNode*slow=head;
    while(fast!=NULL&&fast->next!=NULL)//分别对应奇偶两种情况
    {
        
        fast=fast->next;
        fast=fast->next;
        slow=slow->next;
    }
     return slow;
}
//------------力扣141判断链表是否有环------------- 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head==NULL) return false;
    struct ListNode*fast;
    struct ListNode*slow;
    fast=slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next;
        fast=fast->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
//----------------力扣160判断两个链表是否相交------------------- 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //先遍历两个链表计算长度
    if(headA==NULL||headB==NULL) return NULL;
    int lenA, lenB;
    lenA=lenB=0;
    struct ListNode*pa=headA;
    struct ListNode*pb=headB;
    while(pa!=NULL){
        lenA++;
        pa=pa->next;
    }
    while(pb!=NULL){
        lenB++;
        pb=pb->next;
    }
    pa=headA;
    pb=headB;
    int number=lenA-lenB>=0?lenA-lenB:lenB-lenA;
    if(lenA>lenB){
        while(number--){
            pa=pa->next;
        }
    }
    else{
        while(number--){
            pb=pb->next;
        }
    }
    while(pa!=NULL&&pb!=NULL){
        if(pa==pb) break;
        pa=pa->next;
        pb=pb->next;
    }
   return pa;
    
}
//------------------力扣19删除倒数第n个节点----------------- 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dem;
    dem.next=head;
    struct ListNode*fast=&dem;
    struct ListNode*slow=&dem;
    int i=1;
    while(i<=n+1){
        fast=fast->next;
        i++;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
return dem.next;
}
