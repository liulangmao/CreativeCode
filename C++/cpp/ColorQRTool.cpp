//
//  ColorQRTool.cpp
//  C++
//
//  Created by liming on 2017/8/14.
//

#include "ColorQRTool.hpp"

ColorQRTool::ColorQRTool(int size,int cellsize,ColorElementStyle style)
{
        this->size=size;
        m_mat= new int[size][];
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

Bitmap ColorQRTool::getResizedBitmap(Bitmap bm, int newWidth, int newHeight) {
        int width = bm.getWidth();
        int height = bm.getHeight();
        float scaleWidth = ((float) newWidth) / width;
        float scaleHeight = ((float) newHeight) / height;
        // CREATE A MATRIX FOR THE MANIPULATION
        Matrix matrix = new Matrix();
        // RESIZE THE BIT MAP
        matrix.postScale(scaleWidth, scaleHeight);
        
        // "RECREATE" THE NEW BITMAP
        Bitmap resizedBitmap = Bitmap.createBitmap(bm,0,0,width,height,matrix,false);
        //bm.recycle();
        return resizedBitmap;
    }
void ColorQRTool::GenColorQrCode(int margin)
    {
        int inputsize=cellsize*size+2*margin;
        this.setFinalImage(Bitmap.createBitmap(inputsize, inputsize, Bitmap.Config.ARGB_8888));
        System.out.println("size="+inputsize);
        int Height=inputsize;
        int Width=inputsize;
        Canvas cv = new Canvas(getFinalImage());
        Bitmap black= Bitmap.createBitmap(cellsize, cellsize, Bitmap.Config.ARGB_8888);
        Paint p=new Paint();
        for(int h=0;h<size;h++)
        {
            for(int w=0;w<size;w++)
            {
                if(m_mat[h][w]==1)
                {
                    if ((w <= size / 2) && (h <= size / 2)) {
                        p.setColor(style.getColor()[0]);//(0xFF0094FF);
                    } else if (w <= size / 2 && h >= size / 2) {
                        p.setColor(style.getColor()[1]);
                    } else if (w >= size / 2 && h >= size / 2) {
                        p.setColor(style.getColor()[2]);
                        
                    }else{
                        p.setColor(style.getColor()[3]);
                    }
                }
                else
                {
                    p.setColor(style.getColor()[4]);
                }
                cv.drawRect(h*cellsize+margin, w*cellsize+margin, (h+1)*cellsize+margin,(w+1)*cellsize+margin,p);
            }
        }
        //return  finalImage;
    }
void ColorQRTool::GenMinShengColorQrCode(int margin,Context mContext)
    {
        int inputsize=cellsize*size+2*margin;
        this.setFinalImage(Bitmap.createBitmap(inputsize, inputsize, Bitmap.Config.ARGB_8888));
        Bitmap mask= getDiskBitmap(mContext,"ms_logo");
        int Height=inputsize;
        int Width=inputsize;
        Canvas cv = new Canvas(getFinalImage());
        if(mask.getHeight()!=inputsize||mask.getWidth()!=inputsize){
            mask=getResizedBitmap(mask,size,size);
        }
        Paint p=new Paint();
        for(int h=0;h<size;h++)
        {
            for(int w=0;w<size;w++)
            {
                if(m_mat[h][w]==1)
                {
                    if(mask.getPixel(h,w)==Color.BLUE) {
                        p.setColor(style.getColor()[0]);
                    }
                    else if(mask.getPixel(h,w)==Color.RED) {
                        p.setColor(style.getColor()[1]);
                    }
                    else {
                        p.setColor(Color.BLACK);
                    }
                }
                else
                {
                    p.setColor(Color.WHITE);
                }
                cv.drawRect(h*cellsize+margin, w*cellsize+margin, (h+1)*cellsize+margin,(w+1)*cellsize+margin,p);
            }
        }
        
        
        //return  finalImage;
    }
Bitmap ColorQRTool::getDiskBitmap(Context mContext, String name)
    {
        Bitmap bitmap = BitmapFactory.decodeResource(mContext.getResources(), mContext
                                                     .getResources().getIdentifier(name, "drawable",
                                                                                   mContext.getPackageName()));
        
        if (bitmap == null) {
            Log.i("color", "Bitmap---3");
        }
        
        return bitmap;
        
    }
Bitmap ColorQRTool::oldgetDiskBitmap(String pathString)
    {
        Bitmap bitmap = null;
        try
        {
            File file = new File(pathString);
            if(file.exists())
            {
                bitmap = BitmapFactory.decodeFile(pathString);
            }else{
                System.out.println("aaaa");
            }
        } catch (Exception e)
        {
            // TODO: handle exception
        }
        
        
        return bitmap;
    }
    
void ColorQRTool::AddLogo(Context context)
    {
        int index=style.getLogoPathName().indexOf(".");
        String name=style.getLogoPathName().substring(0,index);
        Bitmap logoBmp= getDiskBitmap(context,name);
        if(logoBmp.getHeight()!=0&&logoBmp.getWidth()!=0) {
            int logoWidth = logoBmp.getWidth();
            int logoHeight = logoBmp.getHeight();
            float scaleFactor = getFinalImage().getWidth() * 1.0f / 5 / logoWidth;
            Canvas canvas = new Canvas(getFinalImage());
            canvas.drawBitmap(getFinalImage(), 0, 0, null);
            canvas.scale(scaleFactor, scaleFactor, getFinalImage().getWidth() / 2,
                         getFinalImage().getHeight() / 2);
            canvas.drawBitmap(logoBmp, (getFinalImage().getWidth() - logoWidth) / 2,
                              (getFinalImage().getHeight() - logoHeight) / 2, null);
            canvas.save(Canvas.ALL_SAVE_FLAG);
            canvas.restore();
            
        }
        //return finalImage;
    }
void ColorQRTool::AddBackground(Context context)
    {
        int index=style.getBackgroundPathName().indexOf(".");
        String name=style.getBackgroundPathName().substring(0,index);
        Bitmap background= getDiskBitmap(context,name);
        int bgWidth = background.getWidth();
        int bgHeight = background.getHeight();
        int fgWidth = getFinalImage().getWidth();
        int fgHeight = getFinalImage().getHeight();
        Bitmap newmap = Bitmap.createBitmap(bgWidth, bgHeight, Bitmap.Config.ARGB_8888);
        Canvas canvas = new Canvas(newmap);
        canvas.drawBitmap(background, 0, 0, null);
        canvas.drawBitmap(getFinalImage(), (bgWidth - fgWidth) / 2,
                          (bgHeight - fgHeight) *3 /5 +70, null);
        canvas.save(Canvas.ALL_SAVE_FLAG);
        canvas.restore();
        setFinalImage(newmap);
        //return newmap;
    }
    
void ColorQRTool::AddWatermark(Context context) {
        int index=style.getWaterPathName().indexOf(".");
        String name=style.getWaterPathName().substring(0,index);
        Bitmap markBMP= getDiskBitmap(context,name);
        // 创建一个新的和SRC长度宽度一样的位图
        Canvas cv = new Canvas(getFinalImage());
        // 在 0，0坐标开始画入原图
        // 在原图的右下角画入水印
        cv.drawBitmap(markBMP, getFinalImage().getWidth() - markBMP.getWidth()*4/5,
                      getFinalImage().getHeight()*2/7 , null);
        // 保存
        cv.save(Canvas.ALL_SAVE_FLAG);
        // 存储
        cv.restore();
    }
void ColorQRTool::clean()
    {
        this.m_mat = null;
    }
    
Bitmap ColorQRTool::getFinalImage() {
        return finalImage;
    }
    
void ColorQRTool::setFinalImage(Bitmap finalImage) {
        this.finalImage = finalImage;
    }
