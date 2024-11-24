//
// Created by ray on 18.11.2024.
//

#ifndef CONTAINERS__DYNARRAY_H_
#define CONTAINERS__DYNARRAY_H_

template<typename T>
class Vector {
 private:
  int size;
  int capacity;
  T* elements;

 public:
  Vector() {
	size = 0;
	const auto DEFAULT_VECTOR_SIZE = 1;
	capacity = DEFAULT_VECTOR_SIZE;
	elements = new T[DEFAULT_VECTOR_SIZE];
  }
  Vector(int n, const T& value) {
	size = n;
	capacity = n * 2;
	elements = new T[capacity];
	for (int i = 0; i < size; i++) {
	  elements[i] = value;
	}
  }
  Vector(const Vector& rhs) {
	size = rhs.size;
	capacity = rhs.capacity;
	elements = new T[capacity];
	for (int i = 0; i < rhs.size; i++) {
	  elements[i] = rhs.elements[i];
	}
  }
  ~Vector() {
	delete[] elements;
  }

  [[nodiscard]] int Size() const {
	return size;
  }
  [[nodiscard]] int Capacity() const {
	return capacity;
  }
  [[nodiscard]] bool IsEmpty() const {
	return size == 0;
  }
  T& operator[](int index) {
	return elements[index];
  }
  const T& operator[](int index) const {
	return elements[index];
  }
  Vector& operator=(const Vector& rhs) {
	if (rhs.size > size) {
	  delete[] elements;
	  capacity = rhs.size * 2;
	  elements = new T[capacity];
	}
	for (int i = 0; i < rhs.size; i++) {
	  elements[i] = rhs.elements[i];
	}
	size = rhs.size;
	return *this;
  }

  void pushBack(const T& object) {
	if (size == capacity) {
	  T* newarr = new T[capacity * 2];
	  for (int i = 0; i < size; i++) {
		newarr[i] = elements[i];
	  }
	  delete[] elements;
	  elements = newarr;
	  capacity = capacity * 2;
	}
	elements[size] = object;
	size++;
  }
  void popBack() {
	if (size > 0) {
	  size--;
	}

  }
  void erase(int index) {
	for (int i = index; i < size - 1; i++) {
	  elements[i] = elements[i + 1];
	}
	size--;

  }
  void clear() {
	size = 0;

  }

  void insert(int index, const T value) {
	Vector<T> tmp;

	for (int i = 0; i < size; i++) {
	  if (i != index) {
		tmp.pushBack(elements[i]);

	  } else {
		tmp.pushBack(value);
		tmp.pushBack(elements[i]);
	  }
	}

	delete[] elements;
	size++;
	capacity = size * 2;
	elements = new T[capacity];
	for (int i = 0; i < tmp.size; i++) {
	  elements[i] = tmp.elements[i];
	}
  }
};

#endif //CONTAINERS__DYNARRAY_H_
