#include "../indexInterface.h"
#include "./src/include/lisa/lisa.h"

template <class KEY_TYPE, class PAYLOAD_TYPE>
class LISAInterface : public indexInterface<KEY_TYPE, PAYLOAD_TYPE>
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

    long long memory_consumption() { return lisa->GetSize(); }

private:
    lisa::LISA<KEY_TYPE, PAYLOAD_TYPE> *lisa;
};

template <class KEY_TYPE, class PAYLOAD_TYPE>
void LISAInterface<KEY_TYPE, PAYLOAD_TYPE>::bulk_load(std::pair<KEY_TYPE, PAYLOAD_TYPE> *key_value,
                                                      size_t num, Param *param)
{
    lisa = new lisa::LISA<KEY_TYPE, PAYLOAD_TYPE>(key_value[0], key_value[num - 1]);
    lisa->bulk_load(key_value, static_cast<int>(num));
}

template <class KEY_TYPE, class PAYLOAD_TYPE>
bool LISAInterface<KEY_TYPE, PAYLOAD_TYPE>::get(KEY_TYPE key, PAYLOAD_TYPE &val, Param *param)
{
    return lisa->Lookup(key, val);
}

template <class KEY_TYPE, class PAYLOAD_TYPE>
bool LISAInterface<KEY_TYPE, PAYLOAD_TYPE>::put(KEY_TYPE key, PAYLOAD_TYPE value, Param *param)
{
    return lisa->Insert(std::make_pair(key, value));
}

template <class KEY_TYPE, class PAYLOAD_TYPE>
bool LISAInterface<KEY_TYPE, PAYLOAD_TYPE>::update(KEY_TYPE key, PAYLOAD_TYPE value,
                                                   Param *param)
{
    return lisa->Insert(std::make_pair(key, value));
}

template <class KEY_TYPE, class PAYLOAD_TYPE>
bool LISAInterface<KEY_TYPE, PAYLOAD_TYPE>::remove(KEY_TYPE key, Param *param)
{
    return lisa->Insert(std::make_pair(key, -1));
}

template <class KEY_TYPE, class PAYLOAD_TYPE>
size_t LISAInterface<KEY_TYPE, PAYLOAD_TYPE>::scan(KEY_TYPE key_low_bound, size_t key_num,
                                                   std::pair<KEY_TYPE, PAYLOAD_TYPE> *result,
                                                   Param *param)
{
    return false;
}