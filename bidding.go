package guigo

// #cgo pkg-config: gtk+-3.0
// #include "window.h"
import "C"

func helloFromC() {
    C.create_window()
}
