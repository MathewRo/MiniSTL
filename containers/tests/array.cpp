/*
 *
 * MIT License
 *
 * Copyright (c) 2021 Rohit Philip Mathew
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "common.hpp"

#ifdef __STDLIB__
#include <array>
#pragma message("compiling arrays for std lib!")
using namespace std;
#else 
#include "array.hpp"
using namespace miniSTL;
#endif


/* Test code for arrays */
int main() {
  array<int, 8> arr = {1,2,3,4,5,6,7,8};

  /*support for zero size array **/
  array<int, 0> zero_arr;
  print1(zero_arr.size());
  for (auto & el: zero_arr) {
    print1(el);
  }
  print1(hex_once(zero_arr.data()));
  print1(zero_arr.max_size());
#ifndef __STDLIB__
  print1(zero_arr.front());
#endif
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

  array<int,5> a = {10, 20, 30, 40, 50};
  array<int,5> b = {10, 20, 30, 40, 50};
  array<int,5> c = {50, 40, 30, 20, 10};



  if (a==b) print1("a and b are equal\n");
  if (b!=c) print1("b and c are not equal\n");
  if (b<c)  print1("b is less than c\n");
  if (c>b)  print1("c is greater than b\n");
  if (a<=b) print1("a is less than or equal to b\n");
  if (a>=b) print1("a is greater than or equal to b\n");
  /* observation - iterators and [] are simple references(&) of the buffer */
  return 0;

}
