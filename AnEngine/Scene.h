#pragma once
#ifndef __SCENE_H__
#define __SCENE_H__

#include "onwind.h"
#include "BaseBehaviour.h"
#include "GameObject.h"
#include "Camera.h"
//#include "GameEntity.h"
#include "GroupWarper.h"
#include <condition_variable>

namespace AnEngine::Game
{
	// Scene仅作为GameObject的集合，同时待ECS完成后也是Entity或Component的集合。
	class Scene : public Object//, public NonCopyable
	{
		// Scene直接调度BaseBehaviour
		//friend class ::AnEngine::Engine;

		std::vector<GameObject*> m_objects;

		std::map<size_t, void*> m_componentGroups;

		//std::vector<ECBS::GameEntity*> m_entities;
		//std::vector<ObjectBehaviour*> m_objects;
		//Camera* defaultCamera;

		//std::condition_variable m_cv;
		std::mutex m_behaviourMutex;
		uint32_t m_complateCount;

		bool m_frameLoop;

	public:
		//Scene(std::wstring _name);
		Scene(std::wstring&& _name);
		Scene(const std::wstring& _name);
		virtual ~Scene() = default;

		std::wstring name;

		void AddObject(GameObject* obj);
		void RemoveObject(GameObject* obj);
		std::vector<GameObject*> GetAllGameObject() { return m_objects; }

		template<typename T>
		ComponentGroup<T>* GetGroupOfType()
		{
			return (ComponentGroup<T>*)m_componentGroups[typeid(T).hash_code()];
		}

		/*template<typename T>
		std::vector<T*> GetAllComponentOfType()
		{
			std::vector<T*> ret;
			for (var i : m_objects)
			{
				//if(i.)
			}
			return ret;
		}*/

		/*void AddEntity(ECBS::GameEntity* entity);
		void RemoveEntity(ECBS::GameEntity* entity);
		std::vector<ECBS::GameEntity*> GetAllEntities() { return m_entities; }*/
	};
}

#endif // !__SCENE_H__
