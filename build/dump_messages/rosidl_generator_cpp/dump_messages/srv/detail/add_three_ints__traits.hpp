// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dump_messages:srv/AddThreeInts.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__SRV__DETAIL__ADD_THREE_INTS__TRAITS_HPP_
#define DUMP_MESSAGES__SRV__DETAIL__ADD_THREE_INTS__TRAITS_HPP_

#include "dump_messages/srv/detail/add_three_ints__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dump_messages::srv::AddThreeInts_Request>()
{
  return "dump_messages::srv::AddThreeInts_Request";
}

template<>
inline const char * name<dump_messages::srv::AddThreeInts_Request>()
{
  return "dump_messages/srv/AddThreeInts_Request";
}

template<>
struct has_fixed_size<dump_messages::srv::AddThreeInts_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dump_messages::srv::AddThreeInts_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dump_messages::srv::AddThreeInts_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dump_messages::srv::AddThreeInts_Response>()
{
  return "dump_messages::srv::AddThreeInts_Response";
}

template<>
inline const char * name<dump_messages::srv::AddThreeInts_Response>()
{
  return "dump_messages/srv/AddThreeInts_Response";
}

template<>
struct has_fixed_size<dump_messages::srv::AddThreeInts_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dump_messages::srv::AddThreeInts_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dump_messages::srv::AddThreeInts_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dump_messages::srv::AddThreeInts>()
{
  return "dump_messages::srv::AddThreeInts";
}

template<>
inline const char * name<dump_messages::srv::AddThreeInts>()
{
  return "dump_messages/srv/AddThreeInts";
}

template<>
struct has_fixed_size<dump_messages::srv::AddThreeInts>
  : std::integral_constant<
    bool,
    has_fixed_size<dump_messages::srv::AddThreeInts_Request>::value &&
    has_fixed_size<dump_messages::srv::AddThreeInts_Response>::value
  >
{
};

template<>
struct has_bounded_size<dump_messages::srv::AddThreeInts>
  : std::integral_constant<
    bool,
    has_bounded_size<dump_messages::srv::AddThreeInts_Request>::value &&
    has_bounded_size<dump_messages::srv::AddThreeInts_Response>::value
  >
{
};

template<>
struct is_service<dump_messages::srv::AddThreeInts>
  : std::true_type
{
};

template<>
struct is_service_request<dump_messages::srv::AddThreeInts_Request>
  : std::true_type
{
};

template<>
struct is_service_response<dump_messages::srv::AddThreeInts_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DUMP_MESSAGES__SRV__DETAIL__ADD_THREE_INTS__TRAITS_HPP_
