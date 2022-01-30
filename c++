c cannot return an array
instead of using auto parameters in a function, use templates

typedef unsigned int * intPointer; [shortens unsigned int * to intPointer so that the next time we want to declare an item of type
unsigned int *, we refer it to as type intPointer]
intPointer foo = new int;

runtime stack - contains memory for functions(activation records)
activation record - local variables and parameters

stack(organized,contiguous,accessed sequentially)
heap(non organized,dynamic allocation and access,leaves non uniform fragments between memory blocks[memory fragmentation])

dynamic memory allocation(the new keyword or the malloc c function) happens thanks to the heap

heap overflow - when the system runs out of blocks of memory to allocate in the heap(no more space for allocating dynamic data structures or variables)(may result in bad_alloc being called)
stack overflow - when the system runs out of blocks of memory to allocate in the stack(no more space to add functions to)

dangling references
memory leaks - are brought about by desolate memory blocks ie memory blocks that no longer have any references to them

(void *)var - returns the memory address that var occupies.
void * - a pointer that does not have any data type assigned to it. It can point to any data type's memory address

type *foo = some var;
(*foo) - refers to the object at the memory address
we could do (*foo).doSomething or foo->doSomething (-> is the pointer operator and (*pointer)var is used to refer to the memory address being
pointed to[dereferences the pointer])

head pointer - a pointer, external to a linked list that points to the first node in the list

If your class allocates any memory using new, then it is essential that you implement a destructor, else you will have memory leaks

When one object is assigned another, c++ performs a shallow copy by default. The data members of one object are directly assigned to the
other.

lvalue(locator value) - represents an object that occupies some identifiable location in memory
rvalue - an expression that does not represent an object occupying some identifiable location in memory
eg
int x = 4; x is an lvalue(it occupies a certain location in memory) and such an expression expects an lvalue as its left operand
(x+2) = 5; (x+2) is a temporary value stored in some temporary register for the duration of the computation and is therefore an rvalue.
The expression is invalid since such an expression requires an lvalue as its left operand
4 = x; 4 is a constant value. This expression attempts to modify the value of 4. 4 is a built in int and therefore not an lvalue hence the
expression will result in an error

friend - a function or class that can access the private and protected members of a class(functions and data)
class foo {
public:
	friend class <class name>;
	friend <return type> <funcName>(<params>);
};


 function pointers
-------------------
<return type> (*<var>)(<params>) -> var will be a pointer variable that references a function
typedef <return type> (*<typename>)(<params>) -> typename will be a shorthand type for a function pointer with the given return type and
parameters
var = &someFunction
var(params) || (*<var>)(params) -> how to call first form
<typename> funcPtr;
funcPtr = &someFunction
funcPtr(params) || (*funcPtr)(params) -> how to call second form
 member function pointers
--------------------------
<return type> (<Class>::*<var>)(<params) -> var will be a pointer variable to a member function
typedef <return type> (<Class>::*<typename>)(<params>) -> typename will be a shorthand type for a pointer to a member function
var = &someFunction;
(this->*var)(<params>) -> how to call first form
typename foo;
foo = &someFunction;
(this->*foo)(<params>) -> how to call second form

 classes that have template definitions and header files(defined in header, implemented in source file)
--------------------------------------------------------------------------------------------------------
-> define dummy function in implementation.cpp
-> include implementation.cpp in file that uses the class(contains function or class that uses the class)
-> include implementation.cpp in header file and remove implementation.cpp from project but not from folder

 const override
----------------
std::string function() const override
-> const - the function promises not to change any member variables and it won't call any functions that might
-> override - overrides a base class function of the same name and signature from the current class' parent class

 virtual
---------
-> virtual <return-type> <function-name>(<parameters>);
-> when a function is made virtual, c++ determines which function is to be invoked at runtime based on the object pointed to by the base
class pointer
