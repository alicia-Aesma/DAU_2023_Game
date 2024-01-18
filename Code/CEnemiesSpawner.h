#ifndef CSPAWNERENEMIES_H
#define CSPAWNERENEMIES_H

#include <list>
#include "InfiniteScroller.h"

namespace InfiniteScroller
{

	class CEnemy;

	class CEnemiesSpawner
	{
	public :
		CEnemiesSpawner();
		~CEnemiesSpawner();
		void DisplayEnemies();
		void UpdateEnemies(float deltaTime);
		void SpawnEnemies();
		void HurtEnemies(int damage);

	private :
		std::list<CEnemy> m_enemiesInScene;
		const float m_maxTimeBetweenSpawns{15.0f};
		const float m_minTimeBetweenSpawns{5.0f};
		float m_timeBetweenSpawn{0};
		float m_currentTimeBetweenSpawn{ m_minTimeBetweenSpawns };


	};

}
#endif // !CSPAWNERENEMIES_H

