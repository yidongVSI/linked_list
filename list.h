#ifndef list_h_
#define list_h_

#include "node.h"

//: Single-linked list
template <class T>
class linked_list {
 public:
  linked_list() : head_(nullptr) {}
  linked_list(node<T>* node_ptr) : head_(node_ptr) {}
  ~linked_list() {}

  node<T>* head_;

  //: count the size of the linked list, i.e. number of nodes inside the list
  unsigned size() const 
  {
    if (this->head_) {
      unsigned cnt = 0;
      node<T>* n = this->head_;
      while (n) {
        cnt++;
        n = n->next_;
      }
      return cnt;
    }
    else
      return 0;
  }

  //: check whether a node is in the list
  // equality of node is defined as: 1. data_ == data_ and 2. next_ == next_
  bool find(node<T>* n) {
    if (!this->head_)
      return false;
    node<T>* tmp = this->head_;
    while(tmp) {
      if (tmp == n)
        return true;
      else
        tmp = tmp->next_;
    }
    return false;
  }

  //: check whether a data is inside the list
  // O(n)
  bool find(T key) {
    if (!this->head_)
      return false;
    node<T>* tmp = this->head_;
    while(tmp) {
      if (tmp->data_ == key)
        return true;
      tmp = tmp->next_;
    }
    return false;
  }

  //: push to front
  void push_front(node<T>* n) {
    n->next_ = this->head_;
    this->head_ = n;
    return;
  }

  //: push to the end
  void push_back(node<T>* n) {
    if (this->head_) {
      node<T>* tmp = this->head_;
      while(tmp->next_) {
        tmp = tmp->next_;
      }  
      tmp->next_ = n;
    }
    else
      this->head_ = n;
    return;
  }

  //: insert node n to the next of given previous node prev_n
  int insert(node<T>* prev_n, node<T>* n)
  {
    if (!this->find(prev_n))
      return false;
    if (this->head_) {
      node<T>* tmp = this->head_;
      while(tmp) {
        if (tmp == prev_n) {
          n->next_ = tmp->next_;
          tmp->next_ = n;
          return true;
        }
        tmp = tmp->next_;
      }
    }
    else {
      this->head_ = n;
      return true;
    }
    return false;
  }

  //: delete a node given the value
  // note that it will delete the first key encounterd in the list
  bool delete_by_key(T key) {
    if (!this->find(key)) {
      std::cerr << "key: " << key << " is not in the list\n" << std::endl;
      return false;
    }
    node<T>* tmp = this->head_;
    // deal with delete head_
    if (tmp->data_ == key) {
      this->head_ = this->head_->next_;
      return true;
    }

    while(tmp) {
      if(tmp->next_->data_ == key) {
        tmp->next_ = tmp->next_->next_;
        return true;
      }
      tmp = tmp->next_;
    }
    return false;
  }

  //: print out the linked list
  void print() const
  {
    if (this->head_) {
      std::cout << "LinkedList(" << this->size() << "): [";
      node<T>* n = this->head_;
      while (n) {
        std::cout << n->data_ << ' ';
        n = n->next_;
      }
      std::cout << "]\n";
    }
    else {
      std::cout << "Empty list\n";
    }
  }

};

#endif // list_h_