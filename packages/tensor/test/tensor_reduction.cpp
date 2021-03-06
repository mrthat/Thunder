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

#include "thunder/tensor.hpp"

#include <memory>
#include <typeinfo>

#include "gtest/gtest.h"
#include "thunder/storage.hpp"

namespace thunder {
namespace {

template< typename T >
void reductionTest() {
  T t1(10, 20, 7);
  int t1_val = 0;
  for (typename T::reference_iterator begin = t1.reference_begin(),
           end = t1.reference_end(); begin != end; ++begin) {
    *begin = static_cast< typename T::value_type >(t1_val++);
  }

  EXPECT_EQ(t1_val - 1, static_cast< int >(T::max(t1)));
  EXPECT_EQ(0, static_cast<int>(T::min(t1)));
  EXPECT_EQ(t1_val * (t1_val - 1) / 2, static_cast<int>(T::sum(t1)));
  EXPECT_EQ(0, static_cast<int>(T::prod(t1)));
  EXPECT_EQ((t1_val-1)/2, static_cast<int>(T::mean(t1)));
  EXPECT_EQ(163333, static_cast<int>(T::var(t1)));
  EXPECT_EQ(404, static_cast<int>(T::std(t1)));

  Tensor< typename T::size_storage > pos1;
  EXPECT_EQ(t1_val - 1, static_cast< int >(T::max(t1, &pos1)));
  EXPECT_EQ(1, pos1.dimension());
  EXPECT_EQ(3, pos1.size(0));
  for (int i = 0; i < pos1.size(0); ++i) {
    EXPECT_EQ(t1.size(i) - 1, pos1(i));
  }
  EXPECT_EQ(0, static_cast< int >(T::min(t1, &pos1)));
  for (int i = 0; i < pos1.size(0); ++i) {
    EXPECT_EQ(0, pos1(i));
  }

  T t2({10, 20, 7}, {290, 14, 2});
  int t2_val = 0;
  for (typename T::reference_iterator begin = t2.reference_begin(),
           end = t2.reference_end(); begin != end; ++begin) {
    *begin = static_cast< typename T::value_type >(t2_val++);
  }

  EXPECT_EQ(t2_val - 1, static_cast< int >(T::max(t2)));
  EXPECT_EQ(0, static_cast<int>(T::min(t2)));
  EXPECT_EQ(t2_val * (t2_val - 1) / 2, static_cast<int>(T::sum(t2)));
  EXPECT_EQ(0, static_cast<int>(T::prod(t2)));
  EXPECT_EQ((t2_val-1)/2, static_cast<int>(T::mean(t2)));
  EXPECT_EQ(163333, static_cast<int>(T::var(t2)));
  EXPECT_EQ(404, static_cast<int>(T::std(t2)));

  Tensor< typename T::size_storage > pos2;
  EXPECT_EQ(t2_val - 1, static_cast< int >(T::max(t2, &pos2)));
  EXPECT_EQ(1, pos2.dimension());
  EXPECT_EQ(3, pos2.size(0));
  for (int i = 0; i < pos2.size(0); ++i) {
    EXPECT_EQ(t2.size(i) - 1, pos2(i));
  }
  EXPECT_EQ(0, static_cast< int >(T::min(t2, &pos2)));
  for (int i = 0; i < pos2.size(0); ++i) {
    EXPECT_EQ(0, pos2(i));
  }
}

TEST(TensorTest, reductionTest) {
  reductionTest< DoubleTensor >();
  reductionTest< FloatTensor >();
}

template < typename T >
void maxTest() {
  T t1(10, 20, 7);
  int t1_val = 0;
  for (typename T::reference_iterator begin = t1.reference_begin(),
           end = t1.reference_end(); begin != end; ++begin) {
    *begin = static_cast< typename T::value_type >(t1_val++);
  }

  T t1_result = T::max(t1, 1);
  EXPECT_EQ(3, t1_result.dimension());
  EXPECT_EQ(10, t1_result.size(0));
  EXPECT_EQ(1, t1_result.size(1));
  EXPECT_EQ(7, t1_result.size(2));
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 7; ++j) {
      EXPECT_EQ(t1(i, 19, j), t1_result(i, 0, j));
    }
  }

  T t2({10, 20, 7, 9}, {1431, 71, 10, 1});
  int t2_val = 0;
  for (typename T::reference_iterator begin = t2.reference_begin(),
           end = t2.reference_end(); begin != end; ++begin) {
    *begin = static_cast< typename T::value_type >(t2_val++);
  }

  T t2_result = T::max(t2, 1);
  EXPECT_EQ(4, t2_result.dimension());
  EXPECT_EQ(10, t2_result.size(0));
  EXPECT_EQ(1, t2_result.size(1));
  EXPECT_EQ(7, t2_result.size(2));
  EXPECT_EQ(9, t2_result.size(3));
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 7; ++j) {
      for (int k = 0; k < 9; ++k) {
        EXPECT_EQ(t2(i, 19, j, k), t2_result(i, 0, j, k));
      }
    }
  }

  T t3(10, 20, 7);
  int t3_val = 0;
  for (typename T::reference_iterator begin = t3.reference_begin(),
           end = t3.reference_end(); begin != end; ++begin) {
    *begin = static_cast< typename T::value_type >(t3_val++);
  }

  Tensor< typename T::size_storage > t3_pos;
  T t3_result = T::max(t3, 1, &t3_pos);
  EXPECT_EQ(3, t3_result.dimension());
  EXPECT_EQ(10, t3_result.size(0));
  EXPECT_EQ(1, t3_result.size(1));
  EXPECT_EQ(7, t3_result.size(2));
  EXPECT_EQ(3, t3_pos.dimension());
  EXPECT_EQ(10, t3_pos.size(0));
  EXPECT_EQ(1, t3_pos.size(1));
  EXPECT_EQ(7, t3_pos.size(2));
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 7; ++j) {
      EXPECT_EQ(t3(i, 19, j), t3_result(i, 0, j));
      EXPECT_EQ(19, t3_pos(i, 0, j));
    }
  }

  T t4({10, 20, 7, 9}, {1431, 71, 10, 1});
  int t4_val = 0;
  for (typename T::reference_iterator begin = t4.reference_begin(),
           end = t4.reference_end(); begin != end; ++begin) {
    *begin = static_cast< typename T::value_type >(t4_val++);
  }

  Tensor< typename T::size_storage > t4_pos;
  T t4_result = T::max(t4, 1, &t4_pos);
  EXPECT_EQ(4, t4_result.dimension());
  EXPECT_EQ(10, t4_result.size(0));
  EXPECT_EQ(1, t4_result.size(1));
  EXPECT_EQ(7, t4_result.size(2));
  EXPECT_EQ(9, t4_result.size(3));
  EXPECT_EQ(4, t4_pos.dimension());
  EXPECT_EQ(10, t4_pos.size(0));
  EXPECT_EQ(1, t4_pos.size(1));
  EXPECT_EQ(7, t4_pos.size(2));
  EXPECT_EQ(9, t4_pos.size(3));
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 7; ++j) {
      for (int k = 0; k < 9; ++k) {
        EXPECT_EQ(t2(i, 19, j, k), t2_result(i, 0, j, k));
        EXPECT_EQ(19, t4_pos(i, 0, j, k));
      }
    }
  }
}

TEST(TensorTest, maxTest) {
  maxTest< DoubleTensor >();
  maxTest< FloatTensor >();
}

template < typename T >
void minTest() {
  T t1(10, 20, 7);
  int t1_val = 0;
  for (typename T::reference_iterator begin = t1.reference_begin(),
           end = t1.reference_end(); begin != end; ++begin) {
    *begin = static_cast< typename T::value_type >(t1_val++);
  }

  T t1_result = T::min(t1, 1);
  EXPECT_EQ(3, t1_result.dimension());
  EXPECT_EQ(10, t1_result.size(0));
  EXPECT_EQ(1, t1_result.size(1));
  EXPECT_EQ(7, t1_result.size(2));
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 7; ++j) {
      EXPECT_EQ(t1(i, 0, j), t1_result(i, 0, j));
    }
  }

  T t2({10, 20, 7, 9}, {1431, 71, 10, 1});
  int t2_val = 0;
  for (typename T::reference_iterator begin = t2.reference_begin(),
           end = t2.reference_end(); begin != end; ++begin) {
    *begin = static_cast< typename T::value_type >(t2_val++);
  }

  T t2_result = T::min(t2, 1);
  EXPECT_EQ(4, t2_result.dimension());
  EXPECT_EQ(10, t2_result.size(0));
  EXPECT_EQ(1, t2_result.size(1));
  EXPECT_EQ(7, t2_result.size(2));
  EXPECT_EQ(9, t2_result.size(3));
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 7; ++j) {
      for (int k = 0; k < 9; ++k) {
        EXPECT_EQ(t2(i, 0, j, k), t2_result(i, 0, j, k));
      }
    }
  }

  T t3(10, 20, 7);
  int t3_val = 0;
  for (typename T::reference_iterator begin = t3.reference_begin(),
           end = t3.reference_end(); begin != end; ++begin) {
    *begin = static_cast< typename T::value_type >(t3_val++);
  }

  Tensor< typename T::size_storage > t3_pos;
  T t3_result = T::min(t3, 1, &t3_pos);
  EXPECT_EQ(3, t3_result.dimension());
  EXPECT_EQ(10, t3_result.size(0));
  EXPECT_EQ(1, t3_result.size(1));
  EXPECT_EQ(7, t3_result.size(2));
  EXPECT_EQ(3, t3_pos.dimension());
  EXPECT_EQ(10, t3_pos.size(0));
  EXPECT_EQ(1, t3_pos.size(1));
  EXPECT_EQ(7, t3_pos.size(2));
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 7; ++j) {
      EXPECT_EQ(t3(i, 0, j), t3_result(i, 0, j));
      EXPECT_EQ(0, t3_pos(i, 0, j));
    }
  }

  T t4({10, 20, 7, 9}, {1431, 71, 10, 1});
  int t4_val = 0;
  for (typename T::reference_iterator begin = t4.reference_begin(),
           end = t4.reference_end(); begin != end; ++begin) {
    *begin = static_cast< typename T::value_type >(t4_val++);
  }

  Tensor< typename T::size_storage > t4_pos;
  T t4_result = T::min(t4, 1, &t4_pos);
  EXPECT_EQ(4, t4_result.dimension());
  EXPECT_EQ(10, t4_result.size(0));
  EXPECT_EQ(1, t4_result.size(1));
  EXPECT_EQ(7, t4_result.size(2));
  EXPECT_EQ(9, t4_result.size(3));
  EXPECT_EQ(4, t4_pos.dimension());
  EXPECT_EQ(10, t4_pos.size(0));
  EXPECT_EQ(1, t4_pos.size(1));
  EXPECT_EQ(7, t4_pos.size(2));
  EXPECT_EQ(9, t4_pos.size(3));
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 7; ++j) {
      for (int k = 0; k < 9; ++k) {
        EXPECT_EQ(t2(i, 0, j, k), t2_result(i, 0, j, k));
        EXPECT_EQ(0, t4_pos(i, 0, j, k));
      }
    }
  }
}

TEST(TensorTest, minTest) {
  minTest< DoubleTensor >();
  minTest< FloatTensor >();
}

#define TEST_DIM_REDUCTION(func)                                        \
  template < typename T >                                               \
  void func ## Test() {                                                 \
    T t1(10, 20, 7);                                                    \
    int t1_val = 0;                                                     \
    for (typename T::reference_iterator begin = t1.reference_begin(),   \
             end = t1.reference_end(); begin != end; ++begin) {         \
      *begin = static_cast< typename T::value_type >(t1_val++);         \
    }                                                                   \
                                                                        \
    T t1_result = T::func(t1, 1);                                       \
    EXPECT_EQ(3, t1_result.dimension());                                \
    EXPECT_EQ(10, t1_result.size(0));                                   \
    EXPECT_EQ(1, t1_result.size(1));                                    \
    EXPECT_EQ(7, t1_result.size(2));                                    \
    for (int i = 0; i < 10; ++i) {                                      \
      for (int j = 0; j < 7; ++j) {                                     \
        EXPECT_EQ(t1[i].select(1, j).func(), t1_result(i, 0, j));       \
      }                                                                 \
    }                                                                   \
                                                                        \
    T t2({10, 20, 7, 9}, {1431, 71, 10, 1});                            \
    int t2_val = 0;                                                     \
    for (typename T::reference_iterator begin = t2.reference_begin(),   \
             end = t2.reference_end(); begin != end; ++begin) {         \
      *begin = static_cast< typename T::value_type >(t2_val++);         \
    }                                                                   \
                                                                        \
    T t2_result = T::func(t2, 1);                                       \
    EXPECT_EQ(4, t2_result.dimension());                                \
    EXPECT_EQ(10, t2_result.size(0));                                   \
    EXPECT_EQ(1, t2_result.size(1));                                    \
    EXPECT_EQ(7, t2_result.size(2));                                    \
    EXPECT_EQ(9, t2_result.size(3));                                    \
    for (int i = 0; i < 10; ++i) {                                      \
      for (int j = 0; j < 7; ++j) {                                     \
        for (int k = 0; k < 9; ++k) {                                   \
          EXPECT_EQ(t2[i].select(1, j).select(1, k).func(),             \
                    t2_result(i, 0, j, k));                             \
        }                                                               \
      }                                                                 \
    }                                                                   \
  }                                                                     \
  TEST(TensorTest, func ## Test) {                                      \
    func ## Test< DoubleTensor >();                                     \
    func ## Test< FloatTensor >();                                      \
  }

TEST_DIM_REDUCTION(sum);
TEST_DIM_REDUCTION(prod);
TEST_DIM_REDUCTION(mean);
TEST_DIM_REDUCTION(var);
TEST_DIM_REDUCTION(std);

}  // namespace
}  // namespace thunder
