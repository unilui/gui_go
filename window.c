#include "window.h"

void draw_pixel(cairo_t *cr, int x, int y, double red, double green, double blue) {
    cairo_set_source_rgb(cr, red, green, blue);
    cairo_rectangle(cr, x, y, 1, 1);
    cairo_fill(cr);
}
// Callback function for drawing on the drawing area
gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer data) {
    // Draw a pixel at coordinates (50, 50) with the color red (1.0, 0.0, 0.0)
    draw_pixel(cr, 50, 50, 1.0, 0.0, 0.0);

    return FALSE; // We handled the draw event; no further processing needed
}

void create_window(void) {
    gtk_init(NULL, NULL);

    // Create a GTK window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Set the window to be frameless
    //gtk_window_set_decorated(GTK_WINDOW(window), FALSE);

    // Set the window's size and position (optional)
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    // Connect the "destroy" signal to exit the application
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Load custom CSS (optional)
    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css_provider,
        "window {"
        "   background-color: #3498db;"
        "   font: 20px 'Sans';"
        "}",
        -1,
        NULL);

    GtkStyleContext *style_context = gtk_widget_get_style_context(window);
    gtk_style_context_add_provider(style_context, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Create a GTK drawing area
    GtkWidget *drawing_area = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), drawing_area);

    // Connect the "draw" signal to handle drawing on the drawing area
    g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(on_draw), NULL);

    // Show all widgets
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();
}
