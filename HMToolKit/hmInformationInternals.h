#pragma once

#include "hmInformationKey.h"
#include "hmObjectBase.h"
#include <unordered_map>
class hmInformationInternals
{
public:
	typedef hmInformationKey* KeyType;
	typedef hmObjectBase* DataType;

	// vtk information_use_hash_map ��� �� Ȱ��ȭ
	struct HashFun
	{
		size_t operator()(KeyType key) const
		{
			return reinterpret_cast<uintptr_t>(key) / sizeof(hmInformationKey);
		}
	};

	typedef std::unordered_map<KeyType, DataType, HashFun> MapType;
	MapType Map;

	// Map�� ���ڷ� unordered_map�� ��Ŷ ������ ���� �� ����
	// �����Ͱ� ������ �ּ� 33���� ĭ���� ������ �ؽ� ���̺� ��ġ!
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
				// Delete ����
			}
		}
	}
};

