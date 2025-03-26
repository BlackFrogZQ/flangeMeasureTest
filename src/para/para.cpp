#include "system/basic.h"
#include "para/define/paraDef.h"
#include "para/para.h"
#include <QXmlStreamReader>
#include <QFile>
#include <QDir>
#include <QUrl>
#include <QDebug>
#include <QDesktopServices>
#include <QStandardPaths>

namespace TIGER_Para
{
    void IParaService::setFileName(QString p_file)
    {
        assert(!p_file.isEmpty());
        m_xmlFilePath = cnStr("%1/%2").arg(QDir::currentPath()).arg(p_file);
    }

    void IParaService::openFilePath() const
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile(QFileInfo(m_xmlFilePath).absolutePath()));
    }

    using namespace TIGER_ParaDef;
    class CParaService : public IParaService
    {
    public:
        using IParaService::IParaService;
        ~CParaService();
        void load();
        void save();

    protected:
        void readNode(IParaNode * const p_node);
        void writNode(const IParaNode * const p_node);

    protected:
        QXmlStreamReader m_xmlReader;
        QXmlStreamWriter m_xmlWriter;
    };

    CParaService::~CParaService(){};

    void CParaService::save()
    {
        assert(!m_xmlFilePath.isEmpty());
        if (paraRootNode() == nullptr)
        {
            return;
        }
        QFile file(m_xmlFilePath);
        if (!file.open(QFile::WriteOnly | QFile::Text))
        {
            return;
        }
        m_xmlWriter.setDevice(&file);
        m_xmlWriter.setAutoFormatting(true);
        m_xmlWriter.writeStartDocument();
        writNode(paraRootNode());
        m_xmlWriter.writeEndDocument();
        file.close();
        if (m_xmlWriter.hasError())
        {
            myInfo << cnStr("%1保存失败").arg(m_xmlFilePath);
        }
    };

    void CParaService::load()
    {
        assert(!m_xmlFilePath.isEmpty());
        QFile file(m_xmlFilePath);
        if (!file.exists())
        {
            myInfo << cnStr("未发现文件：%1,进行创建").arg(m_xmlFilePath);
            save();
            return;
        }

        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            myInfo << cnStr("未发现文件：%1,进行创建").arg(m_xmlFilePath);
            return;
        }
        m_xmlReader.setDevice(&file);
        while (!m_xmlReader.atEnd() && m_xmlReader.readNextStartElement())
        {
            if (m_xmlReader.name().toString() == paraRootNode()->m_attributes.name) // 找到感兴趣根节点 cFirstRootNode，因为第一级根节点，速度很快
            {
                assert(paraRootNode()->m_attributes.name == cFirstRootNode);
                // 根节点属性不能从文件加载
                // paraRootNode()->m_attributes.visible = m_xmlReader.attributes().value(cVisible).toInt();
                // paraRootNode()->m_attributes.remark = m_xmlReader.attributes().value(cRemark).toString();
                // paraRootNode()->m_attributes.cnName = m_xmlReader.attributes().value(cCnName).toString();
                readNode(paraRootNode());
                break;
            }
            m_xmlReader.skipCurrentElement();
        }
        file.close();
        if (m_xmlReader.hasError())
        {
            myInfo << cnStr("参数文件读取错误：%1").arg(m_xmlReader.errorString());
        }
    };

    void CParaService::readNode(IParaNode * const p_node)
    {
        QList<IParaNode *> pNodes = p_node->getChildrenNodes();
        while (!m_xmlReader.atEnd() && !(m_xmlReader.readNext() == QXmlStreamReader::EndElement && m_xmlReader.name().toString() == p_node->m_attributes.name))
        {
            if (!m_xmlReader.isStartElement())
            {
                continue; // 不是开始节点，不能跳过当前节点，有可能有效节点是其他状态
            }

            QString nodeName = m_xmlReader.name().toString();
            if (nodeName == cValueName)
            {
                p_node->setValue(m_xmlReader.readElementText());
                break; // 跳出，不能继续找，当叶子节点名字：p_node->getName() 不为 cValueName，由于叶子节点无子节点，会一直调过节点直到发现一个名为cValueName叶子节点结束时
            }

            int id = p_node->findChildNode(nodeName);
            if (id >= 0)
            {
                pNodes.at(id)->m_attributes.visible = m_xmlReader.attributes().value(cVisible).toInt();
                // 枚举不允许改备注
                if (pNodes.at(id)->m_attributes.type != pntEnum)
                {
                    pNodes.at(id)->m_attributes.remark = m_xmlReader.attributes().value(cRemark).toString();
                }
                pNodes.at(id)->m_attributes.cnName = m_xmlReader.attributes().value(cCnName).toString();
                readNode(pNodes.at(id));
                continue;
            }
            m_xmlReader.skipCurrentElement();
        }
    };

    void CParaService::writNode(const IParaNode * const p_node)
    {
        const auto& attributes = p_node->m_attributes;
        m_xmlWriter.writeStartElement(attributes.name);
        m_xmlWriter.writeAttribute(cRemark, attributes.remark);
        m_xmlWriter.writeAttribute(cCnName, attributes.cnName);
        m_xmlWriter.writeAttribute(cVisible, QString::number(attributes.visible));
        if (attributes.type == pntRoot)
        {
            QList<IParaNode *> childNodes = p_node->getChildrenNodes();
            for (size_t i = 0; i < childNodes.size(); i++)
            {
                writNode(childNodes.at(i));
            }
        }
        else
        {
            m_xmlWriter.writeTextElement(cValueName, p_node->getValue().toString());
        }
        m_xmlWriter.writeEndElement();
    };
};

TIGER_Para::IParaService *const paraService()
{
    static TIGER_Para::CParaService gParaService;
    return &gParaService;
};