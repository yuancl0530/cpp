#ifndef CIRCLE_H
#define CIRCLE_H
#include "graph.h"
using namespace std;
class Circle :virtual public Graph
{
private:
	static int CirCount;
protected:
	float x;
	float y;
	float r;
public:	
	Circle(float x = 0,float y = 0,float r = 1 ,float linewidth = 0,int color = 0,char *str = 0);
	Circle(Circle &a);
	bool inside(float x,float y);
	void showMessage();
	void write(ofstream &fout);
	static int getCount();
	static void add();
};

#endif 