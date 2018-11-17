//
//  DumpConsumer.cpp
//  cpp2lua
//
//  Created by sql on 2018/11/17.
//  Copyright © 2018年 sql. All rights reserved.
//

#include "DumpConsumer.hpp"

DumpConsumer::DumpConsumer(CompilerInstance& compiler)
    : visitor(&compiler.getASTContext()), sourceManager(compiler.getSourceManager())
{
}
    
void DumpConsumer::HandleTranslationUnit(ASTContext& context)
{
    auto entry = sourceManager.getFileEntryForID(sourceManager.getMainFileID());
    std::cout << "-- main file\n";
    
    auto decls = context.getTranslationUnitDecl()->decls();
    for (auto decl : decls)
    {
        auto const& fileId = sourceManager.getFileID(decl->getLocation());
        if (fileId != sourceManager.getMainFileID())
            continue;
        
        visitor.TraverseDecl(decl);
    }
    
    // Pass args to main(), and call it
    if (visitor.HasFoundMain())
    {
        std::cout << "return (function() "
        << "table.insert(arg, 1, arg[0]); "
        << "return main(#arg, arg) end)()\n";
    }
}
