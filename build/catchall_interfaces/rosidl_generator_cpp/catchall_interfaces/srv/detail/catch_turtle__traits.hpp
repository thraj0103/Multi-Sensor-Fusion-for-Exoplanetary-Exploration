// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from catchall_interfaces:srv/CatchTurtle.idl
// generated code does not contain a copyright notice

#ifndef CATCHALL_INTERFACES__SRV__DETAIL__CATCH_TURTLE__TRAITS_HPP_
#define CATCHALL_INTERFACES__SRV__DETAIL__CATCH_TURTLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "catchall_interfaces/srv/detail/catch_turtle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace catchall_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CatchTurtle_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CatchTurtle_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CatchTurtle_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace catchall_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use catchall_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const catchall_interfaces::srv::CatchTurtle_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  catchall_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use catchall_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const catchall_interfaces::srv::CatchTurtle_Request & msg)
{
  return catchall_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<catchall_interfaces::srv::CatchTurtle_Request>()
{
  return "catchall_interfaces::srv::CatchTurtle_Request";
}

template<>
inline const char * name<catchall_interfaces::srv::CatchTurtle_Request>()
{
  return "catchall_interfaces/srv/CatchTurtle_Request";
}

template<>
struct has_fixed_size<catchall_interfaces::srv::CatchTurtle_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<catchall_interfaces::srv::CatchTurtle_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<catchall_interfaces::srv::CatchTurtle_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace catchall_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const CatchTurtle_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CatchTurtle_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CatchTurtle_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace catchall_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use catchall_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const catchall_interfaces::srv::CatchTurtle_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  catchall_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use catchall_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const catchall_interfaces::srv::CatchTurtle_Response & msg)
{
  return catchall_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<catchall_interfaces::srv::CatchTurtle_Response>()
{
  return "catchall_interfaces::srv::CatchTurtle_Response";
}

template<>
inline const char * name<catchall_interfaces::srv::CatchTurtle_Response>()
{
  return "catchall_interfaces/srv/CatchTurtle_Response";
}

template<>
struct has_fixed_size<catchall_interfaces::srv::CatchTurtle_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<catchall_interfaces::srv::CatchTurtle_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<catchall_interfaces::srv::CatchTurtle_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<catchall_interfaces::srv::CatchTurtle>()
{
  return "catchall_interfaces::srv::CatchTurtle";
}

template<>
inline const char * name<catchall_interfaces::srv::CatchTurtle>()
{
  return "catchall_interfaces/srv/CatchTurtle";
}

template<>
struct has_fixed_size<catchall_interfaces::srv::CatchTurtle>
  : std::integral_constant<
    bool,
    has_fixed_size<catchall_interfaces::srv::CatchTurtle_Request>::value &&
    has_fixed_size<catchall_interfaces::srv::CatchTurtle_Response>::value
  >
{
};

template<>
struct has_bounded_size<catchall_interfaces::srv::CatchTurtle>
  : std::integral_constant<
    bool,
    has_bounded_size<catchall_interfaces::srv::CatchTurtle_Request>::value &&
    has_bounded_size<catchall_interfaces::srv::CatchTurtle_Response>::value
  >
{
};

template<>
struct is_service<catchall_interfaces::srv::CatchTurtle>
  : std::true_type
{
};

template<>
struct is_service_request<catchall_interfaces::srv::CatchTurtle_Request>
  : std::true_type
{
};

template<>
struct is_service_response<catchall_interfaces::srv::CatchTurtle_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CATCHALL_INTERFACES__SRV__DETAIL__CATCH_TURTLE__TRAITS_HPP_
