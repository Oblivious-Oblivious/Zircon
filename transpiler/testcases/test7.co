#include <stdlib.h>

model TestModel {
    int a;
    int b;
}

protocol TestProtocol implements Object {
    (void) self |> "test abstract no param";
    (void*) self |> "test abstract with 2 param" |> (void*): a, (void*): b;
}

object Test implements TestProtocol {
    fields {
        TestModel data1;
    }

    init {
        self->data1->a = aValue;
        self->data1->b = bValue;
    }

    defer {}

    (void) self |> "test no param" |> self->data1->a = 42;
    (void) self |> "test with 2 param" |> (int): a, (int): b |> self->data->a = a;
    (void) self |> "test compound statement no param" |> {
        self->data1->data2->a = 422;
    }
    (void) self |> "test compound statement one param" |> (int): a, (int): b |> {
        self->data1->data2->a = a;
    }
    message "test message block" |> return 42;
    message "test message compound" |> {
        return 43;
    }
}

void main(void) {
    return 0;
}
