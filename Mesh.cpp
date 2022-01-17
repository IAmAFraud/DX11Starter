#include "Mesh.h"


Mesh::Mesh(Vertex* _vertices, int _numVertices, unsigned int* _indicies, int _numIndices, Microsoft::WRL::ComPtr<ID3D11Device> _device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> _context)
{
	// Connect appropriate fields
	numIndices = _numIndices;
	context = _context;

	// Set up vertex buffer



	// Set up index buffer
}