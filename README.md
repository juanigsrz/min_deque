# op_deque
Enhanced deque data structure, implemented on C++.
Definitions are provided on *op_deque.h*, and the implementation on *op_deque.cpp*.

## Use
First, include the op_deque with `#include "op_deque.cpp"`. 
To instantiate a new op_deque, use `op_deque<T, F> Name;`,
where `T` is the type of the elements in the deque,
`F` is a commutative and associative functor with arity 2,
and `Name` is the name of your instance.

## Basic methods
      Method name     |            Description
----------------------|-----------------------------------
- [x] `size()`        | get the number of elements
- [x] `[i]`           | get the element at the i-th index
- [x] `pop_front()`   | pop the element at the front
- [x] `pop_back()`    | pop the element at the back
- [x] `push_front(x)` | push a new element x at the front
- [x] `push_back(x)`  | push a new element x at the back
- [x] `front()`       | get the element at the front
- [x] `back()`        | get the element at the back

## Special methods
      Method name     |            Description
----------------------|-----------------------------------
- [x] `get()`         | get, in O(F) amortized time, the result of applying F to the whole deque.

### To do:
- Study and modify the order of operations to relax the commutative functor requirement.

- Replace `rastack<T>` with `vector<T>`.

- Improve the asymptotic constant by optimizing `balance()`.

- Formal proof.



