#include <iostream>

#include "mini_regex.hpp"

void func(mini_regex::_regex_result& res)
{
    for (auto i : res.matched)
        std::cout << i << std::endl;
}

void test(std::string reg, std::string tar, std::function<void (mini_regex::_regex_result&)> callback)
{
    static mini_regex regex;
    regex.compile(reg);
    regex.output_code();
    std::cout << "Target: " << tar << std::endl;
    regex.match(tar,func);
    std::cout << std::endl;
}

int main()
{
    test("\\ba(a|c|b|\\d)*.", "daccaaafascda ac1cgg", func);
    test("d\\(o(es)?", "d(oeing", func);
    test("do(es)+", "doesng", func);
    test("a|food", "aood", func);
    return 0;
}