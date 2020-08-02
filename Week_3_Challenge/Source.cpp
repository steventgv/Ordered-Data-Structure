#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
class Node
{
public:
	int height;
	Node* left, * right;
	Node() {height = -1; left = right = nullptr; }
	~Node()
	{
		delete left;
		left = nullptr;
		delete right;
		right = nullptr;
	}

};
int count(Node* n) {
    int num = 1;
    if (n->left != nullptr)
    {
        num += count(n->left);
    }
    if (n->right != nullptr)
    {
        num += count(n->right);
    }
    return num;
}

void computeHeight(Node* n) {
    int Rheight = 1;
    int Lheight = 1;
    if (n->right == nullptr && n->left==nullptr)
    {
        n->height = 0;
    }
    else
    {
        if (n->right != nullptr) 
        {
            computeHeight(n->right);
            Rheight = n->right->height + 1;
        }
        if (n->left!=nullptr)
        {
            computeHeight(n->left);
            Lheight = n->left->height + 1;
        }
        if (Rheight > Lheight)
        {
            n->height = Rheight;
        }
        else
        {
            n->height = Lheight;
        }
    }       
}


int main() {
    Node* n = new Node();
    n->left = new Node();
    n->right = new Node();
    n->right->left = new Node();
    n->right->right = new Node();
    n->right->right->right = new Node();

    computeHeight(n);
    std::cout << n->height << std::endl;
   // computeHeight(n->right->right);

    // The Node destructor will recursively
    // delete its children nodes.
    delete n;
    n = nullptr;

    return 0;
}