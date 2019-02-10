#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
  c.red = MAX_COLOR;
  c.green = 0;
  c.blue = 0;

  clear_screen(s);

  // for (int x = 25; x < 50; x+=2){
  // 	for (int y = 50; y>=25 ; y--){
  // 		draw_line(x*10, 500 - x*10, y*10, 500 - y*10, s,c);
  // 	}
  // }
  // for (int y = 0; y < 25; y++){
  // 	for (int x = 25; x>=0 ; x--){
  // 		draw_line(x*10, 500 - y*10, y*10, 500 - x*10, s,c);
  // 	}
  // }

  for(int x = 0; x <=50; x++){
  	c.red = x * 5;
  	c.blue = x*10%255;
  	c.green = x*20%255;
  	draw_line(x*10,500,500 - x*10, 0, s,c);
  }
  for(int y = 0; y <=50; y++){
  	c.red = y * 15;
  	c.blue = y*15%255;
  	c.green = y*25%255;
  	draw_line(500,y*10,0,500 - y*10, s,c);
  }



  display(s);
  save_extension(s, "lines.png");
}
