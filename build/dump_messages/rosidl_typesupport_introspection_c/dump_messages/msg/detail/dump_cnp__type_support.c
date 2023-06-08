// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dump_messages:msg/DumpCNP.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dump_messages/msg/detail/dump_cnp__rosidl_typesupport_introspection_c.h"
#include "dump_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dump_messages/msg/detail/dump_cnp__functions.h"
#include "dump_messages/msg/detail/dump_cnp__struct.h"


// Include directives for member types
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void DumpCNP__rosidl_typesupport_introspection_c__DumpCNP_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dump_messages__msg__DumpCNP__init(message_memory);
}

void DumpCNP__rosidl_typesupport_introspection_c__DumpCNP_fini_function(void * message_memory)
{
  dump_messages__msg__DumpCNP__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember DumpCNP__rosidl_typesupport_introspection_c__DumpCNP_message_member_array[3] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dump_messages__msg__DumpCNP, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "operational",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dump_messages__msg__DumpCNP, operational),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dump_messages__msg__DumpCNP, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers DumpCNP__rosidl_typesupport_introspection_c__DumpCNP_message_members = {
  "dump_messages__msg",  // message namespace
  "DumpCNP",  // message name
  3,  // number of fields
  sizeof(dump_messages__msg__DumpCNP),
  DumpCNP__rosidl_typesupport_introspection_c__DumpCNP_message_member_array,  // message members
  DumpCNP__rosidl_typesupport_introspection_c__DumpCNP_init_function,  // function to initialize message memory (memory has to be allocated)
  DumpCNP__rosidl_typesupport_introspection_c__DumpCNP_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t DumpCNP__rosidl_typesupport_introspection_c__DumpCNP_message_type_support_handle = {
  0,
  &DumpCNP__rosidl_typesupport_introspection_c__DumpCNP_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dump_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dump_messages, msg, DumpCNP)() {
  DumpCNP__rosidl_typesupport_introspection_c__DumpCNP_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!DumpCNP__rosidl_typesupport_introspection_c__DumpCNP_message_type_support_handle.typesupport_identifier) {
    DumpCNP__rosidl_typesupport_introspection_c__DumpCNP_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &DumpCNP__rosidl_typesupport_introspection_c__DumpCNP_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
