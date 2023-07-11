#include <LinkedList.hpp>
#include <iostream>
using namespace std;

template <class T>
Node<T>::Node()
{
}

template <class T>
void Node<T>::setinfo(T data)
{ // sets the info of the node
	this->_info = data;
}

template <class T>
void Node<T>::setnext(Node<T>* next)
{ // sets the next pointer to next Node of the Node.
	this->_next = next;
}

template <class T>
Node<T>* Node<T>::getnext()
{ // returns the pointer to the next Node .
	return _next;
}

template <class T>
T Node<T>::getData()
{ // returns the data stored in the node.
	return _info;
}

/*-----LinkedList------LinkedList--------*/
template <class T>
LinkedList<T>::LinkedList()
{ // Initializes an empty LinkedList.
	_HEAD = NULL;
}

template <class T>
bool LinkedList<T>::isEmpty()
{ // checks if the LinkedList is empty or not.
	if (_HEAD == NULL)
		return true;
	else
		return false;
}

template <class T>
bool LinkedList<T>::hasOneElement()
{ // checks if the LinkedList has only one element.
	if (_HEAD == _TAIL)
		return true;
	else
		return false;
}

// adds a node to the head of the LinkedList
template <class T>
Node<T>* LinkedList<T>::addToHead(T data)
{
	Node<T>* newnode = new Node<T>();
	newnode->setinfo(data);

	// sets the _HEAD and _TAIL to the new Node added. And,the next element of the only node to null
	if (isEmpty())
	{
		_HEAD = newnode;
		_TAIL = newnode;
		newnode->setnext(NULL);
	}

	// if the list is not empty , set the next of newnode to the _HEAD then  the _HEAD to the newnode
	else
	{
		newnode->setnext(_HEAD);
		_HEAD = newnode;
	}
	return newnode;
}

// adds a newnode to the Tail of the LinkedList.
template <class T>
Node<T>* LinkedList<T>::addToTail(T data)
{
	Node<T>* newnode = new Node<T>();
	newnode->setinfo(data);

	// if the list is empty, sets the _HEAD and _TAIL to the newnode i.e, newly added NOde
	if (isEmpty())
	{
		_HEAD = newnode;
		_TAIL = newnode;
		newnode->setnext(NULL);
	}
	// if the list is not empty, sets the next of newnode to NULL, next of present _TAIL to newnode and _TAIL to newnode
	else
	{
		newnode->setnext(NULL);
		this->_TAIL->setnext(newnode);
		_TAIL = newnode;
	}
	return newnode;
}

template <class T>
Node<T>* LinkedList<T>::add(T data, Node<T>* node)
{

	Node<T>* newnode = new Node<T>();
	newnode->setinfo(data);

	if (node == _TAIL)
		return addToTail(data);

	else if (node == _HEAD)
	{
		newnode->setnext(_HEAD->getnext());
		_HEAD->setnext(newnode);
		return newnode;
	}

	else
	{
		newnode->setnext(node->getnext());
		node->setnext(newnode);
		return newnode;
	}
}

template <class T>
T LinkedList<T>::removeFromHead()
{
	if (isEmpty())
	{
		cout << "The List is empty nothing to remove\n";
	}

	else
	{
		Node<T>* nodeToDelete = new Node<T>();
		nodeToDelete = _HEAD;
		T data = nodeToDelete->getData();

		if (hasOneElement())
			_HEAD = NULL;
		else
			_HEAD = _HEAD->getnext();
		delete nodeToDelete;
		return data;
	}
}

template <class T>
T LinkedList<T>::removeFromTail()
{
	if (isEmpty())
	{
		cout << "There is nothing to remove from the list" << endl;
	}
	else
	{
		Node<T>* nodeToDelete = _TAIL;
		T data = _TAIL->getData();
		if (hasOneElement())
			_HEAD = NULL;

		else
		{
			Node<T>* temp;
			temp = findprev(_TAIL);
			_TAIL = temp;
			temp->setnext(NULL);
			delete nodeToDelete;
			return data;
		}
	}
}

template <class T>
T LinkedList<T>::remove(Node<T>* node)
{

	if (node == _HEAD)
		return removeFromHead();
	else if (node == _TAIL)
		return removeFromTail();

	else
	{
		Node<T>* nodeToDelete = node;
		T data = nodeToDelete->getData();

		Node<T>* prev = findprev(node);

		prev->setnext(nodeToDelete->getnext());

		delete nodeToDelete;
		return data;
	}
}

template <class T>
T LinkedList<T>::remove(T data)
{
	Node<T>* nodeToDelete = retrive(data);

	return remove(nodeToDelete);
}

template <class T>
void LinkedList<T>::traverse()
{
	Node<T>* temp = _HEAD;

	while (temp != NULL)
	{
		cout << temp->getData() << endl;
		temp = temp->getnext();
	}
}

template <class T>
Node<T>* LinkedList<T>::findprev(Node<T>* node)
{
	Node<T>* temp = _HEAD;

	while ((temp->getnext()) != node)
	{
		temp = temp->getnext();
	}
	return temp;
}

template <class T>
Node<T>* LinkedList<T>::retrive(T data)
{

	for (Node<T>* temp = _HEAD; temp != NULL; temp = temp->getnext())
	{
		if (temp->getData() == data)
			return temp;
	}

	return NULL;
}

template <class T>
bool LinkedList<T>::search(T data)
{
	if ((retrive(data)) != NULL)
		return true;
	else
		return false;
}
