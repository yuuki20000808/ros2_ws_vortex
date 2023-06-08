// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dump_messages:srv/Dumpbool.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__SRV__DETAIL__DUMPBOOL__BUILDER_HPP_
#define DUMP_MESSAGES__SRV__DETAIL__DUMPBOOL__BUILDER_HPP_

#include "dump_messages/srv/detail/dumpbool__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace dump_messages
{

namespace srv
{

namespace builder
{

class Init_Dumpbool_Request_request
{
public:
  Init_Dumpbool_Request_request()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dump_messages::srv::Dumpbool_Request request(::dump_messages::srv::Dumpbool_Request::_request_type arg)
  {
    msg_.request = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dump_messages::srv::Dumpbool_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dump_messages::srv::Dumpbool_Request>()
{
  return dump_messages::srv::builder::Init_Dumpbool_Request_request();
}

}  // namespace dump_messages


namespace dump_messages
{

namespace srv
{

namespace builder
{

class Init_Dumpbool_Response_bit
{
public:
  Init_Dumpbool_Response_bit()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::dump_messages::srv::Dumpbool_Response bit(::dump_messages::srv::Dumpbool_Response::_bit_type arg)
  {
    msg_.bit = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dump_messages::srv::Dumpbool_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dump_messages::srv::Dumpbool_Response>()
{
  return dump_messages::srv::builder::Init_Dumpbool_Response_bit();
}

}  // namespace dump_messages

#endif  // DUMP_MESSAGES__SRV__DETAIL__DUMPBOOL__BUILDER_HPP_
