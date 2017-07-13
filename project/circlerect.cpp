#include "circlerect.h"
#include "circle.h"
#include "rectangle.h"
#include <iostream>
#include <fstream>
using namespace std;
int CircleRect::Count = 0;
const char colorMap[10][10] ={"Black","Red","Yellow","Blue","Orange","Green"};
const char Type[10][10]={"圆形","矩形","圆角矩形"};

CircleRect::CircleRect(float cx,float cy,float cr,float w,float h,float linewidth,int color ,char *str):Graph(3,linewidth,color,str),Circle(cx,cy,cr),Rectangle(h,w){}

CircleRect::CircleRect(CircleRect &a):Graph(3,a.linewidth,a.color,a.str),Circle(a.x,a.y,a.r),Rectangle(a.height,a.width){}
void CircleRect::showMessage()
{
	cout<<"形状:"<<Type[type]<<endl;
	cout<<"半径:"<<r<<endl;
	cout<<"圆心坐标"<<"("<<x<<","<<y<<")"<<endl;
	cout<<"宽:"<<width<<" 高"<<height<<endl;
	cout<<"线条颜色:"<<colorMap[color]<<endl;
	cout<<"线条粗细:"<<linewidth<<endl;
	cout<<"信息:"<<str<<endl;
	cout<<endl;
}
void CircleRect::write(ofstream &fout)
{
	fout.write((char *)&type,sizeof(int));
	fout.write(reinterpret_cast<const char*>(&r),sizeof(float));
	fout.write(reinterpret_cast<const char*>(&x),sizeof(float));
	fout.write(reinterpret_cast<const char*>(&y),sizeof(float));
	fout.write(reinterpret_cast<const char*>(&width),sizeof(float));
	fout.write(reinterpret_cast<const char*>(&height),sizeof(float));
	fout.write((char*)&color,sizeof(int));
	fout.write(reinterpret_cast<const char*>(&linewidth),sizeof(float));
	fout.write((char*)str,100*sizeof(char));
}
int CircleRect::getCount()
{
	return Count;
}
void CircleRect::add()
{
	Count++;
}
bool CircleRect::inside(float x,float y)
{
	float _x = Circle::x/2;
	float _y = Circle::y/2;
	float w = Rectangle::width/2;
	float h = Rectangle::height/2;
	if (_x-w <= x && x <= _x+w && _y+h >= y && y >= _y-h )
		return true;
	return false;
}

