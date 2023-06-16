#ifndef BIRDS_H
#define BIRDS_H

#include "Animal.h"

class Birds : public Animal
{
public:
	Birds() : Animal() {
		m_incubationTime = 0.0f;
	};
	Birds(const char* color, int childs, float avgLifetime, float incubation) : Animal(color,childs,avgLifetime)
	{
		this->m_incubationTime = incubation;
	}
	Birds( ifstream& in_file );//init the Birds from a binary file
	virtual ~Birds();

public:


	// Getters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	float		GetIncubationTime() const {
		return m_incubationTime;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Setters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetIncubationTime(float incubationTime)
	{
		this->m_incubationTime = incubationTime;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	  // Override pure virtual functions from the base class
	virtual void printInfo() const override;
	virtual void save(ofstream& out_file) const override;
	virtual void load(ifstream& in_file) override;


protected:
	float m_incubationTime;
};

#endif // ifndef
