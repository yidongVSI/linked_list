#ifndef remove_duplication_h_
#define remove_duplication_h_

#include <unordered_set>
#include "list.h"
#include "node.h"

template<class T>
class remove_duplication {
 public:
  static void remove_from_sorted_list(linked_list<T>& l)
  {
    
    // since it is sorted so the duplication must be connected to each other
    node<T>* ptr = l.head_;
    while(ptr) {
      if (ptr->data_ == ptr->next_->data_) 
      {
        // find duplication, operate and return
        node<T>* s = ptr;
        node<T>* e = ptr->next_;
        node<T>* tmp;
        while(e && e->data_ == s->data_) {
          tmp = e;
          e = e->next_;
          delete tmp;
        }
        s->next_ = e;
      }
      ptr = ptr->next_;
    }
    return;
  }

  static void remove_from_unsorted_list(linked_list<T>& l)
  {
    if(l.empty())
      return;
    // create a hash to store the visited value;
    std::unordered_set<T> hash;
    
    // loop over the list
    node<T>* curr = l.head_;
    node<T>* prev = l.head_;
    node<T>* next = l.head_->next_;
    while(curr) {
      if (hash.count(curr->data_)) {
        // find the element inside hash, clean it from list
        node<T>* tmp = curr;
        prev->next_ = next;
        curr = next;
        next = next->next_;  
        delete tmp;
      }
      else {
       hash.insert(curr->data_); 
       prev = curr;
       curr = next;
       next = next->next_;
      }
    }
    return;
  }
};


#endif 