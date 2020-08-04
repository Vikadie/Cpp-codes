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

List::List(const List& other): size(other.size), head(other.head), tail(other.tail) { }

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
	this->head = other.head;
	this->size = other.size;
	this->tail = other.tail;
}

void List::removeFirst()
{ 
	if (this->getSize() > 1) {
		head = head->getNext();
		delete head->getPrev();
		head->setPrev(nullptr);
		this->size--;
	}
	else if (this->getSize() == 1) {
		removeAll();
	}
}

void List::removeAll()
{
	Node* nextNode = nullptr;

	while (this->head) {
		nextNode = head->getNext();
		delete head;
		head = nextNode;
		size--;
	}
	tail = nullptr;
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
	// case 1: this is empty
	if (this->isEmpty())
		*this = other;
	// case 2: all elements of other are bigger than this
	/*else if (other.first() > this->tail->getValue()) {
		this->addAll(other);
	} 
	// case 3: all elements of this are bigger than other
	else if (other.tail->getValue() < this->first()) {
		getReversed(getReversed(*this)->addAll(getReversed(other)));
	}*/
	else {

	}

return *this;
}

List& List::operator=(const List& other)
{
	//if (this != &other) {
		this->addAll(other);
	//}
	

	return *this;
}

List::~List()
{
	//removeAll();
}
