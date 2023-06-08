// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dump_messages:msg/ExPosAndTeamNumber.idl
// generated code does not contain a copyright notice
#include "dump_messages/msg/detail/ex_pos_and_team_number__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pos`
#include "turtlesim/msg/detail/pose__functions.h"
// Member `dumpsite`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
dump_messages__msg__ExPosAndTeamNumber__init(dump_messages__msg__ExPosAndTeamNumber * msg)
{
  if (!msg) {
    return false;
  }
  // team
  // pos
  if (!turtlesim__msg__Pose__init(&msg->pos)) {
    dump_messages__msg__ExPosAndTeamNumber__fini(msg);
    return false;
  }
  // dumpsite
  if (!rosidl_runtime_c__float__Sequence__init(&msg->dumpsite, 0)) {
    dump_messages__msg__ExPosAndTeamNumber__fini(msg);
    return false;
  }
  return true;
}

void
dump_messages__msg__ExPosAndTeamNumber__fini(dump_messages__msg__ExPosAndTeamNumber * msg)
{
  if (!msg) {
    return;
  }
  // team
  // pos
  turtlesim__msg__Pose__fini(&msg->pos);
  // dumpsite
  rosidl_runtime_c__float__Sequence__fini(&msg->dumpsite);
}

bool
dump_messages__msg__ExPosAndTeamNumber__are_equal(const dump_messages__msg__ExPosAndTeamNumber * lhs, const dump_messages__msg__ExPosAndTeamNumber * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // team
  if (lhs->team != rhs->team) {
    return false;
  }
  // pos
  if (!turtlesim__msg__Pose__are_equal(
      &(lhs->pos), &(rhs->pos)))
  {
    return false;
  }
  // dumpsite
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->dumpsite), &(rhs->dumpsite)))
  {
    return false;
  }
  return true;
}

bool
dump_messages__msg__ExPosAndTeamNumber__copy(
  const dump_messages__msg__ExPosAndTeamNumber * input,
  dump_messages__msg__ExPosAndTeamNumber * output)
{
  if (!input || !output) {
    return false;
  }
  // team
  output->team = input->team;
  // pos
  if (!turtlesim__msg__Pose__copy(
      &(input->pos), &(output->pos)))
  {
    return false;
  }
  // dumpsite
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->dumpsite), &(output->dumpsite)))
  {
    return false;
  }
  return true;
}

dump_messages__msg__ExPosAndTeamNumber *
dump_messages__msg__ExPosAndTeamNumber__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dump_messages__msg__ExPosAndTeamNumber * msg = (dump_messages__msg__ExPosAndTeamNumber *)allocator.allocate(sizeof(dump_messages__msg__ExPosAndTeamNumber), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dump_messages__msg__ExPosAndTeamNumber));
  bool success = dump_messages__msg__ExPosAndTeamNumber__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dump_messages__msg__ExPosAndTeamNumber__destroy(dump_messages__msg__ExPosAndTeamNumber * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dump_messages__msg__ExPosAndTeamNumber__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dump_messages__msg__ExPosAndTeamNumber__Sequence__init(dump_messages__msg__ExPosAndTeamNumber__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dump_messages__msg__ExPosAndTeamNumber * data = NULL;

  if (size) {
    data = (dump_messages__msg__ExPosAndTeamNumber *)allocator.zero_allocate(size, sizeof(dump_messages__msg__ExPosAndTeamNumber), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dump_messages__msg__ExPosAndTeamNumber__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dump_messages__msg__ExPosAndTeamNumber__fini(&data[i - 1]);
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
dump_messages__msg__ExPosAndTeamNumber__Sequence__fini(dump_messages__msg__ExPosAndTeamNumber__Sequence * array)
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
      dump_messages__msg__ExPosAndTeamNumber__fini(&array->data[i]);
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

dump_messages__msg__ExPosAndTeamNumber__Sequence *
dump_messages__msg__ExPosAndTeamNumber__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dump_messages__msg__ExPosAndTeamNumber__Sequence * array = (dump_messages__msg__ExPosAndTeamNumber__Sequence *)allocator.allocate(sizeof(dump_messages__msg__ExPosAndTeamNumber__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dump_messages__msg__ExPosAndTeamNumber__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dump_messages__msg__ExPosAndTeamNumber__Sequence__destroy(dump_messages__msg__ExPosAndTeamNumber__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dump_messages__msg__ExPosAndTeamNumber__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dump_messages__msg__ExPosAndTeamNumber__Sequence__are_equal(const dump_messages__msg__ExPosAndTeamNumber__Sequence * lhs, const dump_messages__msg__ExPosAndTeamNumber__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dump_messages__msg__ExPosAndTeamNumber__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dump_messages__msg__ExPosAndTeamNumber__Sequence__copy(
  const dump_messages__msg__ExPosAndTeamNumber__Sequence * input,
  dump_messages__msg__ExPosAndTeamNumber__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dump_messages__msg__ExPosAndTeamNumber);
    dump_messages__msg__ExPosAndTeamNumber * data =
      (dump_messages__msg__ExPosAndTeamNumber *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dump_messages__msg__ExPosAndTeamNumber__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          dump_messages__msg__ExPosAndTeamNumber__fini(&data[i]);
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
    if (!dump_messages__msg__ExPosAndTeamNumber__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
