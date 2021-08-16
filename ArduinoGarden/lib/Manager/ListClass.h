#ifndef LISTDEFINE
#define LISTDEFINE

#include <stdint.h>
#include <Arduino.h>

template<typename T>
class List {
private:
	class Node
	{
	public:
		T* data;
		Node* next;
		~Node() {
			delete data;
		}
	};
	Node* _startNode;
	Node* _currentNode;
	uint8_t _countNodes;
public:
List() {
	_startNode = nullptr;
	_currentNode = nullptr;
	_countNodes = 0;
}
T* operator [](uint8_t index) {
	Node* tmp = _startNode;
	for (uint8_t i = 0; i < index; i++)
	{
		tmp = tmp->next;
	}
	return tmp->data;
}

void Add(T* element) {

	if (_countNodes == 0) {
		_startNode = new Node();
		_startNode->data = element;
		_startNode->next = nullptr;
		_countNodes++;
		return;
	}
	Node* tmp = _startNode;
	for (uint8_t i = 1; i < _countNodes; i++)
	{
		tmp = tmp->next;
	}
	tmp->next = new Node();
	tmp = tmp->next;
	tmp->data = element;
	tmp->next = nullptr;
	_countNodes++;
}
void Clear() {
	if (_countNodes == 0) return;
	Node* tmp = _startNode;
	for (uint8_t i = 0; i < _countNodes; i++)
	{
		tmp = tmp->next;
		delete _startNode;
		_startNode = tmp;
	}
	_countNodes = 0;
}
uint8_t Length() {
	return _countNodes;
}
void RemoveAt(uint8_t id) {
	Node* tmp;
	Node* tmp2;
	tmp = _startNode;
	if (id == 0) {

		tmp = tmp->next;
		delete _startNode;
		_startNode = tmp;
		_countNodes--;
		return;
	}
	for (uint8_t i = 1; i < id; i++)
	{
		tmp = tmp->next;
	}
	tmp2 = tmp->next->next;
	delete tmp->next;
	tmp->next = tmp2;
	_countNodes--;
}
void Remove(T* data) {
	Node* tmp;
	Node* tmp2;
	tmp = _startNode;
	if (_startNode->data == data) {
		tmp = tmp->next;
		delete _startNode;
		_startNode = tmp;
		_countNodes--;
		return;
	}
	for (uint8_t i = 1; i < _countNodes; i++)
	{
		if (tmp->next->data == data) {
			tmp2 = tmp->next->next;
			delete tmp->next;
			tmp->next = tmp2;
			_countNodes--;
			return;
		}
		tmp = tmp->next;
	}
}
void SetStart() {
	_currentNode = _startNode;
}
T* Next() {
	Node* tmp = _currentNode;
	if (tmp == nullptr) return nullptr;
	_currentNode = _currentNode->next;
	return tmp->data;
}
~List() {
	Clear();
}
};
#endif
