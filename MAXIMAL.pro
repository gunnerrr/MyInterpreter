TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lexer/lexer.cpp \
    lexer/token.cpp \
    parser/ast.cpp \
    parser/parser.cpp \
    visitor/interpreter.cpp \
    visitor/semantic_analysis.cpp \
    visitor/xml_visitor.cpp

HEADERS += \
    lexer/lexer.h \
    lexer/token.h \
    parser/ast.h \
    parser/parser.h \
    table/table.h \
    visitor/interpreter.h \
    visitor/semantic_analysis.h \
    visitor/visitor.h \
    visitor/xml_visitor.h
