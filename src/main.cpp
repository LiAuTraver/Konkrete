#include "tokenization.hpp"

std::string tokens_to_asm(const std::vector<Token>& tokens) {
    std::stringstream output;
    output << "global _start\n"
        << "_start:\n";
    for (int i = 0; i < tokens.size(); ++i) {
        const Token& token = tokens.at(i);
        if (token.type == TokenType::_return) {
            if (i + 1 < tokens.size() && tokens.at(i + 1).type == TokenType::ini_lit) {
                if (i + 2 < tokens.size() && tokens.at(i + 2).type == TokenType::semi)
                {
                    output << "    mov rax, 60\n"
                        << "    mov rdi, "
                        << tokens.at(i + 1).value.value()
                        << '\n'
                        << "    syscall\n";
                }

            }
        }
    }
    return output.str();
}

int main(int argc, char** argv) {
    std::string contents;
    std::stringstream contents_stream;
    std::fstream input;
    if (argc != 2) {
        // std::cerr << "Usage: konkrete <filename>" << std::endl;
        // std::exit(EXIT_FAILURE);
        input = std::fstream("../test.kon", std::ios::in);
    }
    else input = std::fstream(argv[1], std::ios::in);
    contents_stream << input.rdbuf();
    contents = contents_stream.str();
    input.close();

    Tokenizer tokenizer(std::move(contents));
    std::vector <Token> tokens = tokenizer.tokenize();
    std::cout << tokens_to_asm(tokens) << std::endl
            << std::endl << "The assembly code above will be written into " 
            << "argv[1]" << "'s excutable file."<< std::endl;
    
    std::fstream file("test.asm", std::ios::out);
    file << tokens_to_asm(tokens);
    file.close(); 
    // if not closed, the file will be empty before nasm and ld are executed
    
    system("nasm -f elf64 ../test.asm -o ../test.o");
    system("ld ../test.o -o ../test");

    return EXIT_SUCCESS;
}