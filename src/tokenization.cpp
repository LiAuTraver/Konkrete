// #include "tokenization.hpp"

// // could not use inline because it may not be used in other .cpp.
// std::vector<Token> Tokenizer::tokenize() {
//     std::string buf;
//     std::vector<Token> tokens;
//     while (peak().has_value())
//     {
//         if (isalpha(peak().value())) {
//             buf.push_back(consume());
//             while (peak().has_value() && peak().value()) {
//                 buf.push_back(consume());
//             }
//             if (buf == "exit") {
//                 tokens.push_back({ .type = TokenType::_return });
//                 buf.clear();
//                 continue;
//             }
//             else
//             {
//                 std::cerr << "You messed up!" << std::endl;
//                 exit(EXIT_FAILURE);
//             }
//         }
//         else if (isdigit(peak().value())) {
//             buf.push_back(consume());
//             while (peak().has_value() && isdigit(peak().value())) {
//                 buf.push_back(consume());
//             }
//             tokens.push_back({ .type = TokenType::_return }); // Add missing argument for Token object
//             buf.clear();
//         }
//         else if(peak().value() == ';'){
//             tokens.push_back({ .type = TokenType::semi });
//             consume();
//             continue;
//         }
//         else if(isspace(peak().value())){
//             consume();
//             continue;
//         }
//         else
//         {
//             std::cerr << "You messed up!" << std::endl;
//             exit(EXIT_FAILURE);
//         }   
//     }
//     m_index = 0;
//     return tokens;
// }
