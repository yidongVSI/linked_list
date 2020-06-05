#include <iostream>
#include "node.h"
#include "list.h"
#include "list_palindrome.h"
#include "remove_duplication.h"

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

  // clean up list
  node<int>* current = l.head_;
  node<int>* next;
  while(current) {
    next = current->next_;
    delete current;
    current = next;
  }
}

template<typename T>
void clear_list(linked_list<T> l)
{
  if (!l.head_)
    return;
  node<T>* current = l.head_;
  node<T>* next;
  while(current) {
    next = current->next_;
    delete current;
    current = next;
  }
  return;
}

void test_circle()
{
  // create a list with circle
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
  // create a circle
  l.head_->next_->next_->next_->next_->next_->next_ = l.head_->next_;
  l.head_->next_->next_->next_->next_->next_->print_node();
  l.head_->print_node();
  if (l.is_circle())
    std::cout << "List is a circle!" << std::endl;

  unsigned circle_length = l.count_circle();
  std::cout << "circle length: " << circle_length << std::endl;
  clear_list(l);
  return;
}

void test_reverse()
{
   // create a list with circle
  unsigned n = 5;
  node<int>* h = new node<int>(0);
  linked_list<int> l(h);
  for (unsigned i = 1; i <= n; i++) {
    node<int>* nd = new node<int>(i);
    nd->print_node();
    l.push_back(nd);
    // l.print();
  }
  l.print();
  // reverse list
  std::cout << "reverse..." << std::endl;
  list_palindrome<int>::reverse_list(l);
  l.print();
  clear_list(l);
  return; 
}

void test_index()
{
  // create a list with circle
  unsigned n = 5;
  node<int>* h = new node<int>(0);
  linked_list<int> l(h);
  for (unsigned i = 1; i <= n; i++) {
    node<int>* nd = new node<int>(i);
    l.push_back(nd);
  }
  l.print();
  // reverse list
  for (unsigned i = 0; i < l.size(); i++) {
    std::cout << "node " << i << ": ";
    l[i]->print_node();
  }
  clear_list(l);
  return; 
}

void test_palindrome()
{
  node<char> n1('R');
  node<char> n2('A');
  node<char> n3('D');
  node<char> n4('A');
  node<char> n5('R');
  node<char> n6('R');

  linked_list<char> l(&n1);
  l.push_back(&n2);
  l.push_back(&n3);
  l.push_back(&n4);
  l.push_back(&n5);
  // l.push_back(&n6);

  l.print();

  bool is_p = list_palindrome<char>::using_two_list(l);
  std::cout << "is_P: " << is_p << std::endl;
  l.print();

  is_p = list_palindrome<char>::using_stack(l);
  std::cout << "is_P using stack: " << is_p << std::endl;
  l.print();

  return;
}

void test_remove_duplication()
{
  node<int>* n1 = new node<int>(2);
  node<int>* n2 = new node<int>(2);
  node<int>* n3 = new node<int>(2);
  node<int>* n4 = new node<int>(3);
  node<int>* n5 = new node<int>(4);
  node<int>* n6 = new node<int>(4);
  linked_list<int> l(n1);
  l.push_back(n2);
  l.push_back(n3);
  l.push_back(n4);
  l.push_back(n5);
  l.push_back(n6);
  l.print();

  remove_duplication<int>::remove_from_sorted_list(l);
  l.print();
}

void test_remove_duplication_unsorted()
{
  node<int>* n1 = new node<int>(3);
  node<int>* n2 = new node<int>(15);
  node<int>* n3 = new node<int>(7);
  node<int>* n4 = new node<int>(8);
  node<int>* n5 = new node<int>(3);
  node<int>* n6 = new node<int>(7);
  linked_list<int> l(n1);
  l.push_back(n2);
  l.push_back(n3);
  l.push_back(n4);
  l.push_back(n5);
  l.push_back(n6);
  l.print();
  
  remove_duplication<int>::remove_from_unsorted_list(l);
  l.print();

}

int main() {
  
  // intro_linked_list();
  // test_circle();
  // test_index();
  // test_remove_duplication();
  test_remove_duplication_unsorted();
}