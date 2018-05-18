# Preprocessed files
run `dcc -E -nostdinc implementation.c`
run `dcc -E -nostdinc user.c`

The above commands will preprocess all of the above `c` files - this includes substituting all `#define` values into the `c` file. This is the first step.

# Compilation
run `dcc -c implementation.c`
run `dcc -c user.c`

This step compiles both files individually. Missing function implementations are OK here __as long as there is a prototype somewhere in the `#include` tree__.

# Linking
run `dcc -o cat implementation.o user.o`

This links the files together by filling in missing function implementations. If by the end of this step a function is still missing its associated implementation, a compile error will be given stating `undefined reference to ...`.
