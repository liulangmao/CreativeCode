//
//  CreativeQRTool.cpp
//  CreativeQRcode
//
//  Created by liming on 17/07/2017.
//  Copyright © 2017 liming. All rights reserved.
//

#include "CreativeQRTool.hpp"


CreativeQRTool::CreativeQRTool(int size,int cellsize){
        this->size=size;
        m_mat= new int*[size];
    
        for(int i=0;i<size;i++)
        {
            m_mat[i]=new int[size];
            for(int j=0;j<size;j++)
            {
                m_mat[i][j]=0;
            }
        }
        if(openDebug){
            cout<<"CreativeQRTool"<<" size="<<size<<"cellsize"<<cellsize<<endl;
            Print(m_mat,size,size);
        }
        this->cellSize=cellsize;
}

void CreativeQRTool::fillEye(){
    int startX=0;
    int StartY=0;
    
    //CreativeEnv::addEye();
    
    CreativeElement type=CreativeEnv::getEye();
    this->fillType(startX,StartY,type);
    PointS p_orig = new PointS(StartY,startX);
    type.getM_start()->push_back(p_orig);
    
    this->fillType(startX,size-(int)type.getColspan(),type);
    PointS p_right = new PointS(size-(int)type.getColspan(),startX);
    type.getM_start()->push_back(p_right);
    
    
    this->fillType(size-(int)type.getRowspan(),StartY,type);
    PointS p_left = new PointS(StartY,size-(int)type.getRowspan());
    type.getM_start()->push_back(p_left);
}

void CreativeQRTool::FindCellEqualsOne(){
    
    for(int h=0;h<size;h++)
    {
        for(int w=0;w<size;w++)
        {
            if(m_mat[h][w]==1)
            {
                m_list.push_back(* new PointS(w,h));
            }
        }
    }
    if(openDebug)
    {
        cout<<"FindCellEqualsOne()"<<endl;
        Print(m_mat,size,size);
        vector<PointS>::iterator it;
        it = m_list.begin();
        int previousY=0;
        for(it=m_list.begin();it!=m_list.end();it++)
        {
            int x=(*it).getX();
            int y=(*it).getY();
            if(previousY==y){
                 cout<<"x="<<x<<"y="<<y<<"   ";
            }
            else{
                 cout<<endl<<"x="<<x<<"y="<<y<<"   ";
                previousY=y;
            }
           
        }
    }
}
void CreativeQRTool::FillbyType(){
    list<CreativeElement*>::iterator it;
    /*
     just for testing:
    */
//    CreativeElement *FourByTwo = new CreativeElement(-4,4,2);
//    CreativeEnv::addElement(FourByTwo);
    
//    CreativeElement *ThreeByOne = new CreativeElement(-5, 3, 1);
//    CreativeEnv::addElement(ThreeByOne);
//    
//    CreativeElement *TwoByTwo = new CreativeElement(-2, 2, 2);
//    CreativeEnv::addElement(TwoByTwo);
//    
//    CreativeElement *TwoByOne = new CreativeElement(-3, 2, 1);
//    CreativeEnv::addElement(TwoByOne);
    
//    CreativeElement *OneByOne = new CreativeElement(-6, 1, 1);
//    CreativeEnv::addElement(OneByOne);
    
    int index=0;
    cout<<endl;
    cout<<"method begin:"<<"listnumber: "<<CreativeEnv::getlistSize()<<endl;
    it=CreativeEnv::elementList.begin();it++;
    for (;it!=CreativeEnv::elementList.end();it++)
    {
        if(openDebug) {
            
            cout<<endl<<"Before Remove List["<<index<<"]:"<<(int)m_list.size()<<"type="<<(**it).getValue()<<endl;
        }
        fillAnyType(**it);
        if(openDebug) {
            cout<<"After Remove List:"<<(int)m_list.size()<<endl;
            
        }
        if(openDebugDetail)
        {
            Print(m_mat,size,size);
        }
        index++;
    }
    if(openDebug)
    {
        Print(m_mat,size,size);
        cout<<"fillType()"<<endl;
        cout<<"m_list info:"<<endl;
        vector<PointS>::iterator it;
        it = m_list.begin();
        int previousY=0;
        for(it=m_list.begin();it!=m_list.end();it++)
        {
            int x=(*it).getX();
            int y=(*it).getY();
            if(previousY==y){
                cout<<"x="<<x<<"y="<<y<<"   ";
            }
            else{
                cout<<endl<<"x="<<x<<"y="<<y<<"   ";
                previousY=y;
            }
            
        }
        
        list<CreativeElement*>::iterator itt;
        itt=CreativeEnv::elementList.begin();itt++;
        for (;itt!=CreativeEnv::elementList.end();itt++)
        {
            cout<<"TypeName"<<(*itt)->getValue()<<endl;
            it=((*itt)->getM_start())->begin();
            for(;it!=((*itt)->getM_start())->end();it++){
                cout<<(*it).getX()<<","<<(*it).getY()<<" ";
            }
            cout<<endl;
        }

       
    }
}

UInt32 * CreativeQRTool::CreateFinal(int size,int margin){
    if(openDebug){
        cout<<"CreateFinal():"<<endl;
    }
    UInt32* finalMat = (UInt32 *)calloc(size * size, sizeof(UInt32));

    for(int width=0;width<size * size;width++)
    {
        finalMat[width]=0xffffffff;
    }
    list<CreativeElement*>::iterator it;
    vector<PointS>::iterator itPointBegin;
    vector<PointS>::iterator itPointEnd;
    vector<PointS>::iterator itPoint;
    int index=0;
    for (it=CreativeEnv::elementList.begin();it!=CreativeEnv::elementList.end();it++)
    {
        CreativeElement *temp=(*it);
        cout<<"in for loop["<<index<<"]:value="<<temp->getValue()<<"size="<<temp->getColspan()<<endl;
        index++;
        if(temp->getPreImage()->size()!=0) {
            Cell* r = *(temp->getPreImage()->begin());
            cout<<"Cell"<<"height="<<r->getHeigh()<<"width="<<r->getWidth()<<endl;
            itPointBegin=temp->getM_start()->begin();
            itPointEnd=((temp)->getM_start())->end();
            for(itPoint=itPointBegin;itPoint!=itPointEnd;itPoint++){
                int x=(*itPoint).getX();
                int y=(*itPoint).getY();
                
                Draw(x,y,r,finalMat,margin,size);
            }
        }
    }
    return finalMat;
}

#define Mask8(x) ( (x) & 0xFF )
#define R(x) ( Mask8(x) )
#define G(x) ( Mask8(x >> 8 ) )
#define B(x) ( Mask8(x >> 16) )
#define A(x) ( Mask8(x >> 24) )
#define RGBAMake(r, g, b, a) ( Mask8(r) | Mask8(g) << 8 | Mask8(b) << 16 | Mask8(a) << 24 )
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(x,y) ((x)<(y)?(x):(y))
void CreativeQRTool::Draw(int originWidth, int originHeight,Cell* cell,UInt32* finalMat,int margin,int finalSize){
    int error=0;
    int offsetPixelCountForInput = (originHeight * finalSize + originWidth)*this->cellSize+margin;
    for (int j = 0; j < cell->getWidth(); j++) {
        for (int i = 0; i < cell->getHeigh(); i++) {
            
            UInt32 * inputPixel = finalMat + j * finalSize + i + offsetPixelCountForInput;
            UInt32 * ghostPixel = cell->getPreImage() + j * cell->getWidth() + i;
            UInt32   ghostColor = *ghostPixel;
            
            UInt32 newR = R(ghostColor) ;
            UInt32 newG = G(ghostColor) ;
            UInt32 newB = B(ghostColor) ;
            UInt32 newA = A(ghostColor) ;

            newR = MAX(0,MIN(255, newR));
            newG = MAX(0,MIN(255, newG));
            newB = MAX(0,MIN(255, newB));
            newA =MAX(0,MIN(255, newA));
            *inputPixel = RGBAMake(255,newG, newB, newA);
        }
    }
    if(error==0){
    UInt32 ghostColor = *(cell->getPreImage()+30*7 * cellSize+55);
    UInt32 newR = R(ghostColor) ;
    UInt32 newG = G(ghostColor) ;
    UInt32 newB = B(ghostColor) ;
    cout<<"("<<55<<","<<30<<")="<<(int)newR<<" "<<(int)newG<<" "<<(int)newB<<endl;
        error=1;
    }
}

#undef RGBAMake
#undef R
#undef G
#undef B
#undef A
#undef Mask8
#undef MIN
#undef MAX
void CreativeQRTool::clean(){
    
}






int** CreativeQRTool::getMat(){
    
    return m_mat;
}
void CreativeQRTool::Print(int** array,int width,int height){
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

void CreativeQRTool::fillType(int row,int col,CreativeElement type){
    PointS temp;
    if(openDebugDetail){
        printf("fillType-typename:%d",type.getValue());
        cout<<endl;
    }
    for(int h=0;h<(int)type.getRowspan();h++)
    {
        for(int w=0;w<(int)type.getColspan();w++)
        {
            m_mat[h+row][w+col]=type.getValue();
            if(openDebugDetail&&!type.equals(CreativeEnv::getEye()))
            {
                cout<<"["<<(h+row)<<","<<(w+col)<<"]"<<m_mat[h+row][w+col]<<endl;
            }
            vector<PointS>::iterator it=find(m_list.begin(), m_list.end(), PointS(w+col,h+row));
            if(it!=m_list.end()&&(!type.equals(CreativeEnv::getEye())))
            {
                m_list.erase(it);
                if(openDebugDetail){
                    cout<<"type"<<(int)type.getValue()<<","<<"["<<(h+row)<<","<<(w+col)<<"]"<<endl;
                }
                
            }
        }
    }
}



void CreativeQRTool::fillAnyType(CreativeElement type){
    vector<PointS>::iterator it;
    it = m_list.begin();
    cout<<"fillAnyType():"<<endl;
    for(int i=0;i<m_list.size();)
    {
        PointS p = m_list[i];
        bool result=test(p.getY(),p.getX(),type);
        if(result)
        {
            fillType(p.getY(),p.getX(),type);
            type.getM_start()->push_back(p);
        }
        else{
            i++;
        }
    }
}

string CreativeQRTool::Int_to_String(int n)
{
    ostringstream stream;
    stream<<n;  //n为int类型
    return stream.str();
}
bool CreativeQRTool::test(int row,int col,CreativeElement type){
    string temp;
    for(int h=0;h<(int)type.getRowspan();h++)
    {
        for(int w=0;w<(int)type.getColspan();w++)
        {
            if(h+row<this->size&&w+col<this->size){
                temp.append(Int_to_String(m_mat[h+row][w+col])+"");
            }
        }
        temp=temp+"0";
    }
    if(temp.compare(type.getStr())==0)
    {
        if(openDebugDetail)
        {
            cout<<"Compare:["<<row<<","<<col<<"]:"<<temp.c_str()<<"=="<<type.getStr().c_str()<<endl;
        }
        return true;
    }
    else{
        if(openDebugDetail)
        {
            cout<<"Compare:["<<row<<","<<col<<"]:"<<temp.c_str()<<"!="<<type.getStr().c_str()<<endl;
        }
        return false;
    }
}


