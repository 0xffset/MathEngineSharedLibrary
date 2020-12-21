//
// Created by u-0xffset on 15.11.20.
//

#include "Sign.hpp"

#include <utility>

MathEngine::Sign::Sign(int _pr, std::string _sr, int _ac) : Operator(_pr, std::move(_sr), _ac) {

}

RETURN_TYPE_ERROR_LONGDOUBLE MathEngine::Sign::calc(long double params[]) {
    return RETURN_TYPE_ERROR_LONGDOUBLE{-params[0]};
}
