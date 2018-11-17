//
//  DumpAction.cpp
//  cpp2lua
//
//  Created by sql on 2018/11/17.
//  Copyright © 2018年 sql. All rights reserved.
//

#include "DumpAction.hpp"

//void IncludeFile(std::string const& path)
//{
//    if (BakeIncludes)
//    {
//        std::fstream file(path);
//
//        if (file.fail())
//        {
//            std::cout << "-- Failed to read file: " << path << "\n";
//            return;
//        }
//
//        std::string str;
//
//        file.seekg(0, std::ios::end);
//        str.resize(file.tellg());
//        file.seekg(0, std::ios::beg);
//
//        file.read(&str[0], str.size());
//
//        std::cout << "-- " << path << "\n";
//        std::cout << str;
//    }
//    else
//    {
//        std::cout << "dofile \"" << path << "\"\n";
//    }
//}

bool DumpAction::BeginSourceFileAction(CompilerInstance &compiler)
{
    //        IncludeFile("shim/lua/memory.lua");
    //        IncludeFile("shim/lua/bitwise.lua");
    
    class PrintIncludes : public PPCallbacks
    {
    public:
        PrintIncludes(SourceManager& sourceManager)
        : sourceManager(sourceManager)
        {
        }
        
        virtual void InclusionDirective(SourceLocation location, Token const&, StringRef fileName,
                                        bool isAngled, CharSourceRange, FileEntry const*,
                                        StringRef, StringRef, Module const*, SrcMgr::CharacteristicKind) override
        {
            // Skip over includes that are not from the main file
            if (sourceManager.getFileID(location) != sourceManager.getMainFileID())
                return;
            
            //                auto newFileName = fileName.str();
            //                newFileName = newFileName.substr(0, newFileName.find_last_of('.'));
            //                newFileName += ".lua";
            //
            //                if (isAngled)
            //                    newFileName = "shim/lua/" + newFileName;
            //
            //                IncludeFile(newFileName);
        }
        
        SourceManager& sourceManager;
    };
    
    std::unique_ptr<PrintIncludes> callback(
                                            new PrintIncludes(compiler.getSourceManager()));
    auto& preprocessor = compiler.getPreprocessor();
    preprocessor.addPPCallbacks(std::move(callback));
    
    return true;
}

std::unique_ptr<ASTConsumer> DumpAction::CreateASTConsumer(CompilerInstance& compiler,
                                                       llvm::StringRef inFile)
{
    return std::unique_ptr<ASTConsumer>(new DumpConsumer(compiler));
}
