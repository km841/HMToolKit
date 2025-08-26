#pragma once

#include "hmInformationKey.h"
#include "hmObjectBase.h"
#include <unordered_map>
class hmInformationInternals
{
public:
	typedef hmInformationKey* KeyType;
	typedef hmObjectBase* DataType;

	// vtk information_use_hash_map 사용 시 활성화
	struct HashFun
	{
		size_t operator()(KeyType key) const
		{
			return reinterpret_cast<uintptr_t>(key) / sizeof(hmInformationKey);
		}
	};

	typedef std::unordered_map<KeyType, DataType, HashFun> MapType;
	MapType Map;

	// Map의 인자로 unordered_map의 버킷 개수를 정할 수 있음
	// 데이터가 들어오면 최소 33개의 칸으로 나눠서 해시 테이블에 배치!
	hmInformationInternals()
		: Map(33)
	{
	}

	~hmInformationInternals()
	{
		for (MapType::iterator i = this->Map.begin(); i != this->Map.end(); ++i)
		{
			if (hmObjectBase* value = i->second)
			{
				// Delete 구문
			}
		}
	}
};

