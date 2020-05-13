#include <cstddef>
#ifndef PRACTICLIST_H 
#define PRACTICLIST_H

using ValueType = double;

class List
{
    class Node
	{
		public:
		Node *pnext;
		int data;

		Node(int data = int(), Node *pnext = nullptr)
		{
			this->data = data;
			this->pnext = pnext;
		}
		void insertNext(const ValueType& value);
	};

public:
	List();
	~List();
	void pop_front();
    void push_back(int data);
    size_t GetElementsCounter();
	void operator[](const size_t index);
	void clear();
	void push_front(int data);
    void insert(int value,size_t index);
	void removeAt(size_t index);
	void pop_back();
	Node* getNode(const size_t pos) const;
	void removeNextNode(Node *node);
	static void insertAfterNode(Node* node, const ValueType& value);
	long long int findIndex(const ValueType& value) const;
	Node* findNode(const ValueType& value) const;
	void reverse();
	List& operator=(const List& copyList);
	List(const List& copyList);
	List reverse() const;
	List getReverseList() const;
	List& operator=(List&& moveList) noexcept;
	List(List&& moveList) noexcept;
	void forceNodeDelete(Node* node);

private:
	Node* head;
	size_t elements_counter;
};

#endif 
