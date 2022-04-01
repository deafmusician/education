#include <iostream>

struct TreeNode
{
    int key = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

struct Root
{
    TreeNode *root = nullptr;
};

void add(TreeNode*& node, int key)
{
    if(node)
    {
        if(node->key > key)
        {
            add(node->left, key);
        }
        else
        {
            add(node->right, key);
        }
    }
    else 
    {
        node = new TreeNode;
        node->key = key;
    }
}

void add(Root& tree, int key)
{
    add(tree.root, key);
}

void print(TreeNode* node)
{
    if(node)
    {
        std::cout << node->key << std::endl;
        print(node->left);
        print(node->right);
    }
}

void print(Root& tree)
{
    print(tree.root);
}

void deleteTree(TreeNode* node)
{
    if(node)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void deleteTree(Root& tree)
{
    deleteTree(tree.root);
    tree.root = nullptr;
}

int Input()
{
    std::cout << "Enter a Number to save" << std::endl;
    int input;
    std::cin >> input;
    return input;
}

int main()
{
    Root a;
    add(a, 8); 
    add(a, 4); 
    add(a, 3);
    add(a, 5);
    print(a);
    deleteTree(a);
    return 0;
}