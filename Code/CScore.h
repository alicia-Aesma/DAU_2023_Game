#ifndef CSCORE_H
#define CSCORE_H

namespace InfiniteScroller
{
	class CScore
	{
	public:
		CScore() = default;
		~CScore() = default;
		void DisplayScore();
		void AddValueScore(float value);
		void ResetScore();
		void UpdateScore(float deltaTime);

	private:
		float m_score{ 0 };
		float m_scoreGain{ 1.0f };
	};
}
#endif // !CSCORE_H
