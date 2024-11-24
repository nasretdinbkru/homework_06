//
// Created by ray on 18.11.2024.
//
#include "linkedlist.h"
#include "dynarray.h"


void printVector(Vector<double>& vector) {
  for (int i = 0; i < vector.Size(); i++) {
	std::string endline = ", ";
	if (i == vector.Size() -1 )
	  endline = "";
	std::cout << vector[i] << endline;
  }
  std::cout << std::endl;
}

void printList(LinkedList<int>& list) {
  for (int i = 0; i < list.size(); i++) {
	std::string endline = ", ";
	if (i == list.size() -1 )
	  endline = "";
	std::cout << list.getAt(i)->data << endline;
  }
  std::cout << std::endl;
}






int main() {

  LinkedList<int> my_list;
  for (int i = 0; i <= 9; i++ ){
	my_list.pushBack(i);
  }
  std::cout << "=== Linked List ===\n";
  printList(my_list);
  std::cout << my_list.size() << "\n";

  my_list.erase(2);
  my_list.erase(3);
  my_list.erase(4);
  printList(my_list);
  my_list.insert(0, 10);
  printList(my_list);
  my_list.insert(4, 20);
  printList(my_list);
  my_list.pushBack(30);
  printList(my_list);

  std::cout << "=== Primitive Vector ===\n";


  Vector<double> vec;
  for (int i = 0; i <= 9; i++){
	vec.pushBack(i);
  }
  printVector(vec);
  std::cout << vec.Size() << "\n";
  vec.erase(2);
  vec.erase(3);
  vec.erase(4);
  printVector(vec);
  vec.insert(0, 10);
  printVector(vec);
  vec.insert(4,20);
  printVector(vec);
  vec.pushBack(30);
  printVector(vec);

}
