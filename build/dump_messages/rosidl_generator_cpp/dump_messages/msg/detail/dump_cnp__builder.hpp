// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dump_messages:msg/DumpCNP.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__MSG__DETAIL__DUMP_CNP__BUILDER_HPP_
#define DUMP_MESSAGES__MSG__DETAIL__DUMP_CNP__BUILDER_HPP_

#include "dump_messages/msg/detail/dump_cnp__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace dump_messages
{

namespace msg
{

namespace builder
{

class Init_DumpCNP_position
{
public:
  explicit Init_DumpCNP_position(::dump_messages::msg::DumpCNP & msg)
  : msg_(msg)
  {}
  ::dump_messages::msg::DumpCNP position(::dump_messages::msg::DumpCNP::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dump_messages::msg::DumpCNP msg_;
};

class Init_DumpCNP_operational
{
public:
  explicit Init_DumpCNP_operational(::dump_messages::msg::DumpCNP & msg)
  : msg_(msg)
  {}
  Init_DumpCNP_position operational(::dump_messages::msg::DumpCNP::_operational_type arg)
  {
    msg_.operational = std::move(arg);
    return Init_DumpCNP_position(msg_);
  }

private:
  ::dump_messages::msg::DumpCNP msg_;
};

class Init_DumpCNP_id
{
public:
  Init_DumpCNP_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DumpCNP_operational id(::dump_messages::msg::DumpCNP::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_DumpCNP_operational(msg_);
  }

private:
  ::dump_messages::msg::DumpCNP msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dump_messages::msg::DumpCNP>()
{
  return dump_messages::msg::builder::Init_DumpCNP_id();
}

}  // namespace dump_messages

#endif  // DUMP_MESSAGES__MSG__DETAIL__DUMP_CNP__BUILDER_HPP_
