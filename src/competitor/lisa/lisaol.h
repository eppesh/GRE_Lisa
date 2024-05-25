#include <iostream>

#include "../indexInterface.h"
#include "../lisa/src/include/lisaol/lisaol.h"

template <class KEY_TYPE, class PAYLOAD_TYPE>
class LISAOLInterface : public indexInterface<KEY_TYPE, PAYLOAD_TYPE>
{
public:
    void init(Param *param = nullptr) {}

    void bulk_load(std::pair<KEY_TYPE, PAYLOAD_TYPE> *key_value, size_t num,
                   Param *param = nullptr);

    bool get(KEY_TYPE key, PAYLOAD_TYPE &val, Param *param = nullptr);

    bool put(KEY_TYPE key, PAYLOAD_TYPE value, Param *param = nullptr);

    bool update(KEY_TYPE key, PAYLOAD_TYPE value, Param *param = nullptr);

    bool remove(KEY_TYPE key, Param *param = nullptr);

    size_t scan(KEY_TYPE key_low_bound, size_t key_num, std::pair<KEY_TYPE, PAYLOAD_TYPE> *result,
                Param *param = nullptr);

    long long memory_consumption() { return lisaol->GetSize(); }

private:
    lisaol::LISA<KEY_TYPE, PAYLOAD_TYPE> *lisaol;
};

template <class KEY_TYPE, class PAYLOAD_TYPE>
void LISAOLInterface<KEY_TYPE, PAYLOAD_TYPE>::bulk_load(
    std::pair<KEY_TYPE, PAYLOAD_TYPE> *key_value, size_t num, Param *param)
{
    lisaol = new lisaol::LISA<KEY_TYPE, PAYLOAD_TYPE>(key_value[0], key_value[num - 1]);
    lisaol->bulk_load(key_value, static_cast<int>(num));
}

template <class KEY_TYPE, class PAYLOAD_TYPE>
bool LISAOLInterface<KEY_TYPE, PAYLOAD_TYPE>::get(KEY_TYPE key, PAYLOAD_TYPE &val, Param *param)
{
    return lisaol->Lookup(key, val);
}

template <class KEY_TYPE, class PAYLOAD_TYPE>
bool LISAOLInterface<KEY_TYPE, PAYLOAD_TYPE>::put(KEY_TYPE key, PAYLOAD_TYPE value, Param *param)
{
    return lisaol->Insert(std::make_pair(key, value));
}

template <class KEY_TYPE, class PAYLOAD_TYPE>
bool LISAOLInterface<KEY_TYPE, PAYLOAD_TYPE>::update(KEY_TYPE key, PAYLOAD_TYPE value,
                                                     Param *param)
{
    return lisaol->Insert(std::make_pair(key, value));
}

template <class KEY_TYPE, class PAYLOAD_TYPE>
bool LISAOLInterface<KEY_TYPE, PAYLOAD_TYPE>::remove(KEY_TYPE key, Param *param)
{
    return lisaol->Insert(std::make_pair(key, -1));
}

template <class KEY_TYPE, class PAYLOAD_TYPE>
size_t LISAOLInterface<KEY_TYPE, PAYLOAD_TYPE>::scan(KEY_TYPE key_low_bound, size_t key_num,
                                                     std::pair<KEY_TYPE, PAYLOAD_TYPE> *result,
                                                     Param *param)
{
    return false;
}