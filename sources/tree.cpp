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

void BSTree::Tree::traversal(const Handle before, const Handle middle,
    const Handle after, const Node* cur_node) {
    // if cur_node no select - choose root
    if (!cur_node) {
        // if root not exist - exit, else cur_node is root
        if (root)
            cur_node = root;
        else
            return;
    }

    // before go down
    if (before)
        before(cur_node);

    // left node
    if (cur_node->left)
        traversal(before, middle, after, cur_node->left);

    // middle left and right
    if (middle)
        middle(cur_node);

    // right node
    if (cur_node->right)
        traversal(before, middle, after, cur_node->right);

    // after go down
    if (after)
        after(cur_node);
}

void BSTree::Tree::print(const traversal_order order) {
    // node's output
    BSTree::Handle handle = [](const BSTree::Node* node) {
        std::cout << node->data << " ";
    };

    // traversal order
    switch (order) {
    case pre:
        traversal(handle);
        break;
    case in:
        traversal(nullptr, handle);
        break;
    default:
        traversal(nullptr, nullptr, handle);
    }
}

BSTree::Tree::~Tree() {
}
