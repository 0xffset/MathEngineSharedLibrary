//
// Created by u-0xffset on 12.11.20.
//

#include "SquareRoot.hpp"

#include <cmath>
#include <utility>

MathEngine::SquareRoot::SquareRoot(int _pr, std::string _sr, int _ac) : Operator(_pr, std::move(_sr), _ac) {}

RETURN_TYPE_ERROR_LONGDOUBLE MathEngine::SquareRoot::calc(long double params[]) {
    if (params[0] < 0) {
        std::string errorMessage = "Square root of negative";
        return RETURN_TYPE_ERROR_LONGDOUBLE{MathEngine::Error(MathEngine::ErrorType::SQUARE_ROOT_OF_NEGATIVE, errorMessage)};
    }
    return RETURN_TYPE_ERROR_LONGDOUBLE{sqrtl(params[0])};
}
