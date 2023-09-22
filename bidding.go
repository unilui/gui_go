package guigo

// #cgo pkg-config: gtk+-3.0
// #include "window.h"
// #include "gtk_macro_wrapper.h"
import "C"

func HelloFromC(window *C.GtkWidget) {
	C.create_window(window)
}

func Init() {
	C.gtk_init(nil, nil)
}

func Window_new() *C.GtkWidget {
	return C.gtk_window_new(C.GTK_WINDOW_TOPLEVEL)
}

func Set_default_size(window *C.GtkWidget) {
	C.gtk_window_set_default_size(C.macro_gtk_window(window), 400, 400)
}
