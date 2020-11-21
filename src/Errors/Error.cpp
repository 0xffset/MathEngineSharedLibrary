//
// Created by u-0xffset on 20.11.20.
//

#include "Error.hpp"

#include <utility>

MathEngine::Error::Error(MathEngine::ErrorType _errorType, std::string _errorMessage) :
        errorMessage(std::move(_errorMessage)), errorType(_errorType) {}

MathEngine::Error::Error(MathEngine::ErrorType _errorType) : errorType(_errorType) {}
