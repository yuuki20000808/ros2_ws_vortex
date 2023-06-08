// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dump_messages:msg/ExPosAndTeamNumber.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__MSG__DETAIL__EX_POS_AND_TEAM_NUMBER__STRUCT_H_
#define DUMP_MESSAGES__MSG__DETAIL__EX_POS_AND_TEAM_NUMBER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pos'
#include "turtlesim/msg/detail/pose__struct.h"
// Member 'dumpsite'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/ExPosAndTeamNumber in the package dump_messages.
typedef struct dump_messages__msg__ExPosAndTeamNumber
{
  int64_t team;
  turtlesim__msg__Pose pos;
  rosidl_runtime_c__float__Sequence dumpsite;
} dump_messages__msg__ExPosAndTeamNumber;

// Struct for a sequence of dump_messages__msg__ExPosAndTeamNumber.
typedef struct dump_messages__msg__ExPosAndTeamNumber__Sequence
{
  dump_messages__msg__ExPosAndTeamNumber * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dump_messages__msg__ExPosAndTeamNumber__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DUMP_MESSAGES__MSG__DETAIL__EX_POS_AND_TEAM_NUMBER__STRUCT_H_
