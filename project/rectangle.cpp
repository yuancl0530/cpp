#include "rectangle.h"
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
int Rectangle::RecCount = 0;
const char colorMap[10][10] ={"Black","Red","Yellow","Blue","Orange","Green"};
const char Type[10][10]={"圆形","矩形","圆角矩形"};

Rectangle::Rectangle(float h,float w,float x,float y,float linewidth,int color,char *str):
Graph(1,linewidth,color,str)
{
	height = h;
	width = w;
	x1 = x;
	y1 = y;
	x2 = x + width;
	y2 = y - height;
}
Rectangle::Rectangle(Rectangle &a):Graph(1,a.linewidth,a.color,a.str)
{
	height = a.height;
	width = a.width;
	x1 = a.x1;
	x2 = a.x2;
	y1 = a.y1;
	y2 = a.y2;
}

void Rectangle::showMessage()
{
	cout<<"形状:"<<Type[type]<<endl;
	cout << "左上角坐标:("<<x1<<','<<y1<<")"<<endl;
	cout << "右下角坐标:("<<x2<<','<<y2<<")"<<endl;
	cout<<"宽:"<<width<<" 高"<<height<<endl;
	cout<<"线条颜色:"<<colorMap[color]<<endl;
	cout<<"线条粗细:"<<linewidth<<endl;
	cout<<"信息:"<<str<<endl;
	cout<<endl;
}
void Rectangle::write(ofstream &fout)
{
	fout.write((char *)&type,sizeof(int));
	fout.write(reinterpret_cast<const char*>(&x1),sizeof(float));
	fout.write(reinterpret_cast<const char*>(&y1),sizeof(float));
	fout.write(reinterpret_cast<const char*>(&x2),sizeof(float));
	fout.write(reinterpret_cast<const char*>(&y2),sizeof(float));
	fout.write(reinterpret_cast<const char*>(&width),sizeof(float));
	fout.write(reinterpret_cast<const char*>(&height),sizeof(float));
	fout.write((char*)&color,sizeof(int));
	fout.write(reinterpret_cast<const char*>(&linewidth),sizeof(float));
	fout.write((char*)str,100*sizeof(char));
}
int Rectangle::getCount()
{
	return RecCount;

}
void Rectangle::add()
{
	RecCount++;
}
bool Rectangle::inside(float x,float y)
{
	if (x1 <= x && x <= x2 && y1 >= y && y >= y2)
		return true;
	return false;
}
