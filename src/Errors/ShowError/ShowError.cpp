//
// Created by u-0xffset on 17.11.20.
//

#include "ShowError.hpp"

std::string ShowError::err( int i) {
    std::string out = " ";
    if (i > 0) {
        for (int j = 0; j < i; j++) {
            out += " ";
        }
    }
    out += "^";
    return out;
}