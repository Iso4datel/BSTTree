// Copyright Iso3datel
#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include <string>

namespace BSTree {

    struct Node;                    // forward declaration
    typedef int Data;               // node data
    typedef unsigned int u_int;     // reduction
    typedef std::function<void(const Node*)> Handle;    // node handle

    // numerate bypass
    enum traversal_order {
        pre,
        in,
        post
    };

struct Node {
    Data data;      // value of data
    Node* left;     // ptr to left node
    Node* right;    // ptr to right node

    explicit Node(Data data, Node* left = nullptr, Node* right = nullptr);
    ~Node();
};

class Tree {
    Node* root = nullptr;

    // universal tree traversal
    void traversal(const Handle before = nullptr, const Handle middle = nullptr,
        const Handle after = nullptr, const Node* cur_node = nullptr);
 public:
    bool insert(const Data value);
    explicit Tree(const std::vector<Data> & arr);
    ~Tree();

    bool isEmprty();
    void show();
    void print(const traversal_order order);
};

}   // namespace BSTree
