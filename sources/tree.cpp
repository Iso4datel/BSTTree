#include <tree.hpp>


BSTTree::Node::Node(const Data data, Node* left, Node* right)
	: data(data), left(left), right(right) {
}

BSTTree::Node::~Node() {
	delete left;
	delete right;
};

// Вставка элемента 
bool BSTTree::Tree::insert(Data value) {

	Node* node = new Node(value);

	// Если корня нет - создаем
	if (!root)
		root = node;
	else {

		// Текущее место
		Node* cur_ptr = root;

		while (true) {

			// Если идем по правой ветви
			if (node->data > cur_ptr->data) {

				// Если правой ветви не существует  
				if (!cur_ptr->right) {
					cur_ptr->right = node;
					break;
				}
				else
					cur_ptr = cur_ptr->right;
			}

			// Если идем по левой части
			if (node->data < cur_ptr->data) {

				// Если левой ветви не существует 
				if (!cur_ptr->left) {
					cur_ptr->left = node;
					break;
				}
				else
					cur_ptr = cur_ptr->left;
			}

			// Если элементы совпали
			if (node->data == cur_ptr->data) {
				delete node;
				return false;
			}

		}

	}

	return true;

}

// Конструктор
BSTTree::Tree::Tree(const std::vector<Data> & arr) {
	for (const auto& a : arr)
		insert(a);
}

// Утечка памяти
BSTTree::Tree::~Tree() {

}