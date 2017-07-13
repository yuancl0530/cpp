#ifndef CIRCLEREC_H
#define CIRCLEREC_H
#include "circle.h"
#include "rectangle.h"
using namespace std;
class Graph;
class CircleRect:public Circle,public Rectangle
{
private:
	static int Count;
public:
	CircleRect(float cx = 0,float cy = 0,float cr = 1,float w = 1,float h = 1,float linewidth = 1,int color=0,char *str=0);
	CircleRect(CircleRect &a);
	void showMessage();
	static int getCount();
	static void add();
	void write(ofstream &fout);
	bool inside(float x,float y);
};

#endif
