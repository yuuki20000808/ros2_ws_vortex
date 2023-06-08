// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from dump_messages:msg/ExPosAndTeamNumber.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "dump_messages/msg/detail/ex_pos_and_team_number__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace dump_messages
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ExPosAndTeamNumber_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dump_messages::msg::ExPosAndTeamNumber(_init);
}

void ExPosAndTeamNumber_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dump_messages::msg::ExPosAndTeamNumber *>(message_memory);
  typed_message->~ExPosAndTeamNumber();
}

size_t size_function__ExPosAndTeamNumber__dumpsite(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ExPosAndTeamNumber__dumpsite(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__ExPosAndTeamNumber__dumpsite(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void resize_function__ExPosAndTeamNumber__dumpsite(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ExPosAndTeamNumber_message_member_array[3] = {
  {
    "team",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dump_messages::msg::ExPosAndTeamNumber, team),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<turtlesim::msg::Pose>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dump_messages::msg::ExPosAndTeamNumber, pos),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "dumpsite",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dump_messages::msg::ExPosAndTeamNumber, dumpsite),  // bytes offset in struct
    nullptr,  // default value
    size_function__ExPosAndTeamNumber__dumpsite,  // size() function pointer
    get_const_function__ExPosAndTeamNumber__dumpsite,  // get_const(index) function pointer
    get_function__ExPosAndTeamNumber__dumpsite,  // get(index) function pointer
    resize_function__ExPosAndTeamNumber__dumpsite  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ExPosAndTeamNumber_message_members = {
  "dump_messages::msg",  // message namespace
  "ExPosAndTeamNumber",  // message name
  3,  // number of fields
  sizeof(dump_messages::msg::ExPosAndTeamNumber),
  ExPosAndTeamNumber_message_member_array,  // message members
  ExPosAndTeamNumber_init_function,  // function to initialize message memory (memory has to be allocated)
  ExPosAndTeamNumber_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ExPosAndTeamNumber_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExPosAndTeamNumber_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace dump_messages


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<dump_messages::msg::ExPosAndTeamNumber>()
{
  return &::dump_messages::msg::rosidl_typesupport_introspection_cpp::ExPosAndTeamNumber_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dump_messages, msg, ExPosAndTeamNumber)() {
  return &::dump_messages::msg::rosidl_typesupport_introspection_cpp::ExPosAndTeamNumber_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
