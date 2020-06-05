#ifndef list_palindrome_h_
#define list_palindrome_h_

#include <stack>
#include "list.h"
#include "node.h"

template<class T>
class list_palindrome {
 public:
  static bool using_stack(linked_list<T> l) 
  {
    if (!l.head_)
      return false;

    // first loop of list to create the stack
    std::stack<T> s;
    node<T>* current = l.head_;
    while (current) {
      s.push(current->data_);
      current = current->next_;
    }
    // second loop to compare the value from stack to list
    current = l.head_;
    while (current) {
      if (s.top() != current->data_)
        return false;
      s.pop();
      current = current->next_;
    }
    return true;
  }

  static void reverse_list(linked_list<T>& l) 
  {
    if (!l.head_)
      return;
    node<T>* curr;
    node<T>* next;
    node<T>* prev;
    curr = l.head_->next_;
    prev = l.head_;
    next = l.head_->next_->next_; 
    prev->next_ = nullptr;
    while (next) {
      curr->next_ = prev;
      prev = curr;
      curr = next;
      next = next->next_;
      // next->print_node();
    }
    // curr is at last but its next pointer still not updated
    curr->next_ = prev;
    l.head_ = curr;
    // l.head_->print_node();
    return;
  }

  //: 1. break the list into two part from middle
  //: 2. reverse the second half
  //: 3. do the compare
  //: 4. merge the list back 
  static bool using_two_list(linked_list<T> l)
  {
    if (!l.head_)
      return true;
      
    // find the middle node by slow/fast pointer (this will reduce search time by half)
    node<T>* slow = l.head_;
    node<T>* fast = l.head_;
    while(fast && fast->next_) {
      slow = slow->next_;
      fast = fast->next_->next_;
    }

    // if list has odd number fast would be the last node --> slow would the middle one and should be move one step forward 
    // if list has even number, fast would be the null node
    node<T>* mid;
    if (fast) {
      mid = slow->next_;
    }
    else 
      mid = slow;
    
    linked_list<T> second_half(mid);
    reverse_list(second_half);
    
    node<T>* n1 = l.head_;
    node<T>* n2 = second_half.head_;
    // std::cout << "second half: ";  second_half.print();
    while(n2) {
      if (n1->data_ != n2->data_) {
        // merge it back before we return
        reverse_list(second_half);
        return false;
      }
      n1 = n1->next_;
      n2 = n2->next_;
    }

    // merge them back
    reverse_list(second_half);
    
    return true;
    
  }

};

#endif // list_palindrome_h_
