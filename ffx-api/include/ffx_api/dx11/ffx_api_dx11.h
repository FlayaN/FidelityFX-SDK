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
#include "../ffx_api.h"
#include "../ffx_api_types.h"
#include <d3d11.h>
#include <dxgi.h>
#include <dxgi1_5.h>

#define FFX_API_CREATE_CONTEXT_DESC_TYPE_BACKEND_DX11 0x0000002u
struct ffxCreateBackendDX11Desc
{
    ffxCreateContextDescHeader header;
    ID3D11Device*              device;  ///< Device on which the backend will run.
};

#if defined(__cplusplus)

static inline uint32_t ffxApiGetSurfaceFormatDX11(DXGI_FORMAT format)
{
    switch (format)
    {
    case DXGI_FORMAT_R32G32B32A32_TYPELESS:
        return FFX_API_SURFACE_FORMAT_R32G32B32A32_TYPELESS;
    case DXGI_FORMAT_R32G32B32A32_FLOAT:
        return FFX_API_SURFACE_FORMAT_R32G32B32A32_FLOAT;
    case DXGI_FORMAT_R32G32B32A32_UINT:
        return FFX_API_SURFACE_FORMAT_R32G32B32A32_UINT;
        //case DXGI_FORMAT_R32G32B32A32_SINT:
        //case DXGI_FORMAT_R32G32B32_TYPELESS:
        //case DXGI_FORMAT_R32G32B32_FLOAT:
        //case DXGI_FORMAT_R32G32B32_UINT:
        //case DXGI_FORMAT_R32G32B32_SINT:

    case DXGI_FORMAT_R16G16B16A16_TYPELESS:
    case DXGI_FORMAT_R16G16B16A16_FLOAT:
        return FFX_API_SURFACE_FORMAT_R16G16B16A16_FLOAT;
        //case DXGI_FORMAT_R16G16B16A16_UNORM:
        //case DXGI_FORMAT_R16G16B16A16_UINT:
        //case DXGI_FORMAT_R16G16B16A16_SNORM:
        //case DXGI_FORMAT_R16G16B16A16_SINT:

    case DXGI_FORMAT_R32G32_TYPELESS:
    case DXGI_FORMAT_R32G32_FLOAT:
        return FFX_API_SURFACE_FORMAT_R32G32_FLOAT;
        //case DXGI_FORMAT_R32G32_FLOAT:
        //case DXGI_FORMAT_R32G32_UINT:
        //case DXGI_FORMAT_R32G32_SINT:

    case DXGI_FORMAT_R32G8X24_TYPELESS:
    case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:
    case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS:
        return FFX_API_SURFACE_FORMAT_R32_FLOAT;

    case DXGI_FORMAT_R24G8_TYPELESS:
    case DXGI_FORMAT_D24_UNORM_S8_UINT:
    case DXGI_FORMAT_R24_UNORM_X8_TYPELESS:
        return FFX_API_SURFACE_FORMAT_R32_UINT;

    case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT:
    case DXGI_FORMAT_X24_TYPELESS_G8_UINT:
        return FFX_API_SURFACE_FORMAT_R8_UINT;

    case DXGI_FORMAT_R10G10B10A2_TYPELESS:
    case DXGI_FORMAT_R10G10B10A2_UNORM:
        return FFX_API_SURFACE_FORMAT_R10G10B10A2_UNORM;
        //case DXGI_FORMAT_R10G10B10A2_UINT:

    case DXGI_FORMAT_R11G11B10_FLOAT:
        return FFX_API_SURFACE_FORMAT_R11G11B10_FLOAT;

    case DXGI_FORMAT_R8G8B8A8_TYPELESS:
        return FFX_API_SURFACE_FORMAT_R8G8B8A8_TYPELESS;
    case DXGI_FORMAT_R8G8B8A8_UNORM:
        return FFX_API_SURFACE_FORMAT_R8G8B8A8_UNORM;
    case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
        return FFX_API_SURFACE_FORMAT_R8G8B8A8_SRGB;
    //case DXGI_FORMAT_R8G8B8A8_UINT:
    case DXGI_FORMAT_R8G8B8A8_SNORM:
        return FFX_API_SURFACE_FORMAT_R8G8B8A8_SNORM;

    case DXGI_FORMAT_B8G8R8A8_TYPELESS:
        return FFX_API_SURFACE_FORMAT_B8G8R8A8_TYPELESS;
    case DXGI_FORMAT_B8G8R8A8_UNORM:
        return FFX_API_SURFACE_FORMAT_B8G8R8A8_UNORM;
    case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
        return FFX_API_SURFACE_FORMAT_B8G8R8A8_SRGB;

    case DXGI_FORMAT_R16G16_TYPELESS:
    case DXGI_FORMAT_R16G16_FLOAT:
        return FFX_API_SURFACE_FORMAT_R16G16_FLOAT;
    //case DXGI_FORMAT_R16G16_UNORM:
    case DXGI_FORMAT_R16G16_UINT:
        return FFX_API_SURFACE_FORMAT_R16G16_UINT;
    //case DXGI_FORMAT_R16G16_SNORM
    //case DXGI_FORMAT_R16G16_SINT

    //case DXGI_FORMAT_R32_SINT:
    case DXGI_FORMAT_R32_UINT:
        return FFX_API_SURFACE_FORMAT_R32_UINT;
    case DXGI_FORMAT_R32_TYPELESS:
    case DXGI_FORMAT_D32_FLOAT:
    case DXGI_FORMAT_R32_FLOAT:
        return FFX_API_SURFACE_FORMAT_R32_FLOAT;

    case DXGI_FORMAT_R8G8_TYPELESS:
    case DXGI_FORMAT_R8G8_UINT:
        return FFX_API_SURFACE_FORMAT_R8G8_UINT;
        //case DXGI_FORMAT_R8G8_UNORM:
        //case DXGI_FORMAT_R8G8_SNORM:
        //case DXGI_FORMAT_R8G8_SINT:

    case DXGI_FORMAT_R16_TYPELESS:
    case DXGI_FORMAT_R16_FLOAT:
        return FFX_API_SURFACE_FORMAT_R16_FLOAT;
    case DXGI_FORMAT_R16_UINT:
        return FFX_API_SURFACE_FORMAT_R16_UINT;
    case DXGI_FORMAT_D16_UNORM:
    case DXGI_FORMAT_R16_UNORM:
        return FFX_API_SURFACE_FORMAT_R16_UNORM;
    case DXGI_FORMAT_R16_SNORM:
        return FFX_API_SURFACE_FORMAT_R16_SNORM;
        //case DXGI_FORMAT_R16_SINT:

    case DXGI_FORMAT_R8_TYPELESS:
    case DXGI_FORMAT_R8_UNORM:
    case DXGI_FORMAT_A8_UNORM:
        return FFX_API_SURFACE_FORMAT_R8_UNORM;
    case DXGI_FORMAT_R8_UINT:
        return FFX_API_SURFACE_FORMAT_R8_UINT;
        //case DXGI_FORMAT_R8_SNORM:
        //case DXGI_FORMAT_R8_SINT:
        //case DXGI_FORMAT_R1_UNORM:

    case DXGI_FORMAT_UNKNOWN:
    default:
        return FFX_API_SURFACE_FORMAT_UNKNOWN;
    }
}

static inline FfxApiResource ffxApiGetResourceDX11(ID3D11Resource* pRes, uint32_t state = FFX_API_RESOURCE_STATE_COMPUTE_READ, uint32_t additionalUsages = 0)
{
    FfxApiResource res{};
    res.resource = pRes;
    res.state    = state;
    if (!pRes)
        return res;

    D3D11_RESOURCE_DIMENSION dimension = {};
    pRes->GetType(&dimension);

    if (dimension == D3D11_RESOURCE_DIMENSION_BUFFER)
    {
        D3D11_BUFFER_DESC desc = {};
        reinterpret_cast<ID3D11Buffer*>(pRes)->GetDesc(&desc);
        res.description.flags  = FFX_API_RESOURCE_FLAGS_NONE;
        res.description.usage  = FFX_API_RESOURCE_USAGE_UAV;
        res.description.size   = static_cast<uint32_t>(desc.ByteWidth);
        res.description.stride = 1;
        res.description.type   = FFX_API_RESOURCE_TYPE_BUFFER;
    }
    else
    {
        res.description.flags = FFX_API_RESOURCE_FLAGS_NONE;
        switch (dimension)
        {
            switch (dimension)
            {
            case D3D11_RESOURCE_DIMENSION_TEXTURE1D:
            {
                D3D11_TEXTURE1D_DESC desc = {};
                reinterpret_cast<ID3D11Texture1D*>(pRes)->GetDesc(&desc);

                res.description.type  = FFX_API_RESOURCE_TYPE_TEXTURE1D;
                res.description.usage = (desc.Format == DXGI_FORMAT_D16_UNORM) || (desc.Format == DXGI_FORMAT_D32_FLOAT) ||
                                                (desc.Format == DXGI_FORMAT_D24_UNORM_S8_UINT) || (desc.Format == DXGI_FORMAT_D32_FLOAT_S8X24_UINT)
                                            ? FFX_API_RESOURCE_USAGE_DEPTHTARGET
                                            : FFX_API_RESOURCE_USAGE_READ_ONLY;
                if ((desc.BindFlags & D3D11_BIND_UNORDERED_ACCESS) == D3D11_BIND_UNORDERED_ACCESS)
                    res.description.usage |= FFX_API_RESOURCE_USAGE_UAV;

                res.description.width    = desc.Width;
                res.description.height   = 1;
                res.description.depth    = 1;
                res.description.mipCount = desc.MipLevels;
                res.description.format   = ffxApiGetSurfaceFormatDX11(desc.Format);
                break;
            }
            case D3D11_RESOURCE_DIMENSION_TEXTURE2D:
            {
                D3D11_TEXTURE2D_DESC desc = {};
                reinterpret_cast<ID3D11Texture2D*>(pRes)->GetDesc(&desc);

                if (desc.ArraySize == 1)
                    res.description.type = FFX_API_RESOURCE_TYPE_TEXTURE2D;
                else if (desc.ArraySize == 6)
                    res.description.type = FFX_API_RESOURCE_TYPE_TEXTURE_CUBE;
                else
                    res.description.type = FFX_API_RESOURCE_TYPE_TEXTURE2D;
                res.description.usage = (desc.Format == DXGI_FORMAT_D16_UNORM) || (desc.Format == DXGI_FORMAT_D32_FLOAT) ||
                                                (desc.Format == DXGI_FORMAT_D24_UNORM_S8_UINT) || (desc.Format == DXGI_FORMAT_D32_FLOAT_S8X24_UINT)
                                            ? FFX_API_RESOURCE_USAGE_DEPTHTARGET
                                            : FFX_API_RESOURCE_USAGE_READ_ONLY;
                if ((desc.BindFlags & D3D11_BIND_UNORDERED_ACCESS) == D3D11_BIND_UNORDERED_ACCESS)
                    res.description.usage |= FFX_API_RESOURCE_USAGE_UAV;

                res.description.width    = desc.Width;
                res.description.height   = desc.Height;
                res.description.depth    = desc.ArraySize;
                res.description.mipCount = desc.MipLevels;
                res.description.format   = ffxApiGetSurfaceFormatDX11(desc.Format);
                break;
            }
            case D3D11_RESOURCE_DIMENSION_TEXTURE3D:
            {
                D3D11_TEXTURE3D_DESC desc = {};
                reinterpret_cast<ID3D11Texture3D*>(pRes)->GetDesc(&desc);

                res.description.type  = FFX_API_RESOURCE_TYPE_TEXTURE3D;
                res.description.usage = (desc.Format == DXGI_FORMAT_D16_UNORM) || (desc.Format == DXGI_FORMAT_D32_FLOAT) ||
                                                (desc.Format == DXGI_FORMAT_D24_UNORM_S8_UINT) || (desc.Format == DXGI_FORMAT_D32_FLOAT_S8X24_UINT)
                                            ? FFX_API_RESOURCE_USAGE_DEPTHTARGET
                                            : FFX_API_RESOURCE_USAGE_READ_ONLY;
                if ((desc.BindFlags & D3D11_BIND_UNORDERED_ACCESS) == D3D11_BIND_UNORDERED_ACCESS)
                    res.description.usage |= FFX_API_RESOURCE_USAGE_UAV;

                res.description.width    = desc.Width;
                res.description.height   = desc.Height;
                res.description.depth    = desc.Depth;
                res.description.mipCount = desc.MipLevels;
                res.description.format   = ffxApiGetSurfaceFormatDX11(desc.Format);
                break;
            }
            }
        }

        res.description.usage |= additionalUsages;
        return res;
    }
}
#endif