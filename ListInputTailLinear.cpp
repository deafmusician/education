#include <iostream>

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head = nullptr;
    Node *tail = nullptr;
};

int userInput()
{
    std::cout << "Enter a Number" << std::endl;
    int a;
    std::cin >> a;

    return a;
}

void newNode(List &list)
{
    if(list.head == nullptr)
    {
        list.head = new Node;
        list.head->data = userInput();
        list.head->next = list.tail;
        list.tail = list.head;
    }
    else 
    {
        list.tail->next = new Node;
        list.tail = list.tail->next;
        list.tail->next = nullptr;
        list.tail->data = userInput();
    }
}

void listPrint(List &list)
{
    if(list.head)
    {
        Node *print = list.head;
        while(print != 0)
        {
            std::cout << print->data << std::endl;
            print = print->next;
        }
    }
}

// удаление листа

void deleteList(List &list)
{
    while(list.head)
    {
        list.tail = list.head->next;
        delete list.head;
        list.head = list.tail;
    }
}

int main()
{
    List list_a, list_b;
    newNode(list_a);
    newNode(list_a);
    newNode(list_a);
    newNode(list_a);
    listPrint(list_a);
    std::cout << '\n';
    newNode(list_b);
    newNode(list_b);
    newNode(list_b);
    newNode(list_b);
    listPrint(list_b);
    deleteList(list_a);
    deleteList(list_b);
    return 0;
}