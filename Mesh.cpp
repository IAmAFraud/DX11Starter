#include "Mesh.h"

/// <summary>
/// Parameterized Constructor for the Mesh
/// </summary>
/// <param name="_vertices">A collection of vertices to be used in the mesh</param>
/// <param name="_numVertices">The number of vertices in the mesh</param>
/// <param name="_indices">A collection of unsigned ints that determine the order to use the vertices in</param>
/// <param name="_numIndices">The number of indices in drawing the mesh</param>
/// <param name="_device">A reference to the device object</param>
/// <param name="_context">A reference to the context object</param>
Mesh::Mesh(Vertex* _vertices, int _numVertices, unsigned int* _indices, int _numIndices, Microsoft::WRL::ComPtr<ID3D11Device> _device, Microsoft::WRL::ComPtr<ID3D11DeviceContext> _context)
{
	// Connect appropriate fields
	numIndices = _numIndices;
	context = _context;

	// Sets Up The Vertex Buffer
	// Creates the Vertex Buffer Description
	D3D11_BUFFER_DESC vbd = {};
	vbd.Usage = D3D11_USAGE_IMMUTABLE;
	vbd.ByteWidth = sizeof(Vertex) * _numVertices;
	vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vbd.CPUAccessFlags = 0;
	vbd.MiscFlags = 0;
	vbd.StructureByteStride = 0;

	// Create struct to hold vertex data
	D3D11_SUBRESOURCE_DATA initialVertexData = {};
	initialVertexData.pSysMem = _vertices;

	// Create the Vertex Buffer with the appropriate data
	_device->CreateBuffer(&vbd, &initialVertexData, vertexBuffer.GetAddressOf());

	// Sets up the Index Buffer
	// Creates the Index Buffer Description
	D3D11_BUFFER_DESC ibd = {};
	ibd.Usage = D3D11_USAGE_IMMUTABLE;
	ibd.ByteWidth = sizeof(unsigned int) * numIndices;
	ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;
	ibd.CPUAccessFlags = 0;
	ibd.MiscFlags = 0;
	ibd.StructureByteStride = 0;

	// Create struct to hold index data
	D3D11_SUBRESOURCE_DATA initialIndexData = {};
	initialIndexData.pSysMem = _indices;

	// Create the Index Buffer with the appropriate data
	_device->CreateBuffer(&ibd, &initialIndexData, indexBuffer.GetAddressOf());
}

// Deconstructor (Currently empty as all pointers delete themselves)
Mesh::~Mesh()
{
}

/// <summary>
/// Returns a reference to the mesh's vertex buffer
/// </summary>
Microsoft::WRL::ComPtr<ID3D11Buffer> Mesh::GetVertexBuffer()
{
	return vertexBuffer;
}

/// <summary>
/// Returns a reference to the mesh's index buffer
/// </summary>
/// <returns></returns>
Microsoft::WRL::ComPtr<ID3D11Buffer> Mesh::GetIndexBuffer()
{
	return indexBuffer;
}

/// <summary>
/// Returns the number of indices in the mesh
/// </summary>
int Mesh::GetIndexCount()
{
	return numIndices;
}