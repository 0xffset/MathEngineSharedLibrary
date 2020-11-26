//
// Created by u-0xffset on 19.11.20.
//

#include "Calculator.hpp"
#include "../Parsing/InfixToRPN/InfixToRPN.hpp"
#include "../Parsing/RPNtoBinaryTree/RPNtoBinaryTree.hpp"
#include "../Parsing/InputParser/InputParser.hpp"

#define GET_TIME_PRE this->start = std::chrono::high_resolution_clock::now();
#define GET_TIME_POST this->stop = std::chrono::high_resolution_clock::now();

MathEngine::Calculator::Calculator() {
    this->setup();
}

/*
 * Could be optimized by instead of using std::holds_alternative, use std::alternative::index() with appropriate index
 */

RETURN_TYPE_ERROR MathEngine::Calculator::initCalculation(const std::string& _input) {
    this->rpn_string = "";
    this->rpn_out = "";

    std::string parsedInput;
    RETURN_TYPE_ERROR parseInput = inputParser::parseInput(parsedInput, _input.c_str());
    if (std::holds_alternative<MathEngine::Error>(parseInput)) {
        return parseInput;
    }

    GET_TIME_PRE
    RETURN_TYPE_ERROR convertInput = infixToRPN::convertInput(parsedInput, this->rpn_out, this->rpn_string,
                                                              this->constantTable, this->operatorTable,
                                                              this->constantParseTable, this->operatorParseTable);
    GET_TIME_POST
    if (std::holds_alternative<MathEngine::Error>(convertInput)) {
        return convertInput;
    }

    this->infixToRPNTime = std::chrono::duration_cast<std::chrono::microseconds>(this->stop - this->start);

    GET_TIME_PRE
    RETURN_TYPE_ERROR_TREE tree = rpnToBinaryTree::parseBinaryTree(this->rpn_string, this->constantTable,
                                                                   this->operatorTable);
    GET_TIME_POST
    if (std::holds_alternative<MathEngine::Error>(tree)) {
        return RETURN_TYPE_ERROR{std::get<MathEngine::Error>(tree)};
    }

    this->RPNtoBinaryTreeTime = std::chrono::duration_cast<std::chrono::microseconds>(this->stop - this->start);

    GET_TIME_PRE
    RETURN_TYPE_ERROR_LONGDOUBLE res = this->calculate(std::get<TreeNode>(tree));
    GET_TIME_POST
    if (std::holds_alternative<MathEngine::Error>(res)) {
        return RETURN_TYPE_ERROR{std::get<MathEngine::Error>(res)};
    }

    this->calculationTime = std::chrono::duration_cast<std::chrono::microseconds>(this->stop - this->start);

    this->result = std::get<long double>(res);

    return MathEngine::NoError();
}

void MathEngine::Calculator::setup() {
    this->funcCount = 0;
    this->constCount = 0;

    // Add functions
    ADD_FUNC("sqrt", this->funcCount, new SquareRoot(5, "sqrt", 1))
    ADD_FUNC("sin", this->funcCount, new Sine(6, "sin", 1))
    ADD_FUNC("cos", this->funcCount, new Cosine(6, "cos", 1))
    ADD_FUNC("tan", this->funcCount, new Tangent(6, "tan", 1))

    // Add constants
    ADD_CONST("pi", this->constCount, M_PIl)
    ADD_CONST("e", this->constCount, M_El)

    // Add operators
    ADD_OP('-', new Subtraction(2, "-", 2))
    ADD_OP('+', new Addition(2, "+", 2))
    ADD_OP('*', new Multiplication(3, "*", 2))
    ADD_OP('/', new Division(3, "/", 2))
    ADD_OP('^', new Power(5, "^", 2))
    ADD_OP(funcCode(this->funcCount), new Sign(4, "-", 1))
    this->funcCount++;
}

RETURN_TYPE_ERROR_LONGDOUBLE MathEngine::Calculator::calculate(const TreeNode &tree) {
    if (tree.type != TreeNodeType::Type::Operator)
        return RETURN_TYPE_ERROR_LONGDOUBLE{tree.value};

    long double temp[tree.nodes.size()];
    for (int i = 0; i < tree.nodes.size(); i++) {
        RETURN_TYPE_ERROR_LONGDOUBLE midRes = calculate(tree.nodes.at(i));
        if (std::holds_alternative<MathEngine::Error>(midRes)) {
            return midRes;
        }
        temp[i] = std::get<long double>(midRes);
    }

    return this->operatorTable.at((char) tree.value)->calc(temp);
}

std::chrono::microseconds MathEngine::Calculator::getInfixToRPNTime() const {
    return this->infixToRPNTime;
}

std::chrono::microseconds MathEngine::Calculator::getRPNtoBinaryTreeTime() const {
    return this->RPNtoBinaryTreeTime;
}

std::chrono::microseconds MathEngine::Calculator::getCalculationTime() const {
    return this->calculationTime;
}

std::string MathEngine::Calculator::getRPNOut() const {
    return this->rpn_out;
}

std::string MathEngine::Calculator::getRPNString() const {
    return this->rpn_string;
}

long double MathEngine::Calculator::getResult() const {
    return this->result;
}
