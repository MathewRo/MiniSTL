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
#include <list>

#ifdef __STDLIB__
#pragma message("compiling list for std lib!")
using namespace std;
#else 
#include "list.hpp"
using namespace miniSTL;
#endif

#include <stdexcept>
#include <gtest/gtest.h>

/**
 * print a list
 *
 * @param  : none
 * @return : none
 */
template<typename T>
  void
  print_list (list<T> &list)
  {
    for (auto &el : list)
    {
      print2(el, hex_once(&el));
    }
    nl();
  }

/**
 * compares custom list elements with standard list
 * elements
 *
 * @param  : none
 * @return : none
 */
template<typename T>
  void
  compare_list (list<T> &_l, std::list<T> &_l_std)
  {
    if (_l.begin () == _l.end ())
    {
      return;
    }

    auto _l_iter = _l.begin ();
    auto _l_valid_last = _l_iter;
    auto _l_std_iter = _l_std.begin ();
    auto _l_std_valid_last = _l_std_iter;

    for (; _l_iter != _l.end () && _l_std_iter != _l_std.end ();
        _l_iter++, _l_std_iter++)
    {
      ASSERT_EQ(*_l_iter, *_l_std_iter);
      _l_valid_last = _l_iter;
      _l_std_valid_last = _l_std_iter;
    }
    ASSERT_EQ(1, _l_iter == _l.end ());
    ASSERT_EQ(1, _l_std_iter == _l_std.end ());

    while (true)
    {
      ASSERT_EQ(*_l_valid_last, *_l_std_valid_last);
      if ((_l_valid_last == _l.begin ())
          || (_l_std_valid_last == _l_std.begin ()))
      {
        break;
      }
      _l_valid_last--;
      _l_std_valid_last--;
    }
    ASSERT_EQ(1, _l_valid_last == _l.begin ());
    ASSERT_EQ(1, _l_std_valid_last == _l_std.begin ());
  }

/**
 * default constructor test
 *
 * @param  : none
 * @return : const_iterator - to the end of the array
 */
TEST(list_test, constructor_default)
{
  list<int> l1;
  std::list<int> l1_std;

  print1(hex_once(&l1));
  compare_list (l1, l1_std);
}

TEST(list_test, constructor_size)
{
  list<int> l1 (5);
  std::list<int> l1_std (5);
  print1(hex_once(&l1));
  print_list (l1);
  compare_list (l1, l1_std);
}

TEST(list_test, constructor_fill)
{
  list<int> l1 (10, 5);
  std::list<int> l1_std (10, 5);
  print1(hex_once(&l1));
  print_list (l1);
  compare_list (l1, l1_std);
}

TEST(list_test, constructor_range)
{
  list<int> l1 (10, 5);
  std::list<int> l1_std (10, 5);
  list<int> l2 (l1.begin (), l1.end ());
  std::list<int> l2_std (l1_std.begin (), l1_std.end ());

  print1(hex_once(&l2));
  print_list (l2);
  compare_list (l2, l2_std);
}

TEST(list_test, constructor_copy)
{
  list<int> l1 (10, 5);
  std::list<int> l1_std (10, 5);
  list<int> l2 (l1.begin (), l1.end ());
  std::list<int> l2_std (l1_std.begin (), l1_std.end ());
  list <int> l3 (l2);
  std::list <int> l3_std(l2_std);

  print1(hex_once(&l3));
  print_list (l3);
  compare_list (l3, l3_std);
}

TEST(list_test, constructor_move)
{
  list<int> l1 (10, 5);
  std::list<int> l1_std (10, 5);
  list<int> l2 (l1.begin (), l1.end ());
  std::list<int> l2_std (l1_std.begin (), l1_std.end ());
  list <int> l3 (std::move(l2));
  std::list <int> l3_std(std::move(l2_std));

  print1(hex_once(&l3));
  print_list (l3);
  compare_list (l3, l3_std);
}

TEST(list_test, constructor_initializer_list)
{
  list<int> l1 = { 1, 2, 3, 4, 5, 6, 7 };
  std::list<int> l1_std = { 1, 2, 3, 4, 5, 6, 7 };

  print1(hex_once(&l1));
  print_list (l1);
  compare_list (l1, l1_std);
}

/**
 * main function for test setup
 *
 * @param  : int - number of args
 *         : char ** - list of args
 * @return : int - status of main
 */
int
main (int argc, char **argv)
{

  {
    /* Initializer list constructor test*/
    list<int> l7 = { 1, 2, 3, 4, 5, 6, 7 };
    print1("l7");
    print1(hex_once(&l7));
    print_list (l7);
    nl();
    /* erase test */
    auto iter_begin = l7.begin ();
    iter_begin++;
    iter_begin++;
    iter_begin++;
    iter_begin++;
    auto iter_end = iter_begin;
    iter_begin--;
    iter_begin--;
    l7.erase (iter_begin, iter_end);
    print_list (l7);
    nl();
  }
  {
    print1("assignment test");
    /* Assignment operator test*/
    list<int> l1 = { 'a', 'B', 'c', 'd', 'E' };
    print_list (l1);
    nl();
    /* copy assignment */
    list<int> l2;
    l2 = l1;
    print_list (l2);
    nl();
    /* move assignment */
    list<int> l3;
    l3 = std::move (l2);
    print_list (l3);
    nl();
    /* il list assignment */
    list<int> l4;
    l4 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    print_list (l4);
    nl();
  }

  {
    /* test front and back */
    print1("front/back test");
    /* back/front operator test*/
    list<int> l1 = { 'a', 'B', 'c', 'd', 'E' };
    print1(l1.back ());
    print1(l1.front ());
    /* const back/const front */
    const list<int> l2 = { 1, 2, 3 };
    print1(l2.back ());
    print1(l2.front ());nl();
  }

  {
    /* assign test */
    print1("assign test");
    nl();
    list<int> l1 = { 1, 2, 3 };
    list<int> l2;
    /* General assign to empty list */
    l2.assign (l1.begin (), l1.end ());
    print_list (l2);
    nl();
    list<int> l3 = { 4, 5, 6, 7 };
    /* assign to non-empty list with elements >
     that of current list */
    l2.assign (l3.begin (), l3.end ());
    print_list (l2);
    nl();
    list<int> l4 = { 8, 9 };
    /* assign to non-empty list with elements <
     that of current list */
    l2.assign (l4.begin (), l4.end ());
    print_list (l2);
    nl();

    /* size assign */
    l2.assign (10, 4);
    print_list (l2);
    nl();
    l2.assign (4, 8);
    print_list (l2);
    nl();

    /* initializer list assign */
    l2.assign ( { 12, 13, 14, 15, 16, 17, 18 });
    print_list (l2);
    nl();
    l2.assign ( { 90, 92, 98 });
    print_list (l2);
    nl();
  }
  {
    /* push_back/push_front/pop_back/pop_front*/
    list<int> l1 = { 1, 2, 3 };
    print_list (l1);
    nl();
    l1.push_front (4);
    l1.push_back (5);
    print_list (l1);
    nl();
    l1.push_front (l1.front ());
    l1.push_back (l1.back ());
    print_list (l1);
    nl();
    l1.pop_back ();
    l1.pop_front ();
    print_list (l1);
    nl();
    l1.pop_front ();
    print_list (l1);
    nl();
    l1.pop_front ();
    l1.pop_front ();
    l1.pop_front ();
    l1.pop_front ();
    print_list (l1);
    nl();
  }

  {
    /* list insert methods */
    list<int> l2 = { 12, 23, 34, 45 };
    list<int> l1 = { 1, 2, 3, 4, 5 };
    auto iter = l1.begin ();
    /* insert before head */
    iter = l1.insert (iter, 10);
    print_list (l1);
    nl();
    iter = l1.insert (iter, 4, 12);
    print_list (l1);
    nl();
    iter = l1.insert (iter, l2.begin (), l2.end ());
    print_list (l1);
    nl();
    iter = l1.insert (iter, { 99, 88, 77, 66, 55 });
    print_list (l1);
    nl();
  }

  testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();

#if 0
/* insert few elements at the end */
mylist.push_back(1);
mylist.push_back(2);
mylist.push_back(3);

for (auto &el : mylist)
{
print2(el, hex_once(&el));
}
nl();
for (auto iter = mylist.begin(); iter != mylist.end(); iter++)
{
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
