#include<iostream>
using namespace std;
#include <cassert>
#include <fstream>
#include<cstring>
#include <cmath>

template <typename v>
class HashMap
{
private:
	template <typename v>
	class HashItem
	{
	public:
		int key;
		v value;
		short status;
		HashItem() :key(0), status(0) {}
		HashItem(int kiki, v vivi) {
			key = kiki;
			value = vivi;
			status = 2;
		}
	};

	HashItem<v>* hashArray;
	int currentElements;
protected:
	int capacity;
	virtual int getNextCandidateIndex(int kk, int i)
	{
		return (kk + i) % capacity;
	}

public:

	HashMap() {
		capacity = 10;
		currentElements = 0;
		hashArray = new HashItem<v>[capacity];

	}
	HashMap(int const capacit) {
		assert(capacit > 1);
		capacity = capacit;
		currentElements = 0;
		hashArray = new HashItem<v>[capacity];
	}
	void insert(int const ke, v const valu) {

		if (currentElements >= capacity * 0.75)
		{
			doubleCapacity();
		}

		int j = 1;
		int index = ke % capacity;
		while (hashArray[index].status == 2)
		{
			index = getNextCandidateIndex(ke, j);
			j++;
		}
		hashArray[index] = HashItem<v>(ke, valu);
		currentElements++;
	}



	void doubleCapacity() {
		int capaci = capacity;
		capacity = capacity + capacity;
		HashItem<v>* temp = new HashItem<v>[capacity];
		int c = currentElements;
		for (int i = 0; c != 0; i++) {
			if (hashArray[i].status == 2)
			{
				int j = 1;
				int ky = hashArray[i].key;
				v vale = hashArray[i].value;
				int index = ky % capacity;
				while (temp[index].status == 2)
				{
					index = getNextCandidateIndex(ky, j);
					j++;
				}
				temp[index] = HashItem<v>(ky, vale);
				c--;
			}
		}
		delete[]hashArray;
		hashArray = temp;
	}

	bool deleteKey(int const ke) {
		int j = 1;
		int index = ke % capacity;
		while (index < capacity) {
			if (hashArray[index].status == 2 && hashArray[index].key == ke) {
				hashArray[index].status = 1;
				currentElements--;
				return true;
			}
			index = getNextCandidateIndex(ke, j);
			j++;
		}
		return false;
	}

	v* get(int const ke) {
		int j = 1;
		int index = ke % capacity;
		while (j < capacity) {
			if (hashArray[index].status == 2 && hashArray[index].key == ke) {
				return &hashArray[index].value;
			}
			else {
				index = getNextCandidateIndex(ke, j);
				j++;
			}
		}
		return nullptr;
	}

	~HashMap() {
		delete[]hashArray;
	}
};

template <class v>
class QHashMap : public HashMap<v>
{
private:
	int getNextCandidateIndex(int key, int i) override {
		return (key + (i * i)) % this->capacity;
	}

public:
};

template <class v>
class DHashMap : public HashMap<v>
{
private:
	int getNextCandidateIndex(int key, int i) override
	{
		const int PRIME = 2; // You can choose any prime number
		int first_value = key % this->capacity;
		int second_value = (PRIME - (key % PRIME));
		return (first_value + i * second_value) % this->capacity;
	}

public:
};

void populateHash(string filename, HashMap<std::string>* hash)
{
	std::ifstream file(filename);
	int id;
	std::string name;

	while (file >> id >> name)
	{
		hash->insert(id, name);
	}

	file.close();
}
int main()
{
	HashMap<string>* map = new HashMap<string>;
	populateHash("student.txt", map);
	cout << *map->get(9);
	map->deleteKey(9);
	assert(map->get(9) == NULL);
	delete map;

	map = new QHashMap<string>;
	populateHash("student.txt", map);
	string s = *map->get(98);
	if (&s != nullptr) {
		cout << endl << s;
	}
	map->deleteKey(98);
	delete map;

	map = new DHashMap<string>;
	populateHash("student.txt", map);
	string s1 = *map->get(101);
	if (&s1 != nullptr) {
		cout << endl << s1;
	}
	map->deleteKey(101);
	assert(map->get(101) == NULL);
	delete map;

	return 0;
}



