#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "graph.h"
using namespace std;
class Rectangle:virtual public Graph
{
private:
	static int RecCount;
protected:
	float x1;
	float y1;
	float x2;
	float y2;
	float height;
	float width;
public:	
	Rectangle(float h = 1,float w = 1,float x=0,float y=0,float linewidth = 1,int color=0,char *str = 0 );
	Rectangle(Rectangle &a);
	void showMessage();
	static void add();
	void write(ofstream &fout);
	bool inside(float x,float y);
	static int getCount();
};
#endif
