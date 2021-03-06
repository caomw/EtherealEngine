#pragma once

#include "../ecs.h"
#include <vector>
#include <memory>
#include <chrono>

namespace runtime
{

	struct LodData
	{
		std::uint32_t current_lod_index = 0;
		std::uint32_t target_lod_index = 0;
		float current_time = 0.0f;
	};

	class RenderingSystem : public core::Subsystem
	{
	public:
		//-----------------------------------------------------------------------------
		//  Name : frameRender (virtual )
		/// <summary>
		/// 
		/// 
		/// 
		/// </summary>
		//-----------------------------------------------------------------------------
		void frame_render(std::chrono::duration<float> dt);

		//-----------------------------------------------------------------------------
		//  Name : configure ()
		/// <summary>
		/// 
		/// 
		/// 
		/// </summary>
		//-----------------------------------------------------------------------------
		void receive(Entity e);
		bool initialize() override;
		void dispose() override;
	private:
		std::unordered_map<Entity, std::unordered_map<Entity, LodData>> _lod_data;
	};

}