// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from catchall_interfaces:msg/TurtleArray.idl
// generated code does not contain a copyright notice

#ifndef CATCHALL_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__STRUCT_HPP_
#define CATCHALL_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'turtles'
#include "catchall_interfaces/msg/detail/turtle__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__catchall_interfaces__msg__TurtleArray __attribute__((deprecated))
#else
# define DEPRECATED__catchall_interfaces__msg__TurtleArray __declspec(deprecated)
#endif

namespace catchall_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TurtleArray_
{
  using Type = TurtleArray_<ContainerAllocator>;

  explicit TurtleArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit TurtleArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _turtles_type =
    std::vector<catchall_interfaces::msg::Turtle_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<catchall_interfaces::msg::Turtle_<ContainerAllocator>>>;
  _turtles_type turtles;

  // setters for named parameter idiom
  Type & set__turtles(
    const std::vector<catchall_interfaces::msg::Turtle_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<catchall_interfaces::msg::Turtle_<ContainerAllocator>>> & _arg)
  {
    this->turtles = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    catchall_interfaces::msg::TurtleArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const catchall_interfaces::msg::TurtleArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<catchall_interfaces::msg::TurtleArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<catchall_interfaces::msg::TurtleArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      catchall_interfaces::msg::TurtleArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<catchall_interfaces::msg::TurtleArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      catchall_interfaces::msg::TurtleArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<catchall_interfaces::msg::TurtleArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<catchall_interfaces::msg::TurtleArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<catchall_interfaces::msg::TurtleArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__catchall_interfaces__msg__TurtleArray
    std::shared_ptr<catchall_interfaces::msg::TurtleArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__catchall_interfaces__msg__TurtleArray
    std::shared_ptr<catchall_interfaces::msg::TurtleArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TurtleArray_ & other) const
  {
    if (this->turtles != other.turtles) {
      return false;
    }
    return true;
  }
  bool operator!=(const TurtleArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TurtleArray_

// alias to use template instance with default allocator
using TurtleArray =
  catchall_interfaces::msg::TurtleArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace catchall_interfaces

#endif  // CATCHALL_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__STRUCT_HPP_
