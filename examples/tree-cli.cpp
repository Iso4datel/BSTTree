#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <tree.hpp>

/*

namespace ${Type}Tree
{
enum class traversal_order {pre, in, post};
class Tree {
public:
Tree();
Tree(std::initializer_list<int> list);
Tree(const Tree& tree);
Tree(Tree&& tree);
bool insert(int value);
bool exists(int value);
bool remove(int value);
bool save(const string& path);
bool load(const string& path);
void print(traversal_order order);
auto friend operator<<(ostream& stream, const Tree&) -> ostream& stream;
auto operator=(const Tree&) -> Tree&;
auto operator=(Tree&&) -> Tree&;
~Tree();
private:
Node* root;
};
}
*/


int main(int argc, char* argv[]) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Получаем параметры
	std::vector<BSTTree::Data> arr;
	std::vector<std::string> str(argv + 1, argv + argc);
	for (int i = 0; i < str.size(); i++)
		arr.push_back(std::stoi(str[i]));

	// Инициализируем дерево
	BSTTree::Tree tree(arr);

	// Вывод меню
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
		// Считываем значение
		int res;
		std::cout << "> ";
		std::cin >> res;

		switch (res)
		{
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