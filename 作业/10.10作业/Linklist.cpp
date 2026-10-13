#include <iostream>

struct Node 
{
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* CreateList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        Node* p = new Node(x);

        if (!head) head = tail = p;
        else 
        {
            tail->next = p;
            tail = p;
        }
    }
    return head;
}

Node* Reverse(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;
    while (cur) 
    {
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

void PrintList(Node* head) 
{
    while (head) 
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() 
{
    int n;
    std::cin >> n;
    Node* head = CreateList(n);
    head = Reverse(head);
    PrintList(head);
    return 0;
}


