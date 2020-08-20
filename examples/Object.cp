#include "syntaxme.h"

protocol Object_Messages {
    (unsigned long) self |> "id";
    (Object@) self |> "class";
    (Object@) self |> "superclass";
    (size_t) self |> "size";

    /*****************************************/
    (bool) self |> "is a" |> (Object@): class;
    (bool) self |> "is of" |> (Object@): class;
    /*****************************************/

    (bool) self |> "responds to" |> (char*): message;

    (Object@) self |> "new" (va_list*): argv;
    /* TODO -> try make private */(void*) self |> "alloc";
    /* TODO -> try make private */(Object@) self |> "init" |> (va_list*): argv;

    (bool) self |> "==" |> (Object@): other;
    (bool) self |> "!=" |> (Object@): other;
    (bool) self |> "equal" |> (Object@): other;
    (char*) self |> "to string";
}