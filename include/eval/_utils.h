
#ifndef __EVAL_UTILS_H__
#define __EVAL_UTILS_H__

#include <string>

/**
 * str_count
 * @brief count occurences of c in expr
 * @param expr std::string
 * @param c char
 * @return
 */
inline size_t str_count(const std::string &expr, const char c)
{
    size_t total = 0;
    for (auto _c : expr)
        if (_c == c)
            total++;
    return total;
}

/// @brief Find the last occurence of c starting at pos in expr
/// @param expr const std::string
/// @param c const char
/// @param pos const size_t
/// @return
inline int str_find_last(const std::string &expr, const char c, const size_t &pos = 0)
{
    if (pos < expr.size())
        for (auto i = expr.size() - 1; i >= pos; i--)
            if (expr[i] == c)
                return i;

    return -1;
}

/// @brief Find the first occurence of c starting at pos in expr
/// @param expr const std::string
/// @param c const char
/// @param pos const size_t
/// @return 
inline int str_find_first(const std::string &expr, const char c, const size_t &pos = 0)
{
    if (pos < expr.size())
        for (auto i = pos; i < expr.size(); i++)
            if (expr[i] == c)
                return i;

    return -1;
}

/// @brief check if string s1 start with s2
/// @param s1 const std::string
/// @param s2 const std::string
/// @return true if s1 stqrt with s2, return false otherwise
inline bool str_start_with(const std::string & s1, const std::string & s2)
{
    auto result = s1.compare(0, s2.length(), s2);
    if(result == 0)
        return true;
    
    return false;
}

#endif