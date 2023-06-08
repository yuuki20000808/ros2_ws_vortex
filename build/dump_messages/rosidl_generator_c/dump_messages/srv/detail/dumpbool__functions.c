// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dump_messages:srv/Dumpbool.idl
// generated code does not contain a copyright notice
#include "dump_messages/srv/detail/dumpbool__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
dump_messages__srv__Dumpbool_Request__init(dump_messages__srv__Dumpbool_Request * msg)
{
  if (!msg) {
    return false;
  }
  // request
  return true;
}

void
dump_messages__srv__Dumpbool_Request__fini(dump_messages__srv__Dumpbool_Request * msg)
{
  if (!msg) {
    return;
  }
  // request
}

bool
dump_messages__srv__Dumpbool_Request__are_equal(const dump_messages__srv__Dumpbool_Request * lhs, const dump_messages__srv__Dumpbool_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // request
  if (lhs->request != rhs->request) {
    return false;
  }
  return true;
}

bool
dump_messages__srv__Dumpbool_Request__copy(
  const dump_messages__srv__Dumpbool_Request * input,
  dump_messages__srv__Dumpbool_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // request
  output->request = input->request;
  return true;
}

dump_messages__srv__Dumpbool_Request *
dump_messages__srv__Dumpbool_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dump_messages__srv__Dumpbool_Request * msg = (dump_messages__srv__Dumpbool_Request *)allocator.allocate(sizeof(dump_messages__srv__Dumpbool_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dump_messages__srv__Dumpbool_Request));
  bool success = dump_messages__srv__Dumpbool_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dump_messages__srv__Dumpbool_Request__destroy(dump_messages__srv__Dumpbool_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dump_messages__srv__Dumpbool_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dump_messages__srv__Dumpbool_Request__Sequence__init(dump_messages__srv__Dumpbool_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dump_messages__srv__Dumpbool_Request * data = NULL;

  if (size) {
    data = (dump_messages__srv__Dumpbool_Request *)allocator.zero_allocate(size, sizeof(dump_messages__srv__Dumpbool_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dump_messages__srv__Dumpbool_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dump_messages__srv__Dumpbool_Request__fini(&data[i - 1]);
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
dump_messages__srv__Dumpbool_Request__Sequence__fini(dump_messages__srv__Dumpbool_Request__Sequence * array)
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
      dump_messages__srv__Dumpbool_Request__fini(&array->data[i]);
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

dump_messages__srv__Dumpbool_Request__Sequence *
dump_messages__srv__Dumpbool_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dump_messages__srv__Dumpbool_Request__Sequence * array = (dump_messages__srv__Dumpbool_Request__Sequence *)allocator.allocate(sizeof(dump_messages__srv__Dumpbool_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dump_messages__srv__Dumpbool_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dump_messages__srv__Dumpbool_Request__Sequence__destroy(dump_messages__srv__Dumpbool_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dump_messages__srv__Dumpbool_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dump_messages__srv__Dumpbool_Request__Sequence__are_equal(const dump_messages__srv__Dumpbool_Request__Sequence * lhs, const dump_messages__srv__Dumpbool_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dump_messages__srv__Dumpbool_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dump_messages__srv__Dumpbool_Request__Sequence__copy(
  const dump_messages__srv__Dumpbool_Request__Sequence * input,
  dump_messages__srv__Dumpbool_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dump_messages__srv__Dumpbool_Request);
    dump_messages__srv__Dumpbool_Request * data =
      (dump_messages__srv__Dumpbool_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dump_messages__srv__Dumpbool_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          dump_messages__srv__Dumpbool_Request__fini(&data[i]);
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
    if (!dump_messages__srv__Dumpbool_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
dump_messages__srv__Dumpbool_Response__init(dump_messages__srv__Dumpbool_Response * msg)
{
  if (!msg) {
    return false;
  }
  // bit
  return true;
}

void
dump_messages__srv__Dumpbool_Response__fini(dump_messages__srv__Dumpbool_Response * msg)
{
  if (!msg) {
    return;
  }
  // bit
}

bool
dump_messages__srv__Dumpbool_Response__are_equal(const dump_messages__srv__Dumpbool_Response * lhs, const dump_messages__srv__Dumpbool_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // bit
  if (lhs->bit != rhs->bit) {
    return false;
  }
  return true;
}

bool
dump_messages__srv__Dumpbool_Response__copy(
  const dump_messages__srv__Dumpbool_Response * input,
  dump_messages__srv__Dumpbool_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // bit
  output->bit = input->bit;
  return true;
}

dump_messages__srv__Dumpbool_Response *
dump_messages__srv__Dumpbool_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dump_messages__srv__Dumpbool_Response * msg = (dump_messages__srv__Dumpbool_Response *)allocator.allocate(sizeof(dump_messages__srv__Dumpbool_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dump_messages__srv__Dumpbool_Response));
  bool success = dump_messages__srv__Dumpbool_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dump_messages__srv__Dumpbool_Response__destroy(dump_messages__srv__Dumpbool_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dump_messages__srv__Dumpbool_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dump_messages__srv__Dumpbool_Response__Sequence__init(dump_messages__srv__Dumpbool_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dump_messages__srv__Dumpbool_Response * data = NULL;

  if (size) {
    data = (dump_messages__srv__Dumpbool_Response *)allocator.zero_allocate(size, sizeof(dump_messages__srv__Dumpbool_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dump_messages__srv__Dumpbool_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dump_messages__srv__Dumpbool_Response__fini(&data[i - 1]);
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
dump_messages__srv__Dumpbool_Response__Sequence__fini(dump_messages__srv__Dumpbool_Response__Sequence * array)
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
      dump_messages__srv__Dumpbool_Response__fini(&array->data[i]);
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

dump_messages__srv__Dumpbool_Response__Sequence *
dump_messages__srv__Dumpbool_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dump_messages__srv__Dumpbool_Response__Sequence * array = (dump_messages__srv__Dumpbool_Response__Sequence *)allocator.allocate(sizeof(dump_messages__srv__Dumpbool_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dump_messages__srv__Dumpbool_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dump_messages__srv__Dumpbool_Response__Sequence__destroy(dump_messages__srv__Dumpbool_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dump_messages__srv__Dumpbool_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dump_messages__srv__Dumpbool_Response__Sequence__are_equal(const dump_messages__srv__Dumpbool_Response__Sequence * lhs, const dump_messages__srv__Dumpbool_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dump_messages__srv__Dumpbool_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dump_messages__srv__Dumpbool_Response__Sequence__copy(
  const dump_messages__srv__Dumpbool_Response__Sequence * input,
  dump_messages__srv__Dumpbool_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dump_messages__srv__Dumpbool_Response);
    dump_messages__srv__Dumpbool_Response * data =
      (dump_messages__srv__Dumpbool_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dump_messages__srv__Dumpbool_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          dump_messages__srv__Dumpbool_Response__fini(&data[i]);
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
    if (!dump_messages__srv__Dumpbool_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
