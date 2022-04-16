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
#ifndef TENSORFLOW_CORE_TFRT_EAGER_VIRTUAL_DEVICE_H_
#define TENSORFLOW_CORE_TFRT_EAGER_VIRTUAL_DEVICE_H_

#include "tfrt/host_context/device.h"  // from @tf_runtime

namespace tfrt {

// This device is for the use cases that a `Device` is not mapped to a physical
// device.
class VirtualDevice : public Device, public DeviceTraits<VirtualDevice> {
 public:
  static const char* type_name() {
    static constexpr char kName[] = "virtual";
    return kName;
  }

  explicit VirtualDevice(string_view name) : Device(kDeviceType, name) {
    LOG(ERROR) << "hello boy **************************** create VirtualDevice";
  }

  ~VirtualDevice() override = default;
};

}  // namespace tfrt

#endif  // TENSORFLOW_CORE_TFRT_EAGER_VIRTUAL_DEVICE_H_
