//Resource Acquisition is Initialization(RAII)
// The idea is tying  resources to an objects and using the mechanism of  object construction and destruction to handle resources in the program
// Each time we want to acquire a resource, we do so by creating an object that owns it. Whenever the object goes out of scope, the resource(memory, file, socket, lock etc)
// is released automatically.
// poroblem -1 -  If we have a large program containing a lot of heap allocations and at every point we cannot keeping track of memory is tedious manual and error-prone job.
//problem-2 - Releasing all resources is even more challenging when exceptions are thrown. Whenever we detect a problem, we have to release all the resources acquired so far
// befdore we throw exception.
// All the problems can be solved by introdcuing classes that manages the resources.
// e.g. File streams manage the file handle from C.
//unique pointer and shared pointer handle memory in a leak free and exception safe manner.
// If we are writing our own resource manager e.g. when C++ provided classes wont sufficient to serve
// our purpose, we should not manage more than one resource in a class.