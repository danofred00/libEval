
#include <iostream>
#include <list>
#include <assert.h>
#include "eval/eval.h"

#define ASSERT_EQUAL(x,y) x==y

struct TestCase 
{
    std::string expr;
    std::string expected_output;
};

const std::list<TestCase> tests {
    {"1+1", "2"},    // 0
    {"5*2", "10"},   // 1
    {"3-1", "2"},   // 2
    {"5/2", "2.5"},   // 3
    {"2+5+4-8", "3"},   // 4
    {"5/2+1", "3.5"},   // 5
    {"-20+4*5", "0"},   // 6
    {"-2/2+1*5", "4"},   // 7
    {"1+1/2", "1.5"},   // 8
    {"5%2", "1"},   // 9
    {"(15*5+(5-2))", "78"}, // 10
    {"100-(((((15+5)-4)+5*2)*2)-10)", "58"}, // 11
    {"(2+2*2-2/2)*(3+3*3-3/3)", "55"},
};

int main(int argc, char const *argv[])
{
    /* code */
    int i = 1;

    for(const auto & test : tests)
    {
        auto expr { test.expr };
        std::cout << "\t[+] Running test case " << i << " : eval(\"" << test.expr << "\")";
        std::cout << std::endl;
        
        try {

            auto result = eval(expr);
            if(ASSERT_EQUAL(result, test.expected_output))
                std::cout << "\t\tPass";
            else
                std::cout << "\t\tFailed";
            std::cout << std::endl;
            
        } catch(std::exception & e) { std::cout << "\t\t Failed" << std::endl; }

        i++;
    }

    return 0;
}
