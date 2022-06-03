# WasmBindgenCpp

Use `wasm-bindgen` to *.cpp files.

```cpp
# include "WasmBindgen.h"

WasmBindgenImport(alert, Unit, ((String, message)))
__attribute__((import_module("__wbindgen_placeholder__")))
extern "C" void alert(const char* message, size_t messageLength);

int main() {
    alert("Hei!", sizeof("Hei!"));
}
```
