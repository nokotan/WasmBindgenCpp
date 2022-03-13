# include "../../WasmBindgen.h"

WasmBindgenExport(main, 1, I32, ((I32, argc), (I32, argv)))
__attribute__((visibility("default")))
extern "C" int main() {
    return 0;
}
