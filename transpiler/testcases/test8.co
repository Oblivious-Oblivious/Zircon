#include <stdio.h>

model Composition_Model {
    int a;
    int b;
}

protocol Composition_Protocol implements Object {
    (int) self |> "add";
    (int) self |> "sub";
    (int) self |> "mul";
    (int) self |> "div";
}

object Composition implements Composition_Protocol(int aValue, int bValue) {
    fields {
        /* Compose objects */
        Composition_Model data1;
    }

    init {
        self->data1 = Composition_Model "new";
        self->data1->a = aValue;
        self->data2->b = bValue;
    }

    (void) self |> "set a" |> (int): a |> self->data1->a = a;
    (void) self |> "set b" |> (int): b |> self->data1->b = b;

    message "add" |> return data1->a + data1->b;
    message "sub" |> return data1->a - data1->b;
    message "mul" |> return data1->a * data1->b;
    message "div" |> {
        if(data1->b != 0)
            return data1->a / data1->b;
        return -1;
    }

    defer {}
}

int main(void) {
    Composition obj = Composition "new" 2, 2;
    printf("%d\n", obj "add");

    obj "set a" 5;
    obj "set b" 3;

    int res = obj "add";
    printf("%d\n", res);

    return 0;
}