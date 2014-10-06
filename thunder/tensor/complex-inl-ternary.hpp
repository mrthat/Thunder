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

#ifndef THUNDER_TENSOR_COMPLEX_INL_TERNARY_HPP_
#define THUNDER_TENSOR_COMPLEX_INL_TERNARY_HPP_

#include "thunder/tensor/complex.hpp"
#include "thunder/tensor/complex-inl.hpp"

#include <cmath>
#include <complex>

#include "thunder/tensor/math.hpp"
#include "thunder/tensor/tensor.hpp"

namespace thunder {
namespace tensor {
namespace math {

template < typename D, typename A, typename T2 >
const Tensor< Storage< ::std::complex< D >, A > >& polar(
    const Tensor< Storage< ::std::complex< D >, A > > &x,
    const T2 &y, typename T2::const_reference z) {
  throw domain_error("polar is undefined for complex numbers");
  return x;
}

template < typename D, typename A, typename T2 >
const Tensor< Storage< ::std::complex< D >, A > >& polar(
    const Tensor< Storage< ::std::complex< D >, A > > &x,
    typename T2::const_reference y, const T2 &z) {
  throw domain_error("polar is undefined for complex numbers");
  return x;
}

template < typename D, typename A, typename S >
const Tensor< Storage< ::std::complex< D >, A > >& polar(
    const Tensor< Storage< ::std::complex< D >, A > > &x,
    const Tensor< S > &y, const Tensor< S > &z) {
  throw domain_error("polar is undefined for complex numbers");
  return x;
}

template < typename D, typename A >
const Tensor< Storage< ::std::complex< D >, A > >& polar(
    const Tensor< Storage< ::std::complex< D >, A > > &x,
    typename Tensor< Storage< ::std::complex< D >, A > >::const_reference y,
    typename Tensor< Storage< ::std::complex< D >, A > >::const_reference z) {
  throw domain_error("polar is undefined for complex numbers");
  return x;
}

template < typename D, typename A >
const Tensor< Storage< ::std::complex< D >, A > >& polar(
    const Tensor< Storage< ::std::complex< D >, A > > &x,
    const Tensor< Storage< ::std::complex< D >, A > > &y,
    typename Tensor< Storage< ::std::complex< D >, A > >::const_reference z) {
  throw domain_error("polar is undefined for complex numbers");
  return x;
}

template < typename D, typename A >
const Tensor< Storage< ::std::complex< D >, A > >& polar(
    const Tensor< Storage< ::std::complex< D >, A > > &x,
    typename Tensor< Storage< ::std::complex< D >, A > >::const_reference y,
    const Tensor< Storage< ::std::complex< D >, A > > &z) {
  throw domain_error("polar is undefined for complex numbers");
  return x;
}

template < typename D, typename A >
const Tensor< Storage< ::std::complex< D >, A > >& polar(
    const Tensor< Storage< ::std::complex< D >, A > > &x,
    const Tensor< Storage< ::std::complex< D >, A > > &y,
    const Tensor< Storage< ::std::complex< D >, A > > &z) {
  throw domain_error("polar is undefined for complex numbers");
  return x;
}

template < typename D, typename A >
const Tensor< Storage< ::std::complex< D >, A > >& fma(
    const Tensor< Storage< ::std::complex< D >, A > > &x,
    typename Tensor< Storage< ::std::complex< D >, A > >::const_reference y,
    typename Tensor< Storage< ::std::complex< D >, A > >::const_reference z) {
  throw domain_error("fma is undefined for complex numbers");
  return x;
}

template < typename D, typename A >
const Tensor< Storage< ::std::complex< D >, A > >& fma(
    const Tensor< Storage< ::std::complex< D >, A > > &x,
    const Tensor< Storage< ::std::complex< D >, A > > &y,
    typename Tensor< Storage< ::std::complex< D >, A > >::const_reference z) {
  throw domain_error("fma is undefined for complex numbers");
  return x;
}

template < typename D, typename A >
const Tensor< Storage< ::std::complex< D >, A > >& fma(
    const Tensor< Storage< ::std::complex< D >, A > > &x,
    typename Tensor< Storage< ::std::complex< D >, A > >::const_reference y,
    const Tensor< Storage< ::std::complex< D >, A > > &z) {
  throw domain_error("fma is undefined for complex numbers");
  return x;
}

template < typename D, typename A >
const Tensor< Storage< ::std::complex< D >, A > >& fma(
    const Tensor< Storage< ::std::complex< D >, A > > &x,
    const Tensor< Storage< ::std::complex< D >, A > > &y,
    const Tensor< Storage< ::std::complex< D >, A > > &z) {
  throw domain_error("fma is undefined for complex numbers");
  return x;
}


}  // namespace math
}  // namespace tensor
}  // namespace thunder

#endif  // THUNDER_TENSOR_COMPLEX_INL_TERNARY_HPP_
