// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from catchall_interfaces:msg/TurtleArray.idl
// generated code does not contain a copyright notice

#ifndef CATCHALL_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__STRUCT_H_
#define CATCHALL_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'turtles'
#include "catchall_interfaces/msg/detail/turtle__struct.h"

/// Struct defined in msg/TurtleArray in the package catchall_interfaces.
typedef struct catchall_interfaces__msg__TurtleArray
{
  catchall_interfaces__msg__Turtle__Sequence turtles;
} catchall_interfaces__msg__TurtleArray;

// Struct for a sequence of catchall_interfaces__msg__TurtleArray.
typedef struct catchall_interfaces__msg__TurtleArray__Sequence
{
  catchall_interfaces__msg__TurtleArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} catchall_interfaces__msg__TurtleArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CATCHALL_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__STRUCT_H_
