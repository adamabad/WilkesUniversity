#include "graphics.h"

extern void draw_window(cairo_t *gc, int width, int height, void *data);

gboolean draw(GtkWidget *widget, cairo_t *cr, gpointer data) {
  int width, height;
  GtkWidget *window = gtk_widget_get_toplevel(widget);
  gtk_window_get_size(GTK_WINDOW(window), &width, &height);
  draw_window(cr, width, height, data);
  return FALSE;
}

gboolean destroy(GtkWidget *widget, GdkEvent *event, gpointer data) {
  gtk_main_quit();
}

void create_window(int width, int height, void *data) {
  int n = 0;
  gtk_init(0, NULL);
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  GtkWidget *canvas = gtk_drawing_area_new();
  gtk_window_set_default_geometry(GTK_WINDOW(window), width, height);
  gtk_container_add(GTK_CONTAINER(window), canvas);
  g_signal_connect(G_OBJECT(canvas), "draw", G_CALLBACK(draw), data);
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
  gtk_widget_show_all(window);
  gtk_main();
}
  
