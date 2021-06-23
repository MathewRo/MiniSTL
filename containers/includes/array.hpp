#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stddef.h>
#include <stdbool.h>
#include <initializer_list>
#include <algorithm>

namespace miniSTL {

  template <typename T, size_t _size>
    class array {
      public:

        /* typedefs */
        typedef T                       value_type;
        typedef value_type*             pointer;
        typedef const pointer           const_pointer;
        typedef value_type&             reference;
        typedef const reference         const_reference;
        typedef value_type*             iterator;
        typedef const iterator          const_iterator;
        typedef value_type*             reverse_iterator;
        typedef const reverse_iterator  const_reverse_iterator;
        typedef size_t                  size_type;

        /* public interfaces */
        /* we are not adding anything specifc for zero sized arrays.
           Please understand that for _size == 0, behavior is undefined,
           though it may work without any crash */

        /* Modifiers */
        void fill(const value_type& val) 
        {
          for (int i = 0; i < _size; i++) 
          {
            buffer[i] = val;
          }
        }

        void swap (array& x) noexcept 
        {
          /* This function should not throw exceptions */
          for (int i = 0; i < (_size < x.size()?_size:x.size()); i++) 
          {
            buffer[i] = x[i];
          }
        }

        /* Element access */
        reference at(size_t n) 
        {
          return buffer[n];
        }

        const_reference at(size_t n) const 
        {
          return buffer[n];
        }

        reference operator[](size_t n) 
        {
          return buffer[n];
        }

        const_reference operator[](size_t n) const 
        {
          return buffer[n]; 
        }

        reference front() 
        {
          return buffer[0];
        }

        const_reference front() const
        {
          return buffer[0];
        }

        reference back() 
        {
          return buffer[_size-1];
        }

        const_reference back() const
        {
          return buffer[_size-1];
        }

        value_type* data() noexcept 
        {
          return (pointer)&buffer[0];
        }

        const value_type* data() const noexcept 
        {
          return (const_pointer)&buffer[0]; 
        }

        /* capacity */
        constexpr size_type size() const noexcept 
        {
          return _size;
        }

        constexpr size_type max_size() const noexcept 
        {
          return _size;
        }

        constexpr bool empty() const noexcept
        {
          return _size == 0;
        }

        /* iterators */
        iterator begin() noexcept
        {
          return &buffer[0];
        }

        const_iterator begin() const noexcept
        {
          return (const_iterator)&buffer[0];
        }

        const_iterator cbegin() const noexcept
        {
          return &buffer[0];
        }

        iterator end() noexcept
        {
          return &buffer[_size];
        }

        const_iterator end() const noexcept
        {
          return (const_iterator)&buffer[_size];
        }

        const_iterator cend() const noexcept
        {
          return &buffer[_size];
        }

        /* array is typincally defined as an aggregates in STL. Refer spec to understand more */   
        T buffer[_size];
    };


  /* Relational operator implementation */
  template <class T, size_t N>
    bool operator== ( const array<T,N>& lhs, const array<T,N>& rhs ) 
    {
      return (lhs.size() == rhs.size() && 
          std::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

  template <class T, size_t N>
    bool operator!= ( const array<T,N>& lhs, const array<T,N>& rhs ) 
    {
      return !(lhs == rhs);
    }	

  template <class T, size_t N>
    bool operator<  ( const array<T,N>& lhs, const array<T,N>& rhs ) 
    {
      return (std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }	

  template <class T, size_t N>
    bool operator> ( const array<T,N>& lhs, const array<T,N>& rhs ) 
    {
      return (rhs < lhs);
    }
  template <class T, size_t N>
    bool operator<= ( const array<T,N>& lhs, const array<T,N>& rhs ) 
    {
      return !(rhs < lhs);
    }

  template <class T, size_t N>
    bool operator>= ( const array<T,N>& lhs, const array<T,N>& rhs ) 
    {
      return !(lhs < rhs);
    }
}


#endif /* ARRAY_HPP */

