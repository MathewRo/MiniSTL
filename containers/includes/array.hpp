#ifndef ARRAY_HPP
#define ARRAY_HPP


/* This class would hold a user defined array type */

/*
   operator[]

   Access element (public member function )

   at

   Access element (public member function )

   front

   Access first element (public member function )

   back

   Access last element (public member function )

   data

   Get pointer to data (public member function )

   value_type  The first template parameter (T)  

   reference value_type& 

   const_reference const value_type& 

   pointer value_type* 

   const_pointer const value_type* 

   iterator  a random access iterator to value_type  convertible to const_iterator

   const_iterator  a random access iterator to const value_type  

   reverse_iterator  reverse_iterator<iterator>  

   const_reverse_iterator  reverse_iterator<const_iterator>  

   size_type size_t  unsigned integral type

   difference_type ptrdiff_t signed integral type

 */

namespace miniSTL {

  template <typename T, size_t sz>
    class array {
      public:

        /* typedefs */
        typedef T                       value_type;
        typedef value_type*             pointer;
        typedef const pointer           const_pointer;
        typedef value_type&             reference;
        typedef const referece          const_reference;
        typedef pointer                 iterator;
        typedef const iterator          const_iterator;
        typedef iterator                reverse_iterator;
        typedef const reverse_iterator  const_reverse_iterator;

        /* public interfaces */
        array() {
          size = sz;
        }

        array(const T value) {
          size = sz;
          for (int i = 0; i < size; i++) {
            buffer[i] = value;
          }
        }

        reference at(size_t n);
        const_reference at(size_t n) const;
        reference front();
        const_reference front();
        reference back();
        const_reference back();
        pointer data() noexcept;
        const_pointer data() const noexcept;

      private:
      
        T buffer[sz>0?sz:1];
        size_t size;
    }
}
#endif /* ARRAY_HPP */

