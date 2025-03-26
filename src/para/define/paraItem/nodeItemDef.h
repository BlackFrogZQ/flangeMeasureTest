#pragma once
#include "system/basic.h"
namespace TIGER_ParaDef
{
	class CParaNode;
};
namespace TIGER_ParaItemDef
{
	class IParaItem
	{
	public:
		IParaItem(const QString &p_name, const QString &p_cnName, const bool &p_visible = true, const QString &p_remark = QString("/"));
		virtual ~IParaItem();
		TIGER_ParaDef::CParaNode *currentNode() const;
	protected:
		TIGER_ParaDef::CParaNode* m_currentNode;
	};
};