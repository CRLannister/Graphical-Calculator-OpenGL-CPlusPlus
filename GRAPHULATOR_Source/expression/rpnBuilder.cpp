
#include "rpnBuilder.h"

using namespace std;

/*
 * RPNBuilder Constructor.
 * Just fills the Operator List. Must be called for the class to work properly.
 */
RPNBuilder::RPNBuilder ( )
{
    opList = "()*+-/^";
}

std::vector<Token> RPNBuilder::toRPN ( std::vector<Token> mother )
{
    vector<Token> output;//Output Stack
    stack<Token> opStack; //Operator Stack
    string op; //operator in string type
    int oplvl; //operator level

    //TOKEN LOOP
    for(int i= 0; i<mother.size(); i++)
    {
        Token monkey = mother[i];

        //Operator case
        if(monkey.getType()==eOperator)
        {
            op = monkey.toString();
            oplvl = opLevel(op);

            if(oplvl == 3 || oplvl == 5)
            {
                //CASE ONE - if left paran: "(" OR power "^"
                opStack.push(monkey);
            }
            else if(oplvl == 4)
            {
                //CASE TWO - if right paran: ")"
                while(opStack.top().toString() != "(")
                {
                    output.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.pop(); //pop paran "("
            }
            else
            {
                //CASE THREE - if normal operator
                //WARNING: above is assumed

                //while operator stack is not empty
                while(!opStack.empty() && oplvl <= opLevel(opStack.top().toString()) && opStack.top().toString() != "(") //new has higher precedence
                {
                    //assume lower or equal precedence
                    output.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.push(monkey);\
			}
        }
        else if(monkey.getType() == eLiteral || monkey.getType() == eVariable)
        {
            //Literal or Variable Name Case
            output.push_back(monkey);
        }
        else
        {
            //Bad stuff happens
        }
    }

    //CLEANUP - pop remaining OperatorStack elements
    while ( !opStack.empty() )
    {
        output.push_back(opStack.top());
        opStack.pop();
    }
    return output;
}

int RPNBuilder::opLevel(string op)
{
    if(op == "+" || op == "-")
        return 1;
    else if(op == "*" || op == "/")
        return 2;
    else if(op == "(")
        return 3;
    else if(op == ")")
        return 4;
    else if(op == "^")
        return 5;
}

/*
 * RPNBuilder.convertToRPN ( std::string e )
 * Public method to convert a Infix represented function into RPN. The function is passed as a string.
 */
std::vector<Token> RPNBuilder::convertToRPN ( std::string expression )
{
    preprocessString(expression);
    return toRPN ( buildTokenList ( expression ));
}

void RPNBuilder::preprocessString ( std::string &s )
{
    //Removes all the spaces...cuz I don't like them in there.. Seriously.
    for ( int i = 0; i < s.length(); i++ )
    {
        if ( s[i] == ' ' )
        {
            s.erase(s.begin()+i);
            i = 0;
        }
    }
}

/*
 * RPNBuilder.findInOpList ( char c )
 * Just there to help in seeing whether a character is an operator.
 */
int RPNBuilder::findInOpList ( char c )
{
    for ( int i = 0; (i < 7) && (c >= opList[i]); i++ )
        if ( c == opList[i] )
            return i;
    return -1;
}

/*
 * RPNBuilder.buildTokenList ( std::string expression )
 * Preprocesses the string into tokens that represent a Literal value, Operator or Variable.
 *
 * Warning: Any unusual tokens are just IGNORED at the moment. There is no error checking.
 */
std::vector<Token> RPNBuilder::buildTokenList ( std::string s )
{
    std::vector<Token> tokenList = std::vector<Token>();

    TokenType currState = eBase;
    std::string temp = "";

    for ( int i = 0; i < s.length(); i++ )
    {
        switch ( currState )
        {
            case eBase:
                temp += s[i];
                if ( s[i] >= 48 && s[i] <= 57 )
                {
                    //Definitely some sort of literal.
                    currState = eLiteral;
                }
                else if ( ( s[i] >= 65 && s[i] <= 90 ) || ( s[i] >= 97 && s[i] <= 122 ) )
                {
                    //Definitely a character
                    currState = eVariable;
                }
                else if ( findInOpList ( s[i] ) >= 0 )
                {
                    //Operator
                    currState = eOperator;
                }
                else
                {
                    //Really Weird input?! ignore.
                }
                break;

            case eVariable:
                //Gotta check whether the variable name continues...
                if (   ( s[i] >= 65 && s[i] <= 90 )
                       || ( s[i] >= 97 && s[i] <= 122 )
                       || ( s[i] >= 48 && s[i] <= 57 ) )
                    temp += s[i];
                else
                {
                    //Variable name ended...gotta put it into the token list and place
                    //  the new character into a new temporary token.
                    tokenList.push_back(Token(currState,temp));
                    temp = s[i];
                    if ( s[i] >= 48 && s[i] <= 57 )
                        currState = eLiteral;
                    else if ( ( s[i] >= 65 && s[i] <= 90 ) || ( s[i] >= 97 && s[i] <= 122 ) )
                        currState = eVariable;
                    else if ( findInOpList ( s[i] ) >= 0 )
                        currState = eOperator;
                }
                break;

            case eLiteral:
                //Literals are numbers...including decimal place :)
                if ( (s[i] >= 48 && s[i] <= 57) || (s[i]=='.') )
                    temp += s[i];
                else
                {
                    tokenList.push_back(Token(currState,temp));
                    temp = s[i];
                    if ( s[i] >= 48 && s[i] <= 57 )
                        currState = eLiteral;
                    else if ( ( s[i] >= 65 && s[i] <= 90 ) || ( s[i] >= 97 && s[i] <= 122 ) )
                        currState = eVariable;
                    else if ( findInOpList ( s[i] ) >= 0 )
                        currState = eOperator;
                }
                break;

            case eOperator:
                //Just push it into the token list and put the next character into a new state.
                tokenList.push_back(Token(currState,temp));
                temp = s[i];
                if ( s[i] >= 48 && s[i] <= 57 )
                    currState = eLiteral;
                else if ( ( s[i] >= 65 && s[i] <= 90 ) || ( s[i] >= 97 && s[i] <= 122 ) )
                    currState = eVariable;
                else if ( findInOpList ( s[i] ) >= 0 )
                    currState = eOperator;
                break;
        }
    }
    tokenList.push_back(Token(currState,temp));
    return tokenList;
}

