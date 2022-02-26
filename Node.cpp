#include <iostream>

/*struct Node
{
    int data;
    Node *next;
};

class List
{

private:

    Node *head;

public:

    List()
    {
        head = NULL;
    }

    void addNode(int a)
    {
        Node *nd = new Node;
        nd -> data = a;
        nd -> next = 0;
        if(head == NULL)
        {
            head = nd;
        }
            else
            {
                Node *current = head;
                while (current->next != NULL)
                {
                    current = current->next;
                    current->next = nd;
                }
                
            }

    }

    void printNode()
    {
        Node *current = head;
        while (current != NULL)
        {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }
};

int main()
{
    List myList;

    myList.addNode(25);
    myList.addNode(30);
    myList.addNode(80);
    myList.addNode(5);

    myList.printNode();

    return 0;
} */
/*
struct SaveData
{
    int data;
};

int input()
{
    std::cout << "Enter a random Nuber" << std::endl;
    int a;
    std::cin >> a;
    return a;
}

void Doppelt(SaveData *ptr)
{
    ptr->data = ptr->data * 2;
}

int main()
{
    SaveData *save = new SaveData;
    save->data = input();

    Doppelt(save);

    std::cout << save->data << std::endl;
    delete save;

    return 0;
}*/

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;
/*
int counter(Node *const node)
{
    Node *springer = node;
    int a = 0;
    if(springer)
    {
        while(springer)
        {
            springer = springer->next;
            ++a;
        }
    }
    return a;
}*/
Node* einCycle(Node *node)
{
        Node *save = node;
        Node *prew = nullptr;
        while (save != nullptr)
        {
            node = save;
            save = node->next;
            node->next = prew;
            prew = node;
        }
    return node;
}

Node* einlauf(Node *node)
{
    if(node)
    {
        Node *vorlauf = node->next;
        Node *nachlauf = nullptr;
        while(!(vorlauf->next == nullptr))
        {
            node->next = nachlauf;
            nachlauf = node;
            node = vorlauf;
            vorlauf = vorlauf->next;
        }
            node->next = nachlauf;
            vorlauf->next = node;
            node = vorlauf;
    }
        return node;
}

Node* umdrehen(Node *node)
{
    if(node)
    {
        Node *laufer = node;
        Node *marker = nullptr;
        Node *newhead = nullptr;
        while(laufer->next != marker)
        {
            laufer = laufer->next;
            if(laufer->next == 0)
            {
                newhead = laufer;
                marker = laufer;
                laufer = node;
            }
            else if((laufer->next == newhead) || (laufer->next == marker))    
                    {
                    marker->next = laufer;
                    marker = laufer;
                    laufer = node;
                    }
        }
        marker->next = laufer;
        laufer->next = nullptr;
        node = newhead;
    }
    return node;
}

void printRecursRevers(Node *node)
{
    if(node)
    {
        printRecursRevers(node->next);
        std::cout << node->data << " " << std::endl;
    }
}

void printCycle(Node *node)
{
    for(Node *run = node; !(run == 0); run = run->next)
        
            std::cout << run->data << " ";
}

void Listkiller(Node *node)
{
    while(node)
    {
        Node *killer = node;
        node = killer->next;
        delete killer;
        killer = nullptr;
    }
    head = nullptr;
}

void rucksreiber(Node *const node)
{
    if(node)
    {
        Node *laufer = node;
        Node *stopler = nullptr;
        while(laufer->next != stopler)
        {
            laufer = laufer->next;
            if((laufer->next == 0) || (laufer->next == stopler))    
                {
                std::cout << laufer->data << std::endl;
                stopler = laufer;
                laufer = node;
                }
        }
        std::cout << laufer->data << std::endl;
    }
}

void add(Node *node)
{
    node->next = head;
    head = node;
}

void printNode(Node *node)
{
    if(node)
    {
        std::cout << node->data << " ";
        printNode(node->next);
    }
}

int input()
{
    std::cout << "Enter a random Nuber" << std::endl;
    int a;
    std::cin >> a;
    return a;
}

Node* inputSave()
{
    Node *head = new Node;
    head->data = input();
    return head;
}

int main()
{
    /*counter(head);*/
    add(inputSave());
    add(inputSave());
    add(inputSave());
    add(inputSave());
    add(inputSave());


    /*std::cout << "Список состоит из   " << counter(head) << "       ячеек" << std::endl;
    printNode(head);
    std::cout << std::endl;
    rucksreiber(head);
    printCycle(head);*/
    printNode(head);
    std::cout << std::endl;
    head = einCycle(head);/*
    head = einlauf(head);
    head = umdrehen(head);*/
    printCycle(head);/*
    printRecursRevers(head);*/
    Listkiller(head);
    return 0;
}
