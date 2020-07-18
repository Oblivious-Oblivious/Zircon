#include "helpers.h"

hashmap *_define_class_count;

/* Turn a model into a simple struct */
struct Data {
    int a;
    int b;
} Data;

/* Convert initialize, and return a type pointer */
/* The function gets the parameters passed in the model declaration */
struct Data* Data_new(void) {
    /* Allocate space according to the struct type */
    struct Data* self = (struct Data*)malloc(sizeof(Data));

    /* Switch on the data type */
    /* If one of the base types choose a default value */
    self->a = 0;
    self->b = 0;
    /* Assign if provided in arguments */
    /* Values are assigned in order OR TODO -> NAMED ARGUMENTS */

    /* Return the new struct */
    return self;
}

/* Define a dummy _Object for wrapping struct bindings dynamically */
/* TODO -> USE VTABLES FOR CASTING INHERITED TYPE */
/* struct _Object {
    void *obj;
} _Object; */

/* Turn a protocol into a struct of function pointers */
struct Messages {
    int (*add)();
    int (*sub)();
    int (*mul)();
    int (*div)();
} Messages;

/* Turn an object to a struct continaing
    the items in the `fields` declaration */
struct Controller {
    /* Object fields */
    unsigned long id;
    char *class;

    /* Implement a `super` handler if exists */
    struct Messages *super; /* TODO -> STORE THE TYPE */

    /* Get fields */
    struct Data *data1;
} Controller;



/* If we send a message to a super class then find the stored type */
/* In our case the superclass is `Messages` */
/* Define classes and set the pointers on the `Messages` struct */
int Controller_add(struct Controller* self) {
    return self->data1->a + self->data1->b;
}
int Controller_sub(struct Controller* self) {
    return self->data1->a - self->data1->b;
}
int Controller_mul(struct Controller* self) {
    return self->data1->a * self->data1->b;
}
int Controller_div(struct Controller* self) {
    if(self->data1->b != 0)
        return self->data1->a / self->data1->b;
}

/* TODO -> USE AS VTABLE FOR OVERLOADING */
static int __Controller_setup_messages(struct Controller* self) {
    self->super->add = &Controller_add;
    self->super->sub = &Controller_sub;
    self->super->mul = &Controller_mul;
    self->super->div = &Controller_div;
}

struct Controller* Controller_new(int aValue, int bValue) {
    struct Controller *self = (struct Controller*)malloc(sizeof(struct Controller));

    /* Init super and setup function pointers */
    self->super = (struct Messages*)malloc(sizeof(Messages));
    __Controller_setup_messages(self);

    /* Run `initialize` */
    self->data1 = Data_new();
    self->data1->a = aValue;
    self->data1->b = bValue;

    return self;
}

/* Define self functions */
void Controller_set_a(struct Controller *self, int a) {
    self->data1->a = a;
}
void Controller_set_b(struct Controller *self, int b) {
    self->data1->b = b;
}

/* TODO DEFER */

int main(void) {
    struct Controller *obj = Controller_new(2, 2);
    printf("%d\n", Controller_add(obj));

    /* ANTIPATTERN */
    Controller_set_a(obj, 5);
    Controller_set_b(obj, 3);

    int res = Controller_add(obj);
    int res2 = obj->super->add(obj);
    printf("%d\n", res);
    printf("res2: %d\n", res2);

    return 0;
}
