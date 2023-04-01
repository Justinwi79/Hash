// returns largest prime number <= n or zero if input is too large
// This is likely to be more efficient than prime_above(), because
// it only needs a vector of size n
template <typename K, typename V>
unsigned long HashTable<K, V>::prime_below (unsigned long n)
{
  if (n > max_prime)
    {
      std::cerr << "** input too large for prime_below()\n";
      return 0;
    }
  if (n == max_prime)
    {
      return max_prime;
    }
  if (n <= 1)
    {
		std::cerr << "** input too small \n";
      return 0;
    }

  // now: 2 <= n < max_prime
  std::vector <unsigned long> v (n+1);
  setPrimes(v);
  while (n > 2)
    {
      if (v[n] == 1)
	return n;
      --n;
    }

  return 2;
}

//Sets all prime number indexes to 1. Called by method prime_below(n) 
template <typename K, typename V>
void HashTable<K, V>::setPrimes(std::vector<unsigned long>& vprimes)
{
  int i = 0;
  int j = 0;

  vprimes[0] = 0;
  vprimes[1] = 0;
  int n = vprimes.capacity();

  for (i = 2; i < n; ++i)
    vprimes[i] = 1;

  for( i = 2; i*i < n; ++i)
    {
      if (vprimes[i] == 1)
        for(j = i + i ; j < n; j += i)
          vprimes[j] = 0;
    }
}

// *********************************************************************
// * Default constructor                                               *
// * Last updated: 7/13/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Past Stack and List project                                       *
// *********************************************************************

template <typename K, typename V>
HashTable<K, V>::HashTable(size_t size)
{
    size = 0;
}

// *********************************************************************
// * Destructor                                                        *
// * Last updated: 7/13/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Past Stack and List project                                       *
// *********************************************************************

template <typename K, typename V>
HashTable<K, V>::~HashTable()
{
    makeEmpty();
}

// *********************************************************************
// * Return if contains element                                        *
// * Last updated: 7/14/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

template <typename K, typename V>
bool HashTable<K, V>::contains(const K & k)
{
    auto & whichList = theLists[myhash(k)];
    
    for(auto itr = whichList.begin(); itr!= whichList.end(); ++itr) 
        if(itr->first == k) 
            {return true;} 
        else
            {return false;}
}

// *********************************************************************
// * Is there a match                                                  *
// * Last updated: 7/14/22                                             *
// * By: Harold Windham                                                *
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

template <typename K, typename V>
bool HashTable<K, V>::match(const std::pair<K, V> & kv) 
{
    for(auto whichList : theLists) 
    {
        for(auto itr = whichList.begin(); itr != whichList.end(); itr++)
        {
            if(*itr == kv) 
                return true;
        } 
    }
    return false;
}

// *********************************************************************
// * Insert element                                                    *
// * Last updated: 7/14/22                                             *
// * By: Harold Windham                                                *
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

template <typename K, typename V>
bool HashTable<K, V>::insert(const std::pair<K, V> & kv)
{
    auto & whichList = theLists[myhash(kv)];
    if(find(begin(whichList), end(whichList), kv) != end(whichList))
        return false; 
    whichList.push_back(kv);

    if(++_size > theLists.size())
        rehash(); 
    return true; 
}

// *********************************************************************
// * Insert element move                                               *
// * Last updated: 7/14/22                                             *
// * By: Harold Windham                                                *
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

template <typename K, typename V>
bool HashTable<K, V>::insert(std::pair<K, V> && kv)
{
    auto & whichList = theLists[myhash(kv)];
    if(find(begin(whichList), end(whichList), kv) != end(whichList))
        return false; 
    whichList.push_back(std::move(kv));

    if(++_size > theLists.size())
        rehash(); 
    return true; 
}

// *********************************************************************
// * Remove element                                                    *
// * Last updated: 7/14/22                                             *
// * By: Harold Windham                                                *
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

template <typename K, typename V>
bool HashTable<K, V>::remove(const K & k)
{
    auto & whichList = theLists[myhash(k)];
    auto itr = find(begin(whichList), end(whichList), k); 

    if(itr == end(whichList)) 
        return false; 
    whichList.erase(itr); 
    --_size; 
    return true; 
}

// *********************************************************************
// * Empty the table                                                   *
// * Last updated: 7/13/22                                             *
// * By: Harold Windham                                                *
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

template <typename K, typename V>
void HashTable<K, V>::clear()
{
   makeEmpty();
}

// *********************************************************************
// * Load file                                                         *
// * Last updated: 7/15/22                                             *
// * By: Harold Windham                                                *
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// * https://cplusplus.com/doc/tutorial/files/                         *
// *********************************************************************

template <typename K, typename V>
bool HashTable<K, V>::load(const char * filename)
{
    K key; 
    V val; 
    ifstream _load; 

    _load.clear(); 
    _load.open(filename); 

    _load << key << val; 
    insert(make_pair(key, val)); 

    _load.close(); 
    return true; 
}

// *********************************************************************
// * Print list                                                        *
// * Last updated: 7/13/22                                             *
// * By: Harold Windham                                                *
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

template <typename K, typename V>
void HashTable<K, V>::dump()
{
    for(auto whichList : theLists) 
        for(auto itr = whichList.begin(); itr != whichList.end(); itr++) 
        {
            cout << itr->first << " " << itr->second << endl; 
        }
}

// *********************************************************************
// * Write to file                                                     *
// * Last updated: 7/13/22                                             *
// * By: Harold Windham                                                *
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// * https://cplusplus.com/doc/tutorial/files/                         *
// *********************************************************************

template <typename K, typename V>
bool HashTable<K, V>::write_to_file(const char *filename)
{
    K key; 
    V val; 
    ifstream _load; 

    _load.clear(); 
    _load.open(filename); 

    _load << key << val; 
    insert(make_pair(key, val)); 

    _load.close(); 
    return true; 
}

// *********************************************************************
// * Return size of table                                              *
// * By: Harold Windham                                                *
// * Last updated: 7/13/22                                             *
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

template <typename K, typename V>
int HashTable<K, V>::getSize() 
{
    return _size;
}

//private 

// *********************************************************************
// * Empty the list                                                    *
// * By: Harold Windham                                                *
// * Last updated: 7/13/22                                             *
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

template <typename K, typename V>
void HashTable<K, V>::makeEmpty()
{
    for(auto & thisList : theLists) 
    {
        thisList.clear();
    }
}

// *********************************************************************
// * Rehash                                                            *
// * Last updated: 7/14/22                                             *
// * By: Harold Windham                                                *
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

template <typename K, typename V>
void HashTable<K, V>::rehash()
{
    vector<list<pair<K, V>>> oldLists = theLists; 

    theLists.resize(nextPrime(2 * theLists.size())); 
    for(auto & thisList : theLists) 
        thisList.clear(); 

    _size = 0; 
    for(auto & thisList : oldLists) 
        for(auto & x : thisList) 
            insert(std::move(x));
}

// *********************************************************************
// * Myhash                                                            *
// * Last updated: 7/14/22                                             *
// * By: Harold Windham                                                *
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

template <typename K, typename V>
size_t HashTable<K, V>::myhash(const K & k)
{
    static hash<K> hf; 
    return hf(k) % theLists.size();
}
