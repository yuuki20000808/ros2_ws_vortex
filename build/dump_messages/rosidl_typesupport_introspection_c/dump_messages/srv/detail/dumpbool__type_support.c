// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dump_messages:srv/Dumpbool.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dump_messages/srv/detail/dumpbool__rosidl_typesupport_introspection_c.h"
#include "dump_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dump_messages/srv/detail/dumpbool__functions.h"
#include "dump_messages/srv/detail/dumpbool__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Dumpbool_Request__rosidl_typesupport_introspection_c__Dumpbool_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dump_messages__srv__Dumpbool_Request__init(message_memory);
}

void Dumpbool_Request__rosidl_typesupport_introspection_c__Dumpbool_Request_fini_function(void * message_memory)
{
  dump_messages__srv__Dumpbool_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Dumpbool_Request__rosidl_typesupport_introspection_c__Dumpbool_Request_message_member_array[1] = {
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dump_messages__srv__Dumpbool_Request, request),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Dumpbool_Request__rosidl_typesupport_introspection_c__Dumpbool_Request_message_members = {
  "dump_messages__srv",  // message namespace
  "Dumpbool_Request",  // message name
  1,  // number of fields
  sizeof(dump_messages__srv__Dumpbool_Request),
  Dumpbool_Request__rosidl_typesupport_introspection_c__Dumpbool_Request_message_member_array,  // message members
  Dumpbool_Request__rosidl_typesupport_introspection_c__Dumpbool_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  Dumpbool_Request__rosidl_typesupport_introspection_c__Dumpbool_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Dumpbool_Request__rosidl_typesupport_introspection_c__Dumpbool_Request_message_type_support_handle = {
  0,
  &Dumpbool_Request__rosidl_typesupport_introspection_c__Dumpbool_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dump_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dump_messages, srv, Dumpbool_Request)() {
  if (!Dumpbool_Request__rosidl_typesupport_introspection_c__Dumpbool_Request_message_type_support_handle.typesupport_identifier) {
    Dumpbool_Request__rosidl_typesupport_introspection_c__Dumpbool_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Dumpbool_Request__rosidl_typesupport_introspection_c__Dumpbool_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "dump_messages/srv/detail/dumpbool__rosidl_typesupport_introspection_c.h"
// already included above
// #include "dump_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "dump_messages/srv/detail/dumpbool__functions.h"
// already included above
// #include "dump_messages/srv/detail/dumpbool__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void Dumpbool_Response__rosidl_typesupport_introspection_c__Dumpbool_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dump_messages__srv__Dumpbool_Response__init(message_memory);
}

void Dumpbool_Response__rosidl_typesupport_introspection_c__Dumpbool_Response_fini_function(void * message_memory)
{
  dump_messages__srv__Dumpbool_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Dumpbool_Response__rosidl_typesupport_introspection_c__Dumpbool_Response_message_member_array[1] = {
  {
    "bit",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dump_messages__srv__Dumpbool_Response, bit),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Dumpbool_Response__rosidl_typesupport_introspection_c__Dumpbool_Response_message_members = {
  "dump_messages__srv",  // message namespace
  "Dumpbool_Response",  // message name
  1,  // number of fields
  sizeof(dump_messages__srv__Dumpbool_Response),
  Dumpbool_Response__rosidl_typesupport_introspection_c__Dumpbool_Response_message_member_array,  // message members
  Dumpbool_Response__rosidl_typesupport_introspection_c__Dumpbool_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  Dumpbool_Response__rosidl_typesupport_introspection_c__Dumpbool_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Dumpbool_Response__rosidl_typesupport_introspection_c__Dumpbool_Response_message_type_support_handle = {
  0,
  &Dumpbool_Response__rosidl_typesupport_introspection_c__Dumpbool_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dump_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dump_messages, srv, Dumpbool_Response)() {
  if (!Dumpbool_Response__rosidl_typesupport_introspection_c__Dumpbool_Response_message_type_support_handle.typesupport_identifier) {
    Dumpbool_Response__rosidl_typesupport_introspection_c__Dumpbool_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Dumpbool_Response__rosidl_typesupport_introspection_c__Dumpbool_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "dump_messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "dump_messages/srv/detail/dumpbool__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers dump_messages__srv__detail__dumpbool__rosidl_typesupport_introspection_c__Dumpbool_service_members = {
  "dump_messages__srv",  // service namespace
  "Dumpbool",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // dump_messages__srv__detail__dumpbool__rosidl_typesupport_introspection_c__Dumpbool_Request_message_type_support_handle,
  NULL  // response message
  // dump_messages__srv__detail__dumpbool__rosidl_typesupport_introspection_c__Dumpbool_Response_message_type_support_handle
};

static rosidl_service_type_support_t dump_messages__srv__detail__dumpbool__rosidl_typesupport_introspection_c__Dumpbool_service_type_support_handle = {
  0,
  &dump_messages__srv__detail__dumpbool__rosidl_typesupport_introspection_c__Dumpbool_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dump_messages, srv, Dumpbool_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dump_messages, srv, Dumpbool_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dump_messages
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dump_messages, srv, Dumpbool)() {
  if (!dump_messages__srv__detail__dumpbool__rosidl_typesupport_introspection_c__Dumpbool_service_type_support_handle.typesupport_identifier) {
    dump_messages__srv__detail__dumpbool__rosidl_typesupport_introspection_c__Dumpbool_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)dump_messages__srv__detail__dumpbool__rosidl_typesupport_introspection_c__Dumpbool_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dump_messages, srv, Dumpbool_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dump_messages, srv, Dumpbool_Response)()->data;
  }

  return &dump_messages__srv__detail__dumpbool__rosidl_typesupport_introspection_c__Dumpbool_service_type_support_handle;
}
