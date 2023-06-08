// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dump_messages:msg/DumpCNP.idl
// generated code does not contain a copyright notice
#include "dump_messages/msg/detail/dump_cnp__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
dump_messages__msg__DumpCNP__init(dump_messages__msg__DumpCNP * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // operational
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    dump_messages__msg__DumpCNP__fini(msg);
    return false;
  }
  return true;
}

void
dump_messages__msg__DumpCNP__fini(dump_messages__msg__DumpCNP * msg)
{
  if (!msg) {
    return;
  }
  // id
  // operational
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
}

bool
dump_messages__msg__DumpCNP__are_equal(const dump_messages__msg__DumpCNP * lhs, const dump_messages__msg__DumpCNP * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // operational
  if (lhs->operational != rhs->operational) {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  return true;
}

bool
dump_messages__msg__DumpCNP__copy(
  const dump_messages__msg__DumpCNP * input,
  dump_messages__msg__DumpCNP * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // operational
  output->operational = input->operational;
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  return true;
}

dump_messages__msg__DumpCNP *
dump_messages__msg__DumpCNP__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dump_messages__msg__DumpCNP * msg = (dump_messages__msg__DumpCNP *)allocator.allocate(sizeof(dump_messages__msg__DumpCNP), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dump_messages__msg__DumpCNP));
  bool success = dump_messages__msg__DumpCNP__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dump_messages__msg__DumpCNP__destroy(dump_messages__msg__DumpCNP * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dump_messages__msg__DumpCNP__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dump_messages__msg__DumpCNP__Sequence__init(dump_messages__msg__DumpCNP__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dump_messages__msg__DumpCNP * data = NULL;

  if (size) {
    data = (dump_messages__msg__DumpCNP *)allocator.zero_allocate(size, sizeof(dump_messages__msg__DumpCNP), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dump_messages__msg__DumpCNP__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dump_messages__msg__DumpCNP__fini(&data[i - 1]);
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
dump_messages__msg__DumpCNP__Sequence__fini(dump_messages__msg__DumpCNP__Sequence * array)
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
      dump_messages__msg__DumpCNP__fini(&array->data[i]);
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

dump_messages__msg__DumpCNP__Sequence *
dump_messages__msg__DumpCNP__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dump_messages__msg__DumpCNP__Sequence * array = (dump_messages__msg__DumpCNP__Sequence *)allocator.allocate(sizeof(dump_messages__msg__DumpCNP__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dump_messages__msg__DumpCNP__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dump_messages__msg__DumpCNP__Sequence__destroy(dump_messages__msg__DumpCNP__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dump_messages__msg__DumpCNP__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dump_messages__msg__DumpCNP__Sequence__are_equal(const dump_messages__msg__DumpCNP__Sequence * lhs, const dump_messages__msg__DumpCNP__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dump_messages__msg__DumpCNP__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dump_messages__msg__DumpCNP__Sequence__copy(
  const dump_messages__msg__DumpCNP__Sequence * input,
  dump_messages__msg__DumpCNP__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dump_messages__msg__DumpCNP);
    dump_messages__msg__DumpCNP * data =
      (dump_messages__msg__DumpCNP *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dump_messages__msg__DumpCNP__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          dump_messages__msg__DumpCNP__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dump_messages__msg__DumpCNP__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
