// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from dump_messages:msg/ExPosAndTeamNumber.idl
// generated code does not contain a copyright notice

#ifndef DUMP_MESSAGES__MSG__DETAIL__EX_POS_AND_TEAM_NUMBER__FUNCTIONS_H_
#define DUMP_MESSAGES__MSG__DETAIL__EX_POS_AND_TEAM_NUMBER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "dump_messages/msg/rosidl_generator_c__visibility_control.h"

#include "dump_messages/msg/detail/ex_pos_and_team_number__struct.h"

/// Initialize msg/ExPosAndTeamNumber message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dump_messages__msg__ExPosAndTeamNumber
 * )) before or use
 * dump_messages__msg__ExPosAndTeamNumber__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dump_messages
bool
dump_messages__msg__ExPosAndTeamNumber__init(dump_messages__msg__ExPosAndTeamNumber * msg);

/// Finalize msg/ExPosAndTeamNumber message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dump_messages
void
dump_messages__msg__ExPosAndTeamNumber__fini(dump_messages__msg__ExPosAndTeamNumber * msg);

/// Create msg/ExPosAndTeamNumber message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dump_messages__msg__ExPosAndTeamNumber__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dump_messages
dump_messages__msg__ExPosAndTeamNumber *
dump_messages__msg__ExPosAndTeamNumber__create();

/// Destroy msg/ExPosAndTeamNumber message.
/**
 * It calls
 * dump_messages__msg__ExPosAndTeamNumber__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dump_messages
void
dump_messages__msg__ExPosAndTeamNumber__destroy(dump_messages__msg__ExPosAndTeamNumber * msg);

/// Check for msg/ExPosAndTeamNumber message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dump_messages
bool
dump_messages__msg__ExPosAndTeamNumber__are_equal(const dump_messages__msg__ExPosAndTeamNumber * lhs, const dump_messages__msg__ExPosAndTeamNumber * rhs);

/// Copy a msg/ExPosAndTeamNumber message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dump_messages
bool
dump_messages__msg__ExPosAndTeamNumber__copy(
  const dump_messages__msg__ExPosAndTeamNumber * input,
  dump_messages__msg__ExPosAndTeamNumber * output);

/// Initialize array of msg/ExPosAndTeamNumber messages.
/**
 * It allocates the memory for the number of elements and calls
 * dump_messages__msg__ExPosAndTeamNumber__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dump_messages
bool
dump_messages__msg__ExPosAndTeamNumber__Sequence__init(dump_messages__msg__ExPosAndTeamNumber__Sequence * array, size_t size);

/// Finalize array of msg/ExPosAndTeamNumber messages.
/**
 * It calls
 * dump_messages__msg__ExPosAndTeamNumber__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dump_messages
void
dump_messages__msg__ExPosAndTeamNumber__Sequence__fini(dump_messages__msg__ExPosAndTeamNumber__Sequence * array);

/// Create array of msg/ExPosAndTeamNumber messages.
/**
 * It allocates the memory for the array and calls
 * dump_messages__msg__ExPosAndTeamNumber__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dump_messages
dump_messages__msg__ExPosAndTeamNumber__Sequence *
dump_messages__msg__ExPosAndTeamNumber__Sequence__create(size_t size);

/// Destroy array of msg/ExPosAndTeamNumber messages.
/**
 * It calls
 * dump_messages__msg__ExPosAndTeamNumber__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dump_messages
void
dump_messages__msg__ExPosAndTeamNumber__Sequence__destroy(dump_messages__msg__ExPosAndTeamNumber__Sequence * array);

/// Check for msg/ExPosAndTeamNumber message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dump_messages
bool
dump_messages__msg__ExPosAndTeamNumber__Sequence__are_equal(const dump_messages__msg__ExPosAndTeamNumber__Sequence * lhs, const dump_messages__msg__ExPosAndTeamNumber__Sequence * rhs);

/// Copy an array of msg/ExPosAndTeamNumber messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dump_messages
bool
dump_messages__msg__ExPosAndTeamNumber__Sequence__copy(
  const dump_messages__msg__ExPosAndTeamNumber__Sequence * input,
  dump_messages__msg__ExPosAndTeamNumber__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DUMP_MESSAGES__MSG__DETAIL__EX_POS_AND_TEAM_NUMBER__FUNCTIONS_H_
