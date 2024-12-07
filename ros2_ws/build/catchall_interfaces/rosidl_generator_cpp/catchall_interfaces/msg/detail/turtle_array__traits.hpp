// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from catchall_interfaces:msg/TurtleArray.idl
// generated code does not contain a copyright notice

#ifndef CATCHALL_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__TRAITS_HPP_
#define CATCHALL_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "catchall_interfaces/msg/detail/turtle_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'turtles'
#include "catchall_interfaces/msg/detail/turtle__traits.hpp"

namespace catchall_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TurtleArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: turtles
  {
    if (msg.turtles.size() == 0) {
      out << "turtles: []";
    } else {
      out << "turtles: [";
      size_t pending_items = msg.turtles.size();
      for (auto item : msg.turtles) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TurtleArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: turtles
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.turtles.size() == 0) {
      out << "turtles: []\n";
    } else {
      out << "turtles:\n";
      for (auto item : msg.turtles) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TurtleArray & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace catchall_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use catchall_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const catchall_interfaces::msg::TurtleArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  catchall_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use catchall_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const catchall_interfaces::msg::TurtleArray & msg)
{
  return catchall_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<catchall_interfaces::msg::TurtleArray>()
{
  return "catchall_interfaces::msg::TurtleArray";
}

template<>
inline const char * name<catchall_interfaces::msg::TurtleArray>()
{
  return "catchall_interfaces/msg/TurtleArray";
}

template<>
struct has_fixed_size<catchall_interfaces::msg::TurtleArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<catchall_interfaces::msg::TurtleArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<catchall_interfaces::msg::TurtleArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CATCHALL_INTERFACES__MSG__DETAIL__TURTLE_ARRAY__TRAITS_HPP_
