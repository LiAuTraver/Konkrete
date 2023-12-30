#ifndef TOKENIZATION_HPP
#define TOKENIZATION_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <optional>
#include <sstream>
#include "parser.hpp"

enum class TokenType {
    _return,
    ini_lit,
    semi

};

class Token {
public:
    TokenType type;
    std::optional<std::string> value{};
};

class Tokenizer {
public:
    inline explicit Tokenizer(const std::string src)
        : m_src(std::move(src))
    {

    }
    std::vector<Token> tokenize(); // ??? why could not inline ???

private:
    const std::string m_src;
    int m_index = 0;


};


// temporarily place in the .hpp
// could not use inline because it may not be used in other .cpp.
std::vector<Token> Tokenizer::tokenize() {
    std::string buf;
    std::vector<Token> tokens;
    while (peak().has_value())
    {
        if (isalpha(peak().value())) {
            buf.push_back(consume());
            while (peak().has_value() && isalnum(peak().value())) {
                buf.push_back(consume());
            }
            if (buf == "return") {
                tokens.push_back({ .type = TokenType::_return });
                buf.clear();
                continue;
            }
            else
            {
                std::cerr << "You messed up!" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        else if (isdigit(peak().value())) {
            buf.push_back(consume());
            while (peak().has_value() && isdigit(peak().value())) {
                buf.push_back(consume());
            }
            tokens.push_back({ .type = TokenType::ini_lit, .value = buf }); // Add missing argument for Token object
            buf.clear();
            continue;
        }
        else if (peak().value() == ';') {
            consume();
            tokens.push_back({ .type = TokenType::semi });
            continue;
        }
        else if (isspace(peak().value())) {
            consume();
            continue;
        }
        else
        {
            std::cerr << "You messed up!" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    m_index = 0;
    return tokens;
}

#endif // TOKENIZATION_HPP