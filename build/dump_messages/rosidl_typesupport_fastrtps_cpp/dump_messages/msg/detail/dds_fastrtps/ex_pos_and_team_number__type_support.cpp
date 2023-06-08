// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from dump_messages:msg/ExPosAndTeamNumber.idl
// generated code does not contain a copyright notice
#include "dump_messages/msg/detail/ex_pos_and_team_number__rosidl_typesupport_fastrtps_cpp.hpp"
#include "dump_messages/msg/detail/ex_pos_and_team_number__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace turtlesim
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const turtlesim::msg::Pose &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  turtlesim::msg::Pose &);
size_t get_serialized_size(
  const turtlesim::msg::Pose &,
  size_t current_alignment);
size_t
max_serialized_size_Pose(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace turtlesim


namespace dump_messages
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dump_messages
cdr_serialize(
  const dump_messages::msg::ExPosAndTeamNumber & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: team
  cdr << ros_message.team;
  // Member: pos
  turtlesim::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.pos,
    cdr);
  // Member: dumpsite
  {
    cdr << ros_message.dumpsite;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dump_messages
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  dump_messages::msg::ExPosAndTeamNumber & ros_message)
{
  // Member: team
  cdr >> ros_message.team;

  // Member: pos
  turtlesim::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.pos);

  // Member: dumpsite
  {
    cdr >> ros_message.dumpsite;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dump_messages
get_serialized_size(
  const dump_messages::msg::ExPosAndTeamNumber & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: team
  {
    size_t item_size = sizeof(ros_message.team);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pos

  current_alignment +=
    turtlesim::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.pos, current_alignment);
  // Member: dumpsite
  {
    size_t array_size = ros_message.dumpsite.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.dumpsite[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dump_messages
max_serialized_size_ExPosAndTeamNumber(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: team
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: pos
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        turtlesim::msg::typesupport_fastrtps_cpp::max_serialized_size_Pose(
        full_bounded, current_alignment);
    }
  }

  // Member: dumpsite
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

static bool _ExPosAndTeamNumber__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const dump_messages::msg::ExPosAndTeamNumber *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ExPosAndTeamNumber__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<dump_messages::msg::ExPosAndTeamNumber *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ExPosAndTeamNumber__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const dump_messages::msg::ExPosAndTeamNumber *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ExPosAndTeamNumber__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ExPosAndTeamNumber(full_bounded, 0);
}

static message_type_support_callbacks_t _ExPosAndTeamNumber__callbacks = {
  "dump_messages::msg",
  "ExPosAndTeamNumber",
  _ExPosAndTeamNumber__cdr_serialize,
  _ExPosAndTeamNumber__cdr_deserialize,
  _ExPosAndTeamNumber__get_serialized_size,
  _ExPosAndTeamNumber__max_serialized_size
};

static rosidl_message_type_support_t _ExPosAndTeamNumber__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ExPosAndTeamNumber__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace dump_messages

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_dump_messages
const rosidl_message_type_support_t *
get_message_type_support_handle<dump_messages::msg::ExPosAndTeamNumber>()
{
  return &dump_messages::msg::typesupport_fastrtps_cpp::_ExPosAndTeamNumber__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dump_messages, msg, ExPosAndTeamNumber)() {
  return &dump_messages::msg::typesupport_fastrtps_cpp::_ExPosAndTeamNumber__handle;
}

#ifdef __cplusplus
}
#endif
