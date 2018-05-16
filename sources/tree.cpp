//  BSTree
//  tree.hpp
//  Created by Zinchenko && Shmakov /bmstu/.
//  Copyright © 2018 iso4datel && geminishkv. All rights reserved.
//
#include <tree.hpp>

BSTree::Tree::Tree() {
    root = nullptr;
}

BSTree::Tree::Tree(const std::initializer_list<Data>& list) {
    for (const auto& l : list)
        insert(l);
}

BSTree::Tree::Tree(Tree&& tree) : root(std::move(tree.root)) {
}

BSTree::Tree::Tree(const Tree& tree) {
    if (tree.root) {
        BSTree::Handle handle = [this](Node* node) {
            insert(node->data);
            return false;
        };
        traversal(nullptr, nullptr, nullptr, tree.root);
    } else {
        root = nullptr;
    }
}

BSTree::Node::Node(const Data data, Node* left, Node* right)
    : data(data), left(left), right(right) {
}

BSTree::Node::~Node() {
}

BSTree::Tree::Tree(const std::vector<Data> & arr) {
    for (const auto& a : arr)
        insert(a);
}

BSTree::Tree::~Tree() {
    BSTree::Handle handle = [](const Node* node) {
        delete node;    // insert - new, destructor - delete
        return false;
    };

    traversal(nullptr, nullptr, handle);
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


bool BSTree::Tree::traversal(const Handle before, const Handle middle,
    const Handle after, Node* cur_node) {
    // if cur_node no select - choose root
    if (!cur_node) {
        // if root not exist - exit, else cur_node is root
        if (root)
            cur_node = root;
        else
            return true;
    }

    // before go down
    if (before)
        if (before(cur_node))
            return true;

    // left node
    if (cur_node->left)
        if (traversal(before, middle, after, cur_node->left))
            return true;

    // middle of left and right
    if (middle)
        if (middle(cur_node))
            return true;

    // right node
    if (cur_node->right)
        if (traversal(before, middle, after, cur_node->right))
            return true;

    // after go down
    if (after)
        if (after(cur_node))
            return true;

    return false;
}

void BSTree::Tree::print(const traversal_order order) {
    // node's output
    BSTree::Handle handle = [](BSTree::Node* node) {
        std::cout << node->data << " ";
        return false;
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

bool BSTree::Tree::isEmprty() {
    return !root;
}

void BSTree::Tree::show() {
    if (isEmprty()) {
        std::cout << "Tree is empty!" << std::endl;
        return;
    }

    unsigned int off = 0;
    std::vector<std::string> res;
    BSTree::Handle handle_before = [&off](BSTree::Node* node) {
        off++;
        return false;
    };

    BSTree::Handle handle_middle = [&res, &off](BSTree::Node* node) {
        res.push_back(std::string((off - 1) * 2, '  ') + "--"
            + std::to_string(node->data));
        return false;
    };

    BSTree::Handle handle_after = [&off](BSTree::Node* node) {
        off--;
        return false;
    };

    // calculation
    traversal(handle_before, handle_middle, handle_after);

    // return to right-left order
    for (int i = res.size() - 1; i >= 0; i--)
        std::cout << res[i] << std::endl;
}

bool BSTree::Tree::exists(const Data value) {
    bool exist = false;
    BSTree::Handle handleExist = [&exist, value](Node* node) {
        if (value == node->data)
            return (exist = true);  // find and exit from recursion

        return (exist = false);  // not find, not exit
    };

    traversal(handleExist);
    return exist;
}

bool BSTree::Tree::remove(const Data value) {
    Node * last_node = nullptr;
    bool remove = false;
    Node** root_ptr = &root;
    BSTree::Handle handleRemove = [&last_node, value, &remove, &root_ptr]
                                    (Node* node) {
        if (value == node->data) {
            // 1) node without subnodes (root for subtree)
            if (!node->left && !node->right) {
                // if node is not root
                if (last_node) {
                    if (last_node->left == node)
                        last_node->left = nullptr;
                    else
                        last_node->right = nullptr;
                }


                delete node;

                // if last element in all tree
                if (node == *root_ptr)
                    *root_ptr = nullptr;  // can't change pointer into lambda
            } else {
                // 2) node have two subtree
                if (node->left && node->right) {
                    Node* cur_node = node->right;

                    // if right subtree have only one node
                    if (!cur_node->left) {
                        node->data = cur_node->data;
                        node->right = cur_node->right;
                        delete cur_node;
                    } else {
                        // down to left (-1)
                        while (cur_node->left->left)
                            cur_node = cur_node->left;

                        node->data = cur_node->left->data;
                        delete cur_node->left;
                        cur_node->left = nullptr;
                    }
                } else {
                    // 3) tree have only one node
                    if (node->left && !node->right ||
                        !node->left && node->right) {
                        // if root
                        if (!last_node) {
                            // change on copy-constructor
                            Node* tmp = (node->right) ? node->right
                                : node->left;
                            node->data = tmp->data;
                            node->left = tmp->left;
                            node->right = tmp->right;
                            delete tmp;
                        } else {
                            if (last_node->left == node)
                                last_node->left = (node->left) ? node->left
                                : node->right;
                            else
                                last_node->right = (node->right) ? node->right
                                : node->left;
                            delete node;
                        }
                    }
                }
            }
            // remove all
            return (remove = true);
        }
        last_node = node;
        return (remove = false);
    };
    traversal(handleRemove, handleRemove, handleRemove);
    return remove;
}

bool BSTree::Tree::save(const std::string & path) {
    std::ifstream exist(path);
    if (exist) {
        // file already exists
        std::string answer;
        while (true) {
            std::cout << "File already exist, rewrite? (y/n)" << std::endl;
            std::cin >> answer;
            if (answer == "y") {
                break;
            } else if (answer == "n") {
                return false;
            } else {
                std::cout << "Not valid value. Repeat." << std::endl;
            }
        }
    }
    exist.close();
    std::string res;
    Handle FWrite = [&res](BSTree::Node * node) {
        res += std::to_string(node->data) + " ";
        return false;
    };

    // write
    std::ofstream file(path);
    traversal(FWrite);
    file << res;
    file.close();

    return true;
}

bool BSTree::Tree::load(const std::string & path) {
    // clear tree
    BSTree::Handle handle = [](const Node* node) {
        delete node;    // insert - new, destructor - delete
        return false;
    };

    traversal(nullptr, nullptr, handle);
    root = nullptr;

    // load tree from file
    std::ifstream file(path);
    if (file) {
        while (!file.eof()) {
            Data data;
            file >> data;
            insert(data);
        }
    } else {
        std::cout << "File not exist!" << std::endl;
        return false;
    }
    file.close();
    return true;
}

BSTree::Tree& BSTree::Tree::operator=(const BSTree::Tree& tree) {
    if (this != &tree) {
        // clear tree
        BSTree::Handle handle = [](const Node* node) {
            delete node;    // insert - new, destructor - delete
            return false;
        };

        traversal(nullptr, nullptr, handle);
        root = nullptr;

        // new values
        Handle handle1 = [&](const Node * node) {
            this->insert(node->data);
            return false;
        };

        traversal(handle1);
    }
    return *this;
}

BSTree::Tree& BSTree::Tree::operator=(BSTree::Tree&& tree) {
    root = tree.root;
    return *this;
}

// non-member friend function operator
auto BSTree::operator<<(std::ostream& stream, BSTree::Tree& tree)
                                                ->std::ostream& {
    std::string res;
    BSTree::Handle FWrite = [&res](BSTree::Node * node) {
        res += std::to_string(node->data) + " ";
        return false;
    };
    // private method
    tree.traversal(FWrite);
    return stream << res;
}
