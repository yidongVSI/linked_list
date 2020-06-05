#ifndef util_h_
#define util_h_

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>

class util {
 public:
  util() {}
  ~util() {} 

  static unsigned min_of_three(unsigned a, unsigned b, unsigned c) {
    return std::min(std::min(a,b), c);
  }
  static void print_int_matrix(int nrow, int ncol, int **t);
  static void print_str(char* a, int len);
  static void print_array(int* a, int m);
  static void print_float_array(float* a, int m);
  static void print_vec(std::vector<float> arr);
  template< typename T>
    static void print_list(std::list<T> lst)
    {
      std::cout << "List(" << lst.size() << "): [" << std::flush;
      for (typename std::list<T>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << ',';
      std::cout << "]" << std::endl;
    }

  template<typename T>
    static void print_graph_adj_list(std::vector<std::list<T> > adj_list)
    {
      std::cout << "Adjanent List(" << adj_list.size() << "): " << std::endl;
      for (size_t i = 0; i < adj_list.size(); i++)
      {
        typename std::list<T>::iterator it = adj_list[i].begin();
        std::cout << "Node " << i << ": [";
        for (; it != adj_list[i].end(); ++it)
          std::cout << *it << ',';
        std::cout << "]" << std::endl;
      }
      return;
    }

  template<typename T>
    static void print_stack(std::stack<T> s) {
      std::cout << "Stack( " << s.size() << "): [";
      while (!s.empty()) {
        std::cout << ' ' << s.top();
        s.pop();
      }
      std::cout << "]\n";
      return;
    }
};

#endif // util_h_