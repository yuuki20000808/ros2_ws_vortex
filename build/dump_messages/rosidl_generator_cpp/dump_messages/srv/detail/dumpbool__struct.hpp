// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dump_messages:srv/Dumpbool.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__SRV__DETAIL__DUMPBOOL__STRUCT_HPP_
#define DUMP_MESSAGES__SRV__DETAIL__DUMPBOOL__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__dump_messages__srv__Dumpbool_Request __attribute__((deprecated))
#else
# define DEPRECATED__dump_messages__srv__Dumpbool_Request __declspec(deprecated)
#endif

namespace dump_messages
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Dumpbool_Request_
{
  using Type = Dumpbool_Request_<ContainerAllocator>;

  explicit Dumpbool_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->request = false;
    }
  }

  explicit Dumpbool_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->request = false;
    }
  }

  // field types and members
  using _request_type =
    bool;
  _request_type request;

  // setters for named parameter idiom
  Type & set__request(
    const bool & _arg)
  {
    this->request = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dump_messages::srv::Dumpbool_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const dump_messages::srv::Dumpbool_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dump_messages::srv::Dumpbool_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dump_messages::srv::Dumpbool_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dump_messages::srv::Dumpbool_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dump_messages::srv::Dumpbool_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dump_messages::srv::Dumpbool_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dump_messages::srv::Dumpbool_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dump_messages::srv::Dumpbool_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dump_messages::srv::Dumpbool_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dump_messages__srv__Dumpbool_Request
    std::shared_ptr<dump_messages::srv::Dumpbool_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dump_messages__srv__Dumpbool_Request
    std::shared_ptr<dump_messages::srv::Dumpbool_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Dumpbool_Request_ & other) const
  {
    if (this->request != other.request) {
      return false;
    }
    return true;
  }
  bool operator!=(const Dumpbool_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Dumpbool_Request_

// alias to use template instance with default allocator
using Dumpbool_Request =
  dump_messages::srv::Dumpbool_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dump_messages


#ifndef _WIN32
# define DEPRECATED__dump_messages__srv__Dumpbool_Response __attribute__((deprecated))
#else
# define DEPRECATED__dump_messages__srv__Dumpbool_Response __declspec(deprecated)
#endif

namespace dump_messages
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Dumpbool_Response_
{
  using Type = Dumpbool_Response_<ContainerAllocator>;

  explicit Dumpbool_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->bit = false;
    }
  }

  explicit Dumpbool_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->bit = false;
    }
  }

  // field types and members
  using _bit_type =
    bool;
  _bit_type bit;

  // setters for named parameter idiom
  Type & set__bit(
    const bool & _arg)
  {
    this->bit = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dump_messages::srv::Dumpbool_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const dump_messages::srv::Dumpbool_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dump_messages::srv::Dumpbool_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dump_messages::srv::Dumpbool_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dump_messages::srv::Dumpbool_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dump_messages::srv::Dumpbool_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dump_messages::srv::Dumpbool_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dump_messages::srv::Dumpbool_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dump_messages::srv::Dumpbool_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dump_messages::srv::Dumpbool_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dump_messages__srv__Dumpbool_Response
    std::shared_ptr<dump_messages::srv::Dumpbool_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dump_messages__srv__Dumpbool_Response
    std::shared_ptr<dump_messages::srv::Dumpbool_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Dumpbool_Response_ & other) const
  {
    if (this->bit != other.bit) {
      return false;
    }
    return true;
  }
  bool operator!=(const Dumpbool_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Dumpbool_Response_

// alias to use template instance with default allocator
using Dumpbool_Response =
  dump_messages::srv::Dumpbool_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dump_messages

namespace dump_messages
{

namespace srv
{

struct Dumpbool
{
  using Request = dump_messages::srv::Dumpbool_Request;
  using Response = dump_messages::srv::Dumpbool_Response;
};

}  // namespace srv

}  // namespace dump_messages

#endif  // DUMP_MESSAGES__SRV__DETAIL__DUMPBOOL__STRUCT_HPP_
