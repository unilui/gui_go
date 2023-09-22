#ifndef GTK_MACRO_WRAPPER_H
#define GTK_MACRO_WRAPPER_H

#include <gtk/gtk.h>

GtkWindow	*macro_gtk_window(GtkWidget *widget)
{
	return GTK_WINDOW(widget);
}

#endif
