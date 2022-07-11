//Библиотека,директива процессора
#include <iostream>

//Блок списка, поле хранения данных, указатель на след. блок
struct Node 
{
    int data = 0;
    Node *next = nullptr;
};

//сам список, голова, блок
struct List
{
    Node *head = nullptr;
};

//функция ввода данных
int dataInput()
{
    int input = 0;
    std::cout << "Enter a Number" << std::endl;
    std::cin >> input;
    return input;
}

//функция записи данных в список
void listInput(List &list)
{
    if(list.head)
    {
        Node *newNode = new Node;
        newNode->next = list.head;
        newNode-> data = dataInput();
        list.head = newNode;
    }
    //используктся когда список пуст
    else 
    {
        list.head = new Node;
        list.head-> data = dataInput();
    }
}

//печать списка цикл
void listPrint(const List &list)
{
    if(list.head)
    {
        Node *print = list.head;
        while (print != 0)
        {
            std::cout << print->data << std::endl;
            print = print->next;
        }
    }
    else 
    {
        std::cout << "The List is emply" << std::endl;
    }
}

//печать рекурсия
void recursionPrintNode(const Node *node)
{
    if(node)
    {
        std::cout << node->data << std::endl;
        recursionPrintNode(node->next);
    }
}

//вызов рекурсивной печати
void recursionPrintList(const List &list)
{
    recursionPrintNode(list.head);
}

//разворот
void reversList(List *list)
{
    if(list->head)
    {
        Node *save = nullptr;
        Node *newhead = list->head->next;
        while(newhead != 0)
        {
            list->head->next = save;
            save = list->head;
            list->head = newhead;
            newhead = list->head->next;
            list->head->next = save;
        }
    }
    else
    {
        std::cout << "the list is emply" << std::endl;
    }
}
//List delete
void deleteList(List *list)
{
    if(list->head)
    {
        while(list->head)
        {
            Node *deleteList = list->head;
            list->head = deleteList->next;
            delete deleteList;
            deleteList = nullptr;
        }
    }
    else
    {
        std::cout << "the list is emply" << std::endl;
    }
}
//корень зла
int main()
{
    List list_a;
    
    listInput(list_a);
    listInput(list_a);
    listInput(list_a);
    listInput(list_a);
    listInput(list_a);
    listPrint(list_a);
    recursionPrintList(list_a);
    std::cout << "revers" << std::endl;
    reversList(&list_a);
    std::cout << "reversPrint" << std::endl;
    recursionPrintList(list_a);
    deleteList(&list_a);
    std::cout << "delete" << std::endl;
    listPrint(list_a);

    return 0;
}