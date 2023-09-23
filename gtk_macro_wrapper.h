#ifndef GTK_MACRO_WRAPPER_H
#define GTK_MACRO_WRAPPER_H

#include <gtk/gtk.h>

GtkWindow	*macro_gtk_window(GtkWidget *widget)
{
	return GTK_WINDOW(widget);
}

GObject* macro_g_object(GtkWidget* widget)
{
	return G_OBJECT(widget);
}

GtkContainer* macro_gtk_container(GtkWidget* widget) {
	return GTK_CONTAINER(widget);
}

void macro_g_signal_connect(GObject *widget, const gchar* detailed_signal, GCallback callback, gpointer user_data) {
	g_signal_connect(widget, detailed_signal, callback, user_data);
}

#endif
