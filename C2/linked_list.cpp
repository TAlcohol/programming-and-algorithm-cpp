#include <iostream>
using namespace std;

struct student
{
    int id;
    student *next;
};

student *create()
{
    student *head, *temp;
    int num, n = 0;
    head = new student;
    temp = head;
    cin >> num;
    while (num != -1)
    {
        n++;
        temp->id = num;
        temp->next = new student;
        temp = temp->next;
        cin >> num;
    }
    if (n == 0)
        head = NULL;
    else
        temp->next = NULL;
    return head;
}

student *dele(student *head, int n)
{
    student *temp, *follow;
    temp = head;
    if (head == NULL) // head 为空，空表的情况
    {
        return (head);
    }
    if (head->id == n) // 第一个节点是要删除的目标；
    {
        head = head->next;
        delete temp;
        return (head);
    }
    while (temp != NULL && temp->id != n) // 寻找要删除的目标
    {
        follow = temp;
        temp = temp->next;
    }
    if (temp == NULL) // 没寻到要删除的目标
        cout << "not found";
    else // 删除目标节点
    {
        follow->next = temp->next;
        delete temp;
    }
    return (head);
}

student *insert(student *head, int n)
{
    student *temp, *unit, *follow; // 插入节点为n的节点
    temp = head;
    unit = new student;
    unit->id = n;
    unit->next = NULL;
    if (head == NULL) // 如果链表为空，直接插入
    {
        head = unit;
        return (head);
    }
    while ((temp->next != NULL) && (temp->id < n)) // 寻找第一个不小于n或结尾的节点temp
    {
        follow = temp;
        temp = temp->next;
    }
    if (temp == head) // 如果temp为第一个节点
    {
        unit->next = head;
        head = unit;
    }
    else
    {
        if (temp->next == NULL) // 如果temp为最后一个节点
            temp->next = unit;
        else // 如果temp为一个中间节点
        {
            follow->next = unit;
            unit->next = temp;
        }
    }
    return (head);
}

int main()
{
    student *pointer = create();
    // while (pointer->next != NULL)
    // {
    //     cout << pointer->id << endl;
    //     pointer = pointer->next;
    // }
    student *pointer2 = insert(pointer, 9);
    while (pointer2->next != NULL)
    {
        cout << pointer2->id << endl;
        pointer2 = pointer2->next;
    }
    return 0;
}
