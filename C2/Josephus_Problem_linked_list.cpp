#include <iostream>
using namespace std;

// 用双向链表解决约瑟夫问题
// https://www.coursera.org/learn/c-chengxu-sheji/lecture/ola3e/lian-biao-de-cao-zuo

struct Node
{
    int num;
    Node *ahead;
    Node *next;
};

Node *Create(int N);
Node *Search(Node *head, int P);
Node *Release(Node *head, int M);

int main()
{
    int N, P, M = 0;           // N-起始节点数 P-开始节点
    cin >> N >> P >> M;        // 每次释放第M个节点
    Node *head = Create(N);    // 创建N个节点的环
    head = Search(head, P);    // 找到第P个节点
    while (head->next != head) // 不断释放第M个元素
    {
        head = Release(head, M); // 释放第M个节点
    }
    cout << head->num;
    return 0;
}

Node *Create(int N) // 创建包含N个节点的双向循环链表
{
    int n = 1;
    Node *node = new Node;
    node->num = n;
    Node *head = node; // 指向第一个节点
    Node *tail = head; // 指向最后一个节点
    while (n++ < N)
    {
        node = new Node;   // 建新节点
        node->num = n;     // 赋值
        tail->next = node; // 接入新节点
        node->ahead = tail;
        tail = tail->next; // 尾巴后移
    }
    tail->next = head; // 尾巴处理
    head->ahead = tail;
    return head;
}

Node *Search(Node *head, int P) // 从head开始寻找第P个节点
{
    while (head->num != P)
    {
        head = head->next;
    }
    return head;
}

Node *Release(Node *head, int M) // 释放head开始的第M个节点
{
    int count = 1;
    Node *temp = head;
    while (count < M) // 寻找第M个节点
    {
        temp = temp->next;
        count++;
    }
    temp->ahead->next = temp->next;  // 移除第M个节点
    temp->next->ahead = temp->ahead; // 移除第M个节点
    cout << temp->num << ",";
    head = temp->next; // 释放第M个节点所占内存空间，从去除节点的下一个节点继续开始数
    delete temp;
    return head;
}