#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node *next;
} slink;

// 创建一个单链表
slink *Creatlink(int n) {
    slink *head, *p, *s;
    head = (slink *)malloc(sizeof(slink));
    p = s = head;
    int i = 1;
    printf("请输入要存储的元素\n");
    while (i <= n) {
        s = (slink *)malloc(sizeof(slink));
        // 判断是否成功创立空间
        if (s == NULL)
            return head;
        scanf("%d", &s->data);
        s->next = NULL;
        p->next = s;
        p = s;
        i++;
    }
    return head;
}

// 求表长操作
int SlinkLength(slink *head) {
    int i = 0;
    slink *p = head->next;
    while (NULL != p) {
        p = p->next;
        i++;
    }
    return i;
}

// 取元素操作
int GetElemType(slink *head, int i) {
    int count = SlinkLength(head);
    if (i > count || i < 1)
        return -1;
    slink *p = head->next;
    while (i > 1) {
        p = p->next;
        i--;
    }
    return p->data;
}

// 定位操作
int LocaSlink(slink *head, ElemType number) {
    slink *p = head->next;
    int i = 1;
    while (p != NULL) {
        if (p->data == number)
            return i;
        i++;
        p = p->next;
    }
    return -1;
}

// 删除操作
int DeleSlink(slink *head, int i) {
    slink *fast = head->next;
    slink *slow = head;
    int count = SlinkLength(head);
    // 判断i的合理性
    if (i > count || i < 1)
        return -1;
    // 遍历链表找到合适位置
    while (i > 1) {
        slow = fast;
        fast = fast->next;
        i--;
    }
    // 执行删除操作
    slow->next = fast->next;
    free(fast);
    return 1;
}

// 插入操作
int InserSlink(slink *head, int i, int number) {
    slink *fast = head->next;
    slink *slow = head;
    slink *temp = NULL;
    int count = SlinkLength(head);
    // 判断i的合理性
    if (i > count || i < 1)
        return -1;
    // 找到i的位置
    while (i > 1) {
        slow = fast;
        fast = fast->next;
        i--;
    }
    // 创建新的空间执行插入操作
    temp = (slink *)malloc(sizeof(slink));
    temp->data = number;
    temp->next = fast;
    slow->next = temp;
    return 1;
}

// 输出操作
void print(slink *head) {
    slink *p = head->next;
    while (NULL != p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 排序从小到大
void DiZeng(slink *head) {
    slink *slow = head, *fast = slow->next, *fastfront = slow, *p = slow->next, *pfront = p;
    if (head->next == NULL)
        return;
    while (slow->next != NULL) {
        // 遍历链表
        while (fast != NULL) {
            // 在遍历中进行比较寻找最小值
            if (fast->data < p->data) {
                p = fast;
                pfront = fastfront;
            }
            fastfront = fast;
            fast = fast->next;
        }
        // 判断最小值是不是第一个元素再进行交换
        if (p != pfront) {
            // 交换元素
            pfront->next = p->next;
            p->next = slow->next;
            slow->next = p;
        }
        // 指针移动,指针复位
        slow = slow->next;
        p = p->next;
        pfront = p;
        fast = p;
        fastfront = slow;
    }
}

// 释放函数
void Fre(slink *head) {
    slink *p = head;
    slink *q;
    while (NULL != p) {
        q = p;
        p = p->next;
        free(q);
    }
}

int main() {
    slink *head;
    int number;
    int i;
    printf("请输入要存储多少个数据\n");
    scanf("%d", &number);
    head = Creatlink(number);
    printf("存储后链表的元素为\n");
    print(head); 
    printf("请输入要调用函数几按负一结束调用\n");
    scanf("%d", &number);
    while (number != -1) {
        // 表长函数调用
        if (number == 3) {
            i = SlinkLength(head);
            printf("表长为%d\n", i);
        }
        // 取元素函数调用
        else if (number == 4) {
            printf("请输入要取出第几个元素\n");
            scanf("%d", &i);
            printf("该元素为%d\n", GetElemType(head, i));
        }
        // 元素位置函数调用
        else if (number == 5) {
            printf("请输入要查哪个元素\n");
            scanf("%d", &i);
            printf("这个元素第一次出现的位置为%d\n", LocaSlink(head, i));
        }
        // 删除函数调用
        else if (number == 6) {
            printf("请输入要删除第几个元素\n");
            scanf("%d", &i);
            DeleSlink(head, i);
            printf("删除后的链表为\n");
            print(head);
        }
        // 插入函数调用
        else if (number == 7) {
            printf("请输入要在第几个元素前插入什么元素\n");
            int j;
            scanf("%d%d", &i, &j);
            InserSlink(head, i, j);
            printf("插入后的链表为\n");
            print(head);
        }
        // 输出函数调用
        else if (number == 8) {
            print(head);
        }
        // 排序函数调用
        else if (number == 9) {
            printf("排序后的链表为\n");
            DiZeng(head);
            print(head);
        } else
            printf("数据错误");
        printf("请输入要调用函数几按负一结束调用\n");
        scanf("%d", &number);
    }
    Fre(head);
    return 0;
}

