//
//  ColorQRTool.cpp
//  C++
//
//  Created by liming on 2017/8/14.
//

#include "ColorQRTool.hpp"

ColorQRTool::ColorQRTool(int size,int cellsize,ColorElementStyle* style)
{
        this->size=size;

        m_mat= new int*[size];
        for(int i=0;i<size;i++)
        {
            m_mat[i]=new int[size];
        }
        if(this->opendebug){
            Print(m_mat,size,size);
        }
        this->cellsize=cellsize;
        this->style=style;
}
int** ColorQRTool::getMat()
    {
        return m_mat;
    }
void ColorQRTool::Print(int** array,int width,int height)
    {
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

#define Mask8(x) ( (x) & 0xFF )
#define B(x) ( Mask8(x) )       //g
#define G(x) ( Mask8(x >> 8 ) )//r
#define R(x) ( Mask8(x >> 16) )//a
#define A(x) ( Mask8(x >> 24) )//b
#define BGRAMake(r, g, b, a) ( Mask8(r) | Mask8(g) << 8 | Mask8(b) << 16 | Mask8(a) << 24 )
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(x,y) ((x)<(y)?(x):(y))

void ColorQRTool::GenColorQrCode(int margin)
{
    int inputsize=cellsize*size+2*margin;
    int Height=inputsize;
    int Width=inputsize;
    finalImage = (UInt32 *)calloc(Height * Width, sizeof(UInt32));
    for(int width=0;width<Height * Width;width++)
    {
        finalImage[width]=0xffffffff;
    }
    UInt32 tempcolor=NULL;
    UInt32 colorx=NULL;
    for(int h=0;h<size;h++)
    {
        for(int w=0;w<size;w++)
        {
            if(m_mat[h][w]==1)
            {
                if ((w <= size / 2) && (h <= size / 2)) {
                    colorx=style->getColor()[0];
                    tempcolor=BGRAMake(A(colorx),R(colorx),G(colorx),B(colorx));
                } else if (w <= size / 2 && h >= size / 2) {
                    colorx=style->getColor()[1];
                    tempcolor=BGRAMake(A(colorx),R(colorx),G(colorx),B(colorx));
                } else if (w >= size / 2 && h >= size / 2) {
                    colorx=style->getColor()[2];
                    tempcolor=BGRAMake(A(colorx),R(colorx),G(colorx),B(colorx));
                    
                }else{
                    colorx=style->getColor()[3];
                    tempcolor=BGRAMake(A(colorx),R(colorx),G(colorx),B(colorx));
                }
                
            }else{
                colorx=style->getColor()[4];
                tempcolor=BGRAMake(A(colorx),R(colorx),G(colorx),B(colorx));
            }
            for(int cellheight=0;cellheight<cellsize;cellheight++)
            {
                for(int cellwidth=0;cellwidth<cellsize;cellwidth++)
                {
                    int position=(h*cellsize+margin)*Width+(w*cellsize+margin);
                    finalImage[position+cellheight*Width+cellwidth]=tempcolor;
                }
            }
        }
    }
}

void ColorQRTool::SetMask(UInt32* mask,int masksize){
    mask=mask;
    masksize=masksize;
}
void ColorQRTool::GenMinShengColorQrCode(int margin)
    {
        int inputsize=cellsize*size+2*margin;
        int Height=inputsize;
        int Width=inputsize;
        finalImage = (UInt32 *)calloc(Height * Width, sizeof(UInt32));
        for(int width=0;width<Height * Width;width++)
        {
            finalImage[width]=0xffffffff;
        }
        UInt32 tempcolor=NULL;
        UInt32 colorx=NULL;
        if(masksize!=cellsize){
            cout<<"error!"<<endl;
        }
       
        for(int h=0;h<size;h++)
        {
            for(int w=0;w<size;w++)
            {
                if(m_mat[h][w]==1)
                {
                    if(mask[h*size+w]==0xff0000ff) {
                        colorx=style->getColor()[0];
                        tempcolor=BGRAMake(A(colorx),R(colorx),G(colorx),B(colorx));
                    }
                    else if(mask[h*size+w]==0xffff0000) {
                        colorx=style->getColor()[1];
                        tempcolor=BGRAMake(A(colorx),R(colorx),G(colorx),B(colorx));
                    }
                    else {
                        colorx=0xff000000;
                        tempcolor=BGRAMake(A(colorx),R(colorx),G(colorx),B(colorx));
                    }
                }
                else
                {
                    colorx=0xffffffff;
                    tempcolor=BGRAMake(A(colorx),R(colorx),G(colorx),B(colorx));
                }
                for(int cellheight=0;cellheight<cellsize;cellheight++)
                {
                    for(int cellwidth=0;cellwidth<cellsize;cellwidth++)
                    {
                        int position=(h*cellsize+margin)*Width+(w*cellsize+margin);
                        finalImage[position+cellheight*Width+cellwidth]=tempcolor;
                    }
                }
            }
        }
    }
void ColorQRTool::AddLogo()
    {
//        int index=style.getLogoPathName().indexOf(".");
//        String name=style.getLogoPathName().substring(0,index);
//        Bitmap logoBmp= getDiskBitmap(context,name);
       // int inputsize=cellsize*size+2*margin;
        //this->setFinalImage(Bitmap.createBitmap(inputsize, inputsize, Bitmap.Config.ARGB_8888));
       // int Height=inputsize;
       // int Width=inputsize;
//        Canvas cv = new Canvas(getFinalImage());
//        Bitmap black= Bitmap.createBitmap(cellsize, cellsize, Bitmap.Config.ARGB_8888);
//        Paint p=new Paint();
//        for(int h=0;h<size;h++)
//        {
//            for(int w=0;w<size;w++)
//            {
//                if(m_mat[h][w]==1)
//                {
//                    if ((w <= size / 2) && (h <= size / 2)) {
//                        p.setColor(style.getColor()[0]);//(0xFF0094FF);
//                    } else if (w <= size / 2 && h >= size / 2) {
//                        p.setColor(style.getColor()[1]);
//                    } else if (w >= size / 2 && h >= size / 2) {
//                        p.setColor(style.getColor()[2]);
//                        
//                    }else{
//                        p.setColor(style.getColor()[3]);
//                    }
//                }
//                else
//                {
//                    p.setColor(style.getColor()[4]);
//                }
//                cv.drawRect(h*cellsize+margin, w*cellsize+margin, (h+1)*cellsize+margin,(w+1)*cellsize+margin,p);
//            }
//        }
//        
    }
void ColorQRTool::AddBackground()
    {
//        int index=style.getBackgroundPathName().indexOf(".");
//        String name=style.getBackgroundPathName().substring(0,index);
//        }
    }

void ColorQRTool::AddWatermark() {
   // int index=(int)style.getWaterPathName().find(".");
   // string name=style.getWaterPathName().substr(0,index);

//        Bitmap markBMP= getDiskBitmap(context,name);
//        // 创建一个新的和SRC长度宽度一样的位图
//        Canvas cv = new Canvas(getFinalImage());
//        // 在 0，0坐标开始画入原图
//        // 在原图的右下角画入水印
//        cv.drawBitmap(markBMP, getFinalImage().getWidth() - markBMP.getWidth()*4/5,
//                      getFinalImage().getHeight()*2/7 , null);
//        // 保存
//        cv.save(Canvas.ALL_SAVE_FLAG);
//        // 存储
//        cv.restore();
    }
void ColorQRTool::clean()
    {
        this->m_mat = NULL;
    }
    
UInt32* ColorQRTool::getFinalImage() {
        return finalImage;
    }
    
void ColorQRTool::setFinalImage(UInt32* finalImage) {
        this->finalImage = finalImage;
    }
#undef RGBAMake
#undef R
#undef G
#undef B
#undef A
#undef Mask8
#undef MIN
#undef MAX
