
#include <iostream>
#include <list>
#include <assert.h>
#include "evaluator.h"

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
};

int main(int argc, char const *argv[])
{
    /* code */
    int i = 1;

    for(const auto & test : tests)
    {
        auto expr { test.expr };
        std::cout << "+ Running test case " << i << " " << test.expr;
        
        try {

            auto result = eval(expr);
            if(ASSERT_EQUAL(result, test.expected_output))
                std::cout << " Pass";
            else
                std::cout << " Failed";
            std::cout << std::endl;
            
        } catch(std::exception & e) { std::cout << " Failed" << std::endl; }

        i++;
    }

    return 0;
}
