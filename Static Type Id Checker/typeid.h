#include <string>

template<typename T>
std::string TYPE_ID_IMPL(const char *id) { return id; }

#define TYPE_ID_CHK(ID) TYPE_ID_IMPL<ID>(#ID)

#define TYPE_ID(ID) TYPE_ID_CHK(ID)
