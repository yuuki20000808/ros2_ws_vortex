// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from dump_messages:msg/DumpInfoForServer.idl
// generated code does not contain a copyright notice
#include "dump_messages/msg/detail/dump_info_for_server__rosidl_typesupport_fastrtps_cpp.hpp"
#include "dump_messages/msg/detail/dump_info_for_server__struct.hpp"

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

namespace dump_messages
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dump_messages
cdr_serialize(
  const dump_messages::msg::DumpInfoForServer & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: id
  cdr << ros_message.id;
  // Member: team
  cdr << ros_message.team;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dump_messages
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  dump_messages::msg::DumpInfoForServer & ros_message)
{
  // Member: id
  cdr >> ros_message.id;

  // Member: team
  cdr >> ros_message.team;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dump_messages
get_serialized_size(
  const dump_messages::msg::DumpInfoForServer & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: id
  {
    size_t item_size = sizeof(ros_message.id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: team
  {
    size_t item_size = sizeof(ros_message.team);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_dump_messages
max_serialized_size_DumpInfoForServer(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: id
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: team
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _DumpInfoForServer__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const dump_messages::msg::DumpInfoForServer *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _DumpInfoForServer__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<dump_messages::msg::DumpInfoForServer *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _DumpInfoForServer__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const dump_messages::msg::DumpInfoForServer *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _DumpInfoForServer__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_DumpInfoForServer(full_bounded, 0);
}

static message_type_support_callbacks_t _DumpInfoForServer__callbacks = {
  "dump_messages::msg",
  "DumpInfoForServer",
  _DumpInfoForServer__cdr_serialize,
  _DumpInfoForServer__cdr_deserialize,
  _DumpInfoForServer__get_serialized_size,
  _DumpInfoForServer__max_serialized_size
};

static rosidl_message_type_support_t _DumpInfoForServer__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DumpInfoForServer__callbacks,
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
get_message_type_support_handle<dump_messages::msg::DumpInfoForServer>()
{
  return &dump_messages::msg::typesupport_fastrtps_cpp::_DumpInfoForServer__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, dump_messages, msg, DumpInfoForServer)() {
  return &dump_messages::msg::typesupport_fastrtps_cpp::_DumpInfoForServer__handle;
}

#ifdef __cplusplus
}
#endif
