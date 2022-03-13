# pragma once

//
// Macro Helpers
//

# define WasmBindgenToString(x) #x
# define WasmBindgenMacroToString(x) WasmBindgenToString(x)

# define WasmBindgenConcatenate(x, y) x##y
# define WasmBindgenConcatenateMacro(x, y)     WasmBindgenConcatenate(x, y)

# define WasmBindgenReverseIndexSequence() 0, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
# define WasmBindgenTupleSizeHelper(\
        Arg1,  Arg2,  Arg3,  Arg4,  Arg5,  Arg6,  Arg7,  Arg8,  Arg9,  Arg10, \
        Arg11, Arg12, Arg13, Arg14, Arg15, Arg16, N, ...) N
# define WasmBindgenDummyCommaImpl(...)     __VA_ARGS__
# define WasmBindgenDummyComma(...)         WasmBindgenDummyCommaImpl(__VA_ARGS__)
# define WasmBindgenTupleSizeImpl(...)      WasmBindgenTupleSizeHelper(__VA_ARGS__)
# define WasmBindgenTupleSize(...)          WasmBindgenTupleSizeImpl(WasmBindgenDummyComma __VA_ARGS__ (,,,,, ,,,,, ,,,,,), WasmBindgenReverseIndexSequence())
// # define WasmBindgenTupleSize(...)        WasmBindgenTupleSizeImpl(__VA_ARGS__, WasmBindgenReverseIndexSequence())
# define WasmBindgenForEachImpl_0( Functor, ...      ) 
# define WasmBindgenForEachImpl_1( Functor, Arg1     ) Functor(Arg1, 1)
# define WasmBindgenForEachImpl_2( Functor, Arg1, ...) Functor(Arg1, 2) WasmBindgenForEachImpl_1( Functor, __VA_ARGS__)
# define WasmBindgenForEachImpl_3( Functor, Arg1, ...) Functor(Arg1, 3) WasmBindgenForEachImpl_2( Functor, __VA_ARGS__)
# define WasmBindgenForEachImpl_4( Functor, Arg1, ...) Functor(Arg1, 4) WasmBindgenForEachImpl_3( Functor, __VA_ARGS__)
# define WasmBindgenForEachImpl_5( Functor, Arg1, ...) Functor(Arg1, 5) WasmBindgenForEachImpl_4( Functor, __VA_ARGS__)
# define WasmBindgenForEachImpl_6( Functor, Arg1, ...) Functor(Arg1, 6) WasmBindgenForEachImpl_5( Functor, __VA_ARGS__)
# define WasmBindgenForEachImpl_7( Functor, Arg1, ...) Functor(Arg1, 7) WasmBindgenForEachImpl_6( Functor, __VA_ARGS__)
# define WasmBindgenForEachImpl_8( Functor, Arg1, ...) Functor(Arg1, 8) WasmBindgenForEachImpl_7( Functor, __VA_ARGS__)
# define WasmBindgenForEachImpl_9( Functor, Arg1, ...) Functor(Arg1, 9) WasmBindgenForEachImpl_8( Functor, __VA_ARGS__)
# define WasmBindgenForEachImpl_10( Functor, Arg1, ...) Functor(Arg1, 10) WasmBindgenForEachImpl_9( Functor, __VA_ARGS__)
# define WasmBindgenForEachImpl_11( Functor, Arg1, ...) Functor(Arg1, 11) WasmBindgenForEachImpl_10( Functor, __VA_ARGS__)
# define WasmBindgenForEachImpl_12( Functor, Arg1, ...) Functor(Arg1, 12) WasmBindgenForEachImpl_11( Functor, __VA_ARGS__)
# define WasmBindgenForEachImpl_13( Functor, Arg1, ...) Functor(Arg1, 13) WasmBindgenForEachImpl_12( Functor, __VA_ARGS__)
# define WasmBindgenForEachImpl_14( Functor, Arg1, ...) Functor(Arg1, 14) WasmBindgenForEachImpl_13( Functor, __VA_ARGS__)
# define WasmBindgenForEachImpl_15( Functor, Arg1, ...) Functor(Arg1, 15) WasmBindgenForEachImpl_14( Functor, __VA_ARGS__)
# define WasmBindgenForEachImpl_16( Functor, Arg1, ...) Functor(Arg1, 16) WasmBindgenForEachImpl_15( Functor, __VA_ARGS__)

# define WasmBindgenForEach(Functor, ...) \
    WasmBindgenConcatenateMacro(WasmBindgenForEachImpl_, WasmBindgenTupleSize(__VA_ARGS__))(Functor, __VA_ARGS__)

# define WasmBindgenExpandTupleImpl(...) __VA_ARGS__
# define WasmBindgenExpandTuple(...) WasmBindgenExpandTupleImpl(__VA_ARGS__)
# define WasmBindgenTupleElement_1(Arg1, ...) Arg1
# define WasmBindgenTupleElement_2(Arg1, Arg2, ...) Arg2
# define WasmBindgenTupleElement(Index, ...) WasmBindgenConcatenateMacro(WasmBindgenTupleElement_, Index) __VA_ARGS__



# define WasmBindgenVersionString "{\"schema_version\":\"0.2.74\",\"version\":\"0.2.79\"}"
# define WasmBindgenVersionSection() \
    ".int32 31f - 30f\n" \
    "30:\n" \
    ".ascii " WasmBindgenMacroToString(WasmBindgenVersionString) "\n" \
    "31:\n"

# define WasmBindgenDummyCrateIdentifier "wasm-bindgen-c-stubs"
# define WasmBindgenDummyCrateIdentifierSection() \
    ".int8 41f - 40f\n" \
    "40:\n" \
    ".ascii " WasmBindgenMacroToString(WasmBindgenDummyCrateIdentifier) "\n" \
    "41:\n" \

#define WasmBindgenExpandParameterName(x, i) \
    ".int8 11" WasmBindgenMacroToString(i) "f - 10" WasmBindgenMacroToString(i) "f\n" \
    "10" WasmBindgenMacroToString(i) ":\n" \
    ".ascii " WasmBindgenMacroToString(WasmBindgenMacroToString(WasmBindgenTupleElement_2 x)) "\n" \
    "11" WasmBindgenMacroToString(i) ":\n" \

# define WasmBindgenExportSection(FunctionName, IsStart, Names)     \
    ".int8 1\n" /* Size of `Vec<Export<'a>>`. */                    \
    ".int8 0\n" /* `class: Option<&'a str>`. None is `0` */         \
    ".int8 0\n" /* Size of `comments: Vec<&'a str>`. */             \
    ".int8 0\n" /* `consumed: bool`. false. */                      \
    ".int8 " WasmBindgenMacroToString(WasmBindgenTupleSize Names) "\n" /* Size of `arg_names: Vec<String>`. */ \
    WasmBindgenForEach(WasmBindgenExpandParameterName, WasmBindgenExpandTuple Names) \
    ".int8 0\n" /* `asyncness: bool`. false. */                     \
    ".int8 21f - 20f\n" /* Size of `name: &'a str` */               \
    "20:\n"                                                         \
    ".ascii " WasmBindgenToString(FunctionName) "\n" /* Size of `name: &'a str` */ \
    "21:\n"                                                         \
    ".int8 1\n" /* `generate_typescript: bool`. true. */            \
    ".int8 1\n" /* `method_kind: MethodKind<'a>`. Operation(Operation<'a>) (1). */ \
    ".int8 1\n" /* `is_static: bool`. true. */                      \
    ".int8 0\n" /* `kind: OperationKind<'a>`. Regular (0). */       \
    ".int8 " WasmBindgenToString(IsStart) "\n" /* `start: bool`. */

# define WasmBindgenEnumSection() \
    ".int8 0\n" /* Size of `enums: Vec<Enum<'a>>`. */

# define WasmBindgenImportSection(FunctionName, Names) \
    ".int8 1\n" /* Size of `imports: Vec<Import<'a>>`. */ \
    ".int8 0\n" /* `module: ImportModule<'a>`. None (0) */ \
    ".int8 0\n" /* `js_namespace: Option<Vec<String>>`. None */ \
    ".int8 0\n" /* `kind: ImportKind<'a>`. Function(0) */ \
    ".int8 51f - 50f\n" /* `shim: &'a str` */ \
    "50: \n" \
    ".ascii " WasmBindgenToString(FunctionName) "\n" \
    "51: \n" \
    ".int8 0\n" /* `catch: bool`. False. */ \
    ".int8 0\n" /* `variadic: bool`. False. */ \
    ".int8 0\n" /* `assert_no_shim: bool`. False. */ \
    ".int8 0\n" /* `Option<MethodData<'a>>`. None. */ \
    ".int8 1\n" /* `structural: bool`. True. */ \
    ".int8 " WasmBindgenMacroToString(WasmBindgenTupleSize Names) "\n" /* Size of `arg_names: Vec<String>`. */ \
    WasmBindgenForEach(WasmBindgenExpandParameterName, WasmBindgenExpandTuple Names) \
    ".int8 0\n" /* `asyncness: bool`. false. */                     \
    ".int8 21f - 20f\n" /* Size of `name: &'a str` */               \
    "20:\n"                                                         \
    ".ascii " WasmBindgenToString(FunctionName) "\n" /* Size of `name: &'a str` */ \
    "21:\n" \
    ".int8 1\n" /* `generate_typescript: bool`. true. */

# define WasmBindgenNoImportSection() \
    ".int8 0\n" /* Size of `imports: Vec<Import<'a>>`. */

# define WasmBindgenStructSection() \
    ".int8 0\n" /* Size of `structs: Vec<Struct<'a>>`. */

# define WasmBindgenTypeScriptCustomSection() \
    ".int8 0\n" /* Size of `typescript_custom_sections: Vec<&'a str>`. */

# define WasmBindgenLocalModuleSection() \
    ".int8 0\n" /* Size of `local_modules: Vec<LocalModule<'a>>`. */

# define WasmBindgenInlineJSSection() \
    ".int8 0\n" /* Size of `inline_js: Vec<&'a str>`. */

__attribute__((import_module("__wbindgen_placeholder__")))
extern "C" void __wbindgen_describe(int);

#define WasmBindgenParameterDescripter(x, i) \
    __wbindgen_describe(WasmBindgenTupleElement_1 x);

#define WasmBindgenDescripterFunction(FunctionName, ReturnType, Names) \
__attribute__((visibility("default"))) \
extern "C" void WasmBindgenConcatenateMacro(__wbindgen_describe_, FunctionName) () { \
    __wbindgen_describe(Function); \
    __wbindgen_describe(0); \
    __wbindgen_describe(WasmBindgenTupleSize Names); \
    WasmBindgenForEach(WasmBindgenParameterDescripter, WasmBindgenExpandTuple Names) \
    __wbindgen_describe(ReturnType); \
    __wbindgen_describe(ReturnType); \
}

# define Start 1

# define WasmBindgenExport(FunctionName, IsStart, ReturnType, Parameters) \
__asm( \
    ".section .custom_section.__wasm_bindgen_unstable,\"G\",@,abc123,comdat\n" \
    WasmBindgenVersionSection() \
    ".int32 11f - 10f\n" \
    "10:\n" \
    WasmBindgenExportSection(WasmBindgenMacroToString(FunctionName), IsStart, Parameters) \
    WasmBindgenEnumSection() \
    WasmBindgenNoImportSection() \
    WasmBindgenStructSection() \
    WasmBindgenTypeScriptCustomSection() \
    WasmBindgenLocalModuleSection() \
    WasmBindgenInlineJSSection() \
    WasmBindgenDummyCrateIdentifierSection() \
    ".int8 0\n" \
    "11:\n" \
); \
WasmBindgenDescripterFunction(FunctionName, ReturnType, Parameters)

# define WasmBindgenImport(FunctionName, ReturnType, Parameters) \
__asm( \
    ".section .custom_section.__wasm_bindgen_unstable,\"G\",@,abc123,comdat\n" \
    WasmBindgenVersionSection() \
    ".int32 11f - 10f\n" \
    "10:\n" \
    ".int8 0\n" \
    WasmBindgenEnumSection() \
    WasmBindgenImportSection(WasmBindgenMacroToString(FunctionName), Parameters) \
    WasmBindgenStructSection() \
    WasmBindgenTypeScriptCustomSection() \
    WasmBindgenLocalModuleSection() \
    WasmBindgenInlineJSSection() \
    WasmBindgenDummyCrateIdentifierSection() \
    ".int8 0\n" \
    "11:\n" \
); \
WasmBindgenDescripterFunction(FunctionName, ReturnType, Parameters)

enum WasmBindgenTypes {
    I8,
    U8,
    I16,
    U16,
    I32,
    U32,
    I64,
    U64,
    F32,
    F64,
    Boolean,
    Function,
    Closure,
    CachedString,
    String,
    Ref,
    RefMut,
    Slice,
    Vector,
    ExternRef,
    NamedExternref,
    Enum,
    RustStruct,
    Char,
    Optional,
    Result,
    Unit,
    Clamped
};
