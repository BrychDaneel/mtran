#ifndef IDINFO_H
#define IDINFO_H

#include <type.h>


class IdInfo
{
    int gid;
    Type type;
    int adress;
    bool  local;
public:
    IdInfo(int gid, Type type, int adress, bool local);
    int getGId();
    Type getType();
    int getAdress();
    void setAdress(int adress);
    bool isLocal();
};

#endif // IDINFO_H
