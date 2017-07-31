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
        }
        if(openDebug){
            Print(m_mat,size,size);
        }
        this->cellSize=cellsize;
}

void CreativeQRTool::fillEye(){
    int startX=0;
    int StartY=0;
    
    CreativeEnv::addEye();
    
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
    
    CreativeElement *ThreeByOne = new CreativeElement(-5, 3, 1);
    CreativeEnv::addElement(ThreeByOne);
    
    CreativeElement *TwoByTwo = new CreativeElement(-2, 2, 2);
    CreativeEnv::addElement(TwoByTwo);
    
    CreativeElement *TwoByOne = new CreativeElement(-3, 2, 1);
    CreativeEnv::addElement(TwoByOne);
    
    CreativeElement *OneByOne = new CreativeElement(-6, 1, 1);
    CreativeEnv::addElement(OneByOne);
    
    it=CreativeEnv::elementList.begin();it++;
    for (;it!=CreativeEnv::elementList.end();it++)
    {
        if(openDebug) {
            cout<<endl<<"Before Remove List:"<<(int)m_list.size()<<"="<<(**it).getValue()<<endl;
        }
        fillAnyType(**it);
        if(openDebug) {
            cout<<"After Remove List:"<<(int)m_list.size()<<endl;
            
        }
        if(openDebugDetail)
        {
            Print(m_mat,size,size);
        }
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

CGImageRef* CreativeQRTool::CreateFinal(int size,int margin){
    CGImageRef*  ac;
    return ac;
}


CGImageRef* CreativeQRTool::getResizedBitmap(CGImageRef* bm, int newWidth, int newHeight){
    CGImageRef*  ad;
    return ad;
}

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

CGImageRef* CreativeQRTool::getDiskBitmap(string name){
    CGImageRef*  a;
    return a;
}



void CreativeQRTool::LoadPreImage(string* namelist){
    
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


