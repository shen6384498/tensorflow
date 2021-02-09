/* Copyright 2021 The TensorFlow Authors. All Rights Reserved.

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

// This is part of the ultra-lightweight testing framework designed for use with
// microcontroller applications. See tensorflow/lite/micro/testing/micro_test.h.

#ifndef TENSORFLOW_LITE_MICRO_TESTING_SYSTEM_SETUP_H_
#define TENSORFLOW_LITE_MICRO_TESTING_SYSTEM_SETUP_H_

namespace tflite {

// This is called during initialization of testing framework. It can be
// implemented by each target platform. For more information, see
// tensorflow/lite/micro/system_setup.cc.
void InitializeTarget();

}  // namespace tflite

#endif  // TENSORFLOW_LITE_MICRO_TESTING_SYSTEM_SETUP_H_
