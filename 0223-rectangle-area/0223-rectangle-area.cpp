class Solution {
public:
    int common(int a1 , int a2 , int b1 , int b2){
        if(a2 <= b1 || b2 <= a1) return 0;
        vector<int> v = {a1 , a2 , b1 , b2};
        sort(v.begin() , v.end());
        return v[2] - v[1];
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax1 - ax2) * (ay1 - ay2);
        int area2 = (bx1 - bx2) * (by1 - by2);
        int com = common(ax1 , ax2 , bx1 , bx2) * common(ay1 , ay2 , by1 , by2);
        // cout << area1 << " " << area2 << " " << com << endl;
        return area1 + area2 - com;
    }
};