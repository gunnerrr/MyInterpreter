

#ifndef XML_VISITOR_H
#define XML_VISITOR_H

#include <fstream>
#include "visitor.h"
#include "../parser/ast.h"
#include"../visitor/interpreter.h"

namespace visitor{

    class XMLVisitor : public Visitor {

    public:
        XMLVisitor();
        ~XMLVisitor();

        void visit(parser::ASTProgramNode*) override;
        void visit(parser::ASTDeclarationNode*) override;
        void visit(parser::ASTAssignmentNode*) override;
        void visit(parser::ASTPrintNode*) override;
        void visit(parser::ASTSqrtNode*) override;
        void visit(parser::ASTFactNode*) override;
        void visit(parser::ASTSinNode*) override;
        void visit(parser::ASTCosNode*) override;
        void visit(parser::ASTTangNode*) override;
        void visit(parser::ASTLogNode*) override;
        void visit(parser::ASTReturnNode*) override;
        void visit(parser::ASTBlockNode*) override;
        void visit(parser::ASTIfNode*) override;
        void visit(parser::ASTWhileNode*) override;
        void visit(parser::ASTFunctionDefinitionNode*) override;
        void visit(parser::ASTLiteralNode<int>*) override;
        void visit(parser::ASTLiteralNode<float>*) override;
        void visit(parser::ASTLiteralNode<bool>*) override;
        void visit(parser::ASTLiteralNode<std::string>*) override;
        void visit(parser::ASTBinaryExprNode*) override;
        void visit(parser::ASTIdentifierNode*) override;
        void visit(parser::ASTUnaryExprNode*) override;
        void visit(parser::ASTFunctionCallNode*) override;

    protected:
        std::ofstream xmlfile;
        unsigned int indentation_level;
        const std::string TAB = "    ";
        std::string indentation();
        std::string type_str(parser::TYPE);
        std::string xml_safe_op(std::string);
    };

}

#endif
