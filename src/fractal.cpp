/* The MIT License (MIT)

Copyright (c) 2016 Leonardo Deliyannis Constantin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>

#include<stdio.h>
#include<stdbool.h>
#include<math.h>
//#define DEBP // DEBug Print

bool initialize();

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

ALLEGRO_DISPLAY *screen = NULL;

const float border = 150.0;

void draw_triangle_down_from(float side, float x, float y, ALLEGRO_COLOR color){
	float tHeight = (side * sqrtf(3) / 2);
#ifdef DEBP
	al_draw_rectangle(x, y, x+side, y+tHeight, al_map_rgb(0, 0xFF, 0), 0);
#endif // DEBP;
	al_draw_filled_triangle
		(x, y, x + side, y, x + side / 2.0, y + tHeight, color);
}

void draw_triangle_up_from(float side, float x, float y, ALLEGRO_COLOR color){
	float tHeight = (side * sqrtf(3) / 2);
#ifdef DEBP
	al_draw_rectangle(x, y, x+side, y+tHeight, al_map_rgb(0, 0xFF, 0), 0);
#endif // DEBP;
	al_draw_filled_triangle
		(x + side / 2.0, y, x, y+tHeight, x + side, y + tHeight, color);
}

const int STEPS = 4;
int step_counter = 0;

void koch_snowflake(int steps){
	
}

int main(int argc, char **argv){
	//float seconds;
	//sscanf(argv[1], "%f", &seconds);
	
	if(!initialize())
		return -1;
	/*	
	al_draw_line(20.0, 40.0, 40.0, 60.0, al_map_rgb(255, 0, 0), 1.0);
	al_flip_display();
	
	al_rest(2.0);
	
	al_clear_to_color(al_map_rgb(0,0,0));
	al_flip_display();
	
	al_rest(0.5);
	*/
	draw_triangle_down_from(320.0, 160.0, 150.0, al_map_rgb(255, 255, 255));
	draw_triangle_up_from(320.0, 160.0, 60.0, al_map_rgb(255, 255, 255));
	al_flip_display();
	
	al_rest(3.0);
	
	al_destroy_display(screen);
	
	return 0;
}

bool initialize(){
	
	if(!al_init()){
		fprintf(stderr, "Failed to initialize the Allegro library.\n");
		return false;
	}
	
	if(!al_init_primitives_addon()){
		fprintf(stderr, "Failed to initialize primitives add-on.\n");
		return false;
	}
	
	screen = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
	if(!screen){
		fprintf(stderr, "Failed trying to create window.\n");
		return false;
	}
	
	al_set_window_title(screen, "Testing allegro_primitives");
	return true;
}

