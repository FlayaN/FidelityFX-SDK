// This file is part of the FidelityFX SDK.
//
// Copyright (C) 2024 Advanced Micro Devices, Inc.
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#if FFX_HLSL_SM > 60
#define FFX_WAVE 1
#endif

#define FFX_OPTICALFLOW_BIND_SRV_OPTICAL_FLOW_INPUT                0
#define FFX_OPTICALFLOW_BIND_SRV_OPTICAL_FLOW_PREVIOUS_INPUT       1

#define FFX_OPTICALFLOW_BIND_UAV_OPTICAL_FLOW                      0
#define FFX_OPTICALFLOW_BIND_UAV_OPTICAL_FLOW_SCD_OUTPUT           1

#define FFX_OPTICALFLOW_BIND_CB_COMMON                             0

#include "opticalflow/ffx_opticalflow_callbacks_hlsl.h"

#ifndef FFX_OPTICALFLOW_BLOCK_SIZE
#define FFX_OPTICALFLOW_BLOCK_SIZE 8
#endif
#ifndef FFX_OPTICALFLOW_THREAD_GROUP_WIDTH
#define FFX_OPTICALFLOW_THREAD_GROUP_WIDTH 64
#endif // #ifndef FFX_OPTICALFLOW_THREAD_GROUP_WIDTH
#ifndef FFX_OPTICALFLOW_THREAD_GROUP_HEIGHT
#define FFX_OPTICALFLOW_THREAD_GROUP_HEIGHT 1
#endif // #ifndef FFX_OPTICALFLOW_THREAD_GROUP_HEIGHT
#ifndef FFX_OPTICALFLOW_THREAD_GROUP_DEPTH
#define FFX_OPTICALFLOW_THREAD_GROUP_DEPTH 1
#endif // #ifndef FFX_OPTICALFLOW_THREAD_GROUP_DEPTH

#include "opticalflow/ffx_opticalflow_compute_optical_flow_v5.h"

#ifndef FFX_OPTICALFLOW_NUM_THREADS
#define FFX_OPTICALFLOW_NUM_THREADS [numthreads(FFX_OPTICALFLOW_THREAD_GROUP_WIDTH, FFX_OPTICALFLOW_THREAD_GROUP_HEIGHT, FFX_OPTICALFLOW_THREAD_GROUP_DEPTH)]
#endif // #ifndef FFX_OPTICALFLOW_NUM_THREADS

FFX_OPTICALFLOW_NUM_THREADS
FFX_OPTICALFLOW_EMBED_ROOTSIG_CONTENT
FFX_PREFER_WAVE64
void CS(int2 iGlobalId          : SV_DispatchThreadID,
        int2 iLocalId           : SV_GroupThreadID,
        int2 iGroupId           : SV_GroupID,
        int  iLocalIndex        : SV_GroupIndex)
{
    ComputeOpticalFlowAdvanced(iGlobalId, iLocalId, iGroupId, iLocalIndex);
}
