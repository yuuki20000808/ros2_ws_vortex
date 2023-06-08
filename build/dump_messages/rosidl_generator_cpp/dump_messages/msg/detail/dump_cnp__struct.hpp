// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dump_messages:msg/DumpCNP.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__MSG__DETAIL__DUMP_CNP__STRUCT_HPP_
#define DUMP_MESSAGES__MSG__DETAIL__DUMP_CNP__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dump_messages__msg__DumpCNP __attribute__((deprecated))
#else
# define DEPRECATED__dump_messages__msg__DumpCNP __declspec(deprecated)
#endif

namespace dump_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DumpCNP_
{
  using Type = DumpCNP_<ContainerAllocator>;

  explicit DumpCNP_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ll;
      this->operational = false;
    }
  }

  explicit DumpCNP_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ll;
      this->operational = false;
    }
  }

  // field types and members
  using _id_type =
    int64_t;
  _id_type id;
  using _operational_type =
    bool;
  _operational_type operational;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;

  // setters for named parameter idiom
  Type & set__id(
    const int64_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__operational(
    const bool & _arg)
  {
    this->operational = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dump_messages::msg::DumpCNP_<ContainerAllocator> *;
  using ConstRawPtr =
    const dump_messages::msg::DumpCNP_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dump_messages::msg::DumpCNP_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dump_messages::msg::DumpCNP_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dump_messages::msg::DumpCNP_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dump_messages::msg::DumpCNP_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dump_messages::msg::DumpCNP_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dump_messages::msg::DumpCNP_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dump_messages::msg::DumpCNP_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dump_messages::msg::DumpCNP_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dump_messages__msg__DumpCNP
    std::shared_ptr<dump_messages::msg::DumpCNP_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dump_messages__msg__DumpCNP
    std::shared_ptr<dump_messages::msg::DumpCNP_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DumpCNP_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->operational != other.operational) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    return true;
  }
  bool operator!=(const DumpCNP_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DumpCNP_

// alias to use template instance with default allocator
using DumpCNP =
  dump_messages::msg::DumpCNP_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dump_messages

#endif  // DUMP_MESSAGES__MSG__DETAIL__DUMP_CNP__STRUCT_HPP_
