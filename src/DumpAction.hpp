//
//  DumpAction.hpp
//  cpp2lua
//
//  Created by sql on 2018/11/17.
//  Copyright © 2018年 sql. All rights reserved.
//

#ifndef DumpAction_hpp
#define DumpAction_hpp

#include "DumpConsumer.hpp"

class DumpAction : public ASTFrontendAction
{
public:
    virtual bool BeginSourceFileAction(CompilerInstance &compiler) override;
    
    virtual std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance& compiler,
                                                           llvm::StringRef inFile) override;
};

#endif /* DumpAction_hpp */
