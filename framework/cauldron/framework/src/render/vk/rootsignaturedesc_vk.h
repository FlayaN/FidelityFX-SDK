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

#pragma once

#if defined(_VK)

#include "render/rootsignaturedesc.h"

#include <vulkan/vulkan.h>
#include <vector>

namespace cauldron
{
    struct BindingInfo
    {
        BindingType Type;
        uint32_t BaseShaderRegister;
        uint32_t BindingIndex;
        uint32_t Count;
        VkShaderStageFlags StageFlags;
    };

    struct PushConstantInfo
    {
        uint32_t           BaseShaderRegister;
        uint32_t           Count;
        VkShaderStageFlags StageFlags;
    };

    struct RootSignatureDescInternal final
    {
        bool IsBindingUsed(BindingType type, uint32_t baseShaderRegister, uint32_t count);
        void AddBinding(BindingType type, uint32_t baseShaderRegister, uint32_t bindingIndex, ShaderBindStage bindStages, uint32_t count);
        void AddStaticSamplerBinding(uint32_t baseShaderRegister, uint32_t bindingIndex, ShaderBindStage bindStages, uint32_t count, const SamplerDesc* samplerDescList);

        // Internal members
        std::vector<BindingInfo> m_Bindings;
        std::vector<BindingInfo> m_ImmutableSamplersBindings;
        std::vector<SamplerDesc> m_ImmutableSamplers;
        std::vector<PushConstantInfo> m_PushConstantInfo;
    };

} // namespace cauldron

#endif // #if defined(_VK)
