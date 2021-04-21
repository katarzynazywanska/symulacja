#include "BaseStation.h"

vector<ResourceBlock*> BaseStation::create_resBlocks(int how_many){
	for (int i = 0; i < how_many; i++) {
		ResourceBlock* resBlock_ = new ResourceBlock();
		resource_Block_vec.push_back(resBlock_);
	}
	return resource_Block_vec;
}