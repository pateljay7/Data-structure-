#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;

int main() {
	unsigned long arr[20]= {0},temp;
	int i=0,count=0,hk,value[15];
	bool check[20];
	cout<<endl;
	printf("Data Generated Randomly:\n");
	cout<<endl;
	for(i=0; i<15; i++) {
		value[i]=(rand()% (999999-100000+1))+100000;
	}
	for(i=0; i<15; i++) {
		cout<<value[i]<<" ";
	}
	cout<<endl;
	for(int i=0; i<15; i++) {
		long long k = (value[i] % 18) + 2;
		if(check[k]==false) {
			check[k] = true;
			arr[k] = value[i];
		} else {
			bool flag = false;
			int j=0;
			while(!flag) {
				j++;
				int k2=(k+(1*j)+(1*j*j))%20;

				if(check[k2]==false) {
					flag=true;
					check[k2] = true;
					arr[k2] = value[i];
				   // cout<<arr[k2]<<endl;
				}
			}
		}
	}
	cout<<endl<<endl<<endl;
	cout<<"data are stored in array using probing";
	cout<<endl<<endl;
	for(int i=0; i<20; i++) {
		cout<<arr[i]<<"  ";
	}
}
