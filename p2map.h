#include <cstddef>

template <typename K, typename V>
struct Node {
    K key;
    V value;
    Node<K,V>* next;
};

template <typename K, typename V>
struct Map {
    Node<K,V>** table;
    int size;
};

template <typename K, typename V>    
void initialize(Map<K,V>& m, int s) //initializes the map to the size given for the map and sets all pointers in the map to start at NULL
{
	m.size = s;
	m.table = new Node<K,V>*[s];
	for(int i = 0; i < s; i++)
	{
		m.table[i] = NULL;
	}
}
template <typename K, typename V>
void destroy(Map<K,V>& m) //destroys the map by going through all spots in the array and deleting all Nodes in each index, then deletes the map itself
{
	for(int i = 0; i < m.size; i++)
	{
		Node<K,V>* walker = m.table[i];
		while(walker != NULL)
		{
			Node<K,V>* prev = walker;
			walker = walker->next;
			delete prev;
		}
		m.table[i] = NULL;
	}
	delete [] m.table;
	m.table = NULL;
	m.size = 0;
}

int hash(int key, int size) 
{ 
    return key % size;
}

int hash(char key, int size) 
{
    return key % size;
}

template <typename K, typename V>
bool has_key(Map<K,V> m,K key) //determines if they key sent is in the list
{
	int hashVal = hash(key, m.size);
	Node<K,V>* walker = m.table[hashVal];
	while(walker != NULL && walker->key != key)
	{
		walker = walker->next;
	}
	return walker != NULL;
}

template <typename K, typename V>
void assign(Map<K,V>& m,K key,V value) //assigns the key to the value, either changes the current node existing at the correct index of the array or adds a node to the end of that index if no other node is present
{
	int hashVal = hash(key, m.size);
	Node<K, V>* walker = m.table[hashVal];
	if(!has_key(m, key)) //checking to see if the node is in the list, adding a new on if it is not
	{
		while(walker->next != NULL)
		{
			walker = walker->next;
		}
		walker->next = new Node<K, V>;
		walker = walker->next;
		walker->key = key;
		walker->value = value;
		walker->next = NULL;
	}
	else //finding the node and editing it if it already exists
	{
		while(walker != NULL && walker->key != key)
		{
			walker = walker->next;
		}
		walker->value = value;
	}
	
}
template <typename K, typename V>
void remove(Map<K,V>& m,K key) //removes the node from the list if the node is found in the list when it is called
{
	if(!has_key(m, key)) //this is checking to see if the node is in the list in the first place
	{
		return;
	}
	else
	{
		int hashVal = hash(key, m.size);
		if(m.table[hashVal]->key == key) //this condition is differentiating between the node being the first in the list or somewhere after
		{
			delete m.table[hashVal];
			m.table[hashVal] = NULL;
		}
		else
		{
			Node<K, V>* walker = m.table[hashVal];
			while(walker->next->key != key)
			{
				walker = walker->next;
			}
			Node<K,V>* temp = walker->next;
			walker->next = temp->next;
			delete temp;
		}
	}
}

template <typename K, typename V>
V    lookup(Map<K,V> m,K key) //looks up the node by using teh has value of the key and then walking through until the key is found
{
	K hashVal = (K)hash(key, m.size);
	Node<K,V>* walker = m.table[hashVal];
	while(walker != NULL && walker->key != key)
	{
		walker = walker->next;
	}
	return walker->value;
}