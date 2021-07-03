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
        friend class list<T>;
        using iterator_category = std::input_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = T*;  
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
      explicit list() :
        head(nullptr), 
        tail(nullptr)
      {

      }

      /* fill */
      explicit list(size_type n) : 
        head(nullptr), 
        tail(nullptr) 
      {
        /*Allocate n nodes - don't do any explicit value inits */
        for (size_type i = 0; i < n; i++) 
        {
          push_back(0);
        }
      }

      list(size_type n, const value_type& val) : 
        head(nullptr),
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
          push_back(el);
        }
        return *this;  
      }

      list& operator= (list&& x) 
      {
        if (this == &x)
        {
          return *this;
        }

        erase(begin(),end());
        head = x.head;
        tail = x.tail;
        x.head = x.tail = nullptr;
      }

      list& operator= (std::initializer_list<value_type> il) 
      {
        erase(begin(),end());
        assign(il.begin(), il.end());
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

      /* For a double link list - push_front generally updates head*/
      void push_front (const value_type& val) 
      {
        node * cur_node = new node(val);
        if (head == nullptr) 
        {
          head = tail = cur_node;
        }
        else 
        {
          cur_node->next = head;
          head->prev = cur_node;
          head = cur_node;
        }
      }

      void push_front (value_type&& val)
      {

      }

      void pop_front() 
      {

      }

      /* For a double link list - push_back generally updates tail */
      void push_back (const value_type& val) 
      {
        node * cur_node = new node(val);
        if (head == nullptr)
        {
          head = tail = cur_node;
        }
        else 
        {
          tail->next = cur_node;
          cur_node->prev = tail;
          tail = cur_node;
        }
      }

      void push_back (value_type&& val)
      {
        node * cur_node = new node(val);
        if (head == nullptr)
        {
          head = tail = cur_node;
        }
        else 
        {
          tail->next = cur_node;
          cur_node->prev = tail;
          tail = cur_node;
        }
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
        node * cur_node = position.iter_node, * prev_node, * next_node;
        prev_node = cur_node->prev;
        next_node = cur_node->next;
        if (prev_node)
        {
          prev_node->next = next_node;
        }
        else 
        {
          /* We are erasing head */
          head = next_node;
        }
        if (next_node)
        {
          next_node->prev = prev_node;
        }
        else 
        {
          /* We are erasing tail*/
          tail = prev_node;
        }
        delete cur_node;
        return iterator(head);
      }

      iterator erase (const_iterator first, const_iterator last)
      {

        node *first_node = first.iter_node, *last_node = last.iter_node,
             *prev_node = nullptr, *next_node = last_node, *temp_node = nullptr;

        if (empty())
        {
          return iterator(head);
        }

        prev_node = first_node->prev;

        /* clean from first to last [) */
        while (first_node != last_node)
        {
          temp_node = first_node->next;
          delete first_node;
          first_node = temp_node;
        }

        if (prev_node)
        {
          prev_node->next = next_node;
        }
        else 
        {
          /* We are erasing head */
          head = next_node;
        }
        if (next_node)
        {
          next_node->prev = prev_node;
        }
        else 
        {
          /* We are erasing tail*/
          tail = prev_node;
        }

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
        return iterator(head);
      }

      const_iterator begin() const noexcept
      {
        return (const_iterator)iterator(head);
      }

      const_iterator cbegin() const noexcept
      {
        return (const_iterator)iterator(head);
      }

      iterator end() noexcept
      {
        return iterator(nullptr);
      }

      const_iterator end() const noexcept
      {
        return (const_iterator)iterator(nullptr);
      }

      const_iterator cend() const noexcept
      {
        return (const_iterator)iterator(nullptr);
      }


      bool empty() const 
      {
        return head == nullptr;
      }

      private:
      struct node {
        T data;
        struct node * next;
        struct node * prev;
        node() :data(T()), 
        next(nullptr), 
        prev(nullptr){}
        node (const T val) :data(val)
                            ,next(nullptr) 
                            ,prev(nullptr){}
      };
      node *head, *tail;
    };

}

#endif /* _LIST_HPP_*/
