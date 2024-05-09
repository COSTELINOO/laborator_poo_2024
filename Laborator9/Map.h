
#include <iostream>

template <typename K, typename V>
class Map {
	struct Element {
		K key;
		V value;
		int index;
	} *vector;


	int index;

	int size;

	void Resize()
	{
		if (size != 0)
		{
			Element* v = new Element[size * 2];
			memcpy(v, vector, sizeof(Element) * size);
			vector = v;
			size = size * 2;
			return;
		}
		vector = new Element[1];
		size = 1;
		index = 0;
	}
public:
	Map()
	{
		vector = new Element[1];
		size = 1;
		index = 0;
	}

	Element* begin() const { return &vector[0]; }

	Element* end() const { return &vector[this->index]; }

	V& operator [] (K key)
	{
		for (int i = 0; i < index; i++)
		{
			if (key == vector[i].key)
				return vector[i].value;
		}
		vector[this->index].index = this->index;
		vector[this->index].key = key;
		this->index++;
		if (this->index == size)
			Resize();
		return vector[this->index - 1].value;
	}

	void Set(K k, V v)
	{
		for (int i = 0; i < index; i++)
		{
			if (vector[i].key == k)
			{
				vector[i].value = v;
				size++;
				return;
			}
		}

		printf("Error at Set()... (maybe key doesn't exist?)\n");
		return;
	}

	bool Get(const K& k, V& v)
	{
		for (int i = 0; i < index; i++)
		{
			if (vector[i].key == k)
			{
				v = vector[i].value;
				return true;
			}
		}
		return false;
	}

	int Count() const
	{
		return index;
	}

	void Clear()
	{
		size = 0;
		index = 0;
		delete[] vector;
	}

	bool Delete(const K& k)
	{
		for (int i = 0; i < index; i++)
		{
			if (vector[i].key == k)
			{
				for (int j = i; j < index - 1; j++)
					vector[j] = vector[j + 1];
				index--;
				return true;
			}
		}
		return false;
	}

	bool Includes(const Map<K, V>& map)
	{
		if (index < map.index) return false;

		bool exists;
		for (int i = 0; i < map.index; i++)
		{
			exists = false;
			for (int j = 0; j < index; j++)
				if (vector[j].key == map.vector[i].key)
				{
					exists = true;
					break;
				}
			if (exists == false)
				return false;
		}
		return true;
	}
};

