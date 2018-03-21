// Copyright Iso3datel
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <tree.hpp>



int main(int argc, char* argv[]) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // set argvs to vector
    std::vector<BSTTree::Data> arr;
    std::vector<std::string> str(argv + 1, argv + argc);
    for (int i = 0; i < str.size(); i++)
        arr.push_back(std::stoi(str[i]));

    // inti tree
    BSTTree::Tree tree(arr);

    // show menu
    std::cout << "Выберите одну из операций:" << std::endl;
    std::cout << "1. Вывести дерево на экран" << std::endl;
    std::cout << "2. Вывести список узлов дерева" << std::endl;
    std::cout << "3. Добавить узел в дерево" << std::endl;
    std::cout << "4. Удалить узел из дерева" << std::endl;
    std::cout << "5. Сохранить дерево в файл" << std::endl;
    std::cout << "6. Загрузить дерево из файла" << std::endl;
    std::cout << "7. Проверить наличие узла" << std::endl;
    std::cout << "8. Завершить работу программы" << std::endl;

    while (true) {
        int res;
        std::cout << "> ";
        std::cin >> res;

        switch (res) {
        case 1:
            std::cout << "Вывод дерева на экран" << std::endl;
            break;
        case 3:
            std::cout << "Введите занчение нового элемента: " << std::endl;
            BSTTree::Data temp;
            std::cin >> temp;

            if (tree.insert(temp))
                std::cout << "Элемент успешно добавлен!" << std::endl;
            else
                std::cout << "Ошибка добавления элемента!" << std::endl;
            break;
        default:
            std::cout << "Неизвестная команда: " << res << std::endl;
            break;
        }
    }


    std::cout << std::endl << std::endl;
    system("pause");
    return 0;
}
