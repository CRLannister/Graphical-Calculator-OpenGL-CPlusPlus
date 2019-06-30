
#ifndef TRYCL_RPNBUILDER_H
#define TRYCL_RPNBUILDER_H
#include "token.h"
#include <vector>
#include <stack>

///Converts an expression into reverse polish notation for easy processing
class RPNBuilder
{

private:

    char* opList;

    std::vector<Token> buildTokenList ( std::string s );
    std::vector<Token> toRPN ( std::vector<Token> );

    int findInOpList ( char v );
    int opLevel(std::string op);
    void preprocessString ( std::string &s ) ;

public:

    RPNBuilder();
    std::vector<Token> convertToRPN ( std::string expression );
};

#endif //TRYCL_RPNBUILDER_H
