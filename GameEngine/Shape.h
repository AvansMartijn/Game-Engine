#pragma once

#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_SHAPE __declspec(dllexport)
#else
#define GAMEENGINE_SHAPE __declspec(dllimport)
#endif

#include "Body.h"
//rectangles only
#define MaxPolyVertexCount 4

class GAMEENGINE_SHAPE Shape
{
public:
	Body body;
	Vec2 min;
	Vec2 max;
	//for polygonshape
	Mat2 u;
	int getWidth();
	int getHeight();
	int getWidthFromVertice();
	int getHeightFromVertice();
	void Initialize();
	void SetOrient(real radians);
	void ComputeMass(real density);
	void Set(Vec2* vertices, uint32 count);
	void SetBox(real hw, real hh);
	uint32 m_vertexCount;
	Vec2 m_vertices[MaxPolyVertexCount];
	Vec2 m_normals[MaxPolyVertexCount];
	Vec2 GetSupport(const Vec2& dir);
};

