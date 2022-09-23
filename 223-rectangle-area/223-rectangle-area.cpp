class Solution {
public:
    
    int solve(int a1 , int a2 , int b1 , int b2){
        int l = max(a1 , b1);
        int r = min(a2 , b2);
        
        if(r - l > 0) return r - l;
        return 0;
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int l = solve(ax1 , ax2 , bx1 , bx2);
        int b = solve(ay1 , ay2 , by1 , by2);
        
        long ans = 0;
        ans += (long)(abs(ax1 - ax2)) * abs(ay1 - ay2);
        ans += (long)(abs(bx1 - bx2)) * abs(by1 - by2);
        ans -= (long)l * b;
        // cout << l << " " << b << endl;
        return ans;
    }
};