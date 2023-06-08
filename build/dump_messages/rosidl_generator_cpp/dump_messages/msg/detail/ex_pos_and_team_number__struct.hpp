// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dump_messages:msg/ExPosAndTeamNumber.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__MSG__DETAIL__EX_POS_AND_TEAM_NUMBER__STRUCT_HPP_
#define DUMP_MESSAGES__MSG__DETAIL__EX_POS_AND_TEAM_NUMBER__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'pos'
#include "turtlesim/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__dump_messages__msg__ExPosAndTeamNumber __attribute__((deprecated))
#else
# define DEPRECATED__dump_messages__msg__ExPosAndTeamNumber __declspec(deprecated)
#endif

namespace dump_messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ExPosAndTeamNumber_
{
  using Type = ExPosAndTeamNumber_<ContainerAllocator>;

  explicit ExPosAndTeamNumber_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pos(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->team = 0ll;
    }
  }

  explicit ExPosAndTeamNumber_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pos(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->team = 0ll;
    }
  }

  // field types and members
  using _team_type =
    int64_t;
  _team_type team;
  using _pos_type =
    turtlesim::msg::Pose_<ContainerAllocator>;
  _pos_type pos;
  using _dumpsite_type =
    std::vector<float, typename ContainerAllocator::template rebind<float>::other>;
  _dumpsite_type dumpsite;

  // setters for named parameter idiom
  Type & set__team(
    const int64_t & _arg)
  {
    this->team = _arg;
    return *this;
  }
  Type & set__pos(
    const turtlesim::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pos = _arg;
    return *this;
  }
  Type & set__dumpsite(
    const std::vector<float, typename ContainerAllocator::template rebind<float>::other> & _arg)
  {
    this->dumpsite = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dump_messages::msg::ExPosAndTeamNumber_<ContainerAllocator> *;
  using ConstRawPtr =
    const dump_messages::msg::ExPosAndTeamNumber_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dump_messages::msg::ExPosAndTeamNumber_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dump_messages::msg::ExPosAndTeamNumber_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dump_messages::msg::ExPosAndTeamNumber_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dump_messages::msg::ExPosAndTeamNumber_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dump_messages::msg::ExPosAndTeamNumber_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dump_messages::msg::ExPosAndTeamNumber_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dump_messages::msg::ExPosAndTeamNumber_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dump_messages::msg::ExPosAndTeamNumber_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dump_messages__msg__ExPosAndTeamNumber
    std::shared_ptr<dump_messages::msg::ExPosAndTeamNumber_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dump_messages__msg__ExPosAndTeamNumber
    std::shared_ptr<dump_messages::msg::ExPosAndTeamNumber_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExPosAndTeamNumber_ & other) const
  {
    if (this->team != other.team) {
      return false;
    }
    if (this->pos != other.pos) {
      return false;
    }
    if (this->dumpsite != other.dumpsite) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExPosAndTeamNumber_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExPosAndTeamNumber_

// alias to use template instance with default allocator
using ExPosAndTeamNumber =
  dump_messages::msg::ExPosAndTeamNumber_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dump_messages

#endif  // DUMP_MESSAGES__MSG__DETAIL__EX_POS_AND_TEAM_NUMBER__STRUCT_HPP_
