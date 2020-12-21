//
// Created by u-0xffset on 12.11.20.
//

#include "Division.hpp"

#include <utility>

MathEngine::Division::Division(int _pr, std::string _sr, int _ac) : Operator(_pr, std::move(_sr), _ac) {}

RETURN_TYPE_ERROR_LONGDOUBLE MathEngine::Division::calc(long double params[]) {
    if (params[0] == 0) {
        std::string errorMessage = "Division by 0!";
        return RETURN_TYPE_ERROR_LONGDOUBLE{MathEngine::Error(MathEngine::ErrorType::DIVISION_BY_ZERO, errorMessage)};
    }
    return RETURN_TYPE_ERROR_LONGDOUBLE{params[1] / params[0]};
}
