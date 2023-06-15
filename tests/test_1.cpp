
#include <iostream>
#include "evaluator.h"

int main(int argc, char const *argv[])
{
    /* code */
    std::string expr { argv[1] };
    std::cout << "final result = " << eval(expr) << std::endl;

    return 0;
}
