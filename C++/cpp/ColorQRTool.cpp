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
<<<<<<< HEAD
        m_mat = new int* [size];
        for(int i = 0; i < size; i++)
            m_mat[i] = new int [size];

=======
        m_mat= new int*[size];
        for(int i=0;i<size;i++)
        {
            m_mat[i]=new int[size];
        }
>>>>>>> origin/master
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
<<<<<<< HEAD
#define Mask8(x) ( (x) & 0xFF )
#define B(x) ( Mask8(x) )       //g
#define G(x) ( Mask8(x >> 8 ) )//r
#define R(x) ( Mask8(x >> 16) )//a
#define A(x) ( Mask8(x >> 24) )//b
#define BGRAMake(r, g, b, a) ( Mask8(r) | Mask8(g) << 8 | Mask8(b) << 16 | Mask8(a) << 24 )
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(x,y) ((x)<(y)?(x):(y))
=======


>>>>>>> origin/master
void ColorQRTool::GenColorQrCode(int margin)
{
   
//    cout<<"size="<<inputsize<<"cellsize="<<cellsize<<"margin="<<margin<<endl;
//    cout<<"matsize="<<size<<endl;
    int inputsize=cellsize*size+2*margin;
    int Height=inputsize;
    int Width=inputsize;
    finalImage = (UInt32 *)calloc(Height * Width, sizeof(UInt32));
    for(int width=0;width<Height * Width;width++)
    {
<<<<<<< HEAD
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
=======
        int inputsize=cellsize*size+2*margin;
        //this->setFinalImage(Bitmap.createBitmap(inputsize, inputsize, Bitmap.Config.ARGB_8888));
        int Height=inputsize;
        int Width=inputsize;
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
void ColorQRTool::GenMinShengColorQrCode(int margin)
    {
        int inputsize=cellsize*size+2*margin;
       // this->setFinalImage(Bitmap.createBitmap(inputsize, inputsize, Bitmap.Config.ARGB_8888));
        //Bitmap mask= getDiskBitmap(mContext,"ms_logo");
        int Height=inputsize;
        int Width=inputsize;
//        Canvas cv = new Canvas(getFinalImage());
//        if(mask.getHeight()!=inputsize||mask.getWidth()!=inputsize){
//            mask=getResizedBitmap(mask,size,size);
//        }
//        Paint p=new Paint();
//        for(int h=0;h<size;h++)
//        {
//            for(int w=0;w<size;w++)
//            {
//                if(m_mat[h][w]==1)
//                {
//                    if(mask.getPixel(h,w)==Color.BLUE) {
//                        p.setColor(style.getColor()[0]);
//                    }
//                    else if(mask.getPixel(h,w)==Color.RED) {
//                        p.setColor(style.getColor()[1]);
//                    }
//                    else {
//                        p.setColor(Color.BLACK);
//                    }
//                }
//                else
//                {
//                    p.setColor(Color.WHITE);
//                }
//                cv.drawRect(h*cellsize+margin, w*cellsize+margin, (h+1)*cellsize+margin,(w+1)*cellsize+margin,p);
//            }
//        }
    }

void ColorQRTool::AddLogo()
    {
        int index=(int)style.getLogoPathName().find(".");
        string name=style.getLogoPathName().substr(0,index);
        //Bitmap logoBmp= getDiskBitmap(context,name);
>>>>>>> origin/master
//        if(logoBmp.getHeight()!=0&&logoBmp.getWidth()!=0) {
//            int logoWidth = logoBmp.getWidth();
//            int logoHeight = logoBmp.getHeight();
//            float scaleFactor = getFinalImage().getWidth() * 1.0f / 5 / logoWidth;
//            Canvas canvas = new Canvas(getFinalImage());
//            canvas.drawBitmap(getFinalImage(), 0, 0, null);
//            canvas.scale(scaleFactor, scaleFactor, getFinalImage().getWidth() / 2,
//                         getFinalImage().getHeight() / 2);
//            canvas.drawBitmap(logoBmp, (getFinalImage().getWidth() - logoWidth) / 2,
//                              (getFinalImage().getHeight() - logoHeight) / 2, null);
//            canvas.save(Canvas.ALL_SAVE_FLAG);
//            canvas.restore();
<<<<<<< HEAD
//            
//        }
        //return finalImage;
    }
void ColorQRTool::AddBackground()
    {
//        int index=style.getBackgroundPathName().indexOf(".");
//        String name=style.getBackgroundPathName().substring(0,index);
=======
//        }
    }
void ColorQRTool::AddBackground()
    {
        int index=(int)style.getBackgroundPathName().find(".");
        string name=style.getBackgroundPathName().substr(0,index);

>>>>>>> origin/master
//        Bitmap background= getDiskBitmap(context,name);
//        int bgWidth = background.getWidth();
//        int bgHeight = background.getHeight();
//        int fgWidth = getFinalImage().getWidth();
//        int fgHeight = getFinalImage().getHeight();
//        Bitmap newmap = Bitmap.createBitmap(bgWidth, bgHeight, Bitmap.Config.ARGB_8888);
//        Canvas canvas = new Canvas(newmap);
//        canvas.drawBitmap(background, 0, 0, null);
//        canvas.drawBitmap(getFinalImage(), (bgWidth - fgWidth) / 2,
//                          (bgHeight - fgHeight) *3 /5 +70, null);
//        canvas.save(Canvas.ALL_SAVE_FLAG);
//        canvas.restore();
<<<<<<< HEAD
//        setFinalImage(newmap);
//        //return newmap;
    }
    
void ColorQRTool::AddWatermark() {
//        int index=style.getWaterPathName().indexOf(".");
//        String name=style.getWaterPathName().substring(0,index);
=======
        //setFinalImage(newmap);
}
    
void ColorQRTool::AddWatermark() {
    int index=(int)style.getWaterPathName().find(".");
    string name=style.getWaterPathName().substr(0,index);

>>>>>>> origin/master
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
