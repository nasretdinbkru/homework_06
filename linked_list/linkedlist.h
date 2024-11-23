//
// Created by ray on 18.11.2024.
//

#ifndef LINKED_LIST__LINKEDLIST_H_
#define LINKED_LIST__LINKEDLIST_H_

#include <iostream>
template<typename T>
class Node {
 public:
  T data;
  Node* prev;
  Node* next;
  explicit Node(T data_) {
	data = data_;
	prev = nullptr;
	next = nullptr;
  }
};

template<typename T>
class LinkedList {
 public:
  LinkedList() {
	head = nullptr;
	tail = nullptr;
	size_ = 0;
  }

  Node<T>* pushFront(T data) {
	T* ptr = new T(data);
	ptr->next = head;
	if (head != nullptr) {
	  head->prev = ptr;
	}
	if (tail == nullptr) {
	  tail = ptr;
	}
	head = ptr;
	size_++;
	return ptr;
  }
  Node<T>* pushBack(T data) {
	auto* ptr = new Node<T>(data);
	ptr->prev = tail;
	if (tail != nullptr) {
	  tail->prev = ptr;
	}
	if (head == nullptr) {
	  head = ptr;
	}
	tail = ptr;
	size_++;
	return ptr;
  }
  void popFront() {
	if (head == nullptr) return;
	auto* ptr = head->next;
	if (ptr != nullptr) {
	  ptr->prev = nullptr;
	} else {
	  tail = nullptr;
	}
	delete head;
	size_--;
	head = ptr;
  }

  void popBack() {
	if (tail == nullptr) return;
	T* ptr = tail->prev;
	if (ptr != nullptr) {
	  ptr->next = nullptr;
	} else {
	  head = nullptr;
	}
	delete tail;
	size_--;
	tail = ptr;
  }
  Node<T>* getAt(uint32_t index) const {
	Node<T>* ptr = head;
	uint32_t n = 0;
	while (n != index) {
	  if (ptr == nullptr) {
		return ptr;
	  }
	  ptr = ptr->next;
	  n++;
	}
	return ptr;
  }
  Node<T>* operator[](uint32_t index) const {
	return getAt(index);
  }
  Node<T>* insert(uint32_t index, T data) {
	Node<T>* right = getAt(index);
	if (right == nullptr) {
	  return pushBack(data);
	}
	Node<T>* left = right->prev;
	if (left == nullptr) {
	  return pushFront(data);
	}
	Node<T>* ptr = new T(data);
	ptr->prev = left;
	ptr->next = right;
	left->next = ptr;
	right->prev = ptr;
	size_++;
	return ptr;
  }
  void erase(uint32_t index) {
	Node<T>* ptr = getAt(index);
	if (ptr == nullptr) return;
	if (ptr->prev == nullptr) {
	  popFront();
	  return;
	}
	if (ptr->next == nullptr) {
	  popBack();
	  return;
	}
	Node<T>* left = ptr->prev;
	Node<T>* right = ptr->next;
	left->next = right;
	right->prev = left;
	delete ptr;
	size_--;
  }
  ~LinkedList() {
	while (head != nullptr) {
	  popFront();
	}
  }
  size_t size() {
	return size_;
  }
 private:
  Node<T>* head;
  Node<T>* tail;
  size_t size_;
};

#endif //LINKED_LIST__LINKEDLIST_H_
