// Copyright Iso3datel
#include <tree.hpp>

BSTree::Node::Node(const Data data, Node* left, Node* right)
    : data(data), left(left), right(right) {
}

BSTree::Node::~Node() {
    delete left;
    delete right;
}

bool BSTree::Tree::insert(Data value) {
    Node* node = new Node(value);

    // no root - create
    if (!root) {
        root = node;
    } else {
        Node* cur_ptr = root;

        while (true) {
            if (node->data > cur_ptr->data) {
                if (!cur_ptr->right) {
                    cur_ptr->right = node;
                    break;
                } else {
                    cur_ptr = cur_ptr->right;
                }
            }
            if (node->data < cur_ptr->data) {
                // if left not exists
                if (!cur_ptr->left) {
                    cur_ptr->left = node;
                    break;
                } else {
                    cur_ptr = cur_ptr->left;
                }
            }

            // if equal - can't add
            if (node->data == cur_ptr->data) {
                delete node;
                return false;
            }
        }
    }
    return true;
}

BSTree::Tree::Tree(const std::vector<Data> & arr) {
    for (const auto& a : arr)
        insert(a);
}


BSTree::Tree::~Tree() {
}
