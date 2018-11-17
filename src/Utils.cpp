//
//  Utils.cpp
//  cpp2lua
//
//  Created by sql on 2018/11/17.
//  Copyright © 2018年 sql. All rights reserved.
//

#include "Utils.hpp"

using namespace std;

std::string Utils::replaceString(const std::string &str, const std::string &src, const std::string &dest){
    std::string ret = str;
    while(true){
        std::string::size_type pos(0);
        if((pos = ret.find(src)) != std::string::npos)
            ret.replace(pos, src.length(), dest);
        else
            break;
    }
    return  ret;
}

void Utils::splitString(const std::string& strSrc, const std::string& strFind, std::vector<std::string>& arSplit) {
    if(strSrc == strFind){
        return;
    }
    string tmpStr(strSrc.data(),strSrc.length());
    
    if(tmpStr.length() > strFind.length())
    {
        while (!tmpStr.empty() && tmpStr.find(strFind.c_str()) == 0) {
            tmpStr = tmpStr.substr(strFind.length(), tmpStr.length()-strFind.length());
        }
        while (!tmpStr.empty() && tmpStr.rfind(strFind.c_str()) == (tmpStr.length()-strFind.length())) {
            tmpStr = tmpStr.substr(0, tmpStr.length()-strFind.length());
        }
    }
    
    char* src = const_cast<char*>(tmpStr.c_str());
    while (src != NULL && !tmpStr.empty()) {
        arSplit.push_back(std::string(strtok_r(src, strFind.c_str(), &src)));
    }
}
