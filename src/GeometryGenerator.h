#ifndef GEOMETRYGENERATOR_H
#define GEOMETRYGENERATOR_H

#include <glm\glm.hpp>
#include <vector>

typedef unsigned int        UINT;


class GeometryGenerator
{
public:
	struct Vertex
	{
		Vertex(){}
		Vertex(const glm::vec3& p, const glm::vec3& n, const glm::vec3& t, const glm::vec3& uv)
			: Position(p), Normal(n), TangentU(t), TexC(uv){}
		Vertex(
			float px, float py, float pz, 
			float nx, float ny, float nz,
			float tx, float ty, float tz,
			float u, float v)
			: Position(px,py,pz), Normal(nx,ny,nz),
			  TangentU(tx, ty, tz), TexC(u,v){}

		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec3 TangentU;
		glm::vec2 TexC;
	};

	struct MeshData
	{
		std::vector<Vertex> Vertices;
		std::vector<UINT> Indices;
	};

	void CreateBox(float width, float height, float depth, MeshData& meshData);

	void CreateSkyBox(float width, float height, float depth, MeshData& meshData);

	void CreateSphere(float radius, UINT sliceCount, UINT stackCount, MeshData& meshData);

	void CreateGeosphere(float radius, UINT numSubdivisions, MeshData& meshData);

	void CreateCylinder(float bottomRadius, float topRadius, float height, UINT sliceCount, UINT stackCount, MeshData& meshData);

	void CreateGrid(float width, float depth, UINT m, UINT n, MeshData& meshData);

	void CreateFullscreenQuad(MeshData& meshData);

private:
	void Subdivide(MeshData& meshData);
	void BuildCylinderTopCap(float bottomRadius, float topRadius, float height, UINT sliceCount, UINT stackCount, MeshData& meshData);
	void BuildCylinderBottomCap(float bottomRadius, float topRadius, float height, UINT sliceCount, UINT stackCount, MeshData& meshData);
};

#endif // GEOMETRYGENERATOR_H