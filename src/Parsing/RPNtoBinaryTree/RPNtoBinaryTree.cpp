//
// Created by u-0xffset on 13.11.20.
//

#include "RPNtoBinaryTree.hpp"
#include "../../HeaderOfConvenience.hpp"
#include "./../../Errors/IncludeErrors.hpp"

#include <stack>

int MathEngine::rpnToBinaryTree::numberOfOccurrences(std::string &str, char match) {
    int count = 0;
    for (char c : str) {
        if (c == match)
            count++;
    }
    return count;
}

RETURN_TYPE_ERROR_TREE MathEngine::rpnToBinaryTree::parseBinaryTree(const std::string &rpn_string,
                                                                    const std::map<char, Constant> &constantTable,
                                                                    const std::map<char, Operator *> &operatorTable) {
    std::stack<MathEngine::TreeNode> stack;
    std::string cur;
    for (int i = 0; i < rpn_string.length(); i++) {
        cur = "";

        while (i != rpn_string.length() && rpn_string.at(i) != ' ') {
            cur += rpn_string.at(i);
            i++;
        }

        if (cur.length() == 1) {
            char c = cur.at(0);
            if (MathEngine::isNumeric(c)) {
                stack.push(MathEngine::TreeNode(MathEngine::TreeNodeType::Number, c - '0'));
            } else if (operatorTable.find(c) != operatorTable.end()) {
                std::vector<MathEngine::TreeNode> temp;

                if (stack.size() < operatorTable.at(c)->argumentCount) {
                    std::string errorMessage =
                            "Insufficient arguments were provided for: " + operatorTable.at(c)->stringRepresentation;
                    return RETURN_TYPE_ERROR_TREE{
                            MathEngine::Error(MathEngine::ErrorType::INSUFFICIENT_ARGUMENT_COUNT, errorMessage)};
                }

                for (int j = 0; j < operatorTable.at(c)->argumentCount; j++) {
                    temp.push_back(stack.top());
                    stack.pop();
                }
                stack.push(MathEngine::TreeNode(MathEngine::TreeNodeType::Operator, c, temp));
            } else if (MathEngine::isConstant(c, constantTable.size())) {
                stack.push(MathEngine::TreeNode(MathEngine::TreeNodeType::Constant, constantTable.at(c).value));
            }
        } else {
            if (rpnToBinaryTree::numberOfOccurrences(cur, '.') > 1) {
                std::string errorMessage = "Too many decimal points in: " + cur;
                errorMessage += "\n\"" + rpn_string + "\"\n";
                errorMessage += ShowError::err(i - 1);
                return RETURN_TYPE_ERROR_TREE{
                        MathEngine::Error(MathEngine::ErrorType::TOO_MANY_DECIMALS, errorMessage)};
            }
            stack.push(MathEngine::TreeNode(MathEngine::TreeNodeType::Number, std::stold(cur)));
        }
    }
    if (!stack.empty()) {
        return RETURN_TYPE_ERROR_TREE{stack.top()};
    } else {
        std::string errorMessage = "Empty input!";
        return RETURN_TYPE_ERROR_TREE{MathEngine::Error(MathEngine::ErrorType::EMPTY_INPUT, errorMessage)};
    }
}