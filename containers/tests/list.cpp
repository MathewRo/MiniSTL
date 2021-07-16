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
#if 0
  for (auto &el : list)
    {
      print2(el, hex_once(&el));
    }
    nl();
#endif
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
      print2(*_l_iter, *_l_std_iter);
      ASSERT_EQ(*_l_iter, *_l_std_iter);
      _l_valid_last = _l_iter;
      _l_std_valid_last = _l_std_iter;
    }
    ASSERT_EQ(1, _l_iter == _l.end ());
    ASSERT_EQ(1, _l_std_iter == _l_std.end ());
    nl();
    while (true)
    {
//      print2(*_l_valid_last, *_l_std_valid_last);
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
    print2(_l.size (), _l_std.size ());
    ASSERT_EQ(1, _l.size () == _l_std.size ());
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
  list<int> l3 (l2);
  std::list<int> l3_std (l2_std);

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
  list<int> l3 (std::move (l2));
  std::list<int> l3_std (std::move (l2_std));

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

TEST(list_test, erase_method)
{
  /* Initializer list constructor test*/
  list<int> l1 = { 1, 2, 3, 4, 5, 6, 7 };
  print1(hex_once(&l1));
  print_list (l1);
  auto l1_iter = l1.begin ();
  l1_iter++;
  l1_iter++;
  l1_iter++;
  l1_iter++;
  auto l1_iter_end = l1_iter;
  l1_iter--;
  l1_iter--;
  l1.erase (l1_iter, l1_iter_end);

  std::list<int> l1_std = { 1, 2, 3, 4, 5, 6, 7 };
  auto l1_std_iter = l1_std.begin ();
  l1_std_iter++;
  l1_std_iter++;
  l1_std_iter++;
  l1_std_iter++;
  auto l1_std_iter_end = l1_std_iter;
  l1_std_iter--;
  l1_std_iter--;
  l1_std.erase (l1_std_iter, l1_std_iter_end);

  compare_list (l1, l1_std);
}

TEST(list_test, swap_test)
{
  list<int> l1 = { 1, 2, 3, 4, 5, 6, 7 };
  list<int> l2 = { 21, 31, 41 };
  std::list<int> l1_std = { 1, 2, 3, 4, 5, 6, 7 };
  std::list<int> l2_std = { 21, 31, 41 };
  l1.swap (l2);
  l1_std.swap (l2_std);
  compare_list (l1, l1_std);
  compare_list (l2, l2_std);
}

TEST(list_test, assignment_operator)
{
  /* Assignment operator test*/
  list<int> l1 = { 'a', 'B', 'c', 'd', 'E' };
  print_list (l1);
  /* copy assignment */
  list<int> l2;
  l2 = l1;
  print_list (l2);
  /* move assignment */
  list<int> l3;
  l3 = std::move (l2);
  print_list (l3);
  /* il list assignment */
  list<int> l4;
  l4 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  print_list (l4);

  /* Assignment operator test*/
  std::list<int> l1_std = { 'a', 'B', 'c', 'd', 'E' };
  /* copy assignment */
  std::list<int> l2_std;
  l2_std = l1_std;
  /* move assignment */
  std::list<int> l3_std;
  l3_std = std::move (l2_std);
  /* il list assignment */
  std::list<int> l4_std;
  l4_std = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  compare_list (l1, l1_std);
  compare_list (l2, l2_std);
  compare_list (l3, l3_std);
  compare_list (l4, l4_std);
}

TEST(list_test, front_back_test)
{
  /* test front and back */
  list<int> l1 = { 'a', 'B', 'c', 'd', 'E' };
  print1(l1.back ());
  print1(l1.front ());
  /* const back/const front */
  const list<int> l2 = { 1, 2, 3 };
  print1(l2.back ());
  print1(l2.front ());

  std::list<int> l1_std = { 'a', 'B', 'c', 'd', 'E' };
  /* const back/const front */
  const std::list<int> l2_std = { 1, 2, 3 };

  ASSERT_EQ(1, l1.back () == l1_std.back ());
  ASSERT_EQ(1, l1.front () == l1_std.front ());
  ASSERT_EQ(1, l2.back () == l2_std.back ());
  ASSERT_EQ(1, l2.front () == l2_std.front ());
}

TEST(list_test, assign_test)
{
  /* assign test */
  list<int> l1 = { 1, 2, 3 };
  list<int> l2;
  std::list<int> l1_std = { 1, 2, 3 };
  std::list<int> l2_std;

  /* General assign to empty list */
  l2.assign (l1.begin (), l1.end ());
  l2_std.assign (l1_std.begin (), l1_std.end ());
  compare_list (l2, l2_std);
  print_list (l2);

  list<int> l3 = { 4, 5, 6, 7 };
  /* assign to non-empty list with elements >
   that of current list */
  l2.assign (l3.begin (), l3.end ());
  std::list<int> l3_std = { 4, 5, 6, 7 };
  l2_std.assign (l3_std.begin (), l3_std.end ());
  compare_list (l2, l2_std);
  print_list (l2);

  list<int> l4 = { 8, 9 };
  /* assign to non-empty list with elements <
   that of current list */
  l2.assign (l4.begin (), l4.end ());
  std::list<int> l4_std = { 8, 9 };
  l2_std.assign (l4_std.begin (), l4_std.end ());
  compare_list (l2, l2_std);
  print_list (l2);

  l2.assign (10, 4);
  l2_std.assign (10, 4);
  compare_list (l2, l2_std);
  print_list (l2);

  l2.assign (4, 8);
  l2_std.assign (4, 8);
  compare_list (l2, l2_std);
  print_list (l2);

  /* initializer list assign */
  l2.assign ( { 12, 13, 14, 15, 16, 17, 18 });
  l2_std.assign ( { 12, 13, 14, 15, 16, 17, 18 });
  compare_list (l2, l2_std);
  print_list (l2);

  l2.assign ( { 90, 92, 98 });
  l2_std.assign ( { 90, 92, 98 });
  compare_list (l2, l2_std);
  print_list (l2);

}

TEST(list_test, push_back)
{
  {
    /* push_back/push_front/pop_back/pop_front*/
    list<int> l1 = { 1, 2, 3 };

    l1.push_front (4);
    l1.push_back (5);
    std::list<int> l1_std = { 1, 2, 3 };
    l1_std.push_front (4);
    l1_std.push_back (5);
    compare_list (l1, l1_std);

    l1.push_front (l1.front ());
    l1.push_back (l1.back ());
    l1_std.push_front (l1_std.front ());
    l1_std.push_back (l1_std.back ());
    compare_list (l1, l1_std);

    l1.pop_back ();
    l1.pop_front ();
    l1_std.pop_back ();
    l1_std.pop_front ();
    compare_list (l1, l1_std);

    l1.pop_front ();
    l1.pop_front ();
    l1.pop_front ();
    l1.pop_front ();
    l1.pop_front ();
    l1_std.pop_front ();
    l1_std.pop_front ();
    l1_std.pop_front ();
    l1_std.pop_front ();
    l1_std.pop_front ();
    compare_list (l1, l1_std);
  }
}

TEST(list_test, insert)
{
  {
    /* list insert methods */
    list<int> l2 = { 12, 23, 34, 45 };
    list<int> l1 = { 1, 2, 3, 4, 5 };
    auto iter = l1.begin ();
    std::list<int> l2_std = { 12, 23, 34, 45 };
    std::list<int> l1_std = { 1, 2, 3, 4, 5 };
    auto iter_std = l1_std.begin ();

    /* insert before head */
    iter = l1.insert (iter, 10);
    iter_std = l1_std.insert (iter_std, 10);
    compare_list (l1, l1_std);

    iter = l1.insert (iter, 4, 12);
    iter_std = l1_std.insert (iter_std, 4, 12);
    compare_list (l1, l1_std);

    iter = l1.insert (iter, l2.begin (), l2.end ());
    iter_std = l1_std.insert (iter_std, l2_std.begin (), l2_std.end ());
    compare_list (l1, l1_std);

    iter = l1.insert (iter, { 99, 88, 77, 66, 55 });
    iter_std = l1_std.insert (iter_std, { 99, 88, 77, 66, 55 });
    compare_list (l1, l1_std);

  }
}

TEST(list_test, resize_test)
{
  {
    list<int> l1;
    std::list<int> l1_std;

    for (int i = 1; i < 10; ++i)
    {
      l1.push_back (i);
      l1_std.push_back(i);
    }

    l1.resize (5);
    l1_std.resize(5);
    l1.resize (8, 100);
    l1_std.resize(8, 100);
    l1.resize (12);
    l1_std.resize(12);
    compare_list (l1, l1_std);

  }
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

  testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
