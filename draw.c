#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
	int temp;
	if (x1<x0){
		temp = x1;
		x1 = x0;
		x0 = temp;
		temp = y1;
		y1 = y0;
		y0 = temp;
	}

	//horizontal
	if (y0 ==y1){
		int x = x0;
		while (x1 > x){
			plot(s,c,x,y0);
			x++;
		}
		return ;
	}
	//vertical
	if (x0 ==x1){
		int y = y0;
		while (y1 > y){
			plot(s,c,x0,y);
			y++;
		}
		return ;
	}
  //octant 1
	if (x1-x0>=0 && y1-y0>=0 && x1-x0>= y1-y0){
		int x = x0;
		int y = y0;
		int a = y1-y0;
		int b = -(x1-x0);
		int d = 2*a+b;
		while(x<=x1){
			plot(s,c,x,y);
			if (d>0){
				y++;
				d+=2*b;
			}
			x++;
			d+=2*a;
		}
		return;
	}

  //octant 2
	if (x1-x0>0 && y1-y0>0 && x1-x0<=y1-y0){
		int x = x0;
		int y = y0;
		int a = y1-y0;
		int b = -(x1-x0);
		int d = a+2*b;
		while(y<=y1){
			plot(s,c,x,y);
			if (d<0){
				x++;
				d+=2*a;
			}
			y++;
			d+=2*b;
		}
	}
  	//octant 7
	if (x1-x0>0 && y1-y0<0 && x0-x1>y1-y0){
		int x = x0;
		int y = y0;
		int a = y1-y0;
		int b = -(x1-x0);
		int d = 2*b-a;
		while(y>=y1){
			plot(s,c,x,y);
			if (d<0){
				x++;
				d-=2*a;
			}
			y--;
			d+=2*b;
		}
	}

	if (x1-x0>0 && y1-y0<0 && x0-x1<=y1-y0){
		int x = x0;
		int y = y0;
		int a = y1-y0;
		int b = -(x1-x0);
		int d = b - 2*a;
		while(x<=x1){
			plot(s,c,x,y);
			if (d>0){
				y--;
				d+=2*b;
			}
			x++;
			d-=2*a;
		}
	}

}
