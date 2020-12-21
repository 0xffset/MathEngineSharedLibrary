//
// Created by u-0xffset on 13.11.20.
//

#include "InputParser.hpp"
#include "../../Errors/IncludeErrors.hpp"

int MathEngine::inputParser::numberOfOccurrences(std::string &str, char match) {
    int count = 0;
    for (char c : str) {
        if (c == match)
            count++;
    }
    return count;
}

RETURN_TYPE_ERROR MathEngine::inputParser::parseInput(std::string &in, const char *argv) {
    int _i = 0;
    std::string temp;
    while (argv[_i] != '\0') {
        if (argv[_i] != ' ') {
            temp += argv[_i];
        }
        _i++;
    }

    for (int i = 0; i < temp.size(); i++) {
        if (temp.at(i) == '.') {
            if (i != 0) {
                if (MathEngine::isOperator(temp.at(i - 1))) {
                    in += '0';
                } else if (!MathEngine::isNumeric(temp.at(i - 1))) {
                    std::string errorMessage = "Invalid input near:\n\"" + temp + "\"\n";
                    errorMessage += ShowError::err(i);
                    return RETURN_TYPE_ERROR{MathEngine::Error(MathEngine::ErrorType::INVALID_INPUT, errorMessage)};
                }
            } else {
                in += '0';
            }
        }

        in += temp.at(i);

        if (i + 1 != temp.size()) {
            // Implizite Multiplikation von Klammern ((x+y)(x+y))
            if ((temp.at(i) == ')' && (temp.at(i + 1) == '(' ||
                                       MathEngine::isNumeric(temp.at(i + 1)) ||
                                       MathEngine::isLetter(temp.at(i + 1)))) ||
                (MathEngine::isNumeric(temp.at(i)) && (MathEngine::isLetter(temp.at(i + 1)) ||
                                                       temp.at(i + 1) == '('))) {
                in += '*';
            }
        }
    }

    if (MathEngine::inputParser::numberOfOccurrences(in, '(') !=
        MathEngine::inputParser::numberOfOccurrences(in, ')')) {
        std::string errorMessage = "Uneven distribution of parenthesis";
        return RETURN_TYPE_ERROR{
                MathEngine::Error(MathEngine::ErrorType::UNEVEN_DISTRIBUTION_OF_PARENTHESIS, errorMessage)};
    }

    return RETURN_TYPE_ERROR{MathEngine::NoError()};
}
