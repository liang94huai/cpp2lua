//
//  DumpConsumer.hpp
//  cpp2lua
//
//  Created by sql on 2018/11/17.
//  Copyright © 2018年 sql. All rights reserved.
//

#ifndef DumpConsumer_hpp
#define DumpConsumer_hpp

#include "DumpVisitor.hpp"

class DumpConsumer : public ASTConsumer
{
public:
    DumpConsumer(CompilerInstance& compiler);
    
    virtual void HandleTranslationUnit(ASTContext& context) override;
        
private:
    DumpVisitor visitor;
    SourceManager& sourceManager;
};

#endif /* DumpConsumer_hpp */
