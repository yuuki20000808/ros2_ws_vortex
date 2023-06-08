// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dump_messages:msg/DumpInfoForServer.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__MSG__DETAIL__DUMP_INFO_FOR_SERVER__TRAITS_HPP_
#define DUMP_MESSAGES__MSG__DETAIL__DUMP_INFO_FOR_SERVER__TRAITS_HPP_

#include "dump_messages/msg/detail/dump_info_for_server__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dump_messages::msg::DumpInfoForServer>()
{
  return "dump_messages::msg::DumpInfoForServer";
}

template<>
inline const char * name<dump_messages::msg::DumpInfoForServer>()
{
  return "dump_messages/msg/DumpInfoForServer";
}

template<>
struct has_fixed_size<dump_messages::msg::DumpInfoForServer>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dump_messages::msg::DumpInfoForServer>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dump_messages::msg::DumpInfoForServer>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DUMP_MESSAGES__MSG__DETAIL__DUMP_INFO_FOR_SERVER__TRAITS_HPP_
