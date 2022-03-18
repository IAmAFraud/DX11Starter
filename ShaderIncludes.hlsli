#ifndef __GGP_SHADER_INCLUDES__
#define __GGP_SHADER_INCLUDES__

// Structs

struct VertexToPixel
{
	float4 screenPosition	: SV_POSITION;
	float2 uv				: TEXCOORD;
	float3 normal			: NORMAL;
	float3 worldPosition	: POSITION;
};

struct VertexShaderInput
{
	float3 localPosition	: POSITION;     // XYZ position
	float3 normal			: NORMAL;
	float2 uv				: TEXCOORD;
};



#endif