//
// Created by u-0xffset on 13.11.20.
//

#include "InputParser.hpp"
#include "../../Errors/IncludeErrors.hpp"

int inputParser::numberOfOccurrences(std::string &str, char match) {
    int count = 0;
    for (char c : str) {
        if (c == match)
            count++;
    }
    return count;
}

RETURN_TYPE_ERROR inputParser::parseInput(std::string &in, const char *argv) {
    int _i = 0;
    std::string temp;
    while (argv[_i] != '\0') {
        if (argv[_i] != ' ') {
            temp += argv[_i];
        }
        _i++;
    }

    for (int i = 0; i < temp.size(); i++) {
        if (temp.at(i) == '.' && (i == 0 || !isNumeric(temp.at(i - 1)))) {
            if (i != 0) {
                if (temp.at(i - 1) == ']' || temp.at(i - 1) == ')') {
                    std::string errorMessage = "Invalid input near:\n\"" + temp + "\"\n";
                    errorMessage += ShowError::err(i);
                    return RETURN_TYPE_ERROR{MathEngine::Error(MathEngine::ErrorType::INVALID_INPUT, errorMessage)};
                }
            }
            in += '0';
        }

        in += temp.at(i);

        if (i + 1 != temp.size()) {
            // Implizite Multiplikation von Klammern ((x+y)(x+y)) und Funktionen/Konstanten (4[pi] und [pi][pi])
            if ((temp.at(i) == ')' && temp.at(i + 1) == '(') ||
                ((isNumeric(temp.at(i)) &&
                  temp.at(i + 1) == '[') ||
                 (temp.at(i) == ']' && temp.at(i + 1) == '['))) {
                in += '*';
            }
        }
    }

    if (inputParser::numberOfOccurrences(in, '(') != inputParser::numberOfOccurrences(in, ')')) {
        std::string errorMessage = "Uneven distribution of parenthesis";
        return RETURN_TYPE_ERROR{MathEngine::Error(MathEngine::ErrorType::UNEVEN_DISTRIBUTION_OF_PARENTHESIS, errorMessage)};
    }

    return RETURN_TYPE_ERROR{MathEngine::NoError()};
}
