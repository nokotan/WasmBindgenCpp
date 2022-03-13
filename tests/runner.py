#!/usr/bin/env python3

import subprocess
import unittest
from os import path

class Test(unittest.TestCase):
    def exec(self, command):
        self.assertEqual(
            subprocess.run(
                command.split(),
                cwd=path.dirname(__file__)+"/src"
            ).returncode,
            0
        )

    def singleFileCompile(self, sourceFileName):
        self.exec(f"clang -O2 {sourceFileName} -o index.wasm -fmacro-backtrace-limit=0 -nostartfiles -Wl,--export-dynamic -Wl,--no-entry -Wl,--allow-undefined")
        self.exec("wasm-bindgen index.wasm --out-dir=. --target=nodejs")

    def test_Start(self):
        self.singleFileCompile("Start.cpp")

    def test_ExportWasmFunction(self):
        self.singleFileCompile("ExportWasmFunction.cpp")

    def test_ImportJsFunction(self):
        self.singleFileCompile("ImportJsFunction.cpp")

if __name__ == "__main__":
    unittest.main()