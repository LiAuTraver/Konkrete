#ifndef PARSER_HPP
#define PARSER_HPP

#include "tokenization.hpp" 


namespace node {
    class nodeExpr {
    public:
        std::string value;
        Token ini_lit;
    };
    class nodeExit {
    public:
        nodeExpr expr;

    };
}

class Parser {

public:
    inline explicit Parser(std::vector<Token> tokens)
        : m_tokens(std::move(tokens))
    {

    }

private:

    [[nodiscard]] std::optional<Token> peak(int ahead = 1) const {    // nodiscard disable compiler warning for my const retuen nothing.
        if (m_index + ahead > m_tokens.size())
            return std::nullopt;
        else
            return m_tokens.at(m_index);
    }

    inline Token consume() {
        return m_tokens.at(m_index++);
    }
    const std::vector<Token> m_tokens;
    size_t m_index = 0;

};

#endif // PARSER_HPP