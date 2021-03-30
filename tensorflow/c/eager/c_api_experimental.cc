/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

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

#include "tensorflow/c/eager/c_api_experimental.h"

#include "tensorflow/c/c_api.h"
#include "tensorflow/c/eager/c_api_internal.h"
#include "tensorflow/c/tf_status_helper.h"
#include "tensorflow/core/common_runtime/device.h"
#include "tensorflow/core/lib/monitoring/counter.h"
#include "tensorflow/core/lib/monitoring/gauge.h"
#include "tensorflow/core/lib/monitoring/sampler.h"
#include "tensorflow/core/lib/strings/strcat.h"
#include "tensorflow/core/platform/casts.h"
#include "tensorflow/core/platform/mutex.h"

using tensorflow::string;

void TFE_OpReset(TFE_Op* op_to_reset, const char* op_or_function_name,
                 const char* raw_device_name, TF_Status* status) {
  LOG(ERROR) << "hello boy ********************************** TFE_OpReset";
  if (op_to_reset) {
    op_to_reset->operation->Clear();
    status->status =
        op_to_reset->operation->Reset(op_or_function_name, raw_device_name);
  } else {
    TF_SetStatus(status, TF_INVALID_ARGUMENT,
                 "op_to_reset should not be nullptr");
  }
}

void TFE_ContextEnableGraphCollection(TFE_Context* ctx) {
  LOG(ERROR) << "hello boy ********************************** TFE_ContextEnableGraphCollection";
  ctx->context->SetShouldStoreGraphs(true);
}

void TFE_ContextDisableGraphCollection(TFE_Context* ctx) {
  LOG(ERROR) << "hello boy ********************************** TFE_ContextDisableGraphCollection";
  ctx->context->SetShouldStoreGraphs(false);
}

void TFE_MonitoringCounterCellIncrementBy(TFE_MonitoringCounterCell* cell,
                                          int64_t value) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringCounterCellIncrementBy";
  cell->cell.IncrementBy(value);
}

int64_t TFE_MonitoringCounterCellValue(TFE_MonitoringCounterCell* cell) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringCounterCellValue";
  return cell->cell.value();
}

TFE_MonitoringCounter0* TFE_MonitoringNewCounter0(const char* name,
                                                  TF_Status* status,
                                                  const char* description) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringNewCounter0";
  auto* result = new TFE_MonitoringCounter0({name, description});
  Set_TF_Status_from_Status(status, result->counter->GetStatus());
  if (!result->counter->GetStatus().ok()) {
    delete result;
    return nullptr;
  }
  return result;
}

void TFE_MonitoringDeleteCounter0(TFE_MonitoringCounter0* counter) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringDeleteCounter0";
  delete counter;
}

TFE_MonitoringCounterCell* TFE_MonitoringGetCellCounter0(
    TFE_MonitoringCounter0* counter) {
  return static_cast<TFE_MonitoringCounterCell*>(
      static_cast<void*>(counter->counter->GetCell()));
}

TFE_MonitoringCounter1* TFE_MonitoringNewCounter1(const char* name,
                                                  TF_Status* status,
                                                  const char* description,
                                                  const char* label1) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringNewCounter1";
  auto* result = new TFE_MonitoringCounter1({name, description, label1});
  Set_TF_Status_from_Status(status, result->counter->GetStatus());
  if (!result->counter->GetStatus().ok()) {
    delete result;
    return nullptr;
  }
  return result;
}

void TFE_MonitoringDeleteCounter1(TFE_MonitoringCounter1* counter) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringDeleteCounter1";
  delete counter;
}

TFE_MonitoringCounterCell* TFE_MonitoringGetCellCounter1(
    TFE_MonitoringCounter1* counter, const char* label1) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringGetCellCounter1";
  return static_cast<TFE_MonitoringCounterCell*>(
      static_cast<void*>(counter->counter->GetCell(label1)));
}

TFE_MonitoringCounter2* TFE_MonitoringNewCounter2(const char* name,
                                                  TF_Status* status,
                                                  const char* description,
                                                  const char* label1,
                                                  const char* label2) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringNewCounter2";
  auto* result =
      new TFE_MonitoringCounter2({name, description, label1, label2});
  Set_TF_Status_from_Status(status, result->counter->GetStatus());
  if (!result->counter->GetStatus().ok()) {
    delete result;
    return nullptr;
  }
  return result;
}

void TFE_MonitoringDeleteCounter2(TFE_MonitoringCounter2* counter) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringDeleteCounter2";
  delete counter;
}

TFE_MonitoringCounterCell* TFE_MonitoringGetCellCounter2(
    TFE_MonitoringCounter2* counter, const char* label1, const char* label2) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringGetCellCounter2";
  return static_cast<TFE_MonitoringCounterCell*>(
      static_cast<void*>(counter->counter->GetCell(label1, label2)));
}

void TFE_MonitoringIntGaugeCellSet(TFE_MonitoringIntGaugeCell* cell,
                                   int64_t value) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringIntGaugeCellSet";
  cell->cell.Set(value);
}

int64_t TFE_MonitoringIntGaugeCellValue(TFE_MonitoringIntGaugeCell* cell) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringIntGaugeCellValue";
  return cell->cell.value();
}

TFE_MonitoringIntGauge0* TFE_MonitoringNewIntGauge0(const char* name,
                                                    TF_Status* status,
                                                    const char* description) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringNewIntGauge0";
  auto* result = new TFE_MonitoringIntGauge0({name, description});
  Set_TF_Status_from_Status(status, result->gauge->GetStatus());
  if (!result->gauge->GetStatus().ok()) {
    delete result;
    return nullptr;
  }
  return result;
}

void TFE_MonitoringDeleteIntGauge0(TFE_MonitoringIntGauge0* gauge) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringDeleteIntGauge0";
  delete gauge;
}

TFE_MonitoringIntGaugeCell* TFE_MonitoringGetCellIntGauge0(
    TFE_MonitoringIntGauge0* gauge) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringGetCellIntGauge0";
  return static_cast<TFE_MonitoringIntGaugeCell*>(
      static_cast<void*>(gauge->gauge->GetCell()));
}

TFE_MonitoringIntGauge1* TFE_MonitoringNewIntGauge1(const char* name,
                                                    TF_Status* status,
                                                    const char* description,
                                                    const char* label1) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringNewIntGauge1";
  auto* result = new TFE_MonitoringIntGauge1({name, description, label1});
  Set_TF_Status_from_Status(status, result->gauge->GetStatus());
  if (!result->gauge->GetStatus().ok()) {
    delete result;
    return nullptr;
  }
  return result;
}

void TFE_MonitoringDeleteIntGauge1(TFE_MonitoringIntGauge1* gauge) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringDeleteIntGauge1";
  delete gauge;
}

TFE_MonitoringIntGaugeCell* TFE_MonitoringGetCellIntGauge1(
    TFE_MonitoringIntGauge1* gauge, const char* label1) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringGetCellIntGauge1";
  return static_cast<TFE_MonitoringIntGaugeCell*>(
      static_cast<void*>(gauge->gauge->GetCell(label1)));
}

TFE_MonitoringIntGauge2* TFE_MonitoringNewIntGauge2(const char* name,
                                                    TF_Status* status,
                                                    const char* description,
                                                    const char* label1,
                                                    const char* label2) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringNewIntGauge2";
  auto* result =
      new TFE_MonitoringIntGauge2({name, description, label1, label2});
  Set_TF_Status_from_Status(status, result->gauge->GetStatus());
  if (!result->gauge->GetStatus().ok()) {
    delete result;
    return nullptr;
  }
  return result;
}

void TFE_MonitoringDeleteIntGauge2(TFE_MonitoringIntGauge2* gauge) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringDeleteIntGauge2";
  delete gauge;
}

TFE_MonitoringIntGaugeCell* TFE_MonitoringGetCellIntGauge2(
    TFE_MonitoringIntGauge2* gauge, const char* label1, const char* label2) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringGetCellIntGauge2";
  return static_cast<TFE_MonitoringIntGaugeCell*>(
      static_cast<void*>(gauge->gauge->GetCell(label1, label2)));
}

void TFE_MonitoringStringGaugeCellSet(TFE_MonitoringStringGaugeCell* cell,
                                      const char* value) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringStringGaugeCellSet";
  cell->cell.Set({value});
}

const void TFE_MonitoringStringGaugeCellValue(
    TFE_MonitoringStringGaugeCell* cell, TF_Buffer* buf) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringStringGaugeCellValue";
  tensorflow::string value = cell->cell.value();
  void* data = tensorflow::port::Malloc(value.length());
  value.copy(static_cast<char*>(data), value.length(), 0);
  buf->data = data;
  buf->length = value.length();
  buf->data_deallocator = [](void* data, size_t length) {
    tensorflow::port::Free(data);
  };
}

TFE_MonitoringStringGauge0* TFE_MonitoringNewStringGauge0(
    const char* name, TF_Status* status, const char* description) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringNewStringGauge0";
  auto* result = new TFE_MonitoringStringGauge0({name, description});
  Set_TF_Status_from_Status(status, result->gauge->GetStatus());
  if (!result->gauge->GetStatus().ok()) {
    delete result;
    return nullptr;
  }
  return result;
}

void TFE_MonitoringDeleteStringGauge0(TFE_MonitoringStringGauge0* gauge) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringDeleteStringGauge0";
  delete gauge;
}

TFE_MonitoringStringGaugeCell* TFE_MonitoringGetCellStringGauge0(
    TFE_MonitoringStringGauge0* gauge) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringGetCellStringGauge0";
  return static_cast<TFE_MonitoringStringGaugeCell*>(
      static_cast<void*>(gauge->gauge->GetCell()));
}

TFE_MonitoringStringGauge1* TFE_MonitoringNewStringGauge1(
    const char* name, TF_Status* status, const char* description,
    const char* label1) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringNewStringGauge1";
  auto* result = new TFE_MonitoringStringGauge1({name, description, label1});
  Set_TF_Status_from_Status(status, result->gauge->GetStatus());
  if (!result->gauge->GetStatus().ok()) {
    delete result;
    return nullptr;
  }
  return result;
}

void TFE_MonitoringDeleteStringGauge1(TFE_MonitoringStringGauge1* gauge) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringDeleteStringGauge1";
  delete gauge;
}

TFE_MonitoringStringGaugeCell* TFE_MonitoringGetCellStringGauge1(
    TFE_MonitoringStringGauge1* gauge, const char* label1) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringGetCellStringGauge1";
  return static_cast<TFE_MonitoringStringGaugeCell*>(
      static_cast<void*>(gauge->gauge->GetCell(label1)));
}

TFE_MonitoringStringGauge2* TFE_MonitoringNewStringGauge2(
    const char* name, TF_Status* status, const char* description,
    const char* label1, const char* label2) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringNewStringGauge2";
  auto* result =
      new TFE_MonitoringStringGauge2({name, description, label1, label2});
  Set_TF_Status_from_Status(status, result->gauge->GetStatus());
  if (!result->gauge->GetStatus().ok()) {
    delete result;
    return nullptr;
  }
  return result;
}

void TFE_MonitoringDeleteStringGauge2(TFE_MonitoringStringGauge2* gauge) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringDeleteStringGauge2";
  delete gauge;
}

TFE_MonitoringStringGaugeCell* TFE_MonitoringGetCellStringGauge2(
    TFE_MonitoringStringGauge2* gauge, const char* label1, const char* label2) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringStringGaugeCell";
  return static_cast<TFE_MonitoringStringGaugeCell*>(
      static_cast<void*>(gauge->gauge->GetCell(label1, label2)));
}

void TFE_MonitoringBoolGaugeCellSet(TFE_MonitoringBoolGaugeCell* cell,
                                    bool value) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringBoolGaugeCellSet";
  cell->cell.Set(value);
}

bool TFE_MonitoringBoolGaugeCellValue(TFE_MonitoringBoolGaugeCell* cell) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringBoolGaugeCellValue";
  return cell->cell.value();
}

TFE_MonitoringBoolGauge0* TFE_MonitoringNewBoolGauge0(const char* name,
                                                      TF_Status* status,
                                                      const char* description) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringNewBoolGauge0";
  auto* result = new TFE_MonitoringBoolGauge0({name, description});
  Set_TF_Status_from_Status(status, result->gauge->GetStatus());
  if (!result->gauge->GetStatus().ok()) {
    delete result;
    return nullptr;
  }
  return result;
}

void TFE_MonitoringDeleteBoolGauge0(TFE_MonitoringBoolGauge0* gauge) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringDeleteBoolGauge0";
  delete gauge;
}

TFE_MonitoringBoolGaugeCell* TFE_MonitoringGetCellBoolGauge0(
    TFE_MonitoringBoolGauge0* gauge) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringGetCellBoolGauge0";
  return static_cast<TFE_MonitoringBoolGaugeCell*>(
      static_cast<void*>(gauge->gauge->GetCell()));
}

TFE_MonitoringBoolGauge1* TFE_MonitoringNewBoolGauge1(const char* name,
                                                      TF_Status* status,
                                                      const char* description,
                                                      const char* label1) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringNewBoolGauge1";
  auto* result = new TFE_MonitoringBoolGauge1({name, description, label1});
  Set_TF_Status_from_Status(status, result->gauge->GetStatus());
  if (!result->gauge->GetStatus().ok()) {
    delete result;
    return nullptr;
  }
  return result;
}

void TFE_MonitoringDeleteBoolGauge1(TFE_MonitoringBoolGauge1* gauge) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringDeleteBoolGauge1";
  delete gauge;
}

TFE_MonitoringBoolGaugeCell* TFE_MonitoringGetCellBoolGauge1(
    TFE_MonitoringBoolGauge1* gauge, const char* label1) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringGetCellBoolGauge1";
  return static_cast<TFE_MonitoringBoolGaugeCell*>(
      static_cast<void*>(gauge->gauge->GetCell(label1)));
}

TFE_MonitoringBoolGauge2* TFE_MonitoringNewBoolGauge2(const char* name,
                                                      TF_Status* status,
                                                      const char* description,
                                                      const char* label1,
                                                      const char* label2) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringNewBoolGauge2";
  auto* result =
      new TFE_MonitoringBoolGauge2({name, description, label1, label2});
  Set_TF_Status_from_Status(status, result->gauge->GetStatus());
  if (!result->gauge->GetStatus().ok()) {
    delete result;
    return nullptr;
  }
  return result;
}

void TFE_MonitoringDeleteBoolGauge2(TFE_MonitoringBoolGauge2* gauge) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringDeleteBoolGauge2";
  delete gauge;
}

TFE_MonitoringBoolGaugeCell* TFE_MonitoringGetCellBoolGauge2(
    TFE_MonitoringBoolGauge2* gauge, const char* label1, const char* label2) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringGetCellBoolGauge2";
  return static_cast<TFE_MonitoringBoolGaugeCell*>(
      static_cast<void*>(gauge->gauge->GetCell(label1, label2)));
}

void TFE_MonitoringSamplerCellAdd(TFE_MonitoringSamplerCell* cell,
                                  double value) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringSamplerCellAdd";
  cell->cell.Add(value);
}

void TFE_MonitoringSamplerCellValue(TFE_MonitoringSamplerCell* cell,
                                    TF_Buffer* buf) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringSamplerCellValue";
  string content;
  cell->cell.value().SerializeToString(&content);
  void* data = tensorflow::port::Malloc(content.length());
  content.copy(static_cast<char*>(data), content.length(), 0);
  buf->data = data;
  buf->length = content.length();
  buf->data_deallocator = [](void* data, size_t length) {
    tensorflow::port::Free(data);
  };
}

TFE_MonitoringBuckets* TFE_MonitoringNewExponentialBuckets(double scale,
                                                           double growth_factor,
                                                           int bucket_count) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringNewExponentialBuckets";
  return new TFE_MonitoringBuckets([scale, growth_factor, bucket_count]() {
    return tensorflow::monitoring::Buckets::Exponential(scale, growth_factor,
                                                        bucket_count);
  });
}

void TFE_MonitoringDeleteBuckets(TFE_MonitoringBuckets* buckets) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringDeleteBuckets";
  delete buckets;
}

TFE_MonitoringSampler0* TFE_MonitoringNewSampler0(
    const char* name, TFE_MonitoringBuckets* buckets, TF_Status* status,
    const char* description) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringNewSampler0";
  auto* result = new TFE_MonitoringSampler0(
      {name, buckets->create_buckets(), description});
  Set_TF_Status_from_Status(status, result->sampler->GetStatus());
  if (!result->sampler->GetStatus().ok()) {
    delete result;
    return nullptr;
  }
  return result;
}

void TFE_MonitoringDeleteSampler0(TFE_MonitoringSampler0* sampler) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringDeleteSampler0";
  delete sampler;
}

TFE_MonitoringSamplerCell* TFE_MonitoringGetCellSampler0(
    TFE_MonitoringSampler0* sampler) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringGetCellSampler0";
  return static_cast<TFE_MonitoringSamplerCell*>(
      static_cast<void*>(sampler->sampler->GetCell()));
}

TFE_MonitoringSampler1* TFE_MonitoringNewSampler1(
    const char* name, TFE_MonitoringBuckets* buckets, TF_Status* status,
    const char* description, const char* label1) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringNewSampler1";
  auto* result = new TFE_MonitoringSampler1(
      {name, buckets->create_buckets(), description, label1});
  Set_TF_Status_from_Status(status, result->sampler->GetStatus());
  if (!result->sampler->GetStatus().ok()) {
    delete result;
    return nullptr;
  }
  return result;
}

void TFE_MonitoringDeleteSampler1(TFE_MonitoringSampler1* sampler) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringDeleteSampler1";
  delete sampler;
}

TFE_MonitoringSamplerCell* TFE_MonitoringGetCellSampler1(
    TFE_MonitoringSampler1* sampler, const char* label1) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringGetCellSampler1";
  return static_cast<TFE_MonitoringSamplerCell*>(
      static_cast<void*>(sampler->sampler->GetCell(label1)));
}

TFE_MonitoringSampler2* TFE_MonitoringNewSampler2(
    const char* name, TFE_MonitoringBuckets* buckets, TF_Status* status,
    const char* description, const char* label1, const char* label2) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringNewSampler2";
  auto* result = new TFE_MonitoringSampler2(
      {name, buckets->create_buckets(), description, label1, label2});
  Set_TF_Status_from_Status(status, result->sampler->GetStatus());
  if (!result->sampler->GetStatus().ok()) {
    delete result;
    return nullptr;
  }
  return result;
}

void TFE_MonitoringDeleteSampler2(TFE_MonitoringSampler2* sampler) {
  delete sampler;
}

TFE_MonitoringSamplerCell* TFE_MonitoringGetCellSampler2(
    TFE_MonitoringSampler2* sampler, const char* label1, const char* label2) {
  LOG(ERROR) << "hello boy ********************************** TFE_MonitoringGetCellSampler2";
  return static_cast<TFE_MonitoringSamplerCell*>(
      static_cast<void*>(sampler->sampler->GetCell(label1, label2)));
}

void TFE_ContextOptionsSetMirroringPolicy(TFE_ContextOptions* options,
                                          TFE_ContextMirroringPolicy policy) {
  LOG(ERROR) << "hello boy ********************************** TFE_ContextOptionsSetMirroringPolicy";
  options->mirroring_policy = policy;
}

void TFE_ContextSetThreadLocalMirroringPolicy(
    TFE_Context* ctx, TFE_ContextMirroringPolicy policy) {
  LOG(ERROR) << "hello boy ********************************** TFE_ContextSetThreadLocalMirroringPolicy";
  ctx->context->SetThreadLocalMirroringPolicy(
      static_cast<tensorflow::ContextMirroringPolicy>(policy));
}

// Note: this function looks up a thread local policy. So it should be called in
// the appropriate client thread. In particular, in async mode, it may not be
// safe to call this function from the async EagerExecutor threads.
extern TFE_ContextMirroringPolicy TFE_ContextGetMirroringPolicy(
    TFE_Context* ctx) {
  LOG(ERROR) << "hello boy ********************************** TFE_ContextMirroringPolicy";
  return static_cast<TFE_ContextMirroringPolicy>(
      ctx->context->GetMirroringPolicy());
}

void TFE_ContextOptionsSetLazyRemoteInputsCopy(TFE_ContextOptions* options,
                                               bool lazy_copy) {
  options->lazy_remote_inputs_copy = lazy_copy;
  LOG(ERROR) << "hello boy ********************************** TFE_ContextOptionsSetLazyRemoteInputsCopy";
}

TFE_CancellationManager* TFE_NewCancellationManager() {
  LOG(ERROR) << "hello boy ********************************** TFE_NewCancellationManager";
  return new TFE_CancellationManager;
}

void TFE_CancellationManagerStartCancel(
    TFE_CancellationManager* cancellation_manager) {
  LOG(ERROR) << "hello boy ********************************** TFE_CancellationManagerStartCancel";
  cancellation_manager->cancellation_manager.StartCancel();
}

bool TFE_CancellationManagerIsCancelled(
    TFE_CancellationManager* cancellation_manager) {
  LOG(ERROR) << "hello boy ********************************** TFE_CancellationManagerIsCancelled";
  return cancellation_manager->cancellation_manager.IsCancelled();
}

void TFE_DeleteCancellationManager(
    TFE_CancellationManager* cancellation_manager) {
  LOG(ERROR) << "hello boy ********************************** TFE_DeleteCancellationManager";
  delete cancellation_manager;
}

void TFE_OpSetCancellationManager(TFE_Op* op,
                                  TFE_CancellationManager* cancellation_manager,
                                  TF_Status* status) {
  LOG(ERROR) << "hello boy ********************************** TFE_OpSetCancellationManager";
  status->status = op->operation->SetCancellationManager(cancellation_manager);
}

TFE_Executor* TFE_NewExecutor(bool is_async) {
  LOG(ERROR) << "hello boy ********************************** TFE_NewExecutor";
  return new TFE_Executor(is_async);
}

void TFE_DeleteExecutor(TFE_Executor* executor) { 
  LOG(ERROR) << "hello boy ********************************** TFE_DeleteExecutor";
  delete executor; }

bool TFE_ExecutorIsAsync(TFE_Executor* executor) {
  LOG(ERROR) << "hello boy ********************************** TFE_ExecutorIsAsync";
  return executor->executor()->Async();
}

void TFE_ExecutorWaitForAllPendingNodes(TFE_Executor* executor,
                                        TF_Status* status) {
  LOG(ERROR) << "hello boy ********************************** TFE_ExecutorWaitForAllPendingNodes";
  status->status = executor->executor()->WaitForAllPendingNodes();
}

void TFE_ExecutorClearError(TFE_Executor* executor) {
  LOG(ERROR) << "hello boy ********************************** TFE_ExecutorClearError";
  executor->executor()->ClearError();
}

void TFE_ContextSetExecutorForThread(TFE_Context* ctx, TFE_Executor* executor) {
  LOG(ERROR) << "hello boy ********************************** TFE_ContextSetExecutorForThread";
  ctx->context->SetExecutorForThread(executor->executor());
}

TFE_Executor* TFE_ContextGetExecutorForThread(TFE_Context* ctx) {
  LOG(ERROR) << "hello boy ********************************** TFE_ContextGetExecutorForThread";
  return new TFE_Executor(&ctx->context->Executor());
}

void TFE_HostAddressSpace(TFE_Context* ctx, TF_Buffer* buf) {
  LOG(ERROR) << "hello boy ********************************** TFE_HostAddressSpace";
  auto address_space = tensorflow::DeviceNameUtils::AddressSpace(
      ctx->context->HostCPU()->parsed_name());
  auto str = tensorflow::DeviceNameUtils::ParsedNameToString(address_space);
  void* data = tensorflow::port::Malloc(str.length());
  str.copy(static_cast<char*>(data), str.length(), 0);
  buf->data = data;
  buf->length = str.length();
  buf->data_deallocator = [](void* data, size_t length) {
    tensorflow::port::Free(data);
  };
}

void TFE_TensorHandleEnableImplicitMirroring(TFE_TensorHandle* h,
                                             TF_Status* status) {
  LOG(ERROR) << "hello boy ********************************** TFE_TensorHandleEnableImplicitMirroring";
  h->handle->EnableImplicitMirroring();
  status->status = tensorflow::Status::OK();
}

void TFE_ContextGetFunctionDef(TFE_Context* ctx, const char* function_name,
                               TF_Buffer* buf, TF_Status* status) {
  LOG(ERROR) << "hello boy ********************************** TFE_ContextGetFunctionDef";
  auto* function_def = ctx->context->FindFunctionDef(function_name);
  if (function_def == nullptr) {
    status->status = tensorflow::errors::NotFound(
        "Unable to find FunctionDef with name: ", function_name);
    return;
  }
  string str = function_def->SerializeAsString();
  void* data = tensorflow::port::Malloc(str.length());
  str.copy(static_cast<char*>(data), str.length(), 0);
  buf->data = data;
  buf->length = str.length();
  buf->data_deallocator = [](void* data, size_t length) {
    tensorflow::port::Free(data);
  };
  status->status = tensorflow::Status::OK();
}
