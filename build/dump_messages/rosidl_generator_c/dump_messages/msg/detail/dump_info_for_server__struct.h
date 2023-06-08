// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dump_messages:msg/DumpInfoForServer.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__MSG__DETAIL__DUMP_INFO_FOR_SERVER__STRUCT_H_
#define DUMP_MESSAGES__MSG__DETAIL__DUMP_INFO_FOR_SERVER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/DumpInfoForServer in the package dump_messages.
typedef struct dump_messages__msg__DumpInfoForServer
{
  int64_t id;
  int64_t team;
} dump_messages__msg__DumpInfoForServer;

// Struct for a sequence of dump_messages__msg__DumpInfoForServer.
typedef struct dump_messages__msg__DumpInfoForServer__Sequence
{
  dump_messages__msg__DumpInfoForServer * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dump_messages__msg__DumpInfoForServer__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DUMP_MESSAGES__MSG__DETAIL__DUMP_INFO_FOR_SERVER__STRUCT_H_
