#include <cstring>
#include <iostream>
#include <fstream>
#include <cmath>
#include "circle.h"
using namespace std;
const char colorMap[10][10] ={"Black","Red","Yellow","Blue","Orange","Green"};
const char Type[10][10]={"圆形","矩形","圆角矩形"};
int Circle::CirCount = 0;
Circle::Circle(float x,float y,float r ,float linewidth,int color ,char *str ) :Graph(0,linewidth,color,str)
{
	this->x = x;
	this->y = y;
	this->r = r;
}
Circle::Circle(Circle &a):Graph(0,a.linewidth,a.color,a.str)
{
	x = a.x;
	y = a.y;
	r = a.y;
}
void Circle::add(){CirCount++;}
int Circle::getCount()
{
	return CirCount;
}
void Circle::showMessage()
{
	cout<<"形状:"<<Type[type]<<endl;
	cout<<"半径:"<<r<<endl;
	cout<<"圆心坐标:"<<"("<<x<<","<<y<<")"<<endl;
	cout<<"线条颜色:"<<colorMap[color]<<endl;
	cout<<"线条粗细:"<<linewidth<<endl;
	cout<<"信息:"<<str<<endl;
	cout<<endl;
}
void Circle::write(ofstream &fout)
{
	fout.write((char *)&type,sizeof(int));
	fout.write(reinterpret_cast<const char*>(&r),sizeof(float));
	fout.write(reinterpret_cast<const char*>(&x),sizeof(float));
	fout.write(reinterpret_cast<const char*>(&y),sizeof(float));
	fout.write((char*)&color,sizeof(int));
	fout.write(reinterpret_cast<const char*>(&linewidth),sizeof(float));
	fout.write((char*)str,100*sizeof(char));
}
bool Circle::inside(float x,float y)
{
	float dis = sqrt((this->x-x)*(this->x - x) + (this->y-y)*(this->y - y));
	if (dis <= r)
		return true;
	else 
		return false;

}
