package guigo

// #cgo pkg-config: gtk+-3.0
// #include "window.h"
import "C"

func HelloFromC() {
    C.create_window()
}
