//
// Created by u-0xffset on 12.11.20.
//

#ifndef MATHENGINE_TREENODE_HPP
#define MATHENGINE_TREENODE_HPP

#include <any>
#include <vector>

namespace MathEngine {
    enum class TreeNodeType {
        Operator,
        Constant,
        Number
    };

    class TreeNode {
    public:
        TreeNodeType type;
        long double value;
        std::vector<TreeNode> nodes;

        TreeNode(TreeNodeType _type, long double _value);

        TreeNode(TreeNodeType _type, long double _value, std::vector<TreeNode> _nodes);
    };
}

#endif //MATHENGINE_TREENODE_HPP
