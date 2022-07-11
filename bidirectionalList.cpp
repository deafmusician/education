#include <iostream>

struct Node
{
    int data = 0;
    Node *next = nullptr;
    Node *early = nullptr;
};

struct List
{
    Node *head = nullptr;
};

int userInput()
{
    int input = 0;
    std::cout << "Enter a Number" << std::endl;
    std::cin >> input;
    return input;
}

void listInput(List &list)
{
    if(list.head)
    {
        list.head->early = new Node;
        list.head->early->next = list.head;
        list.head = list.head->early;
        list.head->data = userInput();
    }
    else
    {
        list.head = new Node;
        list.head->data = userInput();
    }
}

void listPrint(const List &list)
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
    else
    {
        std::cout <<"the List is emply" << std::endl;
    }
}
//bearbeiten
void deleteList(List &list)
{
    if(list.head)
    {
        while(list.head)
        {
            Node *deleteList = list.head;
            list.head = deleteList->next;
            /*wenn List aus nur einen Block, oder mehreren Bloke besteht,
            enstehet keine Notwendigkeit den "early" Zeiger zu nullen,
            da gesammten List geloscht wird*/ 
            delete deleteList;
            deleteList = nullptr;
        }
    }
    else
    {
        std::cout << "the List is emply" << std::endl;
    }
}

void reversList(List &list)
{
    if(list.head)
    {
        if(list.head->next)
        //List besthet nicht nur aus einem Block
        {
            while(list.head->next)
            {
                list.head = list.head->next;
                list.head->early->next = list.head->early->early;
                list.head->early->early = list.head;
            }
            list.head->next = list.head->early;
            list.head->early = nullptr;
        }
    }
    else
    {
        std::cout << "List is emply" << std::endl;
    }
}

int main()
{
    List list_a;
    
    listInput(list_a);
    listInput(list_a);
    listInput(list_a);
    listInput(list_a);
    
    listPrint(list_a);
    std::cout << "revers" << std::endl;
    reversList(list_a);
    listPrint(list_a);

    std::cout << "delete" << std::endl;
    deleteList(list_a);
    listPrint(list_a);

    return 0;
}