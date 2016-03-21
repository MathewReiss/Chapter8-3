#include <pebble.h>
#include "main.h"

/**
* For this exercise, you will be filling in the following method. A bitmap will be drawn
* on-screen in both it's original and new color schemes. Your job is to use a FOR loop to
* iterate through the image's color palette, detect if the palette selection matches the 
* old color, and if it does, replace it with the new color.
* 
* You may wish to use the Pebble-provided method:
* - bool gcolor_equals(GColor first, GColor second)
*
* Additionally, you should use the custom get_num_palette_colors method
* to determine an upper bound for your FOR loop.
*
* Method parameters are defined as:
* - image: the bitmap you want to color swap
* - old_color: the color you are attempting to detect
* - new_color: the color you are replacing old_color with
*/
void replace_colors(GBitmap *image, GColor old_color, GColor new_color){
	int num_colors = get_num_palette_colors(image);
	GColor *pal = gbitmap_get_palette(image);
	
	for(int c = 0; c < num_colors; c++){
		if(gcolor_equal(pal[c], old_color)) pal[c] = new_color;
	}
}

int main(void) {handle_init();}