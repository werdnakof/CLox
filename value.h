#ifndef clox_value_h
#define clox_value_h

#include "common.h"

typedef enum {
    VAL_BOOL,
    VAL_NIL,
    VAL_NUMBER
} ValueType; // 4 bytes

typedef struct { 
    ValueType type; // 4 bytes
    union {
        bool boolean;
        double number;
    } as; // union size is based on longest field i.e. double - has 8 bytes 
} Value; // total of 16 bytes in a 64 bit machine, with 4 bytes of padding

// Macros for creating Value
#define BOOL_VAL(value)  ((Value){ VAL_BOOL, { .boolean = value }})
#define NIL_VAL          ((Value){ VAL_NIL,  { .number = 0}})
#define NUMBER_VAL(value)((Value){ VAL_NUMBER, { .number = value}})

// returns actual value
#define AS_BOOL(value) ((value).as.boolean)
#define AS_NUMBER(value)((value).as.number)

// Check Value type
#define IS_BOOL(value) ((value).type == VAL_BOOL)
#define IS_NIL(value)  ((value).type == VAL_NIL)
#define IS_NUMBER(value) ((value).type == VAL_NUMBER)

typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

bool valuesEqual(Value a, Value b);
void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);

#endif