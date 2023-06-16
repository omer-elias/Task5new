#ifndef ANIMAL_H
#define ANIMAL_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <fstream>

	using namespace std;

class Animal
{
protected:

	char* m_color;
	int m_childCount;
	float m_avgLifetime;

	Animal() {
		m_color = new char[strlen("GRAY") + 1];
		strcpy(m_color, "GRAY");
		m_childCount = 0;
		m_avgLifetime = 0.0f;
	}

	Animal(const char* color, int childs, float avgLifetime) {
		m_color = new char[strlen(color) + 1];
		strcpy(m_color, color);
		m_childCount = childs;
		m_avgLifetime = avgLifetime;
	}
	Animal( ifstream& in_file );//init the Animal from a binary file

public:
	virtual ~Animal() {
		delete[] m_color;
	};

public:

	// Access // 
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	const char* GetColor() const { return m_color; };//return the color of the animal
	int			GetChildCount() const { return m_childCount; };//return the child count of the animal
	float		GetLifetime() const { return m_avgLifetime; }//return the life time of the animal 
	//////////////////////////////////////////////////// //////////////////////////////////////////////////////////

	 
	 
	// Setters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	void SetColor(const char* color) {
		delete[] m_color;
		this->m_color = new char[strlen(color) + 1];
		strcpy(this->m_color, color);
	}
	void SetChildCount(int childCound)
	{
		this->m_childCount = childCound;
	}
	void SetavgLifeTime(float lifetime)
	{
		this->m_avgLifetime = lifetime;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////


	// Pure virtual function making this an abstract base class
	virtual void printInfo() const = 0;

	// Virtual functions for file handling
	virtual void save(ofstream& out_file) const = 0;
	virtual void load(ifstream& in_file) = 0;

};

#endif // ifndef
