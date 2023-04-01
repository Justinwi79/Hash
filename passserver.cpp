#include "passserver.h"
#include "base64.h"
#include "hashtable.h"
#include <string>
#include <fstream>



// *********************************************************************
// * Constructor                                                       *
// * Last updated: 7/13/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Past COP4530 projects                                             *
// *********************************************************************

PassServer::PassServer(size_t size): Server(size) 
{

}

// *********************************************************************
// * Destructor                                                        *
// * Last updated: 7/13/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Past COP4530 projects                                             *
// *********************************************************************

PassServer::~PassServer()
{
    Server.clear();
}

// *********************************************************************
// * Load file                                                         *
// * Last updated: 7/13/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

bool PassServer::load(const char *filename)
{
    return true;//Server.load(filename);
}

// *********************************************************************
// * Add a user                                                        *
// * Last updated: 7/13/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

bool PassServer::addUser(std::pair<string,  string> & kv)
{
    return (Server.insert(make_pair(kv.first,encrypt(kv.second))));
}

// *********************************************************************
// * Add a user                                                        *
// * Last updated: 7/13/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

bool PassServer::addUser(std::pair<string,  string> && kv)
{
    return (Server.insert(move(make_pair(kv.first,encrypt(kv.second)))));
}

// *********************************************************************
// * Remove a user                                                     *
// * Last updated: 7/15/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

bool PassServer::removeUser(const string & k)
{   
    return true; //Server.remove(k);
}

// *********************************************************************
// * Change a password                                                 *
// * Last updated: 7/13/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

bool PassServer::changePassword(const pair<string, string> &p, const string & newpassword)
{
    return true;
}

// *********************************************************************
// * Find file                                                         *
// * Last updated: 7/13/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

bool PassServer::find(const string & user)
{
    return Server.contains(user); 
    
}

// *********************************************************************
// * Dump table                                                        *
// * Last updated: 7/13/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

void PassServer::dump()
{
    Server.dump();
}

// *********************************************************************
// * Return size of table                                              *
// * Last updated: 7/13/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Past Stack and List project                                       *
// *********************************************************************

size_t PassServer::size()
{
    return Server.getSize();
}

// *********************************************************************
// * Write to file                                                     *
// * Last updated: 7/15/22                                             *
// * By: Harold Windham                                                * 
// * References: Dr. Gaitros course videos                             *
// * Data Structures and Algorithm Analysis in C++ Fourth Edition Chp 5*
// *********************************************************************

bool PassServer::write_to_file(const char *filename)
{
    return true;//Server.write_to_file(filename);
}

