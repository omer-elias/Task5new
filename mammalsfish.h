#ifndef MAMMALSFISH_H
#define MAMMALSFISH_H

#include "Mammals.h"
#include "Fish.h"

class MammalsFish : public Mammals, public Fish
{
public:
	MammalsFish() :Mammals(),Fish() {};
	MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills)
		: Mammals(color, childs, avgLifetime, preg, milk), Fish(fin, gills)
	{
	
	}	
    MammalsFish( ifstream& in_file );//init the MammalsFish from a binary file
	virtual ~MammalsFish();
};

#endif // ifndef
