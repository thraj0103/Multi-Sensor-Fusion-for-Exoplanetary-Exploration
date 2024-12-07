// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from catchall_interfaces:srv/CatchTurtle.idl
// generated code does not contain a copyright notice
#include "catchall_interfaces/srv/detail/catch_turtle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"

bool
catchall_interfaces__srv__CatchTurtle_Request__init(catchall_interfaces__srv__CatchTurtle_Request * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    catchall_interfaces__srv__CatchTurtle_Request__fini(msg);
    return false;
  }
  return true;
}

void
catchall_interfaces__srv__CatchTurtle_Request__fini(catchall_interfaces__srv__CatchTurtle_Request * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
}

bool
catchall_interfaces__srv__CatchTurtle_Request__are_equal(const catchall_interfaces__srv__CatchTurtle_Request * lhs, const catchall_interfaces__srv__CatchTurtle_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  return true;
}

bool
catchall_interfaces__srv__CatchTurtle_Request__copy(
  const catchall_interfaces__srv__CatchTurtle_Request * input,
  catchall_interfaces__srv__CatchTurtle_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  return true;
}

catchall_interfaces__srv__CatchTurtle_Request *
catchall_interfaces__srv__CatchTurtle_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  catchall_interfaces__srv__CatchTurtle_Request * msg = (catchall_interfaces__srv__CatchTurtle_Request *)allocator.allocate(sizeof(catchall_interfaces__srv__CatchTurtle_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(catchall_interfaces__srv__CatchTurtle_Request));
  bool success = catchall_interfaces__srv__CatchTurtle_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
catchall_interfaces__srv__CatchTurtle_Request__destroy(catchall_interfaces__srv__CatchTurtle_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    catchall_interfaces__srv__CatchTurtle_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
catchall_interfaces__srv__CatchTurtle_Request__Sequence__init(catchall_interfaces__srv__CatchTurtle_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  catchall_interfaces__srv__CatchTurtle_Request * data = NULL;

  if (size) {
    data = (catchall_interfaces__srv__CatchTurtle_Request *)allocator.zero_allocate(size, sizeof(catchall_interfaces__srv__CatchTurtle_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = catchall_interfaces__srv__CatchTurtle_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        catchall_interfaces__srv__CatchTurtle_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
catchall_interfaces__srv__CatchTurtle_Request__Sequence__fini(catchall_interfaces__srv__CatchTurtle_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      catchall_interfaces__srv__CatchTurtle_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

catchall_interfaces__srv__CatchTurtle_Request__Sequence *
catchall_interfaces__srv__CatchTurtle_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  catchall_interfaces__srv__CatchTurtle_Request__Sequence * array = (catchall_interfaces__srv__CatchTurtle_Request__Sequence *)allocator.allocate(sizeof(catchall_interfaces__srv__CatchTurtle_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = catchall_interfaces__srv__CatchTurtle_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
catchall_interfaces__srv__CatchTurtle_Request__Sequence__destroy(catchall_interfaces__srv__CatchTurtle_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    catchall_interfaces__srv__CatchTurtle_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
catchall_interfaces__srv__CatchTurtle_Request__Sequence__are_equal(const catchall_interfaces__srv__CatchTurtle_Request__Sequence * lhs, const catchall_interfaces__srv__CatchTurtle_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!catchall_interfaces__srv__CatchTurtle_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
catchall_interfaces__srv__CatchTurtle_Request__Sequence__copy(
  const catchall_interfaces__srv__CatchTurtle_Request__Sequence * input,
  catchall_interfaces__srv__CatchTurtle_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(catchall_interfaces__srv__CatchTurtle_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    catchall_interfaces__srv__CatchTurtle_Request * data =
      (catchall_interfaces__srv__CatchTurtle_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!catchall_interfaces__srv__CatchTurtle_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          catchall_interfaces__srv__CatchTurtle_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!catchall_interfaces__srv__CatchTurtle_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
catchall_interfaces__srv__CatchTurtle_Response__init(catchall_interfaces__srv__CatchTurtle_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
catchall_interfaces__srv__CatchTurtle_Response__fini(catchall_interfaces__srv__CatchTurtle_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
catchall_interfaces__srv__CatchTurtle_Response__are_equal(const catchall_interfaces__srv__CatchTurtle_Response * lhs, const catchall_interfaces__srv__CatchTurtle_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
catchall_interfaces__srv__CatchTurtle_Response__copy(
  const catchall_interfaces__srv__CatchTurtle_Response * input,
  catchall_interfaces__srv__CatchTurtle_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

catchall_interfaces__srv__CatchTurtle_Response *
catchall_interfaces__srv__CatchTurtle_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  catchall_interfaces__srv__CatchTurtle_Response * msg = (catchall_interfaces__srv__CatchTurtle_Response *)allocator.allocate(sizeof(catchall_interfaces__srv__CatchTurtle_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(catchall_interfaces__srv__CatchTurtle_Response));
  bool success = catchall_interfaces__srv__CatchTurtle_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
catchall_interfaces__srv__CatchTurtle_Response__destroy(catchall_interfaces__srv__CatchTurtle_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    catchall_interfaces__srv__CatchTurtle_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
catchall_interfaces__srv__CatchTurtle_Response__Sequence__init(catchall_interfaces__srv__CatchTurtle_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  catchall_interfaces__srv__CatchTurtle_Response * data = NULL;

  if (size) {
    data = (catchall_interfaces__srv__CatchTurtle_Response *)allocator.zero_allocate(size, sizeof(catchall_interfaces__srv__CatchTurtle_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = catchall_interfaces__srv__CatchTurtle_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        catchall_interfaces__srv__CatchTurtle_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
catchall_interfaces__srv__CatchTurtle_Response__Sequence__fini(catchall_interfaces__srv__CatchTurtle_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      catchall_interfaces__srv__CatchTurtle_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

catchall_interfaces__srv__CatchTurtle_Response__Sequence *
catchall_interfaces__srv__CatchTurtle_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  catchall_interfaces__srv__CatchTurtle_Response__Sequence * array = (catchall_interfaces__srv__CatchTurtle_Response__Sequence *)allocator.allocate(sizeof(catchall_interfaces__srv__CatchTurtle_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = catchall_interfaces__srv__CatchTurtle_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
catchall_interfaces__srv__CatchTurtle_Response__Sequence__destroy(catchall_interfaces__srv__CatchTurtle_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    catchall_interfaces__srv__CatchTurtle_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
catchall_interfaces__srv__CatchTurtle_Response__Sequence__are_equal(const catchall_interfaces__srv__CatchTurtle_Response__Sequence * lhs, const catchall_interfaces__srv__CatchTurtle_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!catchall_interfaces__srv__CatchTurtle_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
catchall_interfaces__srv__CatchTurtle_Response__Sequence__copy(
  const catchall_interfaces__srv__CatchTurtle_Response__Sequence * input,
  catchall_interfaces__srv__CatchTurtle_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(catchall_interfaces__srv__CatchTurtle_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    catchall_interfaces__srv__CatchTurtle_Response * data =
      (catchall_interfaces__srv__CatchTurtle_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!catchall_interfaces__srv__CatchTurtle_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          catchall_interfaces__srv__CatchTurtle_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!catchall_interfaces__srv__CatchTurtle_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
