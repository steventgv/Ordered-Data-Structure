#include<iostream>
#include"Header.h"
/*
static int num = 0;

int count(Node* n) {
   
    if (n != nullptr)
    {
      count(n->left);
      num++;
      count(n->right);       
    }
    return num;
    
}*/
int count(Node* n) {
    int num = 1;
    if (n->left!=nullptr)
    {
        num += count(n->left);    
    }
    if (n->right != nullptr)
    {
        num += count(n->right);    
    }
    return num;
}

int main() {
    Node* n = new Node();
    n->left = new Node();
    n->right = new Node();
    n->right->left = new Node();
    n->right->right = new Node();
    n->right->right->right = new Node();

    // This should print a count of six nodes
    
    std::cout << count(n) << std::endl;
    

    // Deleting n is sufficient to delete the entire tree
    // because this will trigger the recursively-defined
    // destructor of the Node class.
    delete n;
    n = nullptr;

    return 0;
}