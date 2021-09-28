#pragma once
#include <iostream>
#include <cassert>
#include <vector>

template <typename T>
class Node {
public:
	T data;
	Node* next;
	int pos;
	Node(T data, int pos) {
		this->data = data;
		this->pos = pos;
		this->next = nullptr;
	}
};

template<typename T>
class Sparse_list
{
public:
	Sparse_list() {
		this->root = nullptr;
		this->n = 0;
	}
	Sparse_list(int n) :Sparse_list() {
		this->n = n;
	}
	~Sparse_list() {
		Node<T>* current = this->root;
		while (current) {
			Node<T>* node_for_deleting = current;
			current = current->next;
			delete node_for_deleting;
		}
	}
	void add(T data, int index) {
		assert(((index < this->n) && index>=0), "Incorrect element's index");
		Node<T>* current = this->root;
		if (!this->root)
		{
			this->root = new Node<T>(data, index);
		}
		else if (index < current->pos) {
			this->root = new Node<T>(data, index);
			this->root->next = current;
		}
		else if (index == current->pos) {
			current->data = data;
		}
		else {
			while (current->next) {
				if (current->next->pos == index)
				{
					current->next->data = data;
					return;
				}
				else if (current->next->pos > index) {
					Node<T>* new_node = new Node<T>(data, index);
					new_node->next = current->next;
					current->next = new_node;
					return;
				}
				current = current->next;
			}
			current->next = new  Node<T>(data, index);
		}
	}
	T operator[](int index) {
		assert(((index < this->n) && index >= 0), "Incorrect element's index");
		Node<T>*current = this->root;
		while (current) {
			if (current->pos==index)
			{
				return current->data;
			}
			if (current->pos>index)
			{
				return 0;
			}
			current = current->next;
		}
		return 0;
	}
	std::vector<int> positions_by_element(int data) {
		std::vector<int> result(0);
		Node<T>* current = this->root;
		while (current) {
			if (current->data==data)
			{
				result.push_back(current->pos);
			}
			current = current->next;
		}
		return result;
	}

	void print() {
		Node<T> *current = this->root;
		for (int i = 0; i < this->n; i++)
		{
			if (current)
			{
				if (current->pos == i)
				{
					std::cout << current->data << "\t";
					current = current->next;
					continue;
				}
			}
			std::cout << 0 << "\t";
		}
		std::cout << "\n";
	}
protected:
	Node<T>* root;
	int n;
};

template<typename T>
class Sparse_matrix
{
public:
	Sparse_matrix() {
		this->m = 0;
		this->n = 0;
		this->root = nullptr;
	}
	Sparse_matrix(int m, int n) :Sparse_matrix() {
		this->m = m;
		this->n = n;
	}
	~Sparse_matrix() {
		Node<T>* current = this->root;
		while (current) {
			Node<T>* node_for_deleting = current;
			current = current->next;
			delete node_for_deleting;
		}
	}

	Sparse_matrix(const Sparse_matrix& copy) {
		this->n = copy.n;
		this->m = copy.m;
		this->root = nullptr;
		if (!copy.root)
		{
			return;
		}

		Node<T>* copy_current = copy.root;
		this->root = new Node<T>(copy.root->data, copy.root->pos);
		Node<T>* new_current = this->root;

		while (copy_current->next) {
			new_current->next = new Node<T>(copy_current->next->data, copy_current->next->pos);

			copy_current = copy_current->next;
			new_current = new_current->next;
		}

	}
	Sparse_matrix operator= (const Sparse_matrix& copy) {
		this->n = copy.n;
		this->m = copy.m;
		this->root = nullptr;
		if (!copy.root)
		{
			return *this;
		}

		Node<T>* copy_current = copy.root;
		this->root = new Node<T>(copy.root->data, copy.root->pos);
		Node<T>* new_current = this->root;

		while (copy_current->next) {
			new_current->next = new Node<T>(copy_current->next->data, copy_current->next->pos);

			copy_current = copy_current->next;
			new_current = new_current->next;
		}
		return *this;
	}
	void add_to_matrix(T data, int i, int j) {
		assert((i < m & j < n & i >= 0 & j >= 0), "Position is incorrect");
		int index = i * this->n + j;
		Node<T>* current = this->root;
		if (!this->root)
		{
			this->root = new Node<T>(data, index);
		}
		else if (index < current->pos) {
			this->root = new Node<T>(data, index);
			this->root->next = current;
		}
		else if (index == current->pos) {
			current->data = data;
		}
		else {
			while (current->next) {
				if (current->next->pos == index)
				{
					current->next->data = data;
					return;
				}
				else if (current->next->pos > index) {
					Node<T>* new_node = new Node<T>(data, index);
					new_node->next = current->next;
					current->next = new_node;
					return;
				}
				current = current->next;
			}
			current->next = new  Node<T>(data, index);
		}
	}
	T get(int i, int j) {
		int index = i * this->n + j;
		assert(((index < this->n* this->m) && index >= 0), "Incorrect element's index");
		Node<T>* current = this->root;
		while (current) {
			if (current->pos == index)
			{
				return current->data;
			}
			if (current->pos > index)
			{
				return 0;
			}
			current = current->next;
		}
		return 0;
	}
	void print() {
		Node<T>* current = this->root;
		for (int i = 0; i < this->n * this->m; i++)
		{
			if (i % this->n == 0 && i > 0)
			{
				std::cout << std::endl;
			}
			if (current)
			{
				if (current->pos == i)
				{
					std::cout << current->data << "\t";
					current = current->next;
					continue;
				}
			}
			std::cout << 0 << "\t";
		}
		std::cout << "\n";
	}

	Sparse_matrix operator+ (Sparse_matrix& added) {//this + added
		Sparse_matrix<T> sum(this->m, this->n);
		//fast method
		/*Node<T>* current = nullptr;
		Node<T>* current_A = this->root;
		Node<T>* current_B = added.root;
		if (this->m == added.m && this->n == added.n)
		{
			while (current_A || current_B) {
				if (current_A && current_B)
				{
					if (current_A->pos == current_B->pos) {
						if (sum.root)
						{
							current->next = new Node<T>(current_A->data + current_B->data, current_A->pos);;
							current = current->next;
						}
						else {
							sum.root = new Node<T>(current_A->data + current_B->data, current_A->pos);
							current = sum.root;
						}
						current_A = current_A->next;
						current_B = current_B->next;
					}
					else if (current_A->pos > current_B->pos) {
						if (sum.root)
						{
							current->next = new Node<T>(current_B->data, current_B->pos);;
							current = current->next;
						}
						else {
							sum.root = new Node<T>(current_B->data, current_B->pos);
							current = sum.root;
						}
						current_B = current_B->next;
					}
					else {
						if (sum.root)
						{
							current->next = new Node<T>(current_A->data, current_A->pos);;
							current = current->next;
						}
						else {
							sum.root = new Node<T>(current_A->data, current_A->pos);
							current = sum.root;
						}
						current_A = current_A->next;
					}
					continue;
				}
				if (current_A)
				{
					if (sum.root)
					{
						current->next = new Node<T>(current_A->data, current_A->pos);;
						current = current->next;
					}
					else {
						sum.root = new Node<T>(current_A->data, current_A->pos);
						current = sum.root;
					}
					current_A = current_A->next;
					continue;
				}
				if (current_B)
				{
					if (sum.root)
					{
						current->next = new Node<T>(current_B->data, current_B->pos);;
						current = current->next;
					}
					else {
						sum.root = new Node<T>(current_B->data, current_B->pos);
						current = sum.root;
					}
					current_B = current_B->next;
					continue;
				}
			}
			return sum;
		}
		else {
			return sum;
		}*/

		//short code
		for (int i = 0; i < this->m; i++)
		{
			for (int j = 0; j < this->n; j++)
			{
				T a = this->get(i, j);
				T b = added.get(i, j);
				if ((a + b) != 0)
				{
					sum.add_to_matrix(a + b, i, j);
				}
			}
		}
		return sum;
	}
	Sparse_matrix operator* (Sparse_matrix& multiplier) {//this + added
		Sparse_matrix<T> result(this->m, this->n);
		int a = 0;
		for (int i = 0; i < this->m; i++) {
			for (int j = 0; j < multiplier.n; j++) {
				a = 0;

				for (int k = 0; k < multiplier.n; k++) {
					a += this->get(i, k) * multiplier.get(k, j);
				}

				if (a!=0)
				{
					result.add_to_matrix(a, i, j);
				}
			}


		}
		return result;
	}
	Sparse_matrix transitive() {
		Sparse_matrix<T> result(this->n, this->m);
		Node<T>* current = this->root;
		while (current)
		{
			result.add_to_matrix(current->data, current->pos % this->n,current->pos/this->n );
			current = current->next;
		}
		return result;
	}
	

private:
	int m;
	int n;
	Node<T>* root;
};
