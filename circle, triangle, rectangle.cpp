//
//  main.cpp
//  dailyPractice2forC++
//
//  Created by Jay on 03/02/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

#include <iostream>
using namespace std;

#define PI 3.14159

typedef struct coordinate {
    float x;
    float y;
    coordinate() { x = y = 0; }
    coordinate(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
}coordinate;

class Circle
{
public:
    Circle(int radius, int x, int y)
    {
        setRadius(radius);
        this->center.x = x;
        this->center.y = y;
    }
    Circle(int radius, coordinate pos)
    {
        setRadius(radius);
        this->center = pos;
    }
    ~Circle() {}
    
    
private:
    double area;
    int radius;
    coordinate center;
    
    void setCenterPos(int x, int y)
    {
        this->center.x = x;
        this->center.y = y;
    }
    void setCenterPos(coordinate pos)
    {
        setCenterPos(pos.x, pos.y);
    }
    void calcArea(void)
    {
        area = PI * radius * radius;
    }
    
    
public:
    int getRadius()
    {
        return radius;
    }
    void setRadius(int radius)
    {
        if (radius <= 0)
            radius = 1;
        if (radius > 100)
            radius = 100;
        
        this->radius = radius;
    }
    double getArea()
    {
        calcArea();
        return area;
    }
    
    
    void Move(int x, int y)
    {
        setCenterPos(this->center.x + x, this->center.y + y);
    }
    
    void Move(coordinate pos)
    {
        setCenterPos(this->center.x + pos.x, this->center.y + pos.y);
    }
    
    void MoveTo(int x, int y)
    {
        setCenterPos(x, y);
    }
    
    void MoveTo(coordinate pos)
    {
        setCenterPos(pos);
    }
};






class Triangle
{
private:
    coordinate point[3];
    double area;
    
    void setPointPri(int n, int x, int y)
    {
        printf("점들의 번호는 0~2번. \n");
        if (n > 2)
        {
            printf("Out of range. \n");
            return;
        }
        
        point[n].x = x;
        point[n].y = y;
    }
    
    void calcArea(void)
    {
        double minX = 999999;
        double minY = 999999;
        double maxX = -999999;
        double maxY = -999999;
        
        for (int i = 0; i < 3; i++)
        {
            if (minX <= point[i].x)
            {
                minX = point[i].x;
            }
            else if (maxX > point[i].x)
            {
                maxX = point[i].x;
            }
            
            if (minY <= point[i].y)
            {
                minY = point[i].y;
            }
            else if (maxY >= point[i].x)
            {
                maxY = point[i].x;
            }
        }
        area = (maxX - minX) * (maxY - minY) / 2;
    }

    
public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
    {
        setPoint(0, x1, y1);
        setPoint(1, x2, y2);
        setPoint(2, x3, y3);
    }
    
    Triangle(coordinate pos1, coordinate pos2, coordinate pos3)
    {
        setPoint(0, pos1);
        setPoint(1, pos2);
        setPoint(2, pos3);
    }
    
    void setPoint(int n, coordinate pos)
    {
        setPointPri(n, pos.x, pos.y);
    }
    void setPoint(int n, int x, int y)
    {
        setPointPri(n, x, y);
    }
    
    double getArea()
    {
        calcArea();
        return area;
    }
    
    void Move(int x, int y)
    {
//        this->point[0].x += x;
//        this->point[0].y += y;
//        this->point[1].x += x;
//        this->point[1].y += y;
//        this->point[2].x += x;
//        this->point[2].y += y;
        setPointPri(0, this->point[0].x + x, this->point[0].y + y);
        setPointPri(1, this->point[1].x + x, this->point[1].y + y);
        setPointPri(2, this->point[2].x + x, this->point[2].y + y);
    }
    
    void Move(coordinate pos)
    {
        setPointPri(0, this->point[0].x + pos.x, this->point[0].y + pos.y);
        setPointPri(1, this->point[1].x + pos.x, this->point[1].y + pos.y);
        setPointPri(2, this->point[2].x + pos.x, this->point[2].y + pos.y);
    }
    
    void MoveTo(int x, int y)
    {
        
    }
    
    void MoveTo(coordinate pos)
    {
        
    }
};





class Rectangle
{
private:
    coordinate point[2];
//    double width = (point[1].x - point[0].x) > 0 ? (point[1].x - point[0].x) : (point[0].x - point[1].x);
//    double height = (point[1].y - point[0].y) > 0 ? (point[1].y - point[0].y) : (point[0].y - point[1].y);
    double width;
    double height;
//    double area = width * height;
    double area;
    
    void setPointPri(int n, int x, int y)
    {
        printf("n의 범위는 0~1. \n");
        point[n].x = x;
        point[n].y = y;
    }
    
    void calcArea()
    {
        width = (point[1].x - point[0].x) > 0 ? (point[1].x - point[0].x) : (point[0].x - point[1].x);
        height = (point[1].y - point[0].y) > 0 ? (point[1].y - point[0].y) : (point[0].y - point[1].y);
        area = width * height;
    }
    
    
public:

    Rectangle(coordinate pos1, coordinate pos2)
    {
        setPointPri(0, pos1.x, pos1.y);
        setPointPri(1, pos2.x, pos2.y);
    }
    Rectangle(int x1, int y1, int x2, int y2)
    {
        setPointPri(0, x1, y1);
        setPointPri(1, x2, y2);
    }
    
    void setPoint(int n, int x, int y)
    {
        setPointPri(n, x, y);
    }
    void setPoint(int n, coordinate pos)
    {
        setPointPri(n, pos.x, pos.y);
    }
    
    double getArea()
    {
        calcArea();
        return area;
    }
    
    
    void Move(int x, int y)
    {
        setPointPri(0, this->point[0].x + x, this->point[0].y + y);
        setPointPri(1, this->point[1].x + x, this->point[1].y + y);
    }
    
    void Move(coordinate pos)
    {
        setPointPri(0, this->point[0].x + pos.x, this->point[0].y + pos.y);
        setPointPri(1, this->point[1].x + pos.x, this->point[1].y + pos.y);
    }
    
    void MoveTo(int x, int y)
    {
        
    }
    
    void MoveTo(coordinate pos)
    {

    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    Triangle t1(1, 2, 3, 11, 22, 33);
    printf("Area: %f \n", t1.getArea());
    
    
    
   return 0;
}
