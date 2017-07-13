#include "circlerect.h"
#include "circle.h"
#include "rectangle.h"
#include "graph.h"
#include "pptpage.h"
#include <iostream>
#include <fstream>
using namespace std;
const char colorMap[10][10] ={"Black","Red","Yellow","Blue","Orange","Green"};
const char Type[10][10]={"圆形","矩形","圆角矩形"};
int PPTPage::Count = 0;

PPTPage::PPTPage()
{	
	G[0] = 0;
}

void PPTPage::addCR(float cx,float cy,float cr,float w,float h,float linewidth,int color ,char *str)
{
	G[Count++] = new CircleRect(cx,cy,cr,w,h,linewidth,color,str);
	CircleRect::add();
}
void PPTPage::addC(float x,float y,float r,float linewidth,int color,char *str)
{
	G[Count++] = new Circle(x,y,r,linewidth,color,str);
	Circle::add();
}
void PPTPage::addR(float h,float w,float x,float y,float linewidth,int color,char *str)
{
	G[Count++] = new Rectangle(h,w,x,y,linewidth,color,str);
	Rectangle::add();
}
void PPTPage::add()
{
	int type;
	cout<<"输入图形类型（0圆形，1矩形，2圆角矩形）：";
	cin >> type;
	if (type == 0){
		float x,y,r,line;
		int col;
		char str[100];
		cout <<"圆心:";
		cin>>x>>y;
		cout<<"半径:";
		cin>>r;
		cout<<"线条粗细:";
		cin>>line;
		for (int i = 0;colorMap[i][0] != 0;i++)
			cout<<i<<": "<<colorMap[i]<<endl;
		cout<<"颜色：";
		cin>>col;
		cout<<"信息:";
		cin>>str;
		addC(x,y,r,line,col,str);
	}
	else if (type == 1){
		float h,w,x,y,line;
		char str[100];
		int color;
		cout<<"高:";
		cin>>h;
		cout<<"宽:";
		cin>>w;
		cout<<"左上角坐标：";
		cin>>x>>y;
		cout<<"线条粗细:";
		cin>>line;
		for (int i = 0;colorMap[i][0] != 0;i++)
			cout<<i<<": "<<colorMap[i]<<endl;
		cout<<"颜色：";
		cin>>color;
		cout<<"信息:";
		cin>>str;
		addR(h,w,x,y,line,color,str);
	}
	else {
		float x,y,r,w,h,line;
		int col;
		char str[100];
		cout <<"圆心:";
		cin>>x>>y;
		cout<<"半径:";
		cin>>r;
		cout<<"高:";
		cin>>h;
		cout<<"宽:";
		cin>>w;
		cout<<"线条粗细:";
		cin>>line;
		for (int i = 0;colorMap[i][0] != 0;i++)
			cout<<i<<": "<<colorMap[i]<<endl;
		cout<<"颜色：";
		cin>>col;
		cout<<"信息:";
		cin>>str;
		addCR(x,y,r,w,h,line,col,str);
	}
}
void PPTPage::show()
{
	sort(G);
	for (int i = 0;i < Count;i++){
		if (G[i]){
			cout<<"NO."<<i+1<<endl;
			G[i]->showMessage();
		}
	}
	cout<<"共"<<Count<<"个图形"<<endl;
}
void PPTPage::save(char *file)
{
	ofstream fout;
	fout.open(file,ios::out|ios::binary);
	for (int i = 0;i < Count;i++){
		if (G[i]){
			G[i]->write(fout);
		}
	}
	fout.close();
	cout<<"保存成功"<<endl;
}
PPTPage::~PPTPage()
{
	for (int i = 0;i < Count;i++){
		delete G[i];
	}
}
void PPTPage::readG(char *file)
{
	ifstream fin;
	fin.open(file,ios::binary);
	
	while (!fin.eof()){
		int ty;
		fin.read((char *)&ty,sizeof(int));
		if (fin.eof())
			break;
		if (ty == 0){
			float r,x,y,linewidth;
			int color;
			char str[100];
			fin.read(reinterpret_cast<char*>(&r),sizeof(float));
			fin.read(reinterpret_cast<char*>(&x),sizeof(float));
			fin.read(reinterpret_cast<char*>(&y),sizeof(float));
			fin.read((char*)&color,sizeof(int));
			fin.read(reinterpret_cast<char*>(&linewidth),sizeof(float));
			fin.read((char*)str,100*sizeof(char));
			addC(x,y,r,linewidth,color,str);
		}
		else if (ty == 1){
			float height,width,x1,y1,linewidth,x2,y2;
			int color;
			char str[100];
			fin.read(reinterpret_cast<char*>(&x1),sizeof(float));
			fin.read(reinterpret_cast<char*>(&y1),sizeof(float));
			fin.read(reinterpret_cast<char*>(&x2),sizeof(float));
			fin.read(reinterpret_cast<char*>(&y2),sizeof(float));
			fin.read(reinterpret_cast<char*>(&width),sizeof(float));
			fin.read(reinterpret_cast<char*>(&height),sizeof(float));
			fin.read((char*)&color,sizeof(int));
			fin.read(reinterpret_cast<char*>(&linewidth),sizeof(float));
			fin.read((char*)str,100*sizeof(char));
			addR(height,width,x1,y1,linewidth,color,str);
		}
		else {
			float x,y,r,width,height,linewidth;
			int color;
			char str[100];
			fin.read(reinterpret_cast<char*>(&r),sizeof(float));
			fin.read(reinterpret_cast<char*>(&x),sizeof(float));
			fin.read(reinterpret_cast<char*>(&y),sizeof(float));
			fin.read(reinterpret_cast<char*>(&width),sizeof(float));
			fin.read(reinterpret_cast<char*>(&height),sizeof(float));
			fin.read((char*)&color,sizeof(int));
			fin.read(reinterpret_cast<char*>(&linewidth),sizeof(float));
			fin.read((char*)str,100*sizeof(char));
			addCR(x,y,r,width,height,linewidth,color,str);
		
		}
	}
	fin.close();
}
void PPTPage::sort(Graph **g)
{
	for (int i = 0;i < Count;i++){
		for (int j = 1;j < Count-i;j++){
			if ( *g[j] < *g[j-1]){
				Graph *t = g[j-1];
				g[j-1] = g[j];
				g[j] =t;
			}
		}
	}
}
void  PPTPage::del()
{
	float x,y;
	cout<<"请输入点:";
	cin>>x>>y;
	for (int i = 0;i < Count;i++){
		if (G[i]->inside(x,y)){
			delete G[i];
			G[i] = NULL;
			int j = i;
			Count--;
			while (j < Count){
				G[j]= G[j+1];
				j++;
			}
		}
	}

}
