#pragma once
#include <vector>

namespace BSTTree {

	typedef int Data;
	typedef unsigned int u_int;


	// ��������� ���� 
	struct Node {
		Data data;		// ������� �������� ����
		Node* left;		// ��������� �� ����� ����
		Node* right;	// ��������� �� ������ ����


		Node(const Data data, Node* left = nullptr, Node* right = nullptr);
		~Node();
	};

	// ����� ������
	class Tree {
		Node* root = nullptr;

	public:

		// ������� �������� 
		bool insert(Data value);

		// ����������� � ����������
		Tree(const std::vector<Data> & arr);
		~Tree();
	};

}