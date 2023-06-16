#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish : public Animal
{
public:
	Fish() : Animal()
	{
		m_finCount = 0;
		m_gillsCount = 0;
	};


	Fish(int fin, int gills)
		: Animal(), m_finCount(fin), m_gillsCount(gills)
	{
	}


	Fish(const char* color, int childs, float avgLifetime, int fin, int gills)
		: Animal(color, childs, avgLifetime)
	{
		m_finCount = fin;
		m_gillsCount = gills;
	}
	Fish( ifstream& in_file );//init the Fish from a binary file
	virtual ~Fish();

public:

	// Getters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int		GetFinCount() const { return m_finCount; };
	int		GetGillsCount() const {return m_gillsCount;}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////


	// Setters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetFinCount(int finCount)
	{
		this->m_finCount = finCount;
	}
	void SetGillsCount(int gillsCount)
	{
		this->m_gillsCount = gillsCount;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Override pure virtual functions from the base class
	virtual void printInfo() const override;
	virtual void save(ofstream& out_file) const override;
	virtual void load(ifstream& in_file) override;


protected:
	int m_finCount;
	int m_gillsCount;
};

#endif // ifndef
