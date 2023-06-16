#ifndef MERMAID_H
#define MERMAID_H

#include "MammalsFish.h"

class Mermaid : public MammalsFish
{
public:
	Mermaid() : MammalsFish() {
	/*	m_firstName = new char[strlen("Unknown") + 1];
		strcpy(m_firstName, "Unknown");
		m_lastName = new char[strlen("Unknown") + 1];
		strcpy(m_lastName, "Unknown");*/
		m_firstName = NULL;

	};
	Mermaid(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName) : MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills)
	{
		m_firstName = new char[strlen(firstName) + 1];
		strcpy(m_firstName, firstName);
		m_lastName = new char[strlen(lastName) + 1];
		strcpy(m_lastName, lastName);
	}
	Mermaid( ifstream& in_file );//init the Mermaid from a binary file
	virtual ~Mermaid();

public:

	// Getters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	const char* GetFirstName() const { return m_firstName; }//return the first name of the mermaid
	const char* GetLastName() const { return m_lastName; }//return the last name of the mermaid
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////


	// Setters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetFirstName(char* firstname) {
		m_lastName = new char[strlen(firstname) + 1];
		strcpy(m_lastName, firstname);
	}
	void SetLirstName(char* lirstname) {
		m_lastName = new char[strlen(lirstname) + 1];
		strcpy(m_lastName, lirstname);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////


	// Override pure virtual functions from the base class
	virtual void printInfo() const override;
	virtual void save(ofstream& out_file) const override;
	virtual void load(ifstream& in_file) override;

protected:
	char* m_firstName;
	char* m_lastName;
};

#endif // ifndef
