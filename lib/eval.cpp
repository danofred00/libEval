
#include <cstdlib>
// #include <iostream>
#include <sstream>
#include <exception>
#include <cmath>


#include "eval/_eval.h"
#include "eval/_utils.h"

const std::vector<Operator> operators {
    {'+', PRIORITY_DEFAULT},    // addition
    {'-', PRIORITY_DEFAULT},    // substraction
    {'%', PRIORITY_MEDIUM},     // modulo
    {'*', PRIORITY_MEDIUM},     // multiplication
    {'/', PRIORITY_MEDIUM},     // division's operator
    {'^', PRIORITY_MAX},        // power's operator
    // {')', PRIORITY_MAX}
};

static std::vector<Token> tokenize(const std::string & expr)
{
    std::vector<std::pair<int, Operator>> tokens;

    for(int i=0; i<expr.size(); i++)
        if(isOperator(expr[i]))
            tokens.push_back({i, toOp(expr[i])});

    return tokens;
}

static bool isOperator(const char c)
{
    for(const auto & op : operators)
        if(c == op.op)
            return true;

    return false;
}

static Operator toOp(const char op)
{
    for(int i=0; i<operators.size(); i++) {
        if(operators[i].op == op)
            return operators[i];
    }
    return Operator();
}

static void removeBadOps(std::string & expr, const std::string & op, const std::string & r)
{
    auto pos = expr.find(op);
    if(pos == std::string::npos)
        return;
    else {
        expr = expr.replace(pos, op.length(), r);
        removeBadOps(expr, op, r);
    }
}

bool check_expression(const std::string & expr)
{
    bool isValid = true;

    if(str_count(expr, '(') != str_count(expr, ')'))
        isValid = false;

    return isValid;
}

std::string eval(std::string expr)
{
    // vars declaration
    std::stringstream ss;
    std::string result;
    int maxIndex, pos, before, after, sSize;
    size_t beforePos, afterPos;

    // main code
    removeBadOps(expr, "+-", "-");
    removeBadOps(expr, "-+", "-");

    if(! check_expression(expr))
        throw std::logic_error("Invalid expression");

    auto tokens = tokenize(expr);
    
    if(tokens.empty())
        return expr;

    if(tokens.size() == 1 && tokens[0].first == 0)
        if(expr[0] == '-')
            return expr;
        else if(expr[0] == '+')
            return expr.substr(1, expr.size() -1);
        else throw std::logic_error("Bad expression");

    // if string contains parenthesis
    auto last_opp = str_find_last(expr, '(', 0);
    if(last_opp >= 0) {
        auto first_clp = str_find_first(expr, ')', last_opp);
        // the expression between the last parenthesis
        auto substr = expr.substr(last_opp+1, first_clp-last_opp-1);
        // evaluate expression and update the result
        result = eval(substr);
        return eval(expr.replace(last_opp, first_clp-last_opp+1, result));
    }
    
    // if there is no parenthesis in the expression
    sSize = expr.length();
    // get the position the operator with
    // the maximum priority
    maxIndex = find_max_op_level(tokens);
    before = prevOp(tokens, maxIndex);
    after = nextOp(tokens, maxIndex);
    pos = tokens[maxIndex].first;

    // get index of operands around the operator
    // with max priority
    beforePos = (before == maxIndex) ? 0 : tokens[before].first + 1;
    afterPos = (after == maxIndex) ? sSize-1 : tokens[after].first - 1;

    // extract operands
    // if the left operand is a negative number, we take 
    // the sign of negation
    if(beforePos > 0 && expr[beforePos-1] == '-')
        beforePos--;
    
    auto left = expr.substr(beforePos, pos-beforePos);
    auto rigth = expr.substr(pos+1, afterPos-pos);

    // std::cout << "max :" << maxIndex << " - before : " << before << " - after : " << after << std::endl;
    // std::cout << "pos : " << pos << " beforePos :" << beforePos << " - afterPos : " << afterPos << std::endl;
    // std::cout << "left :" << left << " - rigth : " << rigth << std::endl;

    // do operation
    auto res = doOperatrion<float>(tokens[maxIndex].second.op, std::atof(left.c_str()), std::atof(rigth.c_str()));

    // return the result as a string
    ss << res;
    ss >> result;

    auto s = expr.replace(beforePos, afterPos-beforePos+1, result);

    // std::cout << result << " - " << s << std::endl;

    return eval(s);
}

static int prevOp(const std::vector<Token> tokens, int current)
{
    auto size = tokens.size();
    if(current >= size)
        return -1;
    else if(current > 0 && current < size)
        return current - 1;
    else 
        return current;
}

static int nextOp(const std::vector<Token> & tokens, int current)
{
    auto size = tokens.size();
    if(current >= size)
        return -1;
    else if(current >= 0 && current < size - 1)
        return current + 1;
    else 
        return current;
}

static int find_max_op_level(const std::vector<Token> & tokens)
{
    int max = tokens.size()-1;
    for(int i=max-1; i>=0; i--) 
        if(tokens[i].second.priority > tokens[max].second.priority)
            max = i;
    
    return max;
}

template<typename T>
static T doOperatrion(const char op, const T & a, const T & b)
{
    T result;

    if(op == '+')
        result = a + b;
    else if(op == '-')
        result = a - b;
    else if(op == '*')
        result = a * b;
    else if(op == '/')
        result = a / b;
    else if(op == '%')
        result = (int)a % (int)b;
    else if(op == '^')
        result = (T) std::pow((double)a, (double)b);

    return result;
}

static int comparator(const Operator & op1, const Operator & op2)
{
    if(op1.priority > op2.priority)
        return 1;
    else if(op1.priority < op2.priority)
        return -1;
    else 
        return 0;
}

static void sort(std::vector<Token> & tokens)
{
    auto size = tokens.size();

    // quick sort algorithm
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            if(comparator(tokens[i].second, tokens[j].second) > 0)
                std::swap(tokens[i], tokens[j]);

}
