#include "GameEngineRenderer.h"
#include "GameEngineActor.h"
#include "GameEngineLevel.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>

#include "GameEngineVertexBuffer.h"
#include "GameEngineIndexBuffer.h"

GameEngineRenderer::GameEngineRenderer() 
{
}

GameEngineRenderer::~GameEngineRenderer() 
{
}


void GameEngineRenderer::Start() 
{
	GetActor()->GetLevel()->PushRenderer(this);
}

float Angle = 0.0f;
void GameEngineRenderer::Render(float _DeltaTime)
{
	// 랜더링
	GameEngineVertexBuffer* Vertex = GameEngineVertexBuffer::Find("Tri");
	GameEngineIndexBuffer* Index = GameEngineIndexBuffer::Find("Tri");

	Angle += _DeltaTime * 360.0f;

	std::vector<POINT> DrawVertex;
	DrawVertex.resize(Index->Indexs.size());

	std::vector<float4> CopyBuffer;
	CopyBuffer.resize(Index->Indexs.size());



	for (size_t i = 0; i < Index->Indexs.size(); i++)
	{
		int TriIndex = Index->Indexs[i];

		// 0 번째 순서의 점이 됩니다.
		CopyBuffer[i] = Vertex->Vertexs[TriIndex];

		// [0.5f] [0.5f] []                  [100] [100] [] 
		// 크
		CopyBuffer[i] *= GetActor()->GetTransform().GetScale();

		// 자전
		CopyBuffer[i] = float4::VectorRotationToDegreeZ(CopyBuffer[i], Angle);

		// 이동
		CopyBuffer[i] += GetActor()->GetTransform().GetPosition();

		

		DrawVertex[i] = CopyBuffer[i].GetConvertWindowPOINT();
	}

	for (size_t i = 0; i < DrawVertex.size(); i += 3)
	{
		Polygon(GameEngineWindow::GetHDC(), &DrawVertex[i], 3);
	}
}