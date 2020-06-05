#include "util.h"

void util::print_array(int *a, int m)
{
  std::cout << "Array: [";
  for (unsigned i = 0; i < m-1; i++)
    std::cout << a[i] << ',';
  std::cout << a[m-1] << "]\n";
}

void util::print_float_array(float* a, int m)
{
  std::cout << "Array: [";
  for (unsigned i = 0; i < m-1; i++)
    std::cout << a[i] << ',';
  std::cout << a[m-1] << "]\n";
}

void util::print_int_matrix(int nrow, int ncol, int **t)
{
  std::cout << "Matrix: " << nrow << "x" << ncol << std::endl;
  if (nrow == 0 || ncol == 0) {
    std::cout << "Empty Matrix" << std::endl;
    return;
  }
  std::cout << '[';
  for (int i = 0; i < nrow-1; i++) {
    std::cout << '[';
    for (int j = 0; j < ncol-1; j++) {
      std::cout << t[i][j] << ',';
    }
    std::cout << t[i][ncol-1] << "]\n";
  }
  std::cout << '[';
  for (int j = 0; j < ncol-1; j++) {
    std::cout << t[nrow-1][j] << ',';
  }
  std::cout << t[nrow-1][ncol-1] << "]]\n";
  std::cout << std::endl;
  return;
}
void util::print_str(char* a, int len)
{
  for (int i = 0; i < len; i++)
    std::cout << a[i];
  std::cout << std::endl;
}

void util::print_vec(std::vector<float> vec)
{
  std::cout << "Array(" << vec.size() << "): [" << std::flush;
  if (vec.empty())
    std::cout << "]\n";
  else {
    for (size_t i = 0; i < vec.size()-1; i++)
      std::cout << vec[i] << ',';
    std::cout << vec[vec.size()-1] << "]\n";
  }
  return;
}


