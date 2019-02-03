#include "DeferredRenderPipeline.h"
#include "SceneManager.h"
#include "MeshRendererComponent.h"

using namespace std;
using namespace AnEngine::Game;
using namespace AnEngine::RenderCore;

namespace AnEngine::RenderCore
{
	void DeferredRenderPipeline::OnRender(std::mutex& sceneResMutex)
	{
		FenceContext::Instance()->WaitAllFence();
		{
			/* GBuffer�׶Σ���Ⱦ����������� GBuffer��Depth Buffer��Normal Buffer */
			lock_guard<mutex> lock(sceneResMutex);
			GBuffer();
		}
		{
			/* ���ڳ����е�ÿһ����Դ�����������ͼ����������Ӱ�� */
			lock_guard<mutex> lock(sceneResMutex);
			DepthPreLight();
		}
		{
			/* ��Ӱ */
			Shadow();
		}
		{
			/* ���� */
		}
		{
			/* ʹ��ǰ����Ⱦ�����͸������ */
		}
		{
			/* ȫ������ */

		}

		{
			/* ����UI��� */
			UI();
		}
	}

	void DeferredRenderPipeline::GBuffer()
	{
		var scene = Game::SceneManager::ActiveScene();
		var objs = scene->GetGroupOfType<Component::MeshRenderer>();	// �ӳ����л�ȡ���е� Mesh Renderer ���������Ⱦ
		const auto& mrs = *objs;
		var[list, allocator] = GraphicsContext::GetOne();
		var ilist = list->GetCommandList();
		var iallocator = allocator->GetAllocator();
		ThrowIfFailed(iallocator->Reset());


		GraphicsContext::Push(list, allocator);
	}

	void DeferredRenderPipeline::DepthPreLight()
	{
	}

	void DeferredRenderPipeline::Shadow()
	{
	}

	void DeferredRenderPipeline::UI()
	{
	}
	void DeferredRenderPipeline::PostProcess()
	{
	}
}