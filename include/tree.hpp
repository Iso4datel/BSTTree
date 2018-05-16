//  BSTree
//  tree.hpp
//  Created by Zinchenko && Shmakov /bmstu/.
//  Copyright © 2018 iso4datel && geminishkv. All rights reserved.
//
#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <fstream>

namespace BSTree {

    struct Node;                    // forward declaration
    typedef int Data;               // node data
    typedef unsigned int u_int;
    typedef std::function<bool(Node*)> Handle;    // node handle

    // numerate bypass
    enum traversal_order {
        pre,
        in,
        post
    };

struct Node {
    Data data;                // value of data
    Node* left = nullptr;     // ptr to left node
    Node* right = nullptr;    // ptr to right node

    explicit Node(Data data, Node* left = nullptr, Node* right = nullptr);
    ~Node();
};

class Tree {
    Node* root = nullptr;

    // universal tree traversal (if return true - recursion end)
    bool traversal(const Handle before = nullptr, const Handle middle = nullptr,
        const Handle after = nullptr, Node* cur_node = nullptr);

 public:
    Tree();
    explicit Tree(const std::initializer_list<Data>& list);
    explicit Tree(const Tree& tree);
    explicit Tree(Tree&& tree);
    explicit Tree(const std::vector<Data> & arr);

    bool insert(const Data value);
    bool exists(const Data value);
    bool remove(const Data value);

    bool save(const std::string& path);
    bool load(const std::string& path);

    void show();                                // show tree
    void print(const traversal_order order);    // traversal

    bool isEmprty();
    // non-member function operator, have access to private members
    auto friend operator<<(std::ostream& stream, Tree&)->std::ostream&;
    auto operator=(const Tree&)->Tree&;  // A = A
    auto operator=(Tree&&)->Tree&;
    ~Tree();
};

// non-member friend function operator
auto operator<<(std::ostream&, Tree&)->std::ostream&;

}   // namespace BSTree
