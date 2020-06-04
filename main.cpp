#include <iostream>
#include "node.h"
#include "list.h"

void test_node()
{
  node<int> left(1);
  node<int> right(1);
  left.next_ = &right;
  node<int> left1 = left;
  bool is_equal = left == right;
  std::cout << "equal: " << is_equal << std::endl;
  is_equal = left == left1;
  std::cout << "equal: " << is_equal << std::endl;
}

void intro_linked_list()
{
  node<int> head(1);
  node<int> second(2);
  node<int> third(3);
  head.next_ = &second;
  second.next_ = &third;

  head.print_node();
  second.print_node();
  third.print_node();

  // create a list:
  linked_list<int> l(&head);
  l.print();

  // test push to front
  node<int> new_node(4);
  l.push_front(&new_node);
  l.print();

  // test push back
  node<int> new_tail(6);
  l.push_back(&new_tail);
  l.print();

  // test find
  bool is_find = l.find(&new_node);
  std::cout << "node found: " << is_find << std::endl;

  // test insert
  node<int> insert_node(12);
  bool is_insert = l.insert(&second, &insert_node);
  l.print();
}

void test_delete()
{
  unsigned n = 5;
  node<int>* h = new node<int>(0);
  linked_list<int> l(h);
  for (unsigned i = 1; i <= n; i++) {
    node<int>* nd = new node<int>(i);
    std::cout << i << ": ";
    std::cout << " address of node: " << nd << ", ";
    nd->print_node();
    l.push_back(nd);
    // l.print();
  }
  l.print();

}

int main() {
  
  // intro_linked_list();
  test_delete();
}