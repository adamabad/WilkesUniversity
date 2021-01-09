#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <gtk-3.0/gtk/gtk.h>

typedef cairo_t *graphics_context;

extern void create_window(int width, int height, void *data);

#define new_path           cairo_new_path
#define close_path         cairo_close_path
#define stroke             cairo_stroke
#define fill               cairo_fill
#define move_to            cairo_move_to
#define line_to            cairo_line_to
#define rectangle          cairo_rectangle
#define arc                cairo_arc
#define relative_line_to   cairo_rel_line_to
#define relative_move_to   cairo_rel_move_to
#define text               cairo_show_text
#define color              cairo_set_source_rgb
#define set_font(gc, font) cairo_select_font_face(gc, font, CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL)
#define set_font_size      cairo_set_font_size

#endif
