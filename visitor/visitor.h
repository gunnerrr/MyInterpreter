

#ifndef VISITOR_H
#define VISITOR_H

#include <string>

namespace parser {

    class ASTProgramNode;

    class ASTDeclarationNode;
    class ASTAssignmentNode;
    class ASTPrintNode;
    class ASTSqrtNode;
    class ASTFactNode;
    class ASTSinNode;
    class ASTCosNode;
    class ASTTangNode;
    class ASTLogNode;
    class ASTReturnNode;
    class ASTBlockNode;
    class ASTIfNode;
    class ASTWhileNode;
    class ASTFunctionDefinitionNode;

    template <typename T> class ASTLiteralNode;
    class ASTBinaryExprNode;
    class ASTIdentifierNode;
    class ASTUnaryExprNode;
    class ASTFunctionCallNode;
}

namespace visitor {

    class Visitor {

    public:

        virtual void visit(parser::ASTProgramNode*) = 0;
        virtual void visit(parser::ASTDeclarationNode*) = 0;
        virtual void visit(parser::ASTAssignmentNode*) = 0;
        virtual void visit(parser::ASTPrintNode*) = 0;
        virtual void visit(parser::ASTSqrtNode*) = 0;
        virtual void visit(parser::ASTFactNode*) = 0;
        virtual void visit(parser::ASTSinNode*) = 0;
        virtual void visit(parser::ASTCosNode*) = 0;
        virtual void visit(parser::ASTTangNode*) = 0;
        virtual void visit(parser::ASTLogNode*) = 0;
        virtual void visit(parser::ASTReturnNode*) = 0;
        virtual void visit(parser::ASTBlockNode*) = 0;
        virtual void visit(parser::ASTIfNode*) = 0;
        virtual void visit(parser::ASTWhileNode*) = 0;
        virtual void visit(parser::ASTFunctionDefinitionNode*) = 0;
        virtual void visit(parser::ASTLiteralNode<int>*) = 0;
        virtual void visit(parser::ASTLiteralNode<float>*) = 0;
        virtual void visit(parser::ASTLiteralNode<bool>*) = 0;
        virtual void visit(parser::ASTLiteralNode<std::string>*) = 0;
        virtual void visit(parser::ASTBinaryExprNode*) = 0;
        virtual void visit(parser::ASTIdentifierNode*) = 0;
        virtual void visit(parser::ASTUnaryExprNode*) = 0;
        virtual void visit(parser::ASTFunctionCallNode*) = 0;
    };

}


#endif
