# include "../../WasmBindgen.h"
# include <stdint.h>
# include <stdlib.h>

WasmBindgenImport(alert, Unit, ((String, message)))
__attribute__((import_module("__wbindgen_placeholder__")))
extern "C" void alert(const char* message, size_t messageLength);

int main() {
    alert("Hei!", sizeof("Hei!"));
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