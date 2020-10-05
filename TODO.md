## (✔) ver. 0.2.0 proposals
    🟩 Fix preprocessor grammar.
    🟩 `LF` mode on text editors mess up line feeds for the parser, `CRLF` works properly (fix).
    🟩 Check for custom class destructors.
    🟩 Refactor base code to be more modular.
    🟩 When main flag is raised, include all headers store in the `__zircon_main` file.
    🟩 Create an operator for casting to objects (without violating encapsulation rules).
    🟩 Messages cannot handle casting other objects atm only for objects of the same class.
    🟩 Rewrite cDataLib using Zircon.

## (✗) ver. 0.3.0 proposals
    🟥 Fix typedef names with identifiers.
    🟥 Fix preprocessor with typedefs.
    🟥 Fix selectors on different classes with same names (fix namespacing).
    🟥 Add a compiler setup file to include predefined names and preprocessor directives.
    🟥 Bypass the C preprocessor and write a custom one, that includes extending to messages and objects.
    🟥 Extend the object model allowing for more reflection.
    🟥 Fix nested message calls that now require parentheses.
    🟥 Generalize test suite and test files (write a simplified version of cSpec).
    🟥 Create a website to host code, where objects can be forked.
    🟥 Find a way to compile objects to DLLS, for independent redeployment.
    🟥 Add extension modules named `Fragments` (replace cEmerald) (make cSpec a fragment) (combine with cSpec).
    🟥 Write documentation, create a website, write an article.

## (✗) ver. 0.4.0 proposals
    🟥 Find a way to incorporate existing libraries with zircon (using some sort of object porting).
    🟥 Find a way to declare static functions inside classes.
    🟥 Add implicit, explicit calls to bypass compiler optimizations.
    🟥 Try avoid nullity checks, and implement specific action when an object turns out to be NULL.
    🟥 Try implementing automatic defer calls when out of block range (keep for implicit declarations).
    🟥 Fix spaces on text generation (implement a rudimentary form of a self hosting compiler).
    🟥 Declutter compilation steps.
    🟩 Fix `__init_Object()` declarations with independent compilation.
    🟥 Add object header files (yaml or list syntax) for documentation and enabling DLL compilation.
    🟥 Fix messages with the first parameter being a string needing parentheses.
    🟥 Implement void selectors choosing to translate a return statement or not according to return type.
    🟥 Remove the need for `#import "Object"`.
    🟥 Rewrite cSpec using Zircon.

## (✗) ver. 0.5.0 proposals
    🟥 When compiling two files without a main function, only the first gets translated properly (fix).
    🟥 Fix selectors returning void, by choosing at compile time whether to return or not.
    🟥 Add the callback method code for Object
    🟥 Override `new` and `defer` for better memory management.

## (✗) ver. 1.0.0 goals
    🟥 Make compiler self hosting.
    🟥 Add ability for object literals ("str" "call message", 2 "add one").
    🟥 Make the syntax LISP like, by encapsulating functionality in objects and messages.
    🟥 Add syntax highlighting for vscode and vim.
    🟥 Add an optimizing compiler.
    🟥 Add the ability for implementing custom preprocessor layers dynamically.
    🟥 Add GCC extensions grammar and (maybe) use the C preprocessor before Zircon.
    🟥 Implement the idea of parallel object execution and communication with events and messages.
