//
//  BasicQRTool.hpp
//  CreativeQRcode
//
//  Created by liming on 7/14/17.
//  Copyright © 2017 liming. All rights reserved.
//

#ifndef BasicQRTool_hpp
#define BasicQRTool_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class BasicQRTool{
public:
    BasicQRTool(string *txt);
    ~BasicQRTool();
    
public:
    void GenMatrix(int ** m_mat);
    void Print(int **array, int width, int height);
    
private:
    const char *txt;
    
};








#endif /* BasicQRTool_hpp */
