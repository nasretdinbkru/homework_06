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
	const auto DEFAULT_VECTOR_SIZE = 8;
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
  Vector(const Vector& rhs){
	size = rhs.size;
	capacity= rhs.capacity;
	elements = new T[capacity];
	for (int i = 0; i < rhs.size; i++){
	  elements[i] = rhs.elements[i];
	}
  }
  ~Vector() {
	delete[] elements;
  }

  [[nodiscard]] int Size() const{
	return size;
  }
  [[nodiscard]] int Capacity() const{
	return capacity;
  }
  [[nodiscard]] bool IsEmpty() const{
	return size == 0;
  }
  T& operator[](int index) {
	return elements[index];
  }
  const T& operator[](int index) const {
	return elements[index];
  }
  Vector& operator=(const Vector& other);

  void PushBack(const T& object) {
	if (size == capacity){
	  T* newarr = new  T[capacity * 2];
	  for (int i = 0; i < size; i++){
		newarr[i] = elements[i];
	  }
	  delete[] elements;
	  elements = newarr;
	  capacity = capacity * 2;
	}
	elements[size] = object;
	size++;
  }
  void PopBack() {

  }
  void Erase(int index) {

  }
  void Clear() {

  }
  void Insert(int index, T value) {

  }

};

#endif //CONTAINERS__DYNARRAY_H_
