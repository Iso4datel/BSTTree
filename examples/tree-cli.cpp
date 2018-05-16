//  BSTree
//  tree-cli.cpp
//  Created by Zinchenko && Shmakov /bmstu/.
//  Copyright © 2018 iso4datel && geminishkv. All rights reserved.
//
#include <limits>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tree.hpp>

int main(int argc, char* argv[]) {
    // set argvs to vector
    std::vector<BSTree::Data> arr;
    std::vector<std::string> str(argv + 1, argv + argc);
    for (int i = 0; i < str.size(); i++)
        arr.push_back(std::stoi(str[i]));

    // inti tree
    BSTree::Tree tree(arr);

    // show menu
    std::cout << "Select one of the operations:" << std::endl;
    std::cout << "1. Show tree" << std::endl;
    std::cout << "2. Show list of nodes" << std::endl;
    std::cout << "  a. pre-order" << std::endl;
    std::cout << "  b. in-order" << std::endl;
    std::cout << "  c. post-order" << std::endl;
    std::cout << "3. Add node to tree" << std::endl;
    std::cout << "4. Remove node from tree" << std::endl;
    std::cout << "5. Save tree to file" << std::endl;
    std::cout << "6. Load tree from file" << std::endl;
    std::cout << "7. Check the existence of the node" << std::endl;
    std::cout << "8. Exit" << std::endl;

    while (true) {
        bool exit = false;
        int res;
        std::cout << "> ";
        std::cin >> res;

        // if bad command (can't convert to int)
        if (!std::cin) {
            std::cout << "Error command!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (res) {
        case 1:
        {
            tree.show();
            break;
        }
        case 2:
        {
            if (tree.isEmprty()) {
                std::cout << "Tree is empty!" << std::endl;
                break;
            }
            std::cout << "> ";
            char var;
            std::cin >> var;
            // switch
            if (var == 'a')
                tree.print(BSTree::traversal_order::pre);
            else if (var == 'b')
                tree.print(BSTree::traversal_order::in);
            else if (var == 'c')
                tree.print(BSTree::traversal_order::post);
            else
                std::cout << "Don't undertand traversal order!";

            std::cout << std::endl;
            break;
        }
        case 3:
            std::cout << "Enter value of node: " << std::endl;
            BSTree::Data temp;
            std::cin >> temp;

            if (std::cin && tree.insert(temp))
                std::cout << "Successful node addition!" << std::endl;
            else
                std::cout << "Error node addition!" << std::endl;
            break;
        case 4:
        {
            std::cout << "Enter value of node: " << std::endl;
            BSTree::Data temp;
            std::cin >> temp;

            if (std::cin) {
                if (tree.remove(temp))
                    std::cout << "Node removed!" << std::endl;
                else
                    std::cout << "Node does not exist!" << std::endl;
            } else {
                std::cout << "Wrong format!" << std::endl;
            }
            break;
        }
        case 5:
        {
            std::string path;
            std::cout << "Enter path: ";
            std::cin >> path;

            tree.save(path);

            break;
        }
        case 6:
        {
            std::string path;
            std::cout << "Enter path: ";
            std::cin >> path;

            tree.load(path);

            break;
        }
        case 7:
        {
            std::cout << "Enter value of node: " << std::endl;
            BSTree::Data temp;
            std::cin >> temp;

            if (std::cin) {
                if (tree.exists(temp))
                    std::cout << "The tree has this node!" << std::endl;
                else
                    std::cout << "The tree does not have this node!"
                                                     << std::endl;
            } else {
                std::cout << "Wrong format!" << std::endl;
            }
            break;
        }
        case 8:
        {
            std::cout << "Are you sure you want to quit? (y/n)" << std::endl;
            char t;
            std::cin >> t;
            if (t == 'y')
                exit = true;

            break;
        }
        default:
            std::cout << "Unknown command! " << res << std::endl;
            break;
        }
        // exit
        if (exit)
            break;
    }


    return 0;
}

