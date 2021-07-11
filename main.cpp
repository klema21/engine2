#include "Engine.hpp"
#include "Object.hpp"
#include "Object2.hpp"
#include "Object3.hpp"

int main() {
	const char* json1 = "{\"project\":\"json\"}";
	const char* json2 = "{\"project\":\"json\",\"active\": true }";
	const char json3[] = "{\"hello\" : \"world\", \"t\" : true , \"f\" : false, \"i\":123, \"pi\": 3.1416, \"a\":[-1, 2, -3, 4] } ";

	Engine e;
	ObjectBase* o1 = new Object;
	ObjectBase* o2 = new Object2;
	ObjectBase* o3 = new Object3;
	

	e.Parse(json1, o1);
	e.Parse(json2, o2);
	e.Parse(json3, o3);

	delete o1;
	delete o2;
	delete o3;

	return 0;
}
