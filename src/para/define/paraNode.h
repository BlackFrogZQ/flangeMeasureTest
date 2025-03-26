#pragma once
#include "paraDef.h"

namespace TIGER_ParaDef
{
	class CParaNode : public IParaNode
	{
	public:
		CParaNode(const CParaNodeAttributes &p_attributes = {pntSum, "", cnStr("中文名"), false, "/"}, void *p_pValue = nullptr);
		~CParaNode();
		void setValuePtr(void *p_pValue);
		void *getValuePtr() const;
		void setVisible(bool p_visible);
		virtual void setValue(QVariant p_value) override;
		virtual IParaNode *copyNode(bool p_onlyVisible) override;
		virtual QVariant getValue() const override;

		CParaNode *appendRootNode(const CParaNodeAttributes &p_attributes); // 返回添加的根节点，无：创建返回,有：会返回第一个同名根节点
		void appendNode(const CParaNodeAttributes &p_attributes, void *p_pValue);

	protected:
		void *m_value;
	};
};