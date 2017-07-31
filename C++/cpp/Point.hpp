//
//  Point.hpp
//  CreativeQRcode
//
//  Created by liming on 17/07/2017.
//  Copyright © 2017 liming. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

class PointS{
public:
    PointS();
    PointS(int x, int y);
    PointS(PointS * src);
    ~PointS();
    
public:
    void set(int x, int y);
    bool equals(int x, int y);
    bool operator == (const PointS &i);
    bool operator != (const PointS &i);
    int  getX();
    int  getY();
private:
     int x;
     int y;
    
};


#endif /* Point_hpp */
