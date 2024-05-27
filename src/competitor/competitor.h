#include "./indexInterface.h"
#include "./alex/alex.h"
#include "./alexol/alex.h"
#include "./xindex/xindex.h"
#include "./btreeolc/btreeolc.h"
#include "./lipp/lipp.h"
#include "./lippol/lippol.h"
#include "./lisa/lisa.h"
#include "./lisa/lisaol.h"
#include "pgm/pgm.h"
#include "btree/btree.h"
#include "iostream"

template <class KEY_TYPE, class PAYLOAD_TYPE>
indexInterface<KEY_TYPE, PAYLOAD_TYPE> *get_index(std::string index_type)
{
  indexInterface<KEY_TYPE, PAYLOAD_TYPE> *index;
  if (index_type == "alexol")
  {
    index = new alexolInterface<KEY_TYPE, PAYLOAD_TYPE>;
  }
  else if (index_type == "alex")
  {
    index = new alexInterface<KEY_TYPE, PAYLOAD_TYPE>;
  }
  else if (index_type == "btreeolc")
  {
    index = new BTreeOLCInterface<KEY_TYPE, PAYLOAD_TYPE>;
  }
  else if (index_type == "xindex")
  {
    index = new xindexInterface<KEY_TYPE, PAYLOAD_TYPE>;
  }
  else if (index_type == "pgm")
  {
    index = new pgmInterface<KEY_TYPE, PAYLOAD_TYPE>;
  }
  else if (index_type == "btree")
  {
    index = new BTreeInterface<KEY_TYPE, PAYLOAD_TYPE>;
  }
  else if (index_type == "lippol")
  {
    index = new LIPPOLInterface<KEY_TYPE, PAYLOAD_TYPE>;
  }
  else if (index_type == "lipp")
  {
    index = new LIPPInterface<KEY_TYPE, PAYLOAD_TYPE>;
  }
  else if (index_type == "lisa")
  {
    index = new LISAInterface<KEY_TYPE, PAYLOAD_TYPE>;
  }
  else if (index_type == "lisaol")
  {
    index = new LISAOLInterface<KEY_TYPE, PAYLOAD_TYPE>;
  }
  else
  {
    std::cout << "Could not find a matching index called " << index_type << ".\n";
    exit(0);
  }

  return index;
}