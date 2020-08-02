#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Node {
public:
    int value;
    Node* left, * right;
    Node(int val = 0) { value = val; left = right = nullptr; }
    ~Node() {
        delete left;
        left = nullptr;
        delete right;
        right = nullptr;
    }
};

void printTree(Node* n) {
    if (!n) return;
    std::cout << n->value << "(";
    printTree(n->left);
    std::cout << ")(";
    printTree(n->right);
    std::cout << ")";
}
void downHeap(Node* n) {
  //  std::swap(n->value, n->left->value);
    if (n!=nullptr)
    {
        if (n->left!=nullptr && n->right!=nullptr)
        {
            if (n->value > n->left->value || n->value > n->right->value)
            {
                if (n->left->value < n->right->value)
                {
                    std::swap(n->value, n->left->value);
                    downHeap(n->left);
                }
                else
                {
                    std::swap(n->value, n->right->value);
                    downHeap(n->right);
                }
            }
        }
        if (n->left != nullptr && n->right == nullptr)
        {
            if (n->value > n->left->value)
            {
                std::swap(n->value, n->left->value);
            }
            downHeap(n->left);
        }
        if (n->left == nullptr && n->right != nullptr)
        {
            if (n->value > n->right->value)
            {
                std::swap(n->value, n->right->value);               
            }
            downHeap(n->right);
        }
    }
}
int main() {
    /*
     Node* n = new Node(9);
    n->right = new Node(12);
    n->right->left = new Node(19);
    n->left = new Node(8);
    n->left->left = new Node(14);
    */

    /*
    Node* n = new Node(777);
    n->right = new Node(9);
    */

    /*
    Node* n = new Node(100);
    n->left = new Node(1);
    n->right = new Node(2);
    n->right->left = new Node(3);
    n->right->right = new Node(4);
    n->right->right->right = new Node(5);
    */
    
    Node* n = new Node(5);
    n->right = new Node(777);
    n->right->left = new Node(13);
    n->right->left->left = new Node(17);
    n->right->left->left->left = new Node(26);
    n->right->right = new Node(20);
    
    downHeap(n);

    std::cout << "Compact printout:" << std::endl;
    printTree(n);
   // std::cout << std::endl << "Vertical printout:" << std::endl;
   // printTreeVertical(n);

    delete n;
    n = nullptr;

    return 0;
}