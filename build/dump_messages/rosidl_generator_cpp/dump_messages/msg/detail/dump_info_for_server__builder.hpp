// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dump_messages:msg/DumpInfoForServer.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__MSG__DETAIL__DUMP_INFO_FOR_SERVER__BUILDER_HPP_
#define DUMP_MESSAGES__MSG__DETAIL__DUMP_INFO_FOR_SERVER__BUILDER_HPP_

#include "dump_messages/msg/detail/dump_info_for_server__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace dump_messages
{

namespace msg
{

namespace builder
{

class Init_DumpInfoForServer_team
{
public:
  explicit Init_DumpInfoForServer_team(::dump_messages::msg::DumpInfoForServer & msg)
  : msg_(msg)
  {}
  ::dump_messages::msg::DumpInfoForServer team(::dump_messages::msg::DumpInfoForServer::_team_type arg)
  {
    msg_.team = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dump_messages::msg::DumpInfoForServer msg_;
};

class Init_DumpInfoForServer_id
{
public:
  Init_DumpInfoForServer_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DumpInfoForServer_team id(::dump_messages::msg::DumpInfoForServer::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_DumpInfoForServer_team(msg_);
  }

private:
  ::dump_messages::msg::DumpInfoForServer msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dump_messages::msg::DumpInfoForServer>()
{
  return dump_messages::msg::builder::Init_DumpInfoForServer_id();
}

}  // namespace dump_messages

#endif  // DUMP_MESSAGES__MSG__DETAIL__DUMP_INFO_FOR_SERVER__BUILDER_HPP_
