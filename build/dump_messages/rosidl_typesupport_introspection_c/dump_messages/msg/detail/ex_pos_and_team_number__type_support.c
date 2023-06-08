// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dump_messages:msg/ExPosAndTeamNumber.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dump_messages/msg/detail/ex_pos_and_team_number__rosidl_typesupport_introspection_c.h"
#include "dump_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dump_messages/msg/detail/ex_pos_and_team_number__functions.h"
#include "dump_messages/msg/detail/ex_pos_and_team_number__struct.h"


// Include directives for member types
// Member `pos`
#include "turtlesim/msg/pose.h"
// Member `pos`
#include "turtlesim/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `dumpsite`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ExPosAndTeamNumber__rosidl_typesupport_introspection_c__ExPosAndTeamNumber_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dump_messages__msg__ExPosAndTeamNumber__init(message_memory);
}

void ExPosAndTeamNumber__rosidl_typesupport_introspection_c__ExPosAndTeamNumber_fini_function(void * message_memory)
{
  dump_messages__msg__ExPosAndTeamNumber__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ExPosAndTeamNumber__rosidl_typesupport_introspection_c__ExPosAndTeamNumber_message_member_array[3] = {
  {
    "team",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dump_messages__msg__ExPosAndTeamNumber, team),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dump_messages__msg__ExPosAndTeamNumber, pos),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "dumpsite",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dump_messages__msg__ExPosAndTeamNumber, dumpsite),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ExPosAndTeamNumber__rosidl_typesupport_introspection_c__ExPosAndTeamNumber_message_members = {
  "dump_messages__msg",  // message namespace
  "ExPosAndTeamNumber",  // message name
  3,  // number of fields
  sizeof(dump_messages__msg__ExPosAndTeamNumber),
  ExPosAndTeamNumber__rosidl_typesupport_introspection_c__ExPosAndTeamNumber_message_member_array,  // message members
  ExPosAndTeamNumber__rosidl_typesupport_introspection_c__ExPosAndTeamNumber_init_function,  // function to initialize message memory (memory has to be allocated)
  ExPosAndTeamNumber__rosidl_typesupport_introspection_c__ExPosAndTeamNumber_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ExPosAndTeamNumber__rosidl_typesupport_introspection_c__ExPosAndTeamNumber_message_type_support_handle = {
  0,
  &ExPosAndTeamNumber__rosidl_typesupport_introspection_c__ExPosAndTeamNumber_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dump_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dump_messages, msg, ExPosAndTeamNumber)() {
  ExPosAndTeamNumber__rosidl_typesupport_introspection_c__ExPosAndTeamNumber_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, turtlesim, msg, Pose)();
  if (!ExPosAndTeamNumber__rosidl_typesupport_introspection_c__ExPosAndTeamNumber_message_type_support_handle.typesupport_identifier) {
    ExPosAndTeamNumber__rosidl_typesupport_introspection_c__ExPosAndTeamNumber_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ExPosAndTeamNumber__rosidl_typesupport_introspection_c__ExPosAndTeamNumber_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
