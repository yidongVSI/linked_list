#ifndef node_h_
#define node_h_

#include <iostream>

template <class T>
class node 
{
 public:
  node() {}
  node(T data) : data_(data) { next_ = nullptr; }
  ~node() {}

  T data_;
  node<T>* next_;

  bool operator==(node<T>const& p) const
  { return this==&p || (data_== p.data_ && next_ == p.next_); }

  void print_node() const
  {
    std::cout << "data: " << this->data_;
    if (this->next_)
      std::cout << ", next(data): " << this->next_->data_;
    else
      std::cout << ", next(NULL)";
    std::cout << "\n";
  }

};

#endif // node_h_