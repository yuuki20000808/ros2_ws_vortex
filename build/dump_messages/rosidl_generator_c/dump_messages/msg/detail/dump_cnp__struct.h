// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dump_messages:msg/DumpCNP.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__MSG__DETAIL__DUMP_CNP__STRUCT_H_
#define DUMP_MESSAGES__MSG__DETAIL__DUMP_CNP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

// Struct defined in msg/DumpCNP in the package dump_messages.
typedef struct dump_messages__msg__DumpCNP
{
  int64_t id;
  bool operational;
  geometry_msgs__msg__Point position;
} dump_messages__msg__DumpCNP;

// Struct for a sequence of dump_messages__msg__DumpCNP.
typedef struct dump_messages__msg__DumpCNP__Sequence
{
  dump_messages__msg__DumpCNP * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dump_messages__msg__DumpCNP__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DUMP_MESSAGES__MSG__DETAIL__DUMP_CNP__STRUCT_H_
