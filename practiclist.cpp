#include <iostream>
#include "practiclist.h"

List::List()
{
	elements_counter =0;
	head = nullptr;
}

void List::push_back(int data)
{
	if(head  == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node *current = this->head;

		while(current->pnext!=nullptr)
		{
			current = current->pnext;
		}
		current->pnext = new Node(data);

	}
	elements_counter++;
}

List::~List()
{
	clear();
}

void List::operator[](const size_t index)
{

	int counter =0;
	Node *current = this->head;

	while(current!=nullptr)
	{
		if(counter == index)
		{
			std::cout<<current->data<<std::endl;
			break;
		}

		current = current->pnext;
		counter++;
	}

}

void List::pop_front()
{
	Node *temp = head;
	head = head->pnext;

	delete temp;
	elements_counter--;
}

void List::clear()
{
	while(elements_counter)
	{
		pop_front();
	}
}

void List::push_front(int data)
{
    head = new Node(data,head);
	elements_counter++;
}

void List::insert(int value,size_t index)
{

	if(index==0)
	{
		push_front(value);
	}

	else
	{

	Node *previus = this->head;

	for(int i = 0;i<index-1 ; i++)
	{
		previus = previus->pnext;
	}

	Node *newNode = new Node(value,previus->pnext);
	previus->pnext = newNode;

	elements_counter++;
	}
}

void List::removeAt(size_t index)
{
   if(index>0 && index<=elements_counter)
   {
	
	if(index==1)
	{
		pop_front();
	}

	else
	{
		
		Node *current = this->head;

		for(int i=0 ; i<index-2 ; i++)
		{
			current = current->pnext;
        }

		Node *toDelete = current->pnext;
		current->pnext = toDelete->pnext;

		delete toDelete;
		elements_counter--;
    }
  }

}

void List::pop_back()
{
	removeAt(elements_counter-1);
}

List::Node* List::getNode(const size_t pos) const
{

	if(pos<=elements_counter && pos>0)
	{

	  Node *current = this->head;

      for(int i=0  ;i<pos-1 ; ++i)
	  {
        current = current->pnext;
	  }
	  return current;
	}

else
{
	return 0;
	
}
}

void List::removeNextNode(Node *node)
{
	  if(node->pnext==nullptr)
	  {
	  }
	  
	  else 
	  {
		  Node *Delete  = node->pnext;

		  Node *newnext = Delete->pnext;

	      node->pnext = newnext;

		  delete Delete;

		  elements_counter--;
	  }
}
  
void List::insertAfterNode(Node* node, const ValueType& value)
{
	node->insertNext(value);
}

void List::Node::insertNext(const ValueType& value)
{
	Node* newNode = new Node(value, this->pnext);
	this->pnext = newNode;
}

long long int List::findIndex(const ValueType& value) const
{
	Node* current = this->head;
	long long int counter =0;
	
	while(current->pnext!=nullptr)
	{
		current = current->pnext;
		counter++;
		
		if(current->data==value)
		{
			return ++counter;
		}
		
	}
	
	return 0;
}

List::Node* List::findNode(const ValueType& value) const
{
	Node* current = this->head;
	
	while(current->pnext!=nullptr)
	{
		current = current->pnext;
		
		if(current->data==value)
		{
			return current;
		}
		
	}
	
	return 0;
}

void List::reverse()
{
   
 Node* previous = nullptr;
 Node* current = this->head;
 Node* following = this->head;

	while(current!=nullptr) 
	{
    following = following->pnext;
    current->pnext = previous;
    previous = current  ;        
    current = following;
	}
	
	this->head  = previous;
}

List& List::operator=(const List& copyList)
{
	if (this == &copyList) 
	{
		return *this;
	}
	List bufList(copyList);
	this->elements_counter = bufList.elements_counter;
	this->head = bufList.head;

	return *this;
}

List::List(const List& copyList)
{
	this->elements_counter	= copyList.elements_counter;
	if (this->elements_counter == 0) {
		this->head = nullptr;
		return;
	}

	this->head = new Node(copyList.head->data);

	Node* currentNode = this->head;
	Node* currentCopyNode = copyList.head;

	while (currentCopyNode->pnext) 
	{
		currentNode->pnext = new Node(currentCopyNode->pnext->data);
		currentCopyNode = currentCopyNode->pnext;
		currentNode = currentNode->pnext;
	}
}

List List::reverse() const
{
	List reversed (*this);
	reversed.reverse();

	return reversed;
}

List List::getReverseList() const
{
	List reversed = (*this);
	reversed.reverse();

	return reversed;
}

List& List::operator=(List&& moveList) noexcept
{
	if (this == &moveList) {
		return *this;
	}
	removeAt(1);
	this->elements_counter = moveList.elements_counter;
	this->head = moveList.head;

	moveList.elements_counter = 0;
	moveList.head = nullptr;

	return *this;
}

List::List(List&& moveList) noexcept
{
	this->elements_counter = moveList.elements_counter;
	this->head = moveList.head;

	moveList.elements_counter = 0;
	moveList.head = nullptr;
}

void List::forceNodeDelete(Node* node)
{
	if (node == nullptr) 
	{
		return;
	}

	Node* nextDeleteNode = node->pnext;
	delete node;
	forceNodeDelete(nextDeleteNode);
}

size_t List::GetElementsCounter()
{
	return elements_counter;
}
	
