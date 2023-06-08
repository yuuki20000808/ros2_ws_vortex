// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dump_messages:msg/DumpCNP.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__MSG__DETAIL__DUMP_CNP__TRAITS_HPP_
#define DUMP_MESSAGES__MSG__DETAIL__DUMP_CNP__TRAITS_HPP_

#include "dump_messages/msg/detail/dump_cnp__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dump_messages::msg::DumpCNP>()
{
  return "dump_messages::msg::DumpCNP";
}

template<>
inline const char * name<dump_messages::msg::DumpCNP>()
{
  return "dump_messages/msg/DumpCNP";
}

template<>
struct has_fixed_size<dump_messages::msg::DumpCNP>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<dump_messages::msg::DumpCNP>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<dump_messages::msg::DumpCNP>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DUMP_MESSAGES__MSG__DETAIL__DUMP_CNP__TRAITS_HPP_
