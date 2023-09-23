package guigo

// #cgo pkg-config: gtk+-3.0
// #include "window.h"
// #include "gtk_macro_wrapper.h"
// #include <stdlib.h>
import "C"
import "unsafe"
/*
TODO:
-> Bind defines
-> Refact macro bidding
*/

func (widget GtkWidget) HelloFromC(draw_area GtkWidget) {
	C.create_window(widget.GtkWidget, draw_area.GtkWidget)
}

type GtkWidget struct {
	GtkWidget *C.GtkWidget
}

// Bind Argc Argv
func Init() {
	C.gtk_init(nil, nil)
}

// Bind GTK_WINDOW_TOPLEVEL
func Window_new() GtkWidget {
	return GtkWidget{C.gtk_window_new(C.GTK_WINDOW_TOPLEVEL)}
}

func (widget GtkWidget) Set_default_size(width, height int) {
	C.gtk_window_set_default_size(C.macro_gtk_window(widget.GtkWidget), C.int(width), C.int(height))
}

func (widget GtkWidget) Set_decorated (setting bool) {
	var c_setting C.int

	if (setting) {
		c_setting = 1
	} else {
		c_setting = 0
	}
	C.gtk_window_set_decorated(C.macro_gtk_window(widget.GtkWidget), c_setting);
}

// Bind GTK_WIN_POS_CENTER
func (widget GtkWidget) Set_position () {
	C.gtk_window_set_position(C.macro_gtk_window(widget.GtkWidget), C.GTK_WIN_POS_CENTER);
}

func (widget GtkWidget) Signal_connect(detailedSignal string) {
	cStr := C.CString(detailedSignal)
	defer C.free(unsafe.Pointer(cStr))
	C.macro_g_signal_connect(C.macro_g_object(widget.GtkWidget), cStr, C.GCallback(unsafe.Pointer(&callback)), nil);
}

func Drawing_area_new() GtkWidget {
	return GtkWidget{C.gtk_drawing_area_new()};
}

func (widget GtkWidget) Container_add(new_widget GtkWidget) {
	C.gtk_container_add(C.macro_gtk_container(widget.GtkWidget), new_widget.GtkWidget);
}
