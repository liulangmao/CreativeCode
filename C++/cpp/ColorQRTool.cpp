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
    this->mask=mask;
    this->masksize=masksize;
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
        if(masksize!=size){
            cout<<"masksize!=cellnumber or cellwidth"<<endl;
        }
      UInt32  redcolor=0xffff0000;
      UInt32  red=BGRAMake(A(redcolor),R(redcolor),G(redcolor),B(redcolor));
      UInt32  bluecolor=0xff0000ff;
      UInt32  blue=BGRAMake(A(bluecolor),R(bluecolor),G(bluecolor),B(bluecolor));
        for(int h=0;h<size;h++)
        {
            for(int w=0;w<size;w++)
            {
                if(m_mat[h][w]==1)
                {
                    for(int cellheight=0;cellheight<cellsize;cellheight++)
                    {
                        for(int cellwidth=0;cellwidth<cellsize;cellwidth++)
                        {
                            int position=(h*cellsize+margin)*Width+(w*cellsize+margin);
                            if(mask[position+cellheight*Width+cellwidth]==blue){
                                colorx=style->getColor()[0];
                                tempcolor=BGRAMake(A(colorx),R(colorx),G(colorx),B(colorx));
                                
                            }
                            else if(mask[position+cellheight*Width+cellwidth]==red){
                                colorx=style->getColor()[1];
                                tempcolor=BGRAMake(A(colorx),R(colorx),G(colorx),B(colorx));
                                                            }
                            else {
                                colorx=0xff000000;
                                tempcolor=BGRAMake(A(colorx),R(colorx),G(colorx),B(colorx));
                            }
                            finalImage[position+cellheight*Width+cellwidth]=tempcolor;
                        }
                    }
                }
                else
                {
                    colorx=0xffffffff;
                    tempcolor=BGRAMake(A(colorx),R(colorx),G(colorx),B(colorx));
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
