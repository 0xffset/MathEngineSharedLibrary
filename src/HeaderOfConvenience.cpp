//
// Created by u-0xffset on 13.11.20.
//

#include "HeaderOfConvenience.hpp"

bool MathEngine::isNumeric(char c) {
    return c >= '0' && c <= '9';
}

bool MathEngine::isFunction(char c, int amount) {
    return c >= FUNCTION_START_RANGE && c < (FUNCTION_START_RANGE + amount);
}

bool MathEngine::isConstant(char c, int amount) {
    return c >= CONSTANT_START_RANGE && c < (CONSTANT_START_RANGE + amount);
}

bool MathEngine::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool MathEngine::isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}