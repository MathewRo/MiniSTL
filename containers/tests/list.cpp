/*
 *
 * MIT License
 *
 * Copyright (c) 2021 Rohit Philip Mathew
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the &quot;Software&quot;), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED &quot;AS IS&quot;, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
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
#include <list>
#pragma message("compiling list for std lib!")
using namespace std;
#else 
#include "list.hpp"
using namespace miniSTL;
#endif

  template <typename T>
void print_list(list<T> &list) 
{
  for (auto &el : list)
  {
    print2(el, hex_once(&el));
  }
}

int main() {

  {
    /* default constructor test */
    list<int> l1;
    print1("l1");
    print1(hex_once(&l1));
    nl();
  }
  {
    /* size constructor test */
    list<int> l2(5);
    print1("l2");
    print1(hex_once(&l2));
    print_list(l2);
    nl();
    list<int>::iterator iter_begin = l2.begin();
    l2.erase(iter_begin);
    print_list(l2);
    nl();
    iter_begin = l2.begin();
    l2.erase(iter_begin++);
    print_list(l2);
    nl();
  }
  {
    /* fill constructor test */
    list<int> l3(10, 5);
    print1("l3");
    print1(hex_once(&l3));
    print_list(l3);

    /* range constructor test */
    list<int> l4(l3.begin(), l3.end());
    print1("l4");
    print1(hex_once(&l4));
    print_list(l4);

    /* copy constructor test*/
    list<int> l5(l4);
    print1("l5");
    print1(hex_once(&l5));
    print_list(l5);

    /* move constructor test*/
    list<int> l6(std::move(l3));
    print1("l6");
    print1(hex_once(&l6));
    print_list(l6);
    nl();
    l6.erase(l6.begin(), l6.end());
    print_list(l6);
    nl();
  }
  {
    /* Initializer list constructor test*/
    list<int> l7 = {1,2,3,4,5,6,7};
    print1("l7");
    print1(hex_once(&l7));
    print_list(l7);
    nl();
    /* erase test */
    auto iter_begin = l7.begin();
    iter_begin++;iter_begin++;iter_begin++;iter_begin++;
    auto iter_end = iter_begin;
    iter_begin--;iter_begin--;
    l7.erase(iter_begin, iter_end);
    print_list(l7);
    nl();
  }
  {
    print1("assignment test");
    /* Assignment operator test*/
    list<int> l1 = {'a', 'B', 'c', 'd', 'E'};
    print_list(l1);nl();
    /* copy assignment */
    list<int> l2;
    l2  = l1;
    print_list(l2);nl();
    /* move assignment */
    list<int> l3;
    l3 = std::move(l2);
    print_list(l3);nl();
    /* il list assignment */
    list<int> l4;
    l4 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print_list(l4);nl();
  }

  {
    /* test front and back */    
    print1("front/back test");
    /* back/front operator test*/
    list<int> l1 = {'a', 'B', 'c', 'd', 'E'};
    print1(l1.back());
    print1(l1.front());
    /* const back/const front */
    const list<int> l2 = {1, 2, 3};
    print1(l2.back());
    print1(l2.front());nl();
  }

  {
    /* assign test */
    print1("assign test");nl();
    list<int> l1 = {1, 2, 3};
    list<int> l2;
    /* General assign to empty list */
    l2.assign(l1.begin(), l1.end());
    print_list(l2);nl();
    list<int> l3 = {4, 5, 6, 7};
    /* assign to non-empty list with elements > 
       that of current list */
    l2.assign(l3.begin(), l3.end());
    print_list(l2);nl();
    list<int> l4 = {8, 9};
    /* assign to non-empty list with elements <
       that of current list */
    l2.assign(l4.begin(), l4.end());
    print_list(l2);nl();

    /* size assign */
    l2.assign(10, 4);
    print_list(l2);nl();
    l2.assign(4, 8);
    print_list(l2);nl();  

    /* initializer list assign */
    l2.assign({12, 13, 14, 15, 16, 17, 18});
    print_list(l2);nl();
    l2.assign({90, 92, 98});
    print_list(l2);nl();  
  }
  {
    /* push_back/push_front/pop_back/pop_front*/
    list<int> l1 = {1, 2, 3};
    print_list(l1);nl();
    l1.push_front(4);
    l1.push_back(5);
    print_list(l1);nl();
    l1.push_front(l1.front());
    l1.push_back(l1.back());
    print_list(l1);nl();
    l1.pop_back();
    l1.pop_front();
    print_list(l1);nl();
    l1.pop_front();
    print_list(l1);nl();
    l1.pop_front();
    l1.pop_front();
    l1.pop_front();
    l1.pop_front();
    print_list(l1);nl();
  }

  {
    /* list insert methods */
    list<int> l2 = {12, 23, 34, 45};
    list<int> l1 = {1, 2, 3, 4, 5};
    auto iter = l1.begin();
    /* insert before head */
    iter = l1.insert(iter, 10);
    print_list(l1);nl();
    iter = l1.insert(iter, 4, 12);
    print_list(l1);nl();
    iter = l1.insert(iter, l2.begin(), l2.end());
    print_list(l1);nl();
    iter = l1.insert(iter, {99, 88, 77, 66, 55});
    print_list(l1);nl();
  }

#if 0
  /* insert few elements at the end */
  mylist.push_back(1);
  mylist.push_back(2);
  mylist.push_back(3);

  for (auto &el : mylist) {
    print2(el, hex_once(&el));		
  }
  nl();
  for (auto iter = mylist.begin(); iter != mylist.end(); iter++) {
    /* We can't directly print out iterators as they are objects just like our list.
       The address of list and iterator are in similar ranges probably because its a
       nested class implementation. However the range for loops actually print a 
       different address for the reference. This should be because the individual nodes
       in the list come from heap*/
    print2(*iter, hex_once(&iter));
  } 
  nl();
  /* insert few elements at the begining */
  //mylist.push_front();

  //mylist.pop_back();
  //mylist.pop_front();
#endif
  return 0;
}
