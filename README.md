# c-world

> [!WARNING]
>  For my own personal uses, loose code structures. DO NOT CLONE.

* In C, array names act as constant pointers to their first element. You cannot assign one array directly to another using the = operator. 
* An array name evaluates to the memory address of its first element (&arr[0]).
* Use strcpy() to change it.
* Change it char by char (remember last element/char should be '\0' )
* You can copy an array implicitly if it is wrapped inside a struct. (Copies the whole struct.)

* In C, pointers can be used to store data only if it was initialised first or address was provided of other variable. 
* A wild (uninitialized) pointer holds garbage data pointing to an arbitrary address in memory.
* To store data using pointers, memory size is required {Same for arrays}
* Attempting (*ptr = 'A';) (uninitialized pointer) causes undefined behavior {segmentation fault}.

# In C, Memory size is fixed and allocated automatically at compile time.
