

#ifndef PARSER_H
#define PARSER_H


#include "ast.h"
#include "../lexer/lexer.h"

namespace parser {

    class Parser {

        public:
            explicit Parser(lexer::Lexer*);
            Parser(lexer::Lexer*, unsigned int);
            ASTProgramNode* parse_program();
            ASTExprNode* parse_expression();  // public for repl

        private:

            lexer::Lexer* lex;
            lexer::Token current_token;
            lexer::Token next_token;

            void consume_token();

            // Statement Nodes
            ASTStatementNode*             parse_statement();
            ASTDeclarationNode*           parse_declaration_statement();
            ASTAssignmentNode*            parse_assignment_statement();
            ASTPrintNode*                 parse_print_statement();
            ASTSqrtNode*        parse_sqrt_statement();
            ASTFactNode*        parse_fact_statement();
            ASTSinNode*        parse_sin_statement();
            ASTCosNode*        parse_cos_statement();
            ASTTangNode*        parse_tang_statement();
            ASTLogNode*        parse_log_statement();
            ASTReturnNode*                parse_return_statement();
            ASTBlockNode*                 parse_block();
            ASTIfNode*                    parse_if_statement();
            ASTWhileNode*                 parse_while_statement();
            ASTFunctionDefinitionNode*    parse_function_definition();

            // Expression Nodes
            ASTExprNode*               parse_simple_expression();
            ASTExprNode*               parse_term();
            ASTExprNode*               parse_factor();
            ASTFunctionCallNode*       parse_function_call();


            // Parse Types and parameters
            TYPE parse_type(std::string&);
            std::vector<ASTExprNode*> *parse_actual_params();
            std::pair<std::string, TYPE>* parse_formal_param();

    };

}

#endif
