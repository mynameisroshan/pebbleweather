#include <pebble.h>
#include "splash_window.h"

Window *splashWindow;
BitmapLayer *splashImageLayer;
GBitmap *splashImage;
TextLayer *splashImageTitle;

void splash_window_load(Window *window) {
	
	Layer *window_layer = window_get_root_layer(window);
	
	splashImage = gbitmap_create_with_resource(RESOURCE_ID_SPLASH_IMAGE);
	
	splashImageLayer = bitmap_layer_create(GRect(0, 0, 144, 120));
	bitmap_layer_set_bitmap(splashImageLayer, splashImage);
	bitmap_layer_set_compositing_mode(splashImageLayer, GCompOpSet);
	layer_add_child(window_layer, bitmap_layer_get_layer(splashImageLayer));
	
	// Notice the pattern? Try gif someday.
	splashImageTitle = text_layer_create(GRect(0, 115, 144, 58));
	text_layer_set_text(splashImageTitle, "Weather Now");
	text_layer_set_text_alignment(splashImageTitle, GTextAlignmentCenter);
	layer_add_child(window_layer, text_layer_get_layer(splashImageTitle));
}

// Gotta clean up!
void splash_window_unload(Window *window) {
	gbitmap_destroy(splashImage);
	bitmap_layer_destroy(splashImageLayer);
	text_layer_destroy(splashImageTitle);
}

void splash_window_create(){
  splashWindow = window_create();
  window_set_window_handlers(splashWindow, (WindowHandlers) {
    .load = splash_window_load,
    .unload = splash_window_unload
  });
}

void splash_window_destroy() {
  window_destroy(splashWindow);
}

Window *splash_window_get_window() {
  return splashWindow;
}