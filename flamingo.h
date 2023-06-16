#ifndef FLAMINGO_H
#define FLAMINGO_H

#include "Birds.h"

class Flamingo : public Birds
{
public:
	Flamingo() : Birds()
	{
		m_avgHeight = 0.0f;
	}
	Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight) : Birds(color,childs,avgLifetime,incubation)
	{
		this->m_avgHeight = avgHeight;
	}
	Flamingo( ifstream& in_file );//init the Flamingo from a binary file
	virtual ~Flamingo();

public:
	// Getters // 
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	float		GetHeight() const { return m_avgHeight; }//return the avg height of the flamingo
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Setters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void setHeight(float avgHeight)
	{
		this->m_avgHeight = avgHeight;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
    // Override pure virtual functions from the base class
	virtual void printInfo() const override;
	virtual void save(ofstream& out_file) const override;
	virtual void load(ifstream& in_file) override;


protected:
	float m_avgHeight;
};

#endif // ifndef
