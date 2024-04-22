package main

//#include <stdlib.h>
import (
    "C"
    "github.com/charmbracelet/glamour"
)

//export MdRender
func MdRender(x *C.char, wordWrap int) *C.char {
    r, _ := glamour.NewTermRenderer(
		glamour.WithStandardStyle("dark"),
		glamour.WithWordWrap(wordWrap),
        glamour.WithEmoji(),
	)

	out, _ := r.Render(C.GoString(x))
    var cmsg *C.char = C.CString(out)
    return cmsg
}

func main() {}
