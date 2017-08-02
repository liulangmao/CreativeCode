//
//  BasicQRTool.cpp
//  CreativeQRcode
//
//  Created by liming on 7/14/17.
//  Copyright © 2017 liming. All rights reserved.
//

#include "BasicQRTool.hpp"
#include "QrCode.hpp"
using qrcodegen::QrCode;
using qrcodegen::QrSegment;
#include <string>
using namespace std;

const QrCode::Ecc &errCorLvl = QrCode::Ecc::LOW;

BasicQRTool::BasicQRTool(string* txt){
    this->txt=txt;
}
BasicQRTool::~BasicQRTool(){
    }

void BasicQRTool::GenMatrix(int ** m_mat){

    // Make and print the QR Code symbol
    const QrCode code = QrCode::encodeText(this->txt->c_str(), errCorLvl);
    
    cout<<"code size:"<<code.size<<endl;
    if (!code.size) {
        cout<<"error: in BasicQRTool::GenMatrix():QrCode equals null"<<endl;
    }
    for(int y = 0; y < code.size; y++) {
        for(int x = 0; x < code.size; x++) {
            if(code.getModule(x, y)== 1){
                m_mat[x][y]=1;
            }
            else
            {
                m_mat[x][y]=0;
                
            }
        }
    }
    //cout<<"I am in GenMatrix()"<<endl;
    //Print(m_mat, code.size, code.size);
}
void BasicQRTool::Print(int **array, int width, int height){
    cout<<"GenMatrix: \n";
    for(int w=0;w<width;w++)
    {
        for(int h=0;h<height;h++)
        {
            if(array[w][h]<0)
                cout<<array[w][h]<<" ";
            else
                cout<<array[w][h]<<"  ";
        }
        cout<<"\n";
    }
}
