//
//  DumpVisitor.hpp
//  cpp2lua
//
//  Created by sql on 2018/11/17.
//  Copyright © 2018年 sql. All rights reserved.
//

#ifndef DumpVisitor_hpp
#define DumpVisitor_hpp

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "clang/Lex/Preprocessor.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <deque>

using namespace clang;
using namespace clang::tooling;

namespace cl = llvm::cl;

template <typename T>
T* RecurseUntilType(Stmt* stmt)
{
    if (isa<T>(stmt))
        return cast<T>(stmt);
    
    for (auto child : stmt->children())
    {
        auto ret = RecurseUntilType<T>(child);
        if (ret)
            return ret;
    }
    
    return nullptr;
}

class DumpVisitor : public RecursiveASTVisitor<DumpVisitor>
{
public:
    explicit DumpVisitor(ASTContext* context);
    
    void TraverseNewScope(Stmt* stmt);
    
    void TraverseCondition(Stmt* stmt);
    
    std::string GetNameForVarDecl(VarDecl* varDecl);
    std::string GetNameForFuncDecl(FunctionDecl *funcDecl);
    
    bool TraverseStmt(Stmt* stmt);
    
    bool TraverseDecl(Decl* decl);
    
    bool VisitStmt(Stmt* stmt);
    
    void WriteDepth();
    
    bool HasFoundMain() { return foundMain; }
    
private:
    ASTContext* context;
    uint32_t depth = 0;
    bool foundMain = false;
    bool handlingAssignmentInCondition = false;
    uint32_t counter = 0;
    std::deque<std::string> scopeStack;
    
    bool m_isCXXCall = false;
};

#endif /* DumpVisitor_hpp */
