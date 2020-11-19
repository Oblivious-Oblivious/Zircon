# Changes for Zircon 0.2.0 (30-09-2020)

## - Language changes

* Removed the C preprocessor grammar completely expect `#include` directive due to its simple implementation.
* Fixed an issue with files written in `LF` mode by eliminating any syntax rules where whitespace and newlines mattered.
* Refactored compiler code into different header files according to their usage.
* When compiling a file including the `main()` function, we recursivelly add headers and dependencies of objects compiled.
* Removed the need for casting since we only use messages and void pointers.

## - Core library changes

* Rewritten the `cDataLib` structures into Zircon and ran the test files completelly. In the future those data structures will be used to write a first version of a self hosting Zircon compiler

# Changes for Zircon 0.1.0 (30-08-2020)

* Initial version of the transpiler
