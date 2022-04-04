//Scoping
//Demonstrates scope
#include <iostream>

void func();

int main()
{
    int var = 5;    //local variable in main()
    std::cout << "In main() var is: " << var << "\n\n";

    func();

    std::cout << "Back in main() var is: " << var << "\n\n";

    {
        std::cout << "In main() in new scope var is: " << var << "\n\n";

        std::cout << "Creating new var in scope.\n";
        int var = 10; //varible in new scope, hides other variable name var
        std::cout << "In main() new scope var is: " << var << "\n\n";
    }

    std::cout << "At the end of main() var created in new scope no longer exists.\n";
    std::cout << "At the end of main() var is: " << var << std::endl;

    return 0;
}

void func()
{
    int var = -5;   //local variable in func();
    std::cout << "In func() var is: " << var << "\n\n";
    return;
}