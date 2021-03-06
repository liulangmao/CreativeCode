//
//  CreativeQRTool.hpp
//  CreativeQRcode
//
//  Created by liming on 17/07/2017.
//  Copyright © 2017 liming. All rights reserved.
//

#ifndef CreativeQRTool_hpp
#define CreativeQRTool_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "Point.hpp"
#include <sstream>
using namespace std;
#include "CreativeElement.hpp"
#include "CoreGraphics/CGImage.h"
#include "CreativeEnv.hpp"

class CreativeQRTool{
public:
    CreativeQRTool(int size,int cellsize);
    ~CreativeQRTool();
    
public:
    int** getMat();
    void fillEye();
    void FindCellEqualsOne();
    void FillbyType();
    UInt32 * CreateFinal(int size,int margin);
    void clean();
    
    
    
    
private:
    
    void fillType(int row,int col,CreativeElement type);
    void Print(int** array,int width,int height);
    void fillAnyType(CreativeElement type);
    bool test(int row,int col,CreativeElement type);
    string Int_to_String(int n);
    void Draw(int originWidth, int originHeight,Cell* cell,UInt32* finalMat,int margin,int finalSize);
    
    
    int **m_mat;
    int size=0;
    vector<PointS> m_list;
    const bool openDebug=true;
    const bool openDebugDetail=false;
    int  cellSize=0;
    const int  EyeSize=7;
    
};

#endif /* CreativeQRTool_hpp */
