/*
 * \copyright Copyright 2014 Xiang Zhang All Rights Reserved.
 * \license @{
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @}
 */

#ifndef THUNDER_EXCEPTION_EXCEPTION_HPP_
#define THUNDER_EXCEPTION_EXCEPTION_HPP_

#include <stdexcept>

#include "thunder/exception/contiguity_error.hpp"

namespace thunder {
namespace exception {

using ::std::exception;
using ::std::logic_error;
using ::std::runtime_error;
using ::std::invalid_argument;
using ::std::domain_error;
using ::std::length_error;
using ::std::out_of_range;
using ::std::range_error;
using ::std::overflow_error;
using ::std::underflow_error;

}  // namespace exception
}  // namespace thunder

#endif  // THUNDER_EXCEPTION_EXCEPTION_HPP_
