//
//  main.cpp
//  dailyPracticeforC++3
//
//  Created by Jay on 09/02/2019.
//  Copyright © 2019 Jay. All rights reserved.
//

#include <iostream>
using namespace std;

#define PI 3.14159

typedef struct coordinate {
    float x;
    float y;
    coordinate() { x = y = 0; } // C++ 11부터 구조체에도 생성자 소멸자를 사용 가능하게 되었다.
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
    coordinate origin;
    
    double area;
    
    double minX;
    double minY;
    double maxX;
    double maxY;
    
    void setPointPri(int n, int x, int y)
    {
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
        // 함수 밖에서 초기화를 시키니 이동후의 민맥스 좌표값이 반영이 안됨.
        minX = 999999;
        minY = 999999;
        maxX = -999999;
        maxY = -999999;
        
        for (int i = 0; i < 3; i++)
        {
            if (minX > point[i].x)
            {
                minX = point[i].x;
            }
            else if (maxX < point[i].x)
            {
                maxX = point[i].x;
            }
            
            if (minY > point[i].y)
            {
                minY = point[i].y;
            }
            else if (maxY < point[i].x)
            {
                maxY = point[i].y;
            }
        }
        area = (maxX - minX) * (maxY - minY) / 2;
    }
    
    void calcOrigin()
    {
        calcArea(); // 오리진은 삼각형을 감싸는 직사각형의 네 꼭지점중 왼쪽 위 점이므로,
        origin.x = minX;    // x값은 꼭지점중 가장 작은값을 따온다.
        origin.y = maxY;    // y값은 꼭지점중 가장 큰값을 따온다.
        printf("origin: %.2f, %.2f \n", origin.x, origin.y);
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
    
    void getPoint(void)
    {
        printf("point[0].x = %.2f, point[0].y = %.2f \n", point[0].x, point[0].y);
        printf("point[1].x = %.2f, point[0].y = %.2f \n", point[1].x, point[1].y);
        printf("point[2].x = %.2f, point[2].y = %.2f \n", point[2].x, point[2].y);
    }
    
    void Move(int x, int y)
    {
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
        calcOrigin();
        setPointPri(0, point[0].x + (x - origin.x), point[0].y + (y - origin.y));
        setPointPri(1, point[1].x + (x - origin.x), point[1].y + (y - origin.y));
        setPointPri(2, point[2].x + (x - origin.x), point[2].y + (y - origin.y));
    }
    
    void MoveTo(coordinate pos)
    {
        calcOrigin();
        setPointPri(0, point[0].x + (pos.x - origin.x), point[0].y + (pos.y - origin.y));
        setPointPri(1, point[1].x + (pos.x - origin.x), point[1].y + (pos.y - origin.y));
        setPointPri(2, point[2].x + (pos.x - origin.x), point[2].y + (pos.y - origin.y));
    }
};





class Rectangle
{
private:
    coordinate point[2];
    coordinate origin;
    double width;
    double height;
    //    double area = width * height;
    double area;
    
    void setPointPri(int n, int x, int y)
    {
        point[n].x = x;
        point[n].y = y;
    }
    
    void calcArea()
    {
        width = (point[1].x - point[0].x) > 0 ? (point[1].x - point[0].x) : (point[0].x - point[1].x);
        height = (point[1].y - point[0].y) > 0 ? (point[1].y - point[0].y) : (point[0].y - point[1].y);
        area = width * height;
    }
    
    void calcOrigin()
    {
        // 오리진은 사각형의 네 꼭지점중 왼쪽 위 점이므로,
        origin.x = (point[1].x - point[0].x) > 0 ? point[0].x : point[1].x; // x값은 두 점중 작은값을 따온다.
        origin.y = (point[1].y - point[0].y) > 0 ? point[1].y : point[0].y; // y값은 두 점중 큰값을 따온다.
        printf("origin: %.2f, %.2f \n", origin.x, origin.y);
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
    
    void getPoint(void)
    {
        printf("point[0].x = %.2f, point[0].y = %.2f \n", point[0].x, point[0].y);
        printf("point[1].x = %.2f, point[0].y = %.2f \n", point[1].x, point[1].y);
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
        calcOrigin();
        setPointPri(0, point[0].x + (x - origin.x), point[0].y + (y - origin.y));
        setPointPri(1, point[1].x + (x - origin.x), point[1].y + (y - origin.y));
    }
    
    void MoveTo(coordinate pos)
    {
        calcOrigin();
        setPointPri(0, point[0].x + (pos.x - origin.x), point[0].y + (pos.y - origin.y));
        setPointPri(1, point[1].x + (pos.x - origin.x), point[1].y + (pos.y - origin.y));
    }
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    Rectangle* r1 = new Rectangle(3, 11, 7, 5);
    cout << "r1.area: " << r1->getArea() << endl;
    r1->getPoint();
    cout << "moveto(10, 10)" << endl;
    r1->MoveTo(10, 10);
    r1->getPoint();
    cout << "r1.area: " << r1->getArea() << endl;
    cout << endl << endl;
    
    Triangle* t1 = new Triangle(3, 5, 4, 2, 6, 7);
    cout << "t1.area: " << t1->getArea() << endl;
    t1->getPoint();
    cout << "moveto(12, 12)" << endl;
    t1->MoveTo(12, 12);
    t1->getPoint();
    cout << "t1.area: " << t1->getArea() << endl;
    
    
    
    return 0;
}
