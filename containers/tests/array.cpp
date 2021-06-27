#include "array.hpp"
#include "common.hpp"

/* Test code for arrays */
int main() {
  miniSTL::array<int, 8> arr = {1,2,3,4,5,6,7,8};

  /*support for zero size array **/
  miniSTL::array<int, 0> zero_arr;
  print1(zero_arr.size());
  for (auto & el: zero_arr) {
    print1(el);
  }
  print1(hex_once(zero_arr.data()));
  print1(zero_arr.max_size());
  print1(zero_arr.front());
  nl();  

  /* address of the object in memory */	
  print1(hex_once(&arr));
  /* size of arr */
  print1(arr.size());
  /* max size of arr */
  print1(arr.max_size());
  /* if arr is empty or not */
  print1(arr.empty());

  for (auto &el : arr) {
    print2(el, hex_once(&el));
  }
  nl();	
  /* iterators */
  for (auto iter = arr.begin(); iter != arr.end(); iter++) {
    /* The only reason we can actually print out an iterator is because
       iterator for array<> is generally a typedef for Tp * where Tp is the
       type for the particular instance. If we try to do the same for any 
       other container, we would end up with compilation errors as iterator
       might be implemented as custom types where << has not been overloaded */
    print2(*iter, hex_once(iter));
  }
  nl();
  for (size_t i = 0; i < arr.size(); i++ ) {
    print2(arr[i], &arr[i]);
  }
  nl();
  print1(arr.front());
  print1(arr.back());
  print1(arr.data());
  arr.fill(12);
  try {
    print1(arr.at(6));
  } catch (...) {
    print1("some random exception!");
  }

  miniSTL::array<int,5> a = {10, 20, 30, 40, 50};
  miniSTL::array<int,5> b = {10, 20, 30, 40, 50};
  miniSTL::array<int,5> c = {50, 40, 30, 20, 10};



  if (a==b) print1("a and b are equal\n");
  if (b!=c) print1("b and c are not equal\n");
  if (b<c)  print1("b is less than c\n");
  if (c>b)  print1("c is greater than b\n");
  if (a<=b) print1("a is less than or equal to b\n");
  if (a>=b) print1("a is greater than or equal to b\n");
  /* observation - iterators and [] are simple references(&) of the buffer */
  return 0;

}
