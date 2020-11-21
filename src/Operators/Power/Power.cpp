//
// Created by u-0xffset on 12.11.20.
//

#include "Power.hpp"

#include <utility>
#include <cmath>

Power::Power(int _pr, std::string _sr, int _ac) : Operator(_pr, std::move(_sr), _ac) {
    this->leftAssociate = true;
}

RETURN_TYPE_ERROR_LONGDOUBLE Power::calc(long double params[]) {
    return RETURN_TYPE_ERROR_LONGDOUBLE{powl(params[1], params[0])};
}
