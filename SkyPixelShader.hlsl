struct VertexToPixel
{
	float4 position			: SV_POSITION;
	float3 sampleDir		: DIRECTION;
};

TextureCube skybox			: register(t0)
SamplerState samplerState	: register(s0)

float4 main(VertexToPixel input) : SV_TARGET
{
	return float4(skybox.Sample(samplerState, input.sampleDir).rgb, 1.0f);
}