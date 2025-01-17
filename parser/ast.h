

#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
#include "../visitor/visitor.h"

namespace parser {

    // Types
    enum TYPE {INT, REAL, BOOL, STRING};

//    enum FUNCTION {SQRT, POW, LG, FACTORIAL};

    // Abstract Nodes
    class ASTNode {
    public:
        virtual void accept(visitor::Visitor*) = 0;
    };

    class ASTStatementNode : public ASTNode {
    public:
        void accept(visitor::Visitor*) override = 0;
    };

    class ASTExprNode : public ASTNode {
    public:
        void accept(visitor::Visitor*) override = 0;
    };

    // Statement Nodes
    class ASTProgramNode : public ASTNode {
    public:
        explicit ASTProgramNode(std::vector<ASTNode*>);
        std::vector<ASTNode*> statements;
        void accept(visitor::Visitor*) override;
    };

    class ASTDeclarationNode : public ASTStatementNode {
    public:
        ASTDeclarationNode(TYPE, std::string, ASTExprNode*, unsigned int);
        TYPE type;
        std::string identifier;
        ASTExprNode *expr;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };

    class ASTAssignmentNode : public ASTStatementNode {
    public:
        ASTAssignmentNode(std::string, ASTExprNode*, unsigned int);
        std::string identifier;
        ASTExprNode *expr;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };

    class ASTPrintNode : public ASTStatementNode {
    public:
        ASTPrintNode(ASTExprNode*, unsigned int);
        ASTExprNode *expr;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };

    class ASTSqrtNode : public ASTStatementNode {
    public:
        ASTSqrtNode(ASTExprNode*, unsigned int);
        ASTExprNode *expr;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };
    class ASTFactNode : public ASTStatementNode {
    public:
        ASTFactNode(ASTExprNode*, unsigned int);
        ASTExprNode *expr;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };
    class ASTSinNode : public ASTStatementNode {
    public:
        ASTSinNode(ASTExprNode*, unsigned int);
        ASTExprNode *expr;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };
    class ASTCosNode : public ASTStatementNode {
    public:
        ASTCosNode(ASTExprNode*, unsigned int);
        ASTExprNode *expr;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };
    class ASTTangNode : public ASTStatementNode {
    public:
        ASTTangNode(ASTExprNode*, unsigned int);
        ASTExprNode *expr;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };
    class ASTLogNode : public ASTStatementNode {
    public:
        ASTLogNode(ASTExprNode*, unsigned int);
        ASTExprNode *expr;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };
    class ASTReturnNode : public ASTStatementNode {
    public:
        ASTReturnNode(ASTExprNode*, unsigned int);
        ASTExprNode *expr;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };

    class ASTBlockNode : public ASTStatementNode {
    public:
        ASTBlockNode(std::vector<ASTStatementNode*>, unsigned int);
        std::vector<ASTStatementNode*> statements;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };

    class ASTIfNode : public ASTStatementNode {
    public:
        ASTIfNode(ASTExprNode*, ASTBlockNode*, unsigned int, ASTBlockNode* = nullptr);
        ASTExprNode *condition;
        ASTBlockNode *if_block;
        ASTBlockNode *else_block;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };

    class ASTWhileNode : public ASTStatementNode {
    public:
        ASTWhileNode(ASTExprNode*, ASTBlockNode*, unsigned int);
        ASTExprNode *condition;
        ASTBlockNode *block;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };

    class ASTFunctionDefinitionNode : public ASTStatementNode {
    public:
        ASTFunctionDefinitionNode(std::string, std::vector<std::pair<std::string, TYPE>>,
                                  TYPE, ASTBlockNode*, unsigned int);
        std::string identifier;
        std::vector<std::pair<std::string, TYPE>> parameters;
        std::vector<std::string> variable_names;
        std::vector<TYPE> signature;
        TYPE type;
        ASTBlockNode* block;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };

    // Expression Nodes
    template <typename T>
    class ASTLiteralNode : public ASTExprNode {
    public:
        ASTLiteralNode(T val, unsigned int line_number) : val(val), line_number(line_number) {};
        T val;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };

    class ASTBinaryExprNode : public ASTExprNode {
    public:
        ASTBinaryExprNode(std::string, ASTExprNode*, ASTExprNode*, unsigned int);
        std::string op;
        ASTExprNode *left;
        ASTExprNode *right;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };

    class ASTIdentifierNode : public ASTExprNode {
    public:
        explicit ASTIdentifierNode(std::string, unsigned int);
        std::string identifier;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };

    class ASTUnaryExprNode : public ASTExprNode {
    public:
        ASTUnaryExprNode(std::string, ASTExprNode*, unsigned int);
        std::string unary_op;
        ASTExprNode *expr;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };

    class ASTFunctionCallNode : public ASTExprNode {
    public:
        ASTFunctionCallNode(std::string, std::vector<ASTExprNode*>, unsigned int);
        std::string identifier;
        std::vector<ASTExprNode*> parameters;
        unsigned int line_number;
        void accept(visitor::Visitor*) override;
    };

}


#endif
