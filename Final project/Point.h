#ifndef __POINT_H__
#define __POINT_H__
class Point {
    private:
        int x, y;
    public:
    	Point();
        Point(int i, int j); // x = i; y = j;
        int GetX();
        int GetY();
        void SetX(int i);
        void SetY(int j);
        void SetPoint(int i, int j); // x = i; y = j;
};

#endif

