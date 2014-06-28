#ifndef OBJECTDATAMANAGER_H
#define OBJECTDATAMANAGER_H

#include <vector>
#include <assimp/scene.h>
#include "Point.h"

#ifndef ObjectDataStruct
#define ObjectDataStruct
// Each ObjectDataStruct contain raw data for one unique object 
struct ObjectDataStruct{
	std::vector<Point> vert;
	std::vector<int> lineVec;
};
#endif //ObjectDataStruct

class ObjectDataManager{
	public:
		ObjectDataManager();
		virtual ~ObjectDataManager();


		void loadObjectData();
	private:

		std::vector< ObjectDataStruct > ObjVec;

};






#endif //OBJECTDATAMANAGER_H
