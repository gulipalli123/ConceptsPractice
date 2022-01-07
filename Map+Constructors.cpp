#include <iostream>
#include <map>
using namespace std;

bool default_constructed = false;
bool constructed = false;
bool assigned = false;

class C {
public:
	C() { default_constructed = true; }
	C(int) { constructed = true; }
	C& operator=(const C&) { assigned = true; return *this; }
};

int main() {
    map<int, C> m;
    m[7] = C(1);

    cout << default_constructed << constructed << assigned;

    //m.insert(make_pair<int, C>(5, C(1)));  // output 010

    //cout << default_constructed << constructed << assigned;
}

/*
The [] operator inserts an element if the key is not present. In the case of a class, the element is default constructed. So doing m[7] calls the default constructor of C (no matter if we assign to it right after), setting default_constructed to true.

The expression C(1) constructs an instance of C using the constructor taking an int, setting constructed to true.

The = in m[7] = C(1) calls the copy assignment operator to copy assign the newly created C(1) to the previously default constructed C inside the map, setting assigned to true.

The fact that an object is first default constructed is covered by [map.access]�26.4.4.3�2 in the standard:

T& operator[](key_type&& x);

Effects: Equivalent to: return try_emplace(move(x)).first->second;

where try_emplace is defined by [map.modifiers]�26.4.4.4�8:

template <class... Args> pair<iterator, bool> try_emplace(key_type&& k, Args&&... args);

Effects: If the map already contains an element whose key is equivalent to k, there is no effect. Otherwise inserts an object of type value_type constructed with piecewise_construct, forward_as_tuple(std::move(k)), forward_as_tuple(std::forward<Args>(args)...).

value_type is just a typedef for pair<const Key, T>, which in our case is pair<const int, C>. So it inserts a pair(7, C()), which calls the default constructor for C.

To avoid the default construction followed by a copy assignment, you can use one of the following:

m.insert(pair<int, C>(7, C(1)));
m.emplace(7, C(1));
*/