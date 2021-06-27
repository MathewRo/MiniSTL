#ifndef _LIST_HPP_ 
#define _LIST_HPP_

#include <initializer_list>

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
          iterator operator++() 
          {
            return (iterator)iter_node->next;
          }
          iterator operator--() 
          {
            return (iterator)iter_node->prev;
          }
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
        for (int i = 0; i < n; i++) 
        {
          push_back(0);
        }
      }

        list(size_type n, const value_type& val) 
        {
          /*Allocate n nodes - don't do any explicit value inits */
          for (int i = 0; i < n; i++) 
          {
            push_back(val);
          }
        }

        /*range*/
        template <class InputIterator>
          list(InputIterator first, InputIterator last) 
          {
            assign(first, last);
          }

        /* copy */
        list(const list& x):head(nullptr, tail(nullptr)) 
      {
        /*Do a deep copy */
        //TODO 
        //for (auto &el : x) 
        {

          //push_back(x);
        }  
      }

        /* move */
        list(list&& x) {
          head = x.head;
          tail = x.tail;
          x.head = x.tail = nullptr;
        }

        /* initializer list */
        list(std::initializer_list<value_type> il) 
        {
          assign(il.begin(), il.end());
        }

        /* destructor */
        ~list() {
          //TODO
          //erase(begin(),end());
        }

        /* assignment operator */
        list& operator= (const list& x) 
        {
          if (this == &x)
          {
            return *this;
          }
          //TODO
          //erase(begin(), end());
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
          return (reference)tail->data;
        }

        const_reference back() const 
        {
          return (const_reference)tail->data;
        }

        reference front() 
        {
          return (reference)head->data;
        }

        const_reference front() const 
        {
          return (const_reference)head->data;
        }

        template <class InputIterator>
          void assign (InputIterator first, InputIterator last) 
          {
            node * temp = head;
            while (temp != NULL && first != last) {
              temp->data = *first;
              first++;
              temp++;
            }
          }

        void assign (size_type n, const value_type& val) 
        {

        }

        void assign (std::initializer_list<value_type> il) 
        {

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

          }

        iterator insert (const_iterator position, value_type&& val)
        {

        }

        iterator insert (const_iterator position, std::initializer_list<value_type> il)
        {

        }

        iterator erase (const_iterator position)
        {

        }

        iterator erase (const_iterator first, const_iterator last)
        {

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
          return (iterator)head;
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
          return (iterator)tail;
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
