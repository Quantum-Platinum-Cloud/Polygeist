//===- valueCategory.h -------------------------------------------*- C++
//-*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef CLANG_MLIR_VALUE_CATEGORY
#define CLANG_MLIR_VALUE_CATEGORY

#include "mlir/IR/Builders.h"
#include "mlir/IR/Value.h"

// Represents a rhs or lhs value.
class ValueWithOffsets {
public:
  mlir::Value val;
  bool isReference;

public:
  ValueWithOffsets() : val(nullptr), isReference(false){};
  ValueWithOffsets(std::nullptr_t) : val(nullptr), isReference(false){};
  ValueWithOffsets(mlir::Value val, bool isReference)
      : val(val), isReference(isReference){};

  // TODO: rename to 'loadVariable'? getValue seems to generic.
  mlir::Value getValue(mlir::OpBuilder &builder) const;
  void store(mlir::OpBuilder &builder, ValueWithOffsets toStore,
             bool isArray) const;
  // TODO: rename to storeVariable?
  void store(mlir::OpBuilder &builder, mlir::Value toStore) const;
  ValueWithOffsets dereference(mlir::OpBuilder &builder) const;
};

#endif