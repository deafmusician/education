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

void add(TreeNode*& node, TreeNode *savenode)
{
    if(node)
    {
        if(node->key > savenode->key)
        {
            add(node->left, savenode);
        }
        else
        {
            add(node->right, savenode);
        }
    }
    else
       node = savenode;
}


void add(Root& tree, int key)
{
    add(tree.root, key);
}

void print(TreeNode* node)
{
    if(node)
    {
        print(node->left);
        std::cout << node->key << std::endl;
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

/* удаление одного узла */
void deleteOhneElement(Root& tree, TreeNode*& node, int key)
{
    if(node)
    {
        if(node->key == key)
        {
            TreeNode *saveleft = node->left;
            TreeNode *saveright = node->right;
            delete node;
            node = nullptr;
            if(saveleft)
            {
                add(tree.root, saveleft);
            }
            if(saveright)
            {
                add(tree.root, saveright);
            }
        }
        else 
        {
            deleteOhneElement(tree, node->left, key);
            deleteOhneElement(tree, node->right, key);
        }
    }
}

void deleteOhneElement(Root& tree, int key)
{
    deleteOhneElement(tree, tree.root, key);
}

int Input()
{
    std::cout << "Enter a Number to save" << std::endl;
    int input;
    std::cin >> input;
    return input;
}

/*высота*/
int hightTree(TreeNode* node)
{
    if(!node)
    {
        return 0;
    }
        int left = 0, right = 0;
        if(node->left != nullptr)
        {
            left = hightTree(node->left);
        }
        else 
        {
            right = -1;
        }
        if(node->right != nullptr)
        {
            right = hightTree(node->right);
        }
        else 
        {
        right = -1;
        }
        int max = left > right ? left : right;
        return max+1;
}

void hightTree(Root& tree)
{
    if(tree.root)
    {
        int hight = hightTree(tree.root);
        std::cout << hight << std::endl;
    }
}

int main()
{
    Root a;
    add(a, 8); 
    add(a, 4); 
    add(a, 3);
    add(a, 5);
    print(a);
    deleteOhneElement(a, 3);
    print(a);
    std::cout << std::endl;
    hightTree(a);
    deleteTree(a);
    return 0;
}