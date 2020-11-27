//
// Created by u-0xffset on 27.11.20.
//

#include "Factorial.hpp"

#include <utility>

RETURN_TYPE_ERROR_LONGDOUBLE Factorial::calc(long double params[]) {
    auto out = (long long) params[0];
    // TODO rework this with own data type once implemented
    if (out > 20) {
        std::string errorMessage = "Input factorial \"" + std::to_string(out);
        errorMessage += "!\" is too large, maximum allowed is 20!";
        return RETURN_TYPE_ERROR_LONGDOUBLE{
                MathEngine::Error(MathEngine::ErrorType::TOO_LARGE_FACTORIAL, errorMessage)};
    }

    for (auto i = out - 1; i >= 2; i--) {
        out *= i;
    }

    return RETURN_TYPE_ERROR_LONGDOUBLE{(long double) out};
}

Factorial::Factorial(int _pr, std::string _sr, int _ac) : Operator(_pr, std::move(_sr), _ac) {}