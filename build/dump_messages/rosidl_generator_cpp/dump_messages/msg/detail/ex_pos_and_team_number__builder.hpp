// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dump_messages:msg/ExPosAndTeamNumber.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__MSG__DETAIL__EX_POS_AND_TEAM_NUMBER__BUILDER_HPP_
#define DUMP_MESSAGES__MSG__DETAIL__EX_POS_AND_TEAM_NUMBER__BUILDER_HPP_

#include "dump_messages/msg/detail/ex_pos_and_team_number__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace dump_messages
{

namespace msg
{

namespace builder
{

class Init_ExPosAndTeamNumber_dumpsite
{
public:
  explicit Init_ExPosAndTeamNumber_dumpsite(::dump_messages::msg::ExPosAndTeamNumber & msg)
  : msg_(msg)
  {}
  ::dump_messages::msg::ExPosAndTeamNumber dumpsite(::dump_messages::msg::ExPosAndTeamNumber::_dumpsite_type arg)
  {
    msg_.dumpsite = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dump_messages::msg::ExPosAndTeamNumber msg_;
};

class Init_ExPosAndTeamNumber_pos
{
public:
  explicit Init_ExPosAndTeamNumber_pos(::dump_messages::msg::ExPosAndTeamNumber & msg)
  : msg_(msg)
  {}
  Init_ExPosAndTeamNumber_dumpsite pos(::dump_messages::msg::ExPosAndTeamNumber::_pos_type arg)
  {
    msg_.pos = std::move(arg);
    return Init_ExPosAndTeamNumber_dumpsite(msg_);
  }

private:
  ::dump_messages::msg::ExPosAndTeamNumber msg_;
};

class Init_ExPosAndTeamNumber_team
{
public:
  Init_ExPosAndTeamNumber_team()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExPosAndTeamNumber_pos team(::dump_messages::msg::ExPosAndTeamNumber::_team_type arg)
  {
    msg_.team = std::move(arg);
    return Init_ExPosAndTeamNumber_pos(msg_);
  }

private:
  ::dump_messages::msg::ExPosAndTeamNumber msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dump_messages::msg::ExPosAndTeamNumber>()
{
  return dump_messages::msg::builder::Init_ExPosAndTeamNumber_team();
}

}  // namespace dump_messages

#endif  // DUMP_MESSAGES__MSG__DETAIL__EX_POS_AND_TEAM_NUMBER__BUILDER_HPP_
