
#ifndef __EVALUATOR_H__
#define __EVALUATOR_H__

    #include <vector>
    #include <string>

    typedef enum {
        PRIORITY_DEFAULT=0,
        PRIORITY_MEDIUM,
        PRIORITY_MAX
    } OperatorPrority;

    typedef struct
    {
        char op;
        OperatorPrority priority;
    } Operator;

    using Token = std::pair<int, Operator>;

    static std::vector<Token> tokenize(const std::string & expr); 
    
    static bool isOperator(const char c);

    static Operator toOp(const char op);

    bool check_expression(const std::string & expr);

    /// @brief This function can eval a string as an arithmetic expression
    /// @param expr expression to evaluate
    /// @return a result as a string 
    std::string eval(std::string expr);

    template<typename T>
    static T doOperatrion(const char op, const T & a, const T & b);

    static int comparator(const Operator & op1, const Operator & op2);

    static void sort(std::vector<Token> & tokens);

    static int find_max_op_level(const std::vector<Token> & tokens);

    static int prevOp(const std::vector<Token> tokens, int current);

    static int nextOp(const std::vector<Token> & tokens, int current);
    
    static void removeBadOps(std::string & expr, const std::string & op, const std::string & r);

    // static int doSomething(const std::vector<Token> & tokens, int index);

#endif