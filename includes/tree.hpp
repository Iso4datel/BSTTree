// Copyright Iso3datel
#pragma once
#include <vector>

namespace BSTree {

    typedef int Data;
    typedef unsigned int u_int;

struct Node {
    Data data;      // value of data
    Node* left;     // ptr to left node
    Node* right;    // ptr to right node

    explicit Node(Data data, Node* left = nullptr, Node* right = nullptr);
    ~Node();
};

class Tree {
    Node* root = nullptr;
 public:
    bool insert(const Data value);
    explicit Tree(const std::vector<Data> & arr);
    ~Tree();
};
}   // namespace BSTTree
