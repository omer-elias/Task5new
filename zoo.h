#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"

class Zoo
{
public:
	Zoo() : m_name(NULL), m_address(NULL), m_ticketPrice(0.0f), m_openHours(NULL), m_closeHours(NULL), m_numOfAnimals(0), m_animals(NULL) {};//default c'tor  - all to 0 or null
	Zoo(const char* name, const char* address, float ticket, const char* open, const char* close)
	{
		this->m_name = new char[strlen(name)+1];
		strcpy(this->m_name, name);

		this->m_address = new char[strlen(address) + 1];
		strcpy(this->m_address, address);

		this->m_ticketPrice = ticket;

		this->m_openHours = new char[strlen(open) + 1];
		strcpy(this->m_address, open);

		this->m_closeHours = new char[strlen(close) + 1];
		strcpy(this->m_closeHours, close);

		m_numOfAnimals = 0;

		this->m_animals = new  Animal * [m_numOfAnimals];;

	}
	Zoo( ifstream& in_file );//c'tor that gets a binary file and loads the data of the zoo from the file
	virtual ~Zoo()
	{

		delete[] m_name;
		delete[] m_address;
		delete[] m_openHours;
		delete[] m_closeHours;


		// Deallocate each Animal object
		for (int i = 0; i < m_numOfAnimals; ++i) {
			delete m_animals[i];
		}

		// Deallocate the array of Animal pointers
		delete[] m_animals;

	};//d'tor

public:

	// Getters //
	const char* GetName() const { return m_name; }//return the name of the zoo
	const char*		GetAddress() const { return m_address; };//return the address of the zoo
	float			GetTicketPrice() const { return m_ticketPrice; };//return the ticket price of the zoo
	const char*		GetOpenHour() const { return m_openHours; };//return the open hour of the zoo
	const char* GetCloseHour() const  { return m_closeHours; } ;//return the close hour of the zoo
	int				GetNumOfAnimals() const { return m_numOfAnimals; };//return the num of animals in the zoo
	Animal**		GetAnimals() const { return m_animals; };//return the animals array of the zoo
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////



public:

	//TODO
	void AddAnimal( Animal* an );//creates a copy of "an" (deep copy) and adds an animal to the array
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////



	// Setters //
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void SetName(const char* name)
	{
		delete[] m_name;
		this->m_name = new char[strlen(name) + 1];
		strcpy(this->m_name, name);
	}
	void SetAddress(const char* address)
	{
		delete[] m_address;
		this->m_address = new char[strlen(address) + 1];
		strcpy(this->m_address, address);
	}
	
	void setTicketPrice(float ticketprice)
	{
		this->m_ticketPrice = ticketprice;
	}

	void SetOpenHours(const char* openinghours)
	{
		delete[] m_openHours;
		this->m_openHours = new char[strlen(openinghours) + 1];
		strcpy(this->m_openHours, openinghours);
	}

	void SetCloseHours(const char* closinhours)
	{
		delete[] m_closeHours;
		this->m_closeHours = new char[strlen(closinhours) + 1];
		strcpy(this->m_closeHours, closinhours);
	}

	void setNumAnimals(float numanimals)
	{
		this->m_numOfAnimals = numanimals;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
public:

	Zoo& operator+(Animal* an)
	{
		// Create a new array to hold the updated animals
		Animal** updatedAnimals = new Animal * [m_numOfAnimals + 1];

		// Copy existing animal pointers to the updated array
		for (int i = 0; i < m_numOfAnimals; ++i) {
			updatedAnimals[i] = m_animals[i];
		}

		// Add the new animal pointer at the end of the updated array
		updatedAnimals[m_numOfAnimals] = an;

		// Increment the number of animals
		m_numOfAnimals++;

		// Deallocate the old m_animals array
		delete[] m_animals;

		// Assign the updated array to m_animals
		m_animals = updatedAnimals;

		// Return a reference to this Zoo object
		return *this;
	}



	Zoo operator+(const Zoo& other) const
	{
		// Create a new Zoo object to hold the merged properties
		Zoo mergedZoo(*this);  // Copy the properties of 'this' Zoo

		// Add animals from 'other' Zoo to the mergedZoo
		Animal** otherAnimals = other.GetAnimals();
		int numOtherAnimals = other.GetNumOfAnimals();

		for (int i = 0; i < numOtherAnimals; ++i) {
			mergedZoo.AddAnimal(new Animal(*otherAnimals[i]));  // Deep copy each animal
		}

		// Return the mergedZoo
		return mergedZoo;
	}

public:
	friend ofstream& operator<<( ofstream& out, const Zoo& z );//operator to write the zoo to a text file
	friend ifstream& operator >> ( ifstream& in, Zoo& z );//operator to read the zoo from a text file

public:
	void Save( ofstream& ofs ) const;//method to save the info to a text file
	void Load( ifstream& ifs );//method to load the info from a text file
	void SaveBin( ofstream& ofs ) const;//method to save the info to a binary file

private:
	char*		m_name;
	char*		m_address;
	float		m_ticketPrice;
	char*		m_openHours;
	char*		m_closeHours;
	int			m_numOfAnimals;
	Animal**	m_animals;
};

ofstream& operator<<( ofstream& out, const Zoo& z );
ifstream& operator >> ( ifstream& in, Zoo& z );

#endif // ifndef
