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

	// �������� ���������
	std::vector<BSTTree::Data> arr;
	std::vector<std::string> str(argv + 1, argv + argc);
	for (int i = 0; i < str.size(); i++)
		arr.push_back(std::stoi(str[i]));

	// �������������� ������
	BSTTree::Tree tree(arr);

	// ����� ����
	std::cout << "�������� ���� �� ��������:" << std::endl;
	std::cout << "1. ������� ������ �� �����" << std::endl;
	std::cout << "2. ������� ������ ����� ������" << std::endl;
	std::cout << "3. �������� ���� � ������" << std::endl;
	std::cout << "4. ������� ���� �� ������" << std::endl;
	std::cout << "5. ��������� ������ � ����" << std::endl;
	std::cout << "6. ��������� ������ �� �����" << std::endl;
	std::cout << "7. ��������� ������� ����" << std::endl;
	std::cout << "8. ��������� ������ ���������" << std::endl;

	while (true) {
		// ��������� ��������
		int res;
		std::cout << "> ";
		std::cin >> res;

		switch (res)
		{
		case 1:
			std::cout << "����� ������ �� �����" << std::endl;
			break;
		case 3:
			std::cout << "������� �������� ������ ��������: " << std::endl;
			BSTTree::Data temp;
			std::cin >> temp;

			if (tree.insert(temp))
				std::cout << "������� ������� ��������!" << std::endl;
			else
				std::cout << "������ ���������� ��������!" << std::endl;
			break;
		default:
			std::cout << "����������� �������: " << res << std::endl;
			break;
		}

	}


	std::cout << std::endl << std::endl;
	system("pause");
	return 0;
}