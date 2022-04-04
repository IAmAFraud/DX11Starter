#include "ShaderIncludes.hlsli"


cbuffer ExternalData : register(b0)
{
	float4 colorTint;
	float3 cameraPosition;
	float roughness;
	float3 cameraPos;
	float3 ambientLight;
	float uvScale;
	float2 uvOffset;
	Light directionalLight1;
	Light directionalLight2;
	Light directionalLight3;
	Light pointLight1;
	Light pointLight2;
}

Texture2D SurfaceTexture	: register(t0);
Texture2D NormalMap			: register(t1);
SamplerState BasicSampler	: register(s0);

float3 Attenuate(Light light, float3 worldPos)
{
	float dist = distance(light.Position, worldPos);
	float att = saturate(1.0f - (dist * dist / (light.Range * light.Range)));
	return att * att;
}


float3 CalculateDirectionalLight(Light light, VertexToPixel inputData)
{
	// Normalized direction to the light
	float3 dirToLight = normalize(-light.Direction);

	// Calculate Diffuse Amount
	float diffuseAmount = saturate(dot(inputData.normal, dirToLight));
	
	// Specular for light
	float specExponent = (1.0f - roughness) * MAX_SPECULAR_EXPONENT;
	float specular;
	if (specExponent > 0.05f)
	{
		float3 viewVectorToCam = normalize(cameraPosition - inputData.worldPosition);
		float3 reflVector = reflect(-dirToLight, inputData.normal);
		specular = pow(saturate(dot(reflVector, viewVectorToCam)), specExponent);
	}
	

	// Calculate the final color
	float3 lightColor = ((diffuseAmount * light.Color * colorTint) + (ambientLight * colorTint) + specular) * light.Intensity;
	return lightColor;
}


float3 CalculatePointLight(Light light, VertexToPixel inputData)
{
	// Normalized direction to the light
	float3 dirToLight = normalize(light.Position - inputData.worldPosition);

	// Calculate Diffuse Amount
	float diffuseAmount = saturate(dot(inputData.normal, dirToLight));

	// Specular for light
	float specExponent = (1.0f - roughness) * MAX_SPECULAR_EXPONENT;
	float specular;
	if (specExponent > 0.05f)
	{
		float3 viewVectorToCam = normalize(cameraPosition - inputData.worldPosition);
		float3 reflVector = reflect(-dirToLight, inputData.normal);
		specular = pow(saturate(dot(reflVector, viewVectorToCam)), specExponent);
	}

	// Calculate the final color
	float3 lightColor = ((diffuseAmount * light.Color * colorTint) + (ambientLight * colorTint) + specular) * Attenuate(light, inputData.worldPosition) * light.Intensity;
	return lightColor;
}


// --------------------------------------------------------
// The entry point (main method) for our pixel shader
// 
// - Input is the data coming down the pipeline (defined by the struct)
// - Output is a single color (float4)
// - Has a special semantic (SV_TARGET), which means 
//    "put the output of this into the current render target"
// - Named "main" because that's the default the shader compiler looks for
// --------------------------------------------------------
float4 main(VertexToPixel input) : SV_TARGET
{
	// Normalize the normals
	input.normal = normalize(input.normal);

	// Scales/Shifts the uvs
	input.uv = (input.uv + uvOffset) * uvScale;

	// Unpacks the normals
	float3 unpackedNormal = NormalMap.Sample(BasicSampler, input.uv).rgb * 2 - 1;

	// Creates a TBN matrix
	float3 N = input.normal;
	float3 T = normalize(input.tangent);
	T = normalize(T - N * dot(T, N));
	float3 B = cross(T, N);
	float3x3 TBN = float3x3(T, B, N);

	// Transform the unpacked normal
	input.normal = mul(unpackedNormal, TBN);

	// Sets texture colors
	float3 surfaceColor = SurfaceTexture.Sample(BasicSampler, input.uv).rgb;

	// Tints the surface color with material surface
	surfaceColor = surfaceColor * colorTint;

	// Adds lights values to the object
	float3 finalColor = surfaceColor + CalculateDirectionalLight(directionalLight1, input) + CalculateDirectionalLight(directionalLight2, input) + CalculateDirectionalLight(directionalLight3, input);
	finalColor += CalculatePointLight(pointLight1, input) + CalculatePointLight(pointLight2, input);

	return float4(finalColor, 1);
}