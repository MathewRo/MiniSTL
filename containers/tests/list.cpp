#include "common.hpp"

#ifdef __STD__
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
	list<int> l1;
  print1("l1");
	print1(hex_once(&l1));

  list<int> l2(5);
  print1("l2");
	print1(hex_once(&l2));
  print_list(l2);

  list<int> l3(10, 5);
  print1("l3");
	print1(hex_once(&l3));
  print_list(l3);

  list<int> l4(l3.begin(), l3.end());
  print1("l4");
	print1(hex_once(&l4));
  print_list(l4);

  list<int> l5(l4);
  print1("l5");
	print1(hex_once(&l5));
  print_list(l5);

  list<int> l6(std::move(l3));
  print1("l6");
	print1(hex_once(&l6));
  print_list(l6);

  list<int> l7 = {1,2,3,4,5,6,7};
  print1("l7");
	print1(hex_once(&l7));
  print_list(l7);
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
