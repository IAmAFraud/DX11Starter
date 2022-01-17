#pragma once

#include "Vertex.h"
#include <d3d11.h>
#include <wrl/client.h>

class Mesh
{
	private:
		Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> indexBuffer;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> context;
		int numIndices;

	public:
		Mesh(
			Vertex* _vertices,
			int _numVertices,
			unsigned int* _indices,
			int _numIndicies,
			Microsoft::WRL::ComPtr<ID3D11Device> _device,
			Microsoft::WRL::ComPtr<ID3D11DeviceContext> _context);
		~Mesh(); // Deconstructor

		// GetVertexBuffer();	// Need DataType
		// GetIndexBuffer();	// Need DataType
		int GetIndexCount();
		void Draw();
};

