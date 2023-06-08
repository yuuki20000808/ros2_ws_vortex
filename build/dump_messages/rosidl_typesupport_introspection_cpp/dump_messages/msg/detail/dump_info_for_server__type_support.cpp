// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from dump_messages:msg/DumpInfoForServer.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "dump_messages/msg/detail/dump_info_for_server__struct.hpp"
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

void DumpInfoForServer_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dump_messages::msg::DumpInfoForServer(_init);
}

void DumpInfoForServer_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dump_messages::msg::DumpInfoForServer *>(message_memory);
  typed_message->~DumpInfoForServer();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DumpInfoForServer_message_member_array[2] = {
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dump_messages::msg::DumpInfoForServer, id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "team",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dump_messages::msg::DumpInfoForServer, team),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DumpInfoForServer_message_members = {
  "dump_messages::msg",  // message namespace
  "DumpInfoForServer",  // message name
  2,  // number of fields
  sizeof(dump_messages::msg::DumpInfoForServer),
  DumpInfoForServer_message_member_array,  // message members
  DumpInfoForServer_init_function,  // function to initialize message memory (memory has to be allocated)
  DumpInfoForServer_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DumpInfoForServer_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DumpInfoForServer_message_members,
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
get_message_type_support_handle<dump_messages::msg::DumpInfoForServer>()
{
  return &::dump_messages::msg::rosidl_typesupport_introspection_cpp::DumpInfoForServer_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dump_messages, msg, DumpInfoForServer)() {
  return &::dump_messages::msg::rosidl_typesupport_introspection_cpp::DumpInfoForServer_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
