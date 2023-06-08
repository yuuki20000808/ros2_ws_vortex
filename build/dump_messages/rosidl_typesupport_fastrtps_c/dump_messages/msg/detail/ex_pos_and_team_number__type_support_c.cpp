// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from dump_messages:msg/ExPosAndTeamNumber.idl
// generated code does not contain a copyright notice
#include "dump_messages/msg/detail/ex_pos_and_team_number__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "dump_messages/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "dump_messages/msg/detail/ex_pos_and_team_number__struct.h"
#include "dump_messages/msg/detail/ex_pos_and_team_number__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // dumpsite
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // dumpsite
#include "turtlesim/msg/detail/pose__functions.h"  // pos

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dump_messages
size_t get_serialized_size_turtlesim__msg__Pose(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dump_messages
size_t max_serialized_size_turtlesim__msg__Pose(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_dump_messages
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, turtlesim, msg, Pose)();


using _ExPosAndTeamNumber__ros_msg_type = dump_messages__msg__ExPosAndTeamNumber;

static bool _ExPosAndTeamNumber__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ExPosAndTeamNumber__ros_msg_type * ros_message = static_cast<const _ExPosAndTeamNumber__ros_msg_type *>(untyped_ros_message);
  // Field name: team
  {
    cdr << ros_message->team;
  }

  // Field name: pos
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, turtlesim, msg, Pose
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->pos, cdr))
    {
      return false;
    }
  }

  // Field name: dumpsite
  {
    size_t size = ros_message->dumpsite.size;
    auto array_ptr = ros_message->dumpsite.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _ExPosAndTeamNumber__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ExPosAndTeamNumber__ros_msg_type * ros_message = static_cast<_ExPosAndTeamNumber__ros_msg_type *>(untyped_ros_message);
  // Field name: team
  {
    cdr >> ros_message->team;
  }

  // Field name: pos
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, turtlesim, msg, Pose
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->pos))
    {
      return false;
    }
  }

  // Field name: dumpsite
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->dumpsite.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->dumpsite);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->dumpsite, size)) {
      return "failed to create array for field 'dumpsite'";
    }
    auto array_ptr = ros_message->dumpsite.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dump_messages
size_t get_serialized_size_dump_messages__msg__ExPosAndTeamNumber(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ExPosAndTeamNumber__ros_msg_type * ros_message = static_cast<const _ExPosAndTeamNumber__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name team
  {
    size_t item_size = sizeof(ros_message->team);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pos

  current_alignment += get_serialized_size_turtlesim__msg__Pose(
    &(ros_message->pos), current_alignment);
  // field.name dumpsite
  {
    size_t array_size = ros_message->dumpsite.size;
    auto array_ptr = ros_message->dumpsite.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ExPosAndTeamNumber__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_dump_messages__msg__ExPosAndTeamNumber(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_dump_messages
size_t max_serialized_size_dump_messages__msg__ExPosAndTeamNumber(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: team
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: pos
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_turtlesim__msg__Pose(
        full_bounded, current_alignment);
    }
  }
  // member: dumpsite
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _ExPosAndTeamNumber__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_dump_messages__msg__ExPosAndTeamNumber(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ExPosAndTeamNumber = {
  "dump_messages::msg",
  "ExPosAndTeamNumber",
  _ExPosAndTeamNumber__cdr_serialize,
  _ExPosAndTeamNumber__cdr_deserialize,
  _ExPosAndTeamNumber__get_serialized_size,
  _ExPosAndTeamNumber__max_serialized_size
};

static rosidl_message_type_support_t _ExPosAndTeamNumber__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ExPosAndTeamNumber,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, dump_messages, msg, ExPosAndTeamNumber)() {
  return &_ExPosAndTeamNumber__type_support;
}

#if defined(__cplusplus)
}
#endif
