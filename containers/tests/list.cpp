#include "common.hpp"
#include "list.hpp"

int main() {
	miniSTL::list<int> mylist;

	/* print the address of the object */
	print1(hex_once(&mylist));
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
