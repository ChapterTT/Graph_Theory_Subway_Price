#include "dijkstra.cpp"
#include<iostream>
using namespace std;

int main(){
	char a[90];
	for ( int i = 0; i < 90; i++ )
   	{
      a[i] = i;
   	}

	MGraph<char> g(a,90);
	cout<<"请输入起始车站:";
	string as;
	cin>>as;
	int n;
	for(int i=0;i<90;i++){
		if(name[i]==as){
			n=i;
			break;
		}
	}

	int m;
	string ss;
	cout<<"请输入要到达的车站："; 
	cin>>ss;
	for(int i=0;i<90;i++){
		if(name[i]==ss){
			m=i;
			break;
		}
	}

	float length=g.Price(n,m);
	cout<<"该路程总长度为："<<length<<"公里"<<endl;

	cout<<"购买该段路程所需费用为";
	if(length<=0){
		cout<<"系统故障，请稍候再试!";
	}
	else if(length<=6){
		cout<<"2元"<<endl;
	}
	else if(length<=12){
		cout<<"3元"<<endl;
	}
	else if(length<=20){
		cout<<"4元"<<endl;
	}
	else if(length<=28){
		cout<<"5元"<<endl;
	}
	else if(length>28){
		cout<<int((length-28)/10+6)<<"元"<<endl;
	}

	//打印最小生成树的临接矩阵
	// g.Print();

	return 0;
}


