//
//  CreativeElementStyle.hpp
//  CreativeQRcode
//
//  Created by liming on 2017/7/25.
//  Copyright © 2017年 liming. All rights reserved.
//

#ifndef CreativeElementStyle_hpp
#define CreativeElementStyle_hpp

#include <stdio.h>
#include<string>
using namespace std;

class CreativeElementStyle{
private:
    int cellsize=0;
    string* namelist;
public:
    CreativeElementStyle();
    CreativeElementStyle(int value,string* namelist);
    int getCellsize();
    string* getNamelist();
    void setCellsize(int cellsize);
    void setNamelist(string* namelist);
};
#endif /* CreativeElementStyle_hpp */
