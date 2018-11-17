//
//  Utils.hpp
//  cpp2lua
//
//  Created by sql on 2018/11/17.
//  Copyright © 2018年 sql. All rights reserved.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <string>
#include <vector>

class Utils
{
public:
    static std::string replaceString(const std::string &str, const std::string &src, const std::string &dest);
    
    static void splitString(const std::string& strSrc, const std::string& strFind, std::vector<std::string>& arSplit);
};

#endif /* Utils_hpp */
