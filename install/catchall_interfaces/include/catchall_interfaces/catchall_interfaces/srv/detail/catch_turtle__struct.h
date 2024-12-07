// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from catchall_interfaces:srv/CatchTurtle.idl
// generated code does not contain a copyright notice

#ifndef CATCHALL_INTERFACES__SRV__DETAIL__CATCH_TURTLE__STRUCT_H_
#define CATCHALL_INTERFACES__SRV__DETAIL__CATCH_TURTLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/CatchTurtle in the package catchall_interfaces.
typedef struct catchall_interfaces__srv__CatchTurtle_Request
{
  rosidl_runtime_c__String name;
} catchall_interfaces__srv__CatchTurtle_Request;

// Struct for a sequence of catchall_interfaces__srv__CatchTurtle_Request.
typedef struct catchall_interfaces__srv__CatchTurtle_Request__Sequence
{
  catchall_interfaces__srv__CatchTurtle_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} catchall_interfaces__srv__CatchTurtle_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/CatchTurtle in the package catchall_interfaces.
typedef struct catchall_interfaces__srv__CatchTurtle_Response
{
  bool success;
} catchall_interfaces__srv__CatchTurtle_Response;

// Struct for a sequence of catchall_interfaces__srv__CatchTurtle_Response.
typedef struct catchall_interfaces__srv__CatchTurtle_Response__Sequence
{
  catchall_interfaces__srv__CatchTurtle_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} catchall_interfaces__srv__CatchTurtle_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CATCHALL_INTERFACES__SRV__DETAIL__CATCH_TURTLE__STRUCT_H_
