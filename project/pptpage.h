#ifndef PPTPAGE_H
#define PPTPAGE_H
#include "circlerect.h"
#include "circle.h"
#include "rectangle.h"
#include "graph.h"
class PPTPage
{
private:
	Graph * G[1000];
	static int Count;
public:
	PPTPage();
	~PPTPage();
	void readG(char *file);
	void add();
	void addCR(float cx,float cy,float cr,float w,float h,float linewidth,int color=0 ,char *str=0);
	void addC(float x,float y,float r,float linewidth,int color = 0,char *str=0);
	void addR(float h,float w,float x,float y,float linewidth,int color = 0,char *str=0);
	void show();
	void del();
	void save(char *file);
	void sort(Graph **g);
};
#endif
