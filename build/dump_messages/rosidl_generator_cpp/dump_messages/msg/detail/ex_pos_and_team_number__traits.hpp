// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dump_messages:msg/ExPosAndTeamNumber.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__MSG__DETAIL__EX_POS_AND_TEAM_NUMBER__TRAITS_HPP_
#define DUMP_MESSAGES__MSG__DETAIL__EX_POS_AND_TEAM_NUMBER__TRAITS_HPP_

#include "dump_messages/msg/detail/ex_pos_and_team_number__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'pos'
#include "turtlesim/msg/detail/pose__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dump_messages::msg::ExPosAndTeamNumber>()
{
  return "dump_messages::msg::ExPosAndTeamNumber";
}

template<>
inline const char * name<dump_messages::msg::ExPosAndTeamNumber>()
{
  return "dump_messages/msg/ExPosAndTeamNumber";
}

template<>
struct has_fixed_size<dump_messages::msg::ExPosAndTeamNumber>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dump_messages::msg::ExPosAndTeamNumber>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dump_messages::msg::ExPosAndTeamNumber>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DUMP_MESSAGES__MSG__DETAIL__EX_POS_AND_TEAM_NUMBER__TRAITS_HPP_
