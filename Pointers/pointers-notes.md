# GFU Game Dev Club Week 4 - Pointers

# Table of Contents
### 1. What is a pointer
### 2. Why use a pointer instead of a variable
### 3. What are pointers used for?
### 4. Pointer Practice Problems

# What is a pointer?
Pointers are very simply, variables specially designated to “point” to the memory addresses of other variables. Let's illustrate this concept with a basic C++ example
```
#include <iostream>
#include <string>

int main()
{
    std::string name = "Emerson";
    std::string* sample = &name;
    std::cout << "name: " << name << "\n";
    std::cout << "name's memory address: " << sample << "\n";
    return 0;
}
```

Sample Output: 
```
Name: Emerson
Name's memory address: 0x4a7c5ffa30 
```

Now if you were to run this example on your own computer, you probably won't get the same output for the memory address, and that's perfectly normal! The input will be different every single time that you run the code because the memory is simply getting assigned to a different spot in your RAM. 

Now let's examine the syntax used within this example.
```
std::string* sample = &name;
```
Right after the datatype to denotate that we want a pointer and not a normal variable we'll add a '*'. On the right hand side of the declaration statement, we'll put an '&' before the name of the variable to denotate that we want the memory address of the variable, not the actual value.

Now there are two ways of referencing a pointer within code.

1. Simply calling the pointer
2. Calling the pointer's name, but adding an * before it

Both of these are useful depending on what we want to do in the code. If we need the actual memory address, the first method is useful. If we need the actual value, then the second method is more useful. The * is very important in creating and using pointers, but it's important to recognize where it's being used and what it's doing. When * is used in a declaration, it's initializing the pointer variable. But when it's used outside of declarations, it acts as a dereference operator, and fetchs the value of that pointer instead. 

We can modify pointers very similarly to how we modify any other variable, but there are some strange side effects due to them storing the same memory address as another variable. Let's see this effect demonstrated through an example.

```
#include <iostream>
#include <string>

int main()
{
    std::string name = "Emerson";
    std::string* sample = &name;
    std::cout << "name: " << name << "\n";
    std::cout << "name's memory address: " << sample << "\n";
    std::cout << "name using sample: " << *sample << "\n";
    *sample = "Rogers";
    std::cout << "sample's new value: " << *sample << "\n";
    std::cout << "name's new value: " << name << "\n";
    return 0;
}
```

Output:
```
name: Emerson
name's memory address: 0xf43ebff
name using *sample: Emerson
*sample's new value: Rogers
name's new value: Rogers
```

If you take a careful look at the output, you'll notice that when we change *sample's value, we actually change the value of the name as well. Why is this? It's because name and sample are pointing to the same memory value, so when we change one, the other will also change. It also works in the opposite direction, where when we change name, *sample's value also changes

```
#include <iostream>
#include <string>

int main()
{
    std::string name = "Emerson";
    std::string* sample = &name;
    std::cout << "name: " << name << "\n";
    std::cout << "name's memory address: " << sample << "\n";
    std::cout << "name using sample: " << *sample << "\n";
    name = "Rogers";
    std::cout << "name's new value: " << name << "\n";
    std::cout << "sample's new value: " << *sample << "\n";
    return 0;
}
```

Output:
```
name: Emerson
name's memory address: 0x875adff870
name using sample: Emerson
name's new value: Rogers
sample's new value: Rogers
```
# What are pointers used for?
Pointers are mainly used to dynamically access and manipulate memory across a multitude of applications, but pointers become extremely powerful when used to make custom data structures that don't fit within normal variable declarations. 

Pointers are used in a miriad of different scenarios, from making data structures like linked lists possible, to speeding up the efficiency of programs when used over normal variables. Let's take a look at a basic example of iterating through an array to showcase the usefulness of pointers. 

Now in practically every language with for loops, you'll initialize a counter variable, setup a stopping point, and then setup how much your counter is going to increment each loop, like the example shown below
```
#include <iostream>

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < sizeof(a); i++)
    {
        std::cout << a[i] << "\n";
    }
}
```

But when we use pointers, we can make our slightly faster. (Though in this example the speed difference is minute at best)
```
#include <iostream>

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    for (int* i = a; i < a + sizeof(a) / sizeof(*a); i++)
    {
        std::cout << *i << "\n";
    }
}
```
Now this looks really weird, and that's because it is. We are used to using standard array notation to loop through each value, but we can use pointers instead. 

Why does this work? If we think back to the definition of an array, it's a contiguous block of memory dedicated to holding a defined number of values. Pointers are variables that point to a specific spot in our memory. If we make a pointer that "points" to the start of the array in the memory, by adding to it we'll get the next block in our memory, and therefore the next value in the array. 

But what's with the loop condition? Excellent question. We are technically still comparing how many elements are in the array against how big our loop variable is, but in a more roundabout way. We're comparing our pointer to the array + the number of bytes that the object occupies in memory, but because the ```int``` type takes up more than one byte, we need to divide by the size of a single element. We need to do this because of the way C++ does pointer arithmetic, it automatically increments by the number of bytes that the size of the datatype is. 

# Why use pointers over variables?
If we look back to our array example up above, we were able to dynamically access the memory and simply use the memory address to return a value. Instead if we looped normally, we would be using a variable to go through the array and then find the memory address and then find the actual value of that array.

Pointers are also used to do things that aren't normally possible within C++, like returning an array from a function. 

In addition the dynamically accessing memory, we're also able to manage memory a lot more efficiently with pointers when our programs get bigger and more complicated. We can use pointers to reference the same object over and over again in many different places in our code, without having to pass in the actual variable that is tied to our object.

In addition to all of this, pointers are also used to dynamically allocate memory, as they can grow and shrink as needed because they only point to one memory address, and don't track what's actually at the address. 

# Additional Links and Info
1. https://www.reddit.com/r/cpp/comments/kx2xaj/why_should_i_use_pointers/
2. https://www.w3schools.com/cpp/cpp_pointers.asp
3. https://www.geeksforgeeks.org/cpp-pointers/
