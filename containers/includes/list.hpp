#ifndef _LIST_HPP_ 
#define _LIST_HPP_

#include <initializer_list>
#include <cstdbool>
#include <type_traits>

namespace miniSTL {

  /* For time being we are skipping allocator */
  template <class T>
    class list {

      struct node;
      public:

      /* should iterators be aggregates? */
      struct iterator {
        iterator() : iter_node(nullptr) {}
        iterator(node * val) : iter_node(val) {}

        using iterator_category = std::input_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = T*;  // or also value_type*
        using reference         = T&; 
        /* postfix */
        iterator operator++(int)
        {
          iter_node = iter_node->next;
          return *this;
        }

        /* prefix */
        iterator& operator++() 
        {
          iter_node = iter_node->next;
          return *this;
        }

        /* postfix */
        iterator operator--(int) 
        {
          iter_node = iter_node->prev;
          return *this;
        }

        /* prefix */
        iterator& operator--() 
        {
          iter_node = iter_node->prev;
          return *this;
        }

        bool operator!=(const iterator& iter)
        {
          return iter_node != iter.iter_node;
        }

        T& operator*()
        {
          return iter_node->data;
        }

        //        T operator*() 
        //        {
        //          return iter_node->data;
        //        }

        private:
        node * iter_node;
      };

      typedef T                       value_type;
      typedef value_type*             pointer;
      typedef const pointer           const_pointer;
      typedef value_type&             reference;
      typedef const reference         const_reference;
      typedef const iterator          const_iterator;
      typedef value_type*             reverse_iterator;
      typedef const reverse_iterator  const_reverse_iterator;
      typedef size_t                  size_type;

      /* I need to be truthful here. I copied this snippet from SO. 
         My understanding here is that during template instantiation, 
         this would do a compile time check to see if the deducted 
         type is an iterator. Since std::iterator require 5 different
         members inlcuding a tag denoting its type, I added them for 
         my iterator as well. Things work now. I'll need to start with 
         traits soon since this would just be the begining :(
       */
      template<typename InputIterator>
        using RequireInputIterator = typename
        std::enable_if<std::is_convertible<typename
        std::iterator_traits<InputIterator>::iterator_category,
        std::input_iterator_tag>::value>::type;

      /* constructors */
      /* default */
      explicit list() :head(nullptr), 
      tail(nullptr)
      {

      }

      /* fill */
      explicit list(size_type n): head(nullptr), 
      tail(nullptr) 
      {
        /*Allocate n nodes - don't do any explicit value inits */
        for (size_type i = 0; i < n; i++) 
        {
          push_back(0);
        }
      }

      list(size_type n, const value_type& val): head(nullptr),
      tail(nullptr)
      {
        /*Allocate n nodes - don't do any explicit value inits */
        for (size_type i = 0; i < n; i++) 
        {
          push_back(val);
        }
      }

      /*range*/
      template <class InputIterator, typename = RequireInputIterator<InputIterator>>
        list(InputIterator first, InputIterator last): head(nullptr),
        tail(nullptr) 
      {
        assign(first, last);
      }

      /* copy */
      list(const list& x):head(nullptr), tail(nullptr)
      {
        /*Do a deep copy */
        for (auto &el : x) 
        {
          push_back(el);
        }  
      }

      /* move */
      list(list&& x) {
        head = x.head;
        tail = x.tail;
        x.head = x.tail = nullptr;
      }

      /* initializer list */
      list(std::initializer_list<value_type> il):
        head(nullptr),tail(nullptr)
      {
        assign(il.begin(), il.end());
      }

      /* destructor */
      ~list() {
        erase(begin(),end());
      }

      /* assignment operator */
      list& operator= (const list& x) 
      {
        if (this == &x)
        {
          return *this;
        }

        erase(begin(), end());
        /*Do a deep copy */ 
        for (auto &el : x) 
        {
          push_back(x);
        }
        return *this;  
      }

      list& operator= (list&& x) 
      {
        if (this == &x)
        {
          return *this;
        }
        //TODO
        //erase(begin(),end());
        head = x.head;
        tail = x.tail;
        x.head = x.tail = nullptr;
      }

      list& operator= (std::initializer_list<value_type> il) 
      {
        return *this;
      }

      /* Element access */
      reference back() {
        /* this member function can throw if list is empty */
        return (reference)*tail;
      }

      const_reference back() const 
      {
        return (const_reference)*tail;
      }

      reference front() 
      {
        return (reference)*head;
      }

      const_reference front() const 
      {
        return (const_reference)*head;;
      }

      template <class InputIterator>
        void assign (InputIterator first, InputIterator last) 
        {
          iterator temp = head;
          while (temp != nullptr && first != last) 
          {
            *temp = *first;
            first++; temp++;
          }
          //TODO - double check the behavior of assign
          // if we don't have allocated nodes, should 
          // we push_back or do a seg_fault?
          while (first != last) 
          {
            push_back(*first);
            first++;
          }
        }

      void assign (size_type n, const value_type& val) 
      {
        if (!n) return;
        iterator temp = head;
        while (temp != nullptr) 
        {
          *temp = val;
          n -= 1; temp++;
        }
        //TODO - double check the behavior of assign
        // if we don't have allocated nodes, should 
        // we push_back or do a seg_fault?
        while (n) 
        {
          push_back(val);
          n -= 1;
        }
      }

      void assign (std::initializer_list<value_type> il) 
      {
        if (!il.size()) return;
        iterator temp = head;
        auto il_iter = il.begin();
        while (temp != nullptr && il_iter != il.end()) 
        {
          *temp = *il_iter;
          il_iter++; temp++;
        }
        //TODO - double check the behavior of assign
        // if we don't have allocated nodes, should 
        // we push_back or do a seg_fault?
        while (il_iter != il.end()) 
        {
          push_back(*il_iter);
          il_iter++;
        }
      }

      void push_front (const value_type& val) 
      {

      }

      void push_front (value_type&& val)
      {

      }

      void pop_front() 
      {

      }

      void push_back (const value_type& val) 
      {

      }

      void push_back (value_type&& val)
      {

      }

      void pop_back() 
      {

      }

      iterator insert (const_iterator position, const value_type& val) 
      {

      }

      iterator insert (const_iterator position, size_type n, const value_type& val)
      {

      }

      template <class InputIterator>
        iterator insert (const_iterator position, InputIterator first, InputIterator last)
        {
          return head;
        }

      iterator insert (const_iterator position, value_type&& val)
      { 
        return head;
      } 

      iterator insert (const_iterator position, std::initializer_list<value_type> il)
      {
        return head;
      }

      iterator erase (const_iterator position)
      {
        return head;
      }

      iterator erase (const_iterator first, const_iterator last)
      {
        return head;
      }

      void swap (list& x)
      {

      }

      void resize (size_type n)
      {

      }

      void resize (size_type n, const value_type& val)
      {

      }

      void clear() noexcept
      {

      }

      iterator begin() noexcept
      {
        return head;
      }

      const_iterator begin() const noexcept
      {
        return (const_iterator)head;
      }

      const_iterator cbegin() const noexcept
      {
        return (const_iterator)head;
      }

      iterator end() noexcept
      {
        return tail;
      }

      const_iterator end() const noexcept
      {
        return (const_iterator)tail;
      }

      const_iterator cend() const noexcept
      {
        return (const_iterator)tail;
      }

      private:
      struct node {
        T data;
        struct node * next;
        struct node * prev;
        node() :next(nullptr), prev(nullptr){}
        node (const T val) :next(nullptr) 
                            ,prev(nullptr)
                            ,data(val){}
      };
      iterator head, tail;
    };

}

#endif /* _LIST_HPP_*/
