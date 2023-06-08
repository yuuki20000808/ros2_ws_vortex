// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dump_messages:srv/Dumpbool.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__SRV__DETAIL__DUMPBOOL__TRAITS_HPP_
#define DUMP_MESSAGES__SRV__DETAIL__DUMPBOOL__TRAITS_HPP_

#include "dump_messages/srv/detail/dumpbool__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dump_messages::srv::Dumpbool_Request>()
{
  return "dump_messages::srv::Dumpbool_Request";
}

template<>
inline const char * name<dump_messages::srv::Dumpbool_Request>()
{
  return "dump_messages/srv/Dumpbool_Request";
}

template<>
struct has_fixed_size<dump_messages::srv::Dumpbool_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dump_messages::srv::Dumpbool_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dump_messages::srv::Dumpbool_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dump_messages::srv::Dumpbool_Response>()
{
  return "dump_messages::srv::Dumpbool_Response";
}

template<>
inline const char * name<dump_messages::srv::Dumpbool_Response>()
{
  return "dump_messages/srv/Dumpbool_Response";
}

template<>
struct has_fixed_size<dump_messages::srv::Dumpbool_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dump_messages::srv::Dumpbool_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dump_messages::srv::Dumpbool_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dump_messages::srv::Dumpbool>()
{
  return "dump_messages::srv::Dumpbool";
}

template<>
inline const char * name<dump_messages::srv::Dumpbool>()
{
  return "dump_messages/srv/Dumpbool";
}

template<>
struct has_fixed_size<dump_messages::srv::Dumpbool>
  : std::integral_constant<
    bool,
    has_fixed_size<dump_messages::srv::Dumpbool_Request>::value &&
    has_fixed_size<dump_messages::srv::Dumpbool_Response>::value
  >
{
};

template<>
struct has_bounded_size<dump_messages::srv::Dumpbool>
  : std::integral_constant<
    bool,
    has_bounded_size<dump_messages::srv::Dumpbool_Request>::value &&
    has_bounded_size<dump_messages::srv::Dumpbool_Response>::value
  >
{
};

template<>
struct is_service<dump_messages::srv::Dumpbool>
  : std::true_type
{
};

template<>
struct is_service_request<dump_messages::srv::Dumpbool_Request>
  : std::true_type
{
};

template<>
struct is_service_response<dump_messages::srv::Dumpbool_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DUMP_MESSAGES__SRV__DETAIL__DUMPBOOL__TRAITS_HPP_
