//
// Created by u-0xffset on 13.11.20.
//

#include "InfixToRPN.hpp"

#include "../../HeaderOfConvenience.hpp"
#include "../../Errors/IncludeErrors.hpp"

#include <stack>

#define getCorrectString(x, y, z) \
if (x.find(y) != x.end()) { \
rpn_out += x.at(y) z stringRepresentation; \
} else { \
rpn_out += y; \
} \
rpn_string += y;


void infixToRPN::spacing(std::string &rpn_out, std::string &rpn_string) {
    if (!rpn_out.empty()) {
        if (rpn_out.at(rpn_out.size() - 1) != ' ') {
            rpn_out += " ";
            rpn_string += " ";
        }
    }
}

RETURN_TYPE_ERROR infixToRPN::convertInput(std::string &in, std::string &rpn_out, std::string &rpn_string,
                                           const std::map<char, Constant> &constantTable,
                                           const std::map<char, Operator *> &operatorTable,
                                           const std::map<std::string, char> &constantParseTable,
                                           const std::map<std::string, char> &operatorParseTable) {
    // --- START INFIX ZU RPN ---
    std::stack<char> operatorStack;
    for (int i = 0; i < in.size(); i++) {
        char token = in.at(i);
        if (isLetter(token)) {
            std::string specialSymbolParse;

            while (i < in.size() && !isOperator(in.at(i)) && in.at(i) != '(' && in.at(i) != ')') {
                specialSymbolParse += in.at(i);
                i++;
            }
            i--;

            if (operatorParseTable.find(specialSymbolParse) != operatorParseTable.end()) {
                token = operatorParseTable.at(specialSymbolParse);
                if (i + 1 == in.size() || in.at(i + 1) != '(') {
                    in.insert(i + 1, "(0)");
                }
            } else if (constantParseTable.find(specialSymbolParse) != constantParseTable.end()) {
                token = constantParseTable.at(specialSymbolParse);
            } else {
                std::string errorMessage = "Function/Constant \"" + specialSymbolParse;
                errorMessage += "\" not found!\n\"" + in + "\"\n";
                errorMessage += ShowError::err(i - specialSymbolParse.size() - 1);;
                return RETURN_TYPE_ERROR{(MathEngine::Error(MathEngine::ErrorType::FUNC_CONST_NOT_FOUND, errorMessage))};
            }
        } else if (token == '-' && (i == 0 ||
                                    (i > 0 && (in.at(i - 1) == '+' || in.at(i - 1) == '-' ||
                                               in.at(i - 1) == '*' || in.at(i - 1) == '/')))) {
            token = funcCode(4);
        }


        if (isNumeric(token) || token == '.' || isConstant(token, constantTable.size())) {
            getCorrectString(constantTable, token, .)

            // if number ends
            if (i + 1 != in.size() && !(isNumeric(in.at(i + 1))) && in.at(i + 1) != '.') {
                rpn_out += ' ';
                rpn_string += ' ';
            }
        } else if (isFunction(token, operatorTable.size()) || token == '(') {
            operatorStack.push(token);
        } else if (token == ')') {
            while (operatorStack.top() != '(') {
                infixToRPN::spacing(rpn_out, rpn_string);

                getCorrectString(operatorTable, operatorStack.top(), ->)

                operatorStack.pop();
            }

            if (operatorStack.top() == '(') {
                operatorStack.pop();
            }
        } else {
            if (operatorTable.find(token) == operatorTable.end()) {
                std::string errorMessage = "Invalid input near\n\"" + in + "\"\n";
                errorMessage += ShowError::err(i);
                return RETURN_TYPE_ERROR{MathEngine::Error(MathEngine::ErrorType::INVALID_INPUT, errorMessage)};
            }

            while (!operatorStack.empty() &&
                   operatorStack.top() != '(' &&
                   (operatorTable.at(operatorStack.top())->precedence > operatorTable.at(token)->precedence ||
                    (operatorTable.at(operatorStack.top())->precedence == operatorTable.at(token)->precedence &&
                     !operatorTable.at(token)->leftAssociate))) {
                infixToRPN::spacing(rpn_out, rpn_string);

                getCorrectString(operatorTable, operatorStack.top(), ->)

                operatorStack.pop();
            }
            infixToRPN::spacing(rpn_out, rpn_string);

            operatorStack.push(token);
        }
    }

    while (!operatorStack.empty()) {
        infixToRPN::spacing(rpn_out, rpn_string);

        getCorrectString(operatorTable, operatorStack.top(), ->)

        operatorStack.pop();
    }
    // --- ENDE INFIX ZU RPN ---

    return RETURN_TYPE_ERROR{MathEngine::NoError()};
}
