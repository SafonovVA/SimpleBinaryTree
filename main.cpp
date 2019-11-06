#include <iostream>
using namespace std;
template<typename T>
struct node {
    T key;
    node<T> *left, *right;
    node() : left(nullptr), right(nullptr) {}
};

template<typename T>
class tree {
private:
    node<T> *root;
public:
    tree() :root(nullptr) {}

    void push(const T& val) {
        if (!root) {
            root = new node<T>;
            root->key = val;
            return;
        }
        push(val, root);
    }

    void push(const T& val, node<T>* side) {
        if (val > side->key && side->right)
            push(val, side->right);
        if (val <= side->key && side->left)
            push(val, side->left);

        auto *branch = new node<T>;
        branch->key = val;

        if (val > side->key && !side->right)
            side->right = branch;
        if (val <= side->key && !side->left)
            side->left = branch;
    }


    void show() {
        if (root) {
            show(root);
        }
    }

    void show(node<T> *NODE) {
        cout << NODE->key << ", ";
        if (NODE->left)
            show(NODE->left);
        if (NODE->right)
            show(NODE->right);
    }
};

int main() {
    tree<int> a;
    a.push(45);
    a.push(30);
    a.push(50);
    a.push(27);
    a.push(39);
    a.push(15);
    a.push(90);
    a.push(103);
    a.push(70);

    a.show();
}
