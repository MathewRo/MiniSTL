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

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stddef.h>
#include <stdbool.h>
#include <initializer_list>
#include <algorithm>

namespace miniSTL
{

  template<typename T, size_t _size>
    class array
    {
    public:

      /* typedefs */
      typedef T value_type;
      typedef value_type *pointer;
      typedef const pointer const_pointer;
      typedef value_type &reference;
      typedef const reference const_reference;
      typedef value_type *iterator;
      typedef const iterator const_iterator;
      typedef value_type *reverse_iterator;
      typedef const reverse_iterator const_reverse_iterator;
      typedef size_t size_type;

      /* public interfaces */
      /* we are not adding anything specifc for zero sized arrays.
       Please understand that for _size == 0, behavior is undefined,
       though it may work without any crash */

      /// Modifiers ///
      /**
       * fill/assign the array elements with required values
       * iterators
       *
       * @param  : const value_type& - the value to be assigned
       *           to each element
       *
       * @return : none
       */
      void
      fill (const value_type &val)
      {
        for (size_type i = 0; i < _size; i++)
        {

          buffer[i] = val;
        }
      }

      /**
       * replace the elements in the array with the elements from
       * the array that is passed as a param
       *
       * @param  : array&  - array from which the values need to be
       *                     assigned
       * @return : none
       */
      void
      swap (array &x) noexcept
      {
        /* This function should not throw exceptions */
        for (size_type i = 0; i < (_size < x.size () ? _size : x.size ()); i++)
        {
          buffer[i] = x[i];
        }
      }

      /// Element access ///

      /**
       * return the element at the position pointed by the param
       *
       * @param  : size_type  - index/position
       *
       * @return : reference - to the element at the position
       */
      reference
      at (size_type n)
      {
        return buffer[n];
      }

      /**
       * return the element at the position pointed by the param
       *
       * @param  : size_type  - index/position
       *
       * @return : const_reference - to the element at the position
       */
      const_reference
      at (size_type n) const
      {
        return buffer[n];
      }

      /**
       * operator [] overloaded to access element at position
       * pointed by the index
       *
       * @param  : size_type  - index/position
       *
       * @return : reference - to the element at the position
       */
      reference
      operator[] (size_type n)
      {
        return buffer[n];
      }

      /**
       * operator [] overloaded to access element at position
       * pointed by the index
       *
       * @param  : size_type  - index/position
       *
       * @return : const_reference - to the element at the position
       */
      const_reference
      operator[] (size_type n) const
      {
        return buffer[n];
      }

      /**
       * returns a reference to the element at the start of
       * the array
       *
       * @param  : none
       *
       * @return : reference - to the element at the start
       */
      reference
      front ()
      {
        return buffer[0];
      }

      /**
       * returns a reference to the element at the start of
       * the array
       *
       * @param  : none
       *
       * @return : const_reference - to the element at the start
       */
      const_reference
      front () const
      {
        return buffer[0];
      }

      /**
       * returns a reference to the element at the end of
       * the array
       *
       * @param  : none
       *
       * @return : reference - to the element at the end
       */
      reference
      back ()
      {
        return buffer[_size - 1];
      }

      /**
       * returns a reference to the element at the end of
       * the array
       *
       * @param  : none
       *
       * @return : const_reference - to the element at the end
       */
      const_reference
      back () const
      {
        return buffer[_size - 1];
      }

      /**
       * return a raw pointer to the start of array
       *
       * @param  : none
       *
       * @return : value_type* - pointer to start
       */
      value_type*
      data () noexcept
      {
        return (pointer) &buffer[0];
      }

      /**
       * return a raw pointer to the start of array
       *
       * @param  : none
       *
       * @return : const value_type* - pointer to start
       */
      const value_type*
      data () const noexcept
      {
        return (const_pointer) &buffer[0];
      }

      /// capacity ///

      /**
       * return the size of the array
       *
       * @param  : none
       *
       * @return : size_type - size of the array
       */
      constexpr size_type
      size () const noexcept
      {
        return _size;
      }

      /**
       * return the max size of array
       *
       * @param  : none
       *
       * @return : size_type - size of array
       */
      constexpr size_type
      max_size () const noexcept
      {
        return _size;
      }

      /**
       * checks if the array is empty
       *
       * @param  : none
       *
       * @return : bool - true if array is empty,
       *                  false otherwise
       */
      constexpr bool
      empty () const noexcept
      {
        return _size == 0;
      }

      /// iterators ////

      /**
       * returns a iterator to the start of array
       *
       * @param  : none
       *
       * @return : iterator - to the start of the array
       */
      iterator
      begin () noexcept
      {
        return &buffer[0];
      }

      /**
       * returns a constant iterator to the start of array
       *
       * @param  : none
       *
       * @return : const_iterator - to the start of the array
       */
      const_iterator
      begin () const noexcept
      {
        return (const_iterator) &buffer[0];
      }

      /**
       * returns a constant iterator to the start of array
       *
       * @param  : none
       *
       * @return : const_iterator - to the start of the array
       */
      const_iterator
      cbegin () const noexcept
      {
        return &buffer[0];
      }

      /**
       * returns a iterator to the end of array
       *
       * @param  : none
       *
       * @return : iterator - to the end of the array
       */
      iterator
      end () noexcept
      {
        return &buffer[_size];
      }

      /**
       * returns a  iterator to the end of array
       *
       * @param  : none
       *
       * @return : const_iterator - to the end of the array
       */
      const_iterator
      end () const noexcept
      {
        return (const_iterator) &buffer[_size];
      }

      /**
       * returns a constant iterator to the end of array
       *
       * @param  : none
       *
       * @return : const_iterator - to the end of the array
       */
      const_iterator
      cend () const noexcept
      {
        return &buffer[_size];
      }

      /* array is typincally defined as an aggregates in STL. Refer spec to understand more */
      T buffer[_size];
    };

  /**
   * == operator overloaded for array comparison
   *
   * @param  : const array<T, N> - lhs array
   *         : const array<T, N> - rhs array
   *
   * @return : bool - true if lhs == rhs
   *           false otherwise
   */
  template<class T, size_t N>
    bool
    operator== (const array<T, N> &lhs, const array<T, N> &rhs)
    {
      return (lhs.size () == rhs.size ()
          && std::equal (lhs.begin (), lhs.end (), rhs.begin ()));
    }

  /**
   * != operator overloaded for array comparison
   *
   * @param  : const array<T, N> - lhs array
   *         : const array<T, N> - rhs array
   *
   * @return : bool - true if lhs != rhs
   *           false otherwise
   */
  template<class T, size_t N>
    bool
    operator!= (const array<T, N> &lhs, const array<T, N> &rhs)
    {
      return !(lhs == rhs);
    }

  /**
   * < operator overloaded for array comparison
   *
   * @param  : const array<T, N> - lhs array
   *         : const array<T, N> - rhs array
   *
   * @return : bool - true if lhs < rhs
   *           false otherwise
   */
  template<class T, size_t N>
    bool
    operator< (const array<T, N> &lhs, const array<T, N> &rhs)
    {
      return (std::lexicographical_compare (lhs.begin (), lhs.end (),
                                            rhs.begin (), rhs.end ()));
    }

  /**
   * > operator overloaded for array comparison
   *
   * @param  : const array<T, N> - lhs array
   *         : const array<T, N> - rhs array
   *
   * @return : bool - true if lhs > rhs
   *           false otherwise
   */
  template<class T, size_t N>
    bool
    operator> (const array<T, N> &lhs, const array<T, N> &rhs)
    {
      return (rhs < lhs);
    }

  /**
   * <= operator overloaded for array comparison
   *
   * @param  : const array<T, N> - lhs array
   *         : const array<T, N> - rhs array
   *
   * @return : bool - true if lhs <= rhs
   *           false otherwise
   */
  template<class T, size_t N>
    bool
    operator<= (const array<T, N> &lhs, const array<T, N> &rhs)
    {
      return !(rhs < lhs);
    }

  /**
   * >= operator overloaded for array comparison
   *
   * @param  : const array<T, N> - lhs array
   *         : const array<T, N> - rhs array
   *
   * @return : bool - true if lhs >= rhs
   *           false otherwise
   */
  template<class T, size_t N>
    bool
    operator>= (const array<T, N> &lhs, const array<T, N> &rhs)
    {
      return !(lhs < rhs);
    }
}

#endif /* ARRAY_HPP */

