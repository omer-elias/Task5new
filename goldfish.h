#ifndef GOLDFISH_H
#define GOLDFISH_H

#include "MammalsFish.h"

class GoldFish : public MammalsFish
{
public:
	GoldFish() : MammalsFish() {
		m_avgWeight = 0.0f;
		m_avgLength = 0.0f;
	};
	GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL) : MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills)
	{
		m_avgWeight = 0.0f;
		m_avgLength = 0.0f;
	}
	GoldFish( ifstream& in_file );//init the GoldFish from a binary file
	virtual ~GoldFish();

public:

	// Getters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	float		GetWeight() const { return m_avgWeight; }//return the avg weight of the gold fish
	float		GetLength() const { return m_avgLength; };//return the avg length of the gold fish
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Setters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetWeight(float avgWeight)
	{
		this->m_avgWeight = avgWeight;
	}
	void SetLength(float length)
	{
		this->m_avgLength = length;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
protected:
	float m_avgWeight;
	float m_avgLength;
};

#endif // ifndef
