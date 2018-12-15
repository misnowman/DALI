// Copyright (c) 2017-2018, NVIDIA CORPORATION. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef DALI_PIPELINE_OPERATORS_READER_NVDECODER_CUVIDEODECODER_H_
#define DALI_PIPELINE_OPERATORS_READER_NVDECODER_CUVIDEODECODER_H_

#include "dali/pipeline/operators/reader/nvdecoder/dynlink_nvcuvid.h"
#include "dali/error_handling.h"

namespace dali {

class CUVideoDecoder {
 public:
  CUVideoDecoder();
  explicit CUVideoDecoder(CUvideodecoder);
  ~CUVideoDecoder();

  // no copying
  CUVideoDecoder(const CUVideoDecoder&) = delete;
  CUVideoDecoder& operator=(const CUVideoDecoder&) = delete;

  CUVideoDecoder(CUVideoDecoder&& other);
  CUVideoDecoder& operator=(CUVideoDecoder&& other);

  operator CUvideodecoder() const;

  int initialize(CUVIDEOFORMAT* format);
  bool initialized() const;

  uint16_t width() const;
  uint16_t height() const;

 private:
  CUvideodecoder decoder_;
  CUVIDDECODECREATEINFO decoder_info_;

  bool initialized_;
};

}  // namespace dali

#endif  // DALI_PIPELINE_OPERATORS_READER_NVDECODER_CUVIDEODECODER_H_
