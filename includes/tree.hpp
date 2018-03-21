#pragma once
#include <vector>

namespace BSTTree {

	typedef int Data;
	typedef unsigned int u_int;


	// Структура ноды 
	struct Node {
		Data data;		// Текущее значение узла
		Node* left;		// Указатель на левый узел
		Node* right;	// Указатель на правый узел


		Node(const Data data, Node* left = nullptr, Node* right = nullptr);
		~Node();
	};

	// Класс дерева
	class Tree {
		Node* root = nullptr;

	public:

		// Вставка элемента 
		bool insert(Data value);

		// Конструктор и деструктор
		Tree(const std::vector<Data> & arr);
		~Tree();
	};

}