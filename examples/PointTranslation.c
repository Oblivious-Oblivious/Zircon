#include "helpers.h"

hashmap *_define_class_count;

/* Turn a model into a simple struct */
struct PointFields {
    double x;
    double y;
} PointFields;

/* Convert initialize, and return a type pointer */
/* The function gets the parameters passed in the model declaration */
struct PointFields* PointFields_new(double x, double y) {
    /* Allocate space according to the struct type */
    struct PointFields* self = (struct PointFields*)malloc(sizeof(PointFields));

    /* Switch on the data type */
    /* If one of the base types choose a default value */
    self->x = 0;
    self->y = 0;
    /* Assign if provided in arguments */
    self->x = x;
    self->y = y;
    /* Values are assigned in order OR TODO -> NAMED ARGUMENTS */

    /* Return the new struct */
    return self;
}

/* Turn an object to a struct continaing
    the items in the `fields` declaration */
struct Point {
    /* Object fields */
    unsigned long id;
    char *class;

    char *name;
    struct PointFields *coords;
} Point;

/* Initialize object base functions */
bool Point__EQEQ__(struct Point* self, struct Point* other) {
    return self->id == other->id;
}

bool Point__NOT_EQ__(struct Point* self, struct Point* other) {
    return self->id != other->id;
}

unsigned long Point_id(struct Point* self) {
    return self->id;
}

bool Point_equal(struct Point* self, struct Point* other) {
    return Point__EQEQ__(self, other);
}

/* TODO -> Override table */
/* char* Point_to_string(struct Point* self) {
    return self->class;
} */

void _object_setup(void) {
    if(!_define_class_count) _define_class_count = new_hashmap();
}

struct Point* Point_new(double x, double y) {
    /* Setup basic functionality */
    _object_setup();

    struct Point* self = (struct Point*)malloc(sizeof(Point));

    /* Initialize Object fields */
    hashmap_add(_define_class_count, "-1", "-1");
    _define_class_count->alloced++;
    self->id = _generate_id(_define_class_count, "Test_new");
    self->class = (char*)malloc(sizeof(char) * 1024);
    self->class = _generate_class_name("Test");

    /* Execute the commands of `initialize` */
    self->name = "default";
    self->coords = PointFields_new(x, y);

    return self;
}

/* Implement messages and methods */
/* TODO -> STORE MESSAGES IN A DATA STRUCTURE AND
    USE FUNCTION POINTERS TO ACCESS METHODS */
/* Add a `self` parameter in the function call according to the data type */
struct Point* Point__PLUS_MESSAGE_(struct Point* self, struct Point* other) {
    /* Allocate according to the return type of the function */
    struct Point* Point__PLUS_MESSAGE__ret_value = (struct Point*)malloc(sizeof(Point));

    /* Execute the commands inside the method */
    Point__PLUS_MESSAGE__ret_value = Point_new(self->coords->x + other->coords->x, self->coords->y + other->coords->y);

    /* Return the allocated result */    
    return Point__PLUS_MESSAGE__ret_value;
}
struct Point* Point__MINUS_MESSAGE_(struct Point* self, struct Point* other) {
    struct Point* Point__MINUS_MESSAGE__ret_value = (struct Point*)malloc(sizeof(Point));
    
    Point__MINUS_MESSAGE__ret_value = Point_new(self->coords->x - other->coords->x, self->coords->y - other->coords->y);
    
    return Point__MINUS_MESSAGE__ret_value;
}
struct Point* Point__MUL_MESSAGE_(struct Point* self, struct Point* other) {
    struct Point* Point__MUL_MESSAGE__ret_value = (struct Point*)malloc(sizeof(Point));
    
    Point__MUL_MESSAGE__ret_value = Point_new(self->coords->x * other->coords->x, self->coords->y * other->coords->y);
    
    return Point__MUL_MESSAGE__ret_value;
}
struct Point* Point__DIV_MESSAGE_(struct Point* self, struct Point* other) {
    struct Point* Point__DIV_MESSAGE__ret_value = (struct Point*)malloc(sizeof(Point));
    
    if(other->coords->x != 0 && other->coords->y != 0) {
        Point__DIV_MESSAGE__ret_value = Point_new(self->coords->x / other->coords->x, self->coords->y / other->coords->y);
        return Point__DIV_MESSAGE__ret_value;
    }
    return NULL;

    /* This gets ignored obviously */
    return Point__DIV_MESSAGE__ret_value;
}

char* Point_to_string(struct Point* self) {
    /* Allocate enough space */
    /* TODO -> STRING BUILDER IF USING A BASE TYPE POINTER */
    /* BELOW RESULTS IN A SEGFAULT, HAVE `format` HANDLE MEMORY */
    char* Point_to_string_ret_value = (char*)malloc(sizeof(char));

    /* TODO -> IMPLEMENT FORMAT CODE */
    sprintf(Point_to_string_ret_value, "P(%g, %g)",
    self->coords->x,
    self->coords->y);

    return Point_to_string_ret_value;
}

/* TODO -> DEFER */

int main(void) {
    /* Point *p1 = Point "new" 2.5, 6.4; */
    /* Point *p2 = Point "new" 2.1, 3.3; */
    /* Point *pres = p1 "+" p2; */
    /* display("res = %s\n", pres); */
    struct Point *p1 = Point_new(2.5, 6.4);
    struct Point *p2 = Point_new(2.1, 3.3);
    struct Point *pres = Point__PLUS_MESSAGE_(p1, p2);
    printf("res = %s\n", Point_to_string(pres));
}