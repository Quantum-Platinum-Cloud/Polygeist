// RUN: cgeist %s --function=* -S -O0 | FileCheck %s

template <typename... Ts>
constexpr unsigned long sizeofpack(Ts&&... ts) {
  return sizeof...(ts);
}

// CHECK-LABEL:   func.func @_Z10sizeofpackIJEEmDpOT_() -> i64
// CHECK-NEXT:      %[[VAL_0:.*]] = arith.constant 0 : i64
// CHECK-NEXT:      return %[[VAL_0]] : i64
// CHECK-NEXT:    }
template unsigned long sizeofpack();
// CHECK-LABEL:   func.func @_Z10sizeofpackIJiEEmDpOT_(
// CHECK-SAME:                                         %[[VAL_0:.*]]: memref<?xi32>) -> i64
// CHECK-NEXT:      %[[VAL_1:.*]] = arith.constant 1 : i64
// CHECK-NEXT:      return %[[VAL_1]] : i64
// CHECK-NEXT:    }
template unsigned long sizeofpack(int&&);
// CHECK-LABEL:   func.func @_Z10sizeofpackIJiPvEEmDpOT_(
// CHECK-SAME:                                           %[[VAL_0:.*]]: memref<?xi32>,
// CHECK-SAME:                                           %[[VAL_1:.*]]: memref<?xmemref<?xi8>>) -> i64
// CHECK-NEXT:      %[[VAL_2:.*]] = arith.constant 2 : i64
// CHECK-NEXT:      return %[[VAL_2]] : i64
// CHECK-NEXT:    }
template unsigned long sizeofpack(int&&, void*&&);
// CHECK-LABEL:   func.func @_Z10sizeofpackIJiiEEmDpOT_(
// CHECK-SAME:                                          %[[VAL_0:.*]]: memref<?xi32>,
// CHECK-SAME:                                          %[[VAL_1:.*]]: memref<?xi32>) -> i64
// CHECK-NEXT:      %[[VAL_2:.*]] = arith.constant 2 : i64
// CHECK-NEXT:      return %[[VAL_2]] : i64
// CHECK-NEXT:    }
template unsigned long sizeofpack(int&&, int&&);
// CHECK-LABEL:   func.func @_Z10sizeofpackIJiifEEmDpOT_(
// CHECK-SAME:                                           %[[VAL_0:.*]]: memref<?xi32>, %[[VAL_1:.*]]: memref<?xi32>, %[[VAL_2:.*]]: memref<?xf32>) -> i64
// CHECK-NEXT:      %[[VAL_3:.*]] = arith.constant 3 : i64
// CHECK-NEXT:      return %[[VAL_3]] : i64
// CHECK-NEXT:    }
template unsigned long sizeofpack(int&&, int&&, float&&);
