#ifndef _MINI_REGEXP_H_
#define _MINI_REGEXP_H_

#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "mini_regexp_token.hpp"
#include "mini_regexp_code.hpp"
#include "mini_regexp_lexer.hpp"
#include "mini_regexp_parser.hpp"
#include "mini_regexp_vm.hpp"

using namespace mini_regexp_code;
using namespace mini_regexp_token;
using namespace mini_regexp_lexer;
using namespace mini_regexp_parser;
using namespace mini_regexp_vm;

class mini_regexp
{
public:
    struct Result {
        std::vector<std::string> matched;
    } regex_result;

    bool Multiline; /* for ^ and $ */
    
    mini_regexp();
    bool compile(const std::string& regexp_str);
    bool match(const std::string& match_str, std::function<void(Result&)> callback = nullptr);
    void output_code();

private:
    RE_Lexer mini_lexer;
    RE_Parser mini_parser;
    RE_VM mini_vm;
    std::string regexp;
    std::string target;

    void _reset();
};

#endif