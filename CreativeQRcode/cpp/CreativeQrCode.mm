//
//  CreativeQrCode.cpp
//  CreativeQRcode
//
//  Created by liming on 2017/7/25.
//  Copyright © 2017年 liming. All rights reserved.
//

#include "CreativeQrCode.hpp"
//CreativeQrCode::CreativeQrCode(CreativeElementStyle style){
//    this->setStyle(style);
//}
//
//
//// Bitmap getDiskBitmap(Context mContext, string name);
//// Bitmap getResizedBitmap(Bitmap bm, int newWidth, int newHeight);
//void CreativeQrCode::AnalysisStyle(int cellSize){
//    string name="";
//    string* namelist=style.getNamelist();
//    cout<<"AnalysisStyle====namelist"<<namelist->size();
//    for ( int n=0;n<namelist->size();n++) {
//        name=namelist[n];
//        if(name.contains("_")&&name.contains("bmp"))
//        {
//            int index=name.indexOf("_");
//            int index_bmp=name.indexOf(".");
//            String nameread=name.substring(0,index_bmp);
//            String nameswitch=name.substring(index+1, index+1+3);
//            Bitmap image = getDiskBitmap(mContext,nameread);
//            boolean resize=true;
//            Bitmap resizeimage;
//            switch(nameswitch)
//            {
//                case "4_2": {
//                    CreativeElement FourByTwo = new CreativeElement(-4,4,2);
//                    if(resize) {
//                        resizeimage = getResizedBitmap(image, 2 * cellSize, 4 * cellSize);
//                        FourByTwo.getPreImage().add(resizeimage);
//                    }
//                    else{
//                        FourByTwo.getPreImage().add(image);
//                    }
//                    CreativeEnv.addElement(FourByTwo);
//                    System.out.println("AnalysisStyle====case 4_2");
//                }
//                    break;
//                case "7_7": {
//                    
//                    if(resize) {
//                        resizeimage = getResizedBitmap(image, 7 * cellSize, 7 * cellSize);
//                        CreativeEnv.getEye().getPreImage().add(resizeimage);
//                    }
//                    else{
//                        CreativeEnv.getEye().getPreImage().add(image);
//                    }
//                    System.out.println("AnalysisStyle====case 7_7");
//                }
//                    break;
//                case "3_1": {
//                    CreativeElement ThreeByOne = new CreativeElement(-5, 3, 1);
//                    if(resize) {
//                        resizeimage = getResizedBitmap(image,  cellSize, 3 * cellSize);
//                        ThreeByOne.getPreImage().add(resizeimage);
//                    }
//                    else{
//                        ThreeByOne.getPreImage().add(image);
//                    }
//                    CreativeEnv.addElement(ThreeByOne);
//                    System.out.println("AnalysisStyle====case 3_1");
//                }
//                    break;
//                    
//                case "2_2": {
//                    CreativeElement TwoByTwo = new CreativeElement(-2, 2, 2);
//                    if(resize) {
//                        resizeimage = getResizedBitmap(image, 2 * cellSize, 2 * cellSize);
//                        TwoByTwo.getPreImage().add(resizeimage);
//                    }
//                    else{
//                        TwoByTwo.getPreImage().add(image);
//                    }
//                    CreativeEnv.addElement(TwoByTwo);
//                    System.out.println("AnalysisStyle====case 2_2");
//                }
//                    break;
//                case "2_1":{
//                    CreativeElement TwoByOne = new CreativeElement(-3, 2, 1);
//                    if(resize) {
//                        resizeimage = getResizedBitmap(image,  cellSize, 2 * cellSize);
//                        TwoByOne.getPreImage().add(resizeimage);
//                    }
//                    else{
//                        TwoByOne.getPreImage().add(image);
//                    }
//                    CreativeEnv.addElement(TwoByOne);
//                    System.out.println("AnalysisStyle====case 2_1");
//                }
//                    break;
//                case "1_1":{
//                    CreativeElement OneByOne = new CreativeElement(-6, 1, 1);
//                    if(resize) {
//                        resizeimage = getResizedBitmap(image, cellSize,  cellSize);
//                        OneByOne.getPreImage().add(resizeimage);
//                    }
//                    else{
//                        OneByOne.getPreImage().add(image);
//                    }
//                    CreativeEnv.addElement(OneByOne);
//                    System.out.println("AnalysisStyle====case 1_1");
//                }
//                    break;
//                default:
//                    System.out.println("error!");
//                    break;
//            }
//        }
//    }
//}
int CreativeQrCode::ComputCellNumberByVersion(int version){
    int cellNumber = 21 + (version-1) * 4;
    return cellNumber;
}
//Bitmap CreativeQRZXing(string txt,int size,int margin,Context mContext);
CreativeElementStyle getStyle();
void setStyle(CreativeElementStyle style);
string getLogoPath();
void setLogoPath(string logoBmp);
