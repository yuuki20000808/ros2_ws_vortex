// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dump_messages:msg/DumpInfoForServer.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__MSG__DETAIL__DUMP_INFO_FOR_SERVER__STRUCT_HPP_
#define DUMP_MESSAGES__MSG__DETAIL__DUMP_INFO_FOR_SERVER__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__dump_messages__msg__DumpInfoForServer __attribute__((deprecated))
#else
# define DEPRECATED__dump_messages__msg__DumpInfoForServer __declspec(deprecated)
#endif

namespace dump_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DumpInfoForServer_
{
  using Type = DumpInfoForServer_<ContainerAllocator>;

  explicit DumpInfoForServer_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ll;
      this->team = 0ll;
    }
  }

  explicit DumpInfoForServer_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ll;
      this->team = 0ll;
    }
  }

  // field types and members
  using _id_type =
    int64_t;
  _id_type id;
  using _team_type =
    int64_t;
  _team_type team;

  // setters for named parameter idiom
  Type & set__id(
    const int64_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__team(
    const int64_t & _arg)
  {
    this->team = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dump_messages::msg::DumpInfoForServer_<ContainerAllocator> *;
  using ConstRawPtr =
    const dump_messages::msg::DumpInfoForServer_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dump_messages::msg::DumpInfoForServer_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dump_messages::msg::DumpInfoForServer_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dump_messages::msg::DumpInfoForServer_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dump_messages::msg::DumpInfoForServer_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dump_messages::msg::DumpInfoForServer_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dump_messages::msg::DumpInfoForServer_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dump_messages::msg::DumpInfoForServer_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dump_messages::msg::DumpInfoForServer_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dump_messages__msg__DumpInfoForServer
    std::shared_ptr<dump_messages::msg::DumpInfoForServer_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dump_messages__msg__DumpInfoForServer
    std::shared_ptr<dump_messages::msg::DumpInfoForServer_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DumpInfoForServer_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->team != other.team) {
      return false;
    }
    return true;
  }
  bool operator!=(const DumpInfoForServer_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DumpInfoForServer_

// alias to use template instance with default allocator
using DumpInfoForServer =
  dump_messages::msg::DumpInfoForServer_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dump_messages

#endif  // DUMP_MESSAGES__MSG__DETAIL__DUMP_INFO_FOR_SERVER__STRUCT_HPP_
