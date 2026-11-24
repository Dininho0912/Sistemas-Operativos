# Operating Systems (SO)

C programming exercises covering pointers, file I/O, libraries, processes, and system calls.

## Contents

- **Complex Number Library (`complex.h`, `complex_*.c`, `maintest.c`)** — Modular arithmetic operations (`add`, `sub`, `mul`, `div`, `conj`, `mod`, `arg`, `re`, `im`) compiled into static (`.a`) and shared (`.so`) libraries.
- **File & Text Utilities (`mycat.c`, `mycp.c`, `mywc.c`, `backwards.c`, `compare.c`, `filetest.c`, `quote.txt`)** — Custom implementations of standard Unix utilities and file manipulation exercises[cite: 3].
- **Worksheet Exercises (`f3_*.c` – `f6_*.c`, `pointers.c`, `char_array.c`, `trig.c`, `hello.c`)** — Lab exercises covering pointers, strings, math linking (`-lm`), and process/system programming[cite: 3].

## Building

Compile individual exercises with `gcc`:

```bash
# Standard compilation
gcc -Wall -Wextra file.c -o file

# Linking math library (e.g., trig.c, complex_mod.c)
gcc -Wall -Wextra trig.c -lm -o trig