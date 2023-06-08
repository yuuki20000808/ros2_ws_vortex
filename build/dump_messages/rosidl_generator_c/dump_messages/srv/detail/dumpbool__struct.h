// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dump_messages:srv/Dumpbool.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__SRV__DETAIL__DUMPBOOL__STRUCT_H_
#define DUMP_MESSAGES__SRV__DETAIL__DUMPBOOL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/Dumpbool in the package dump_messages.
typedef struct dump_messages__srv__Dumpbool_Request
{
  bool request;
} dump_messages__srv__Dumpbool_Request;

// Struct for a sequence of dump_messages__srv__Dumpbool_Request.
typedef struct dump_messages__srv__Dumpbool_Request__Sequence
{
  dump_messages__srv__Dumpbool_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dump_messages__srv__Dumpbool_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/Dumpbool in the package dump_messages.
typedef struct dump_messages__srv__Dumpbool_Response
{
  bool bit;
} dump_messages__srv__Dumpbool_Response;

// Struct for a sequence of dump_messages__srv__Dumpbool_Response.
typedef struct dump_messages__srv__Dumpbool_Response__Sequence
{
  dump_messages__srv__Dumpbool_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dump_messages__srv__Dumpbool_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DUMP_MESSAGES__SRV__DETAIL__DUMPBOOL__STRUCT_H_
