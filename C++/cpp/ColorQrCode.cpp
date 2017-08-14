//
//  ColorQrCode.cpp
//  C++
//
//  Created by liming on 2017/8/14.

//

#include "ColorQrCode.hpp"

static final ColorQrCode::ColorElementStyle QQstyle = new ColorElementStyle(
                                                                          new int[]{0xFF0094FF,0xFFFED545,0xFF5ACF00,0xFF000000,0xffffffff},
                                                                          "color_bak.bmp",
                                                                          "color_logo1.png",
                                                                          "color_water.png");
ColorQrCode::ColorQrCode(ColorElementStyle style)
{
        this->style=style;
}
ColorQrCode::ColorQrCode()
{
        
}
int ColorQrCode::ComputCellNumberByVersion(int version)
{
        int cellNumber = 21 + (version-1) * 4;
        return cellNumber;
}
    
    
CGImageRef ColorQrCode::ColorQRSweatake(string txt, int margin, int version) {
        
        int cellNumber = ComputCellNumberByVersion(version);
        int cellSize = 12;
        /*
         1.CreativeQRTool must be created before GenMatrix
         */
        ColorQRTool h = new ColorQRTool(cellNumber, cellSize,style);
        //h.collectPixelCountBitmap(h.m_mat, WBImage, cellSize, cellSize);
        BasicQRTool basic= new BasicQRTool(version,txt);
        /*
         2. be careful about below line because in the method of GenMatrix will fill in h.m_mat
         */
        basic.GenMatrix(h.getMat());
        h.GenColorQrCode(margin);
        if(style.getLogoPathName()!=""){
            h.AddLogo(context);
        }
        if(style.getBackgroundPathName()!=""){
            h.AddBackground(context);
        }
        if(style.getWaterPathName()!=""){
            h.AddWatermark(context);
        }
        
        Bitmap finalImage=h.getFinalImage();
        h.clean();
        if (finalImage == null) {
            Log.i("cmbc", "====8");
        }
        Log.i("cmbc", "====");
        return finalImage;
        
}
CGImageRef ColorQrCode::ColorQRMinSheng(String txt, int margin, int version, Context context ) {
        
        int cellNumber = ComputCellNumberByVersion(version);
        int cellSize = 10;
        /*
         1.CreativeQRTool must be created before GenMatrix
         */
        ColorQRTool h = new ColorQRTool(cellNumber, cellSize,style);
        //h.collectPixelCountBitmap(h.m_mat, WBImage, cellSize, cellSize);
        BasicQRTool basic= new BasicQRTool(version,txt);
        /*
         2. be careful about below line because in the method of GenMatrix will fill in h.m_mat
         */
        basic.GenMatrix(h.getMat());
        h.GenMinShengColorQrCode(margin,context);
        
        Bitmap finalImage=h.getFinalImage();
        h.clean();
        if (finalImage == null) {
            Log.i("cmbc", "====8");
        }
        Log.i("cmbc", "====");
        return finalImage;
        
    }
