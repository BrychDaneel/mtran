#include "idinfo.h"

IdInfo::IdInfo(int gid, Type type, int adress, bool local)
{
    this->gid = gid;
    this->type = type;
    this->adress = adress;
    this->local = local;
}

int IdInfo::getGId()
{
    return gid;
}

Type IdInfo::getType()
{
    return type;
}

int IdInfo::getAdress()
{
    return adress;
}

void IdInfo::setAdress(int adress)
{
    this->adress = adress;
}

bool IdInfo::isLocal()
{
    return local;
}
