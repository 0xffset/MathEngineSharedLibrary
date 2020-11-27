//
// Created by u-0xffset on 13.11.20.
//

#include "HeaderOfConvenience.hpp"

bool isNumeric(char c) {
    return c >= '0' && c <= '9';
}

bool isFunction(char c, int amount) {
    return c >= FUNCTION_START_RANGE && c < (FUNCTION_START_RANGE + amount);
}

bool isConstant(char c, int amount) {
    return c >= CONSTANT_START_RANGE && c < (CONSTANT_START_RANGE + amount);
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}