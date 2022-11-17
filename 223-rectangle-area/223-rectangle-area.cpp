class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int ovxr = min(ax2, bx2);
        int ovxl = max(ax1, bx1);
        int ovyr = min(ay2, by2);
        int ovyl = max(ay1, by1);
        
        if (ovxr > ovxl && ovyr > ovyl) {
            return (((ax2 - ax1) * (ay2 - ay1)) 
                    + ((bx2 - bx1) * (by2 - by1))
                    - ((ovxr - ovxl) * (ovyr - ovyl)));
            
        } else {
            return ((ax2 - ax1) * (ay2 - ay1)) + ((bx2 - bx1) * (by2 - by1));
        } 
    }
};