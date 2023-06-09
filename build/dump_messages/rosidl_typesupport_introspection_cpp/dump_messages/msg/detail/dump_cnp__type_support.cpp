// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from dump_messages:msg/DumpCNP.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "dump_messages/msg/detail/dump_cnp__struct.hpp"
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

void DumpCNP_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dump_messages::msg::DumpCNP(_init);
}

void DumpCNP_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dump_messages::msg::DumpCNP *>(message_memory);
  typed_message->~DumpCNP();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DumpCNP_message_member_array[3] = {
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dump_messages::msg::DumpCNP, id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "operational",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dump_messages::msg::DumpCNP, operational),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Point>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dump_messages::msg::DumpCNP, position),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DumpCNP_message_members = {
  "dump_messages::msg",  // message namespace
  "DumpCNP",  // message name
  3,  // number of fields
  sizeof(dump_messages::msg::DumpCNP),
  DumpCNP_message_member_array,  // message members
  DumpCNP_init_function,  // function to initialize message memory (memory has to be allocated)
  DumpCNP_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DumpCNP_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DumpCNP_message_members,
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
get_message_type_support_handle<dump_messages::msg::DumpCNP>()
{
  return &::dump_messages::msg::rosidl_typesupport_introspection_cpp::DumpCNP_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dump_messages, msg, DumpCNP)() {
  return &::dump_messages::msg::rosidl_typesupport_introspection_cpp::DumpCNP_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
