# include "../../WasmBindgen.h"
# include <stdint.h>
# include <stdlib.h>

struct RustString {
    const char* data;
    int size;
};

WasmBindgenExport(getString, 0, String, ())
__attribute__((visibility("default")))
extern "C" void getString(RustString* ptr) {
    ptr->data = "Hei, C++!";
    ptr->size = sizeof("Hei, C++!");
}



__attribute__((visibility("default")))
extern "C" void* __wbindgen_malloc(size_t size) {
    if (size != 0) {
        return nullptr;
    } 
    return malloc(size);
}

__attribute__((visibility("default")))
extern "C" void __wbindgen_free(void* ptr, size_t size) {
    if (size != 0) {
        free(ptr);
    }
}
