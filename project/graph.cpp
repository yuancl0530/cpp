#include "graph.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

const char colorMap[10][10] ={"Black","Red","Yellow","Blue","Orange","Green"};
const char Type[10][10]={"Ô²ÐÎ","¾ØÐÎ","Ô²½Ç¾ØÐÎ"};
bool Graph::operator < (Graph &a)
{
	return type < a.type;
}
Graph::Graph(int type,float linewidth,int color,char *str)
{
	this->type = type;
	this->linewidth = linewidth;
	this->color=color;
	if (str){
		int len = strlen(str);
		this->str = new char[len+1];
		strcpy(this->str,str);
	}
}
Graph::~Graph()
{
	delete []str;
}
Graph::Graph(Graph &a)
{
	color = a.color;
	linewidth = a.linewidth;
	color = a.color;
	if (a.str){
		str = new char[strlen(a.str)+1];
		strcpy(str,a.str);
	}
}
