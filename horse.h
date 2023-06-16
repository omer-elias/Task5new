#ifndef HORSE_H
#define HORSE_H

#include "Mammals.h"

class Horse : public Mammals
{
public:
	Horse() : Mammals() {
		//m_type = new char[strlen("Unknown") + 1];
		//strcpy(m_type, "Unknown");
		m_type = NULL;
	}
	Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type) : Mammals(color, childs, avgLifetime, preg, milk)
	{
		m_type = new char[strlen(type) + 1];
		strcpy(m_type,type);
	}

	Horse( ifstream& in_file );//init the Horse from a binary file
	virtual ~Horse() {
		delete[] m_type;
	}

public:

	// Access // 
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	const char* GetType() const { return m_type; }//return the type of the horse
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Getters // 
	void SetType(char* type)
	{
		delete[] m_type;
		m_type = new char[strlen(type) + 1];
		strcpy(m_type, type);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Override pure virtual functions from the base class
	virtual void printInfo() const override;
	virtual void save(ofstream& out_file) const override;
	virtual void load(ifstream& in_file) override;



protected:
	char*	m_type;
};

#endif // ifndef
