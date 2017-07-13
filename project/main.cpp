#include <iostream>
#include <iomanip>
#include "circlerect.h"
#include "circle.h"
#include "rectangle.h"
#include "graph.h"
#include "pptpage.h"
using namespace std;
int main()
{
	bool isSave = true;
	PPTPage a;
	char FileName[]="data.dat";
	a.readG(FileName);
	cout<<"*****************************菜  单************************************"<<endl;
	cout<<setw(36)<<"1.添加\n"<<setw(36)<<"2.删除\n"<<setw(36)<<"3.显示\n"<<setw(36)<<"4.保存\n"<<setw(36)<<"0.退出\n";
	cout<<"***********************************************************************"<<endl;
	cout<<setw(38)<<"请选择功能:";
	int sel;
	while (cin >> sel){
		if (sel == 2){
			a.del();
			isSave = false;
		}
		else if (sel==1){
			a.add();
			isSave = false;
			cout<<endl;
		}
		else if (sel == 3){
			a.show();
			cout<<endl;
		}
		else if (sel == 4){
			a.save("data.dat");
			isSave = true;
			cout<<endl;
		}
		else if (sel == 0){
			if (!isSave){
				cout<<"是否保存更改？(y/n):";
				char s;
				cin>>s;
				if (s=='y' || s=='Y')
					a.save(FileName);
			}
			break;
		}
		else {
			cout<<"输入有误！\n";
		}
	cout<<"*****************************菜  单************************************"<<endl;
	cout<<setw(36)<<"1.添加\n"<<setw(36)<<"2.删除\n"<<setw(36)<<"3.显示\n"<<setw(36)<<"4.保存\n"<<setw(36)<<"0.退出\n";
	cout<<"***********************************************************************"<<endl;
	cout<<setw(38)<<"请选择功能:";
	}
	return 0;
}
