#include <utility>
#include "List.h"

List::Node::Node(int value, Node* prev, Node* next):
	value(value),
	prev(prev),
	next(next)
{
}

int List::Node::getValue() const
{
	return this->value;
}

void List::Node::setValue(int value)
{
	this->value = value;
}

List::Node* List::Node::getNext() const
{
	return this->next;
}

void List::Node::setNext(Node* next)
{
	this->next = next;
}

List::Node* List::Node::getPrev() const
{
	return this->prev;
}

void List::Node::setPrev(Node* prev)
{
	this->prev = prev;
}

List::List(): size(0), head(NULL), tail(NULL) { }

List::List(const List& other) { 
	addAll(other);
}

int List::first() const
{
	return this->head->getValue();
}

void List::add(int value)
{
	Node* node = new Node(0, NULL, NULL);
	node->setValue(value);

	// case 1: there are no nodes yeat
	if (head == NULL) {
		head = node;
		tail = head;
		size = 1;
	}
	else  
	{
		//case 2: inserting at the head of the lsit
		if (node->getValue() < head->getValue()) {
			node->setNext(head);
			head = node;
		}
		else
		//case 3: inserting at the end of the list
		if (node->getValue() > tail->getValue()) {
			node->setPrev(tail);
			tail->setNext(node);
			tail = node;
		}
		else
		{
			//case 4: in the middle (general case)
			Node* curr = head;
			while (curr && (node->getValue() > curr->getValue())) {
				curr = curr->getNext();
			}
			if (curr) {
				node->setNext(curr);
				node->setPrev(curr->getPrev());
				curr->getPrev()->setNext(node);
				curr->setPrev(node);
			}
		}
		size++;
	}	
}

void List::addAll(const List& other)
{
	head = tail = nullptr; size = 0;
	Node* temp = other.head;
	while (temp)
	{
		Node* p = tail;
		tail = new Node(temp->getValue(), p, nullptr);
		if (p)
			p->setNext(tail);
		else
			head = tail;
		temp = temp->getNext();
		size++;
	}
}

void List::removeFirst()
{ 
	if (this->getSize() > 1) {
		head = head->getNext();
		delete head->getPrev();
		head->setPrev(nullptr);
		this->size--;
	}
	else {
		Node* temp = head;
		head = head->getNext();
		delete temp;
		size--;
	}/*if (this->getSize() == 1) {
		this->head = this->head->getNext();
		delete this->head->getPrev();
		this->size--;
		head = tail = nullptr;
	}*/
	
}

void List::removeAll()
{
	Node* nextNode = nullptr;

	while (size) {
		nextNode = head->getNext();
		delete head;
		head = nextNode;
		size--;
	}
	
	tail = head = nullptr;
	/*Node* p = head;
	while (p) {
		head = head->getNext();
		delete p;
		p = nullptr;
		p = head;
	}
	head = tail = nullptr;*/
}

size_t List::getSize() const
{
	return this->size;
}

bool List::isEmpty() const
{
	if (size == 0)
		return true;
	return false;
}

List List::getReversed(List l)
{
	if (l.isEmpty())
		return l;
	
	List reversed;
	
	Node* tmp = NULL;
	Node* curr = l.tail;
	tmp = curr->getPrev();
	curr->setPrev(curr->getNext());
	curr->setNext(tmp);
	reversed.head = curr;
	while (tmp != NULL) {
		curr = tmp;
		tmp = curr->getPrev();
		curr->setPrev(curr->getNext());
		curr->setNext(tmp);
		
	}
	
	reversed.size = l.getSize();
	reversed.tail = curr;
	return reversed;
}

std::string List::toString() const
{
	size_t i = 0;
	std::string out = "";
	Node* node = this->head;
	
	while (this->getSize() - 1 != i) {
		out += std::to_string(node->getValue()) + " ";
		node = node->getNext();
		i++;
	}
	out += std::to_string(this->tail->getValue());
	return out;
}

List& List::operator<<(const int& value)
{
	this->add(value);

	return *this;
}

List& List::operator<<(const List& other)
{
return *this;
}

List& List::operator=(const List& other)
{
	removeAll();
	if (other.size == 0) {
		head = tail = nullptr;
		size = 0;
	}
	else {
		addAll(other);
	}
	return *this;
}

List::~List()
{
	removeAll();
}
