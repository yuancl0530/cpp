#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;
class Graph
{
protected:
	int type;
	int color;
	char *str;
	float linewidth;
public:
	Graph(int type = 0,float linewidth = 0,int color = 0,char *str=0);
	Graph(Graph &a);
	virtual ~Graph();
	virtual void showMessage()=0;
	virtual void write(std::ofstream &fout)=0;
	virtual bool inside(float x,float y)=0;
	bool operator <(Graph &a);
};
#endif