//
// Created by ray on 18.11.2024.
//
#include "linkedlist.h"
#include "dynarray.h"

void printVector(Vector<double>& vector){
  for (int i = 0; i < vector.Size(); i++) {
	std::cout << vector[i] << " " ;
  }
  std::cout << std::endl;
}
int main() {

//  LinkedList<double> my_list;
//  my_list.pushBack(3.2);
//  my_list.pushBack(3.14);
  Vector<double> my_vec;
  my_vec.pushBack(1.1);
  printVector(my_vec);
  my_vec.pushBack(2.2);
  printVector(my_vec);
  my_vec.pushBack(3.1);
  printVector(my_vec);
  my_vec.insert(1, 2.1);
  printVector(my_vec);

  int i = 0;
}
