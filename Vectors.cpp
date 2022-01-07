//std::vector - defined in header vector
// template <class T, class Allocator = std::allocator<T>> class vector;
// std::vector is a sequence container that encapsulates dynamic size arrays.

// The elements are stored contiguously, which  means that elements can be accessed
// not only through iterators, but also using offsets to regular pointers to elements.
// This means that a pointer to an element of a vector can be passed to any function
// that expects a pointer to an element of an array.

//The storage of the vector is handled automatically, being expanded and contracted 
// as needed. Vectors usually occupy more space than static arrays, because more memory
// is allocated to handle future growth.
//This way a vector does not need to allocate memory each time an element is inserted.
//, but only when the additional memory is exhausted.

//The total amount of memory allocated can be queried using capacity()
// Extra memory can be returned to the system via a call to shrink_to_fit()(C++11)

//Reallocations are costly operations interms of performance. 
//The reserve() function can be used to eliminate reallocations if the number of elements is known beforehand.

//The complexity(efficiency) of common operations on vectors as follows:
//random access - constant O(1)
//Insertion or removal of elements at the end - amortized constant - O(1)
//Insertion or removal of elements - linear in the distance to the end of the vector O(n)

//std::vector(for T other than bool) meets the requiements of a COntainer, AllocatorAwareCOntainer,
//SequenceContainer, ContiguousContainer
// Template parameters
// T - the type of the elements, T must meet the requuirements of CopyAssignable,
// CopyConstructible.
// The requirements that are imposed on the elements depend on the actual operations
// performed on the container. Generally it is required that element type meets the 
// requirements of Erasable.

//An allocator that is used to acquire/release memory and to construct/destroy the
// elements in that memory. The type must meet the requirements of Allocator.

//Template Spcialization - The standard library provides a specialization of std::vector
// for the type bool, which may be optimized for space efficiency - vector<bool>.

#include <iostream>
#include <vector>

class Test
{
	int data;
public:
	Test(int x) { data = x; }
	void printData()
	{
		std::cout << "data = " << data << "\n";
	}
};

//For all readonly operations Iterators are never invalidated.
/*int main()
{
	std::vector<Test> test_vec1{ Test(12), Test(24) };
	std::vector<Test> test_vec2{ Test(5), Test(10) };


	//swap 
	std::swap(test_vec1, test_vec2); //If number of elements are not same in test_vec1 and test_vec2, 
	// std::swap behaviour is undefined, program will crash
	test_vec1[1].printData();
	test_vec2[0].printData();
	//After swap operation, end() iterator is invalidated.

	//operator=

	//auto itr = test_vec2.begin(); // after operator= , the iterator is invalidated.
	//test_vec2 = test_vec1;
	//itr->printData(); // This will cause abort 

	// assign

	/*auto itr2 = test_vec2.begin();
	test_vec2.assign(test_vec1.begin(), test_vec1.end()); //after assign, the iterator is invalidated
	itr2->printData();  //This will cause abort*/

	//clear

	/*auto itr2 = test_vec2.begin();
	test_vec2.clear(); //after clear, the iterator is invalidated
	itr2->printData();  //This will cause abort
	*/

	//reserve
	//Reallocations are costly operations interms of performance. 
	//The reserve() function can be used to eliminate reallocations if the number of elements is known beforehand.

	//auto itr2 = test_vec2.begin();
	//test_vec2.reserve(10); //after reserve, all the iterators are invalidated if the vector changed capacity, if not none.
	//itr2->printData();  //This will cause abort
	

	//shrink_to_fit
	// Extra memory can be returned to the system via a call to shrink_to_fit()(C++11)
	//auto itr2 = test_vec2.begin();
	//test_vec2.shrink_to_fit();
	//itr2->printData(); //This will cause abort
//}