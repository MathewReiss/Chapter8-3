#include <pebble.h>

Layer *layer;
Window *window;
GBitmap *old_image, *image;

int HEIGHT = PBL_IF_RECT_ELSE(168,180);
int WIDTH = PBL_IF_RECT_ELSE(144,180);

int IMAGE_HEIGHT = 76;
int IMAGE_WIDTH = 56;

void draw(Layer *layer, GContext *ctx){
	graphics_context_set_compositing_mode(ctx, GCompOpSet);
	graphics_draw_bitmap_in_rect(ctx, old_image, GRect((WIDTH-IMAGE_WIDTH)/2, PBL_IF_RECT_ELSE(4,8), IMAGE_WIDTH, IMAGE_HEIGHT));
	graphics_draw_bitmap_in_rect(ctx, image, GRect((WIDTH-IMAGE_WIDTH)/2, HEIGHT-PBL_IF_RECT_ELSE(4,8)-IMAGE_HEIGHT, IMAGE_WIDTH, IMAGE_HEIGHT));
	graphics_context_set_stroke_color(ctx, GColorBlack);
	graphics_draw_line(ctx, GPoint(0,HEIGHT/2), GPoint(WIDTH,HEIGHT/2));
}

int get_num_palette_colors(GBitmap *b){

	GBitmapFormat format = gbitmap_get_format(b);

	switch (format) {
		case GBitmapFormat1Bit: return 0;
		case GBitmapFormat8Bit: return 0;
		case GBitmapFormat1BitPalette: return 2;
		case GBitmapFormat2BitPalette: return 4;
		case GBitmapFormat4BitPalette: return 16;

		default: return 0;
	}

}

void replace_colors(GBitmap *image, GColor8 current_color, GColor8 new_color);

void handle_init(){
	window = window_create();
	layer = layer_create(layer_get_bounds(window_get_root_layer(window)));
	layer_set_update_proc(layer, draw);
	layer_add_child(window_get_root_layer(window), layer);
	
	image = gbitmap_create_with_resource(RESOURCE_ID_IMAGE);
	old_image = gbitmap_create_with_resource(RESOURCE_ID_IMAGE);
	
	replace_colors(image, GColorRed, GColorBlue);
	replace_colors(image, GColorDarkCandyAppleRed, GColorOxfordBlue);
	
	window_stack_push(window, true);
	
	light_enable(true);
	
	app_event_loop();
}