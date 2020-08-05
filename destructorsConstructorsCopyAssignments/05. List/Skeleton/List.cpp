#include "List.h"
#include <utility>

List::Node::Node(int value, Node* prev, Node* next)
	:value(value), prev(prev), next(next) {}

int List::Node::getValue() const
{
	return value;
}

void List::Node::setValue(int value)
{
	this->value = value;
}

List::Node* List::Node::getNext() const
{
	return next;
}

void List::Node::setNext(Node* next)
{
	this->next = next;
}

List::Node* List::Node::getPrev() const
{
	return prev;
}

void List::Node::setPrev(Node* prev)
{
	this->prev = prev;
}

List::List() : size(0)
{
	head = tail = nullptr;
}

List::List(const List& other)
{
	addAll(other);
}

int List::first() const
{
	return head->getValue();
}

void List::add(int value)
{
	Node* p = tail;
	tail = new Node(value, p, nullptr);

	if(p)
		p->setNext(tail);
	else
		head = tail;
}

void List::addAll(const List& other)
{
	head = tail = nullptr;
	Node* tmp = other.head;
	while (tmp)
	{
		Node* p = tail;
		tail = new Node(tmp->getValue(), p, nullptr);
		if (p)
			p->setNext(tail);
		else
			head = tail;
		tmp = tmp->getNext();
	}
}

void List::removeFirst()
{
	Node* temp = head;
	head = head->getNext();
	delete temp;
}

void List::removeAll()
{
	Node* p = head;
	while(p)
	{
		head = head->getNext();
		delete p;
		p = head;
	}
	head = tail = nullptr;
}


bool List::isEmpty() const
{
	return head == nullptr;
}

std::string List::toString() const
{
	std::string res;
	Node* p = head;
	while(p)
	{
		res += (std::to_string(p->getValue()) + " ");
		p = p->getNext();
	}
	return std::move(res);
}

List& List::operator<<(const int& value)
{
	this->add(value);
	return *this;
}

List& List::operator=(const List& other)
{
	if(this != &other)
	{
		removeAll();
		addAll(other);
	}
	return *this;
}

List::~List()
{
	removeAll();
}