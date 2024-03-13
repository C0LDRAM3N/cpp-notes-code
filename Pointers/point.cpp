#include <iostream>
#include <string>
#include <cstdio>

void exampleOne();
void exampleTwo();
void exampleThree();

/**
 * Starting place for all of the examples
*/
int main()
{
    std::string move;
    exampleOne();
    std::cout << "Do you want to run the next example? (y/n): ";
    std::cin >> move;
    if (move == "y")
    {
        exampleTwo();
        std::cout << "Do you want to run the next example? (y/n): ";
        std::cin >> move;
        if (move == "y")
        {
            exampleThree();
            printf("All done!\nDon't forget to check the additional resources to learn more when you get stuck");
        }
    }
    return 0;
}

/**
 * Example one, illustrating a basic pointer example
*/
void exampleOne()
{
    std::string name = "Emerson";
    std::string* sample = &name;
    std::cout << "name: " << name << "\n";
    std::cout << "name's memory address: " << sample << "\n";
}

/**
 * Example two, displaying moving the pointer
*/
void exampleTwo()
{
    std::string name = "Emerson";
    std::string* sample = &name;
    std::cout << "name: " << name << "\n";
    std::cout << "name's memory address: " << sample << "\n";
    std::cout << "name using sample: " << *sample << "\n";
    *sample = "Rogers";
    std::cout << "sample's new value: " << *sample << "\n";
    std::cout << "name's new value: " << name << "\n";
}

/**
 * Example three, displaying how pointers can be used in conjunction with arrays
*/
void exampleThree()
{
    int a[] = {1, 2, 3, 4, 5};
    for (int* i = a; i < a + sizeof(a) / sizeof(*a); i++)
    {
        std::cout << *i << "\n";
    }
}