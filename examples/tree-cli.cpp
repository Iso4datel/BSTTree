// Copyright Iso3datel
#include <iostream>
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
    std::cout << "3. Add node to tree" << std::endl;
    std::cout << "4. Remove node from tree" << std::endl;
    std::cout << "5. Save tree to file" << std::endl;
    std::cout << "6. Load tree from file" << std::endl;
    std::cout << "7. Check the existence of the node" << std::endl;
    std::cout << "8. Exit" << std::endl;

    while (true) {
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
            //std::cout << "Вывод дерева на экран" << std::endl;
            break;
        case 3:
            std::cout << "Enter value of node: " << std::endl;
            BSTree::Data temp;
            std::cin >> temp;

            if (std::cin && tree.insert(temp))
                std::cout << "Successful node addition!" << std::endl;
            else
                std::cout << "Error node addition!" << std::endl;
            break;
        default:
            std::cout << "Unknown command! " << res << std::endl;
            break;
        }
    }

    return 0;
}
