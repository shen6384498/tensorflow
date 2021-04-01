/* Copyright 2015 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tensorflow/core/util/port.h"
#include "tensorflow/core/platform/logging.h"


namespace tensorflow {

bool IsGoogleCudaEnabled() {
  LOG(ERROR) << "hello boy ********************************** IsGoogleCudaEnabled";
#if GOOGLE_CUDA
  return true;
#else
  return false;
#endif
}

bool IsBuiltWithROCm() {
  LOG(ERROR) << "hello boy ********************************** IsBuiltWithROCm";
#if TENSORFLOW_USE_ROCM
  return true;
#else
  return false;
#endif
}

bool IsBuiltWithXLA() {
  LOG(ERROR) << "hello boy ********************************** IsBuiltWithXLA";
#if TENSORFLOW_USE_XLA
  return true;
#else
  return false;
#endif
}

bool IsBuiltWithNvcc() {
  LOG(ERROR) << "hello boy ********************************** IsBuiltWithNvcc";
#if TENSORFLOW_USE_NVCC
  return true;
#else
  return false;
#endif
}

bool GpuSupportsHalfMatMulAndConv() {
  LOG(ERROR) << "hello boy ********************************** GpuSupportsHalfMatMulAndConv";
#if (defined(GOOGLE_CUDA) && GOOGLE_CUDA) || \
    (defined(TENSORFLOW_USE_ROCM) && TENSORFLOW_USE_ROCM)
  return true;
#else
  return false;
#endif
}

bool IsMklEnabled() {
  LOG(ERROR) << "hello boy ********************************** IsMklEnabled";
#if defined(INTEL_MKL) && defined(ENABLE_MKL)
  return true;
#else
  return false;
#endif  // INTEL_MKL && ENABLE_MKL
}
}  // end namespace tensorflow
