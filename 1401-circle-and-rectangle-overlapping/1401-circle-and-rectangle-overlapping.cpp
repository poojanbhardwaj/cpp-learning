class Solution {
public:
    double calcdist(int x1,int y1,int x2,int y2){
        return pow((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2),0.5);
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(y2 <= yCenter + radius && y2>= yCenter - radius && x2<= xCenter + radius && x2>=xCenter - radius ) return true;  
        
        if(y1 <= yCenter + radius && y1>= yCenter - radius && x1<= xCenter + radius && x1>=xCenter - radius ) return true;   
        if(calcdist(x1,yCenter,xCenter,yCenter) <= (double)radius && yCenter>=y1 && yCenter<=y2) return true;
        if(calcdist(xCenter,y1,xCenter,yCenter) <= (double)radius && xCenter>=x1 && xCenter<=x2) return true;
        if(calcdist(xCenter,y2,xCenter,yCenter) <= (double)radius  && xCenter>=x1 && xCenter<=x2) return true;
        
        if(calcdist(x2,yCenter,xCenter,yCenter) <= (double)radius && yCenter>=y1 && yCenter<=y2) return true;
        if(xCenter+radius <= x2 && yCenter + radius <= y2 && xCenter - radius >= x1 && yCenter - radius >= y1) return true;
        
        return false;    }
};