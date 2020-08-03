// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2018 www.open3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#pragma once

#include <mkl.h>

#ifdef BUILD_CUDA_MODULE
#include <cublas_v2.h>
#endif

namespace open3d {
namespace core {

static_assert(sizeof(MKL_INT) == 8,
              "Unsupported platform: long long int must be 8 bytes");

template <typename scalar_t>
void gemm_cpu(CBLAS_LAYOUT layout,
              CBLAS_TRANSPOSE trans_A,
              CBLAS_TRANSPOSE trans_B,
              int m,
              int n,
              int k,
              scalar_t alpha,
              const scalar_t *A_data,
              int lda,
              const scalar_t *B_data,
              int ldb,
              scalar_t beta,
              scalar_t *C_data,
              int ldc);

#ifdef BUILD_CUDA_MODULE
template <typename scalar_t>
cublasStatus_t gemm_cuda(cublasHandle_t handle,
                         cublasOperation_t transa,
                         cublasOperation_t transb,
                         int m,
                         int n,
                         int k,
                         const scalar_t *alpha,
                         const scalar_t *A_data,
                         int lda,
                         const scalar_t *B_data,
                         int ldb,
                         const scalar_t *beta,
                         scalar_t *C_data,
                         int ldc);
#endif
}  // namespace core
}  // namespace open3d
