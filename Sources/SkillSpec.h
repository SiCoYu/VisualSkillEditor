/************************************************************************/
/*
@file:SkillSpec.h
@author:LRiver.2019.10.25
@desc:���뼼�������ļ�(Bin/Config/SkillSpec.xml)
<Spec>                                              ---class SkillSpec
<Enums>
<enum id="enum.bool">
<value name="false">0</value>           ---class SkillSpecEnumValue
<value name="true">1</value>            ---class SkillSpecEnumValue
</enum>
</Enums>
<Sections>
<section id="onstart">                      ---class SkillNode
<title desc="���䣺��ʼ����"/>           ---class SkillNodeParam
<desc desc="���䣺��ʼ����"/>            ---class SkillNodeParam
</section>
</Sections>
<Conds>
<cond id="hasimpact">                       ---class SkillNode
<title desc="�������Ƿ�ӵ��impact"/>     ---class SkillNodeParam
<desc desc="����������ɫ..."/>         ---class SkillNodeParam
</cond>
</Conds>
<Actions>
<action id="select">                        ---class SkillNode
<title desc="ָ�ѡ���֧"/>           ---class SkillNodeParam
<desc desc="ָ����ڱ�ʾ..."/>         ---class SkillNodeParam
</action>
</Actions>
</Spec>
*/
/************************************************************************/

#pragma once
#include "stdafx.h"
#include "define.h"

//////////////////////////////////////////////////////////////////////////
class SkillSpecEnumValue
{
public:
    SkillSpecEnumValue();
    bool fromXml(const QDomElement& curNode, int instId);

public:
    QString getName() const { return _name; }
    int getValue() const { return _value; }
    QString getData() const { return _data; }

    int getIntArg(int idx) const;
    QString getStrArg(int idx) const;

private:
    QString     _name;
    int         _value;
    QString     _data;

    static const int C_INT_ARG_COUNT = 3;
    static const int C_STR_ARG_COUNT = 3;

    int         _intArgs[C_INT_ARG_COUNT];
    QString     _strArgs[C_STR_ARG_COUNT];
};
using SkillSpecEnumValuePtr = QSharedPointer<SkillSpecEnumValue>;

//////////////////////////////////////////////////////////////////////////
class SkillSpecEnum
{
public:
    SkillSpecEnum();
    bool fromXml(const QDomElement& curNode, int instId);

public:
    QString getId() const { return _id; }
    bool isCheck() const { return _isCheck; }
    SkillSpecEnumValuePtr getValue(int value) const
    {
        for (int idx = 0; idx < _values.length(); idx++) {
            if (_values[idx]->getValue() == value) {
                return _values[idx];
            }
        }
        return SkillSpecEnumValuePtr();
    }
    const QList<SkillSpecEnumValuePtr>& getValues() const
    {
        return _values;
    }

private:
    QString                                     _id;
    bool                                        _isCheck;
    QList<SkillSpecEnumValuePtr>                _values;
};
using SkillSpecEnumPtr = QSharedPointer<SkillSpecEnum>;

//////////////////////////////////////////////////////////////////////////
class SkillSpecLimit
{
public:
    SkillSpecLimit();
    bool fromXml(const QDomElement& curNode, int instId);
    void mergeLimit(const SkillSpecLimit& limit);

public:
    int getMinCls() const { return _mincls; }
    int getMaxCls() const { return _maxcls; }
    QString getDesc() const { return _desc; }

private:
    int         _mincls;
    int         _maxcls;
    QString     _desc;
};
using SkillSpecLimitPtr = QSharedPointer<SkillSpecLimit>;

//////////////////////////////////////////////////////////////////////////
class SkillSpecNodeParam
{
public:
    SkillSpecNodeParam();
    bool fromXml(const QDomElement& curNode, int instId);

public:
    QString getName() const { return _name; }
    QString getTitle() const { return _title; }
    QString getDesc() const { return _desc; }
    QString getType() const { return _type; }
    QString getDefault() const { return _default; }
    QString getMin() const { return _min; }
    QString getMax() const { return _max; }
    bool getIsNeed() const { return _isNeeded; }

private:
    QString     _name;
    QString     _title;
    QString     _desc;
    QString     _type;
    QString     _default;
    QString     _min;
    QString     _max;
    bool        _isNeeded;
};
using SkillSpecNodeParamPtr = QSharedPointer<SkillSpecNodeParam>;

//////////////////////////////////////////////////////////////////////////
class SkillSpecNode
{
public:
    using SpecNodeParamPtrList = QList<SkillSpecNodeParamPtr>;

public:
    SkillSpecNode();
    bool fromXml(const QDomElement& curNode, int instId);

public:
    QString getId() const { return _id; }
    QString getName() const { return _name; }
    QString getTitle() const { return _title; }
    QString getDesc() const { return _desc; }
    QString getFormat() const { return _format; }
    int getNodeType() const { return _nodeType; }
    int getPublicType() const { return _public; }
    int getCode() const { return _code; }
    SkillSpecNodeParamPtr getParam(const QString& name) const;
    SpecNodeParamPtrList& getParams() { return _params; }

    SkillSpecLimitPtr getLimit() const { return _limit; }

private:
    QString                 _id;
    QString                 _name;
    QString                 _title;
    QString                 _desc;
    QString                 _format;
    int                     _nodeType;
    int                     _code;
    int                     _public;
    SpecNodeParamPtrList    _params;
    SkillSpecLimitPtr       _limit;
};
using SkillSpecNodePtr = QSharedPointer<SkillSpecNode>;

//////////////////////////////////////////////////////////////////////////
class SkillSpec : public QObject
{
    Q_OBJECT

public:
    using SpecNodeList = QList<SkillSpecNodePtr>;
    using SpecEnumMap = QMap<QString, SkillSpecEnumPtr>;
    using SpecLimitList = QList<SkillSpecLimitPtr>;

public:
    SkillSpec();
    void clear();
    bool load(const QString & fileName);
    bool fromXml(const QDomElement& curNode, int instId);

public:
    QString getFilePath() const { return _curFilePath; }
    SkillSpecNodePtr getNode(const QString& id) const;
    SpecNodeList::iterator nodesBegin() { return _nodes.begin(); }
    SpecNodeList::iterator nodesEnd() { return _nodes.end(); }
    SkillSpecEnumPtr getEnum(const QString& id) const;

private:
    void parseNodes(const QDomNode& node, const QString& tagName);

private:
    QString             _curFilePath;
    SpecNodeList        _nodes;
    SpecEnumMap         _enums;
};

///////////////////////////////////////////////////////////////////////////
//����id��ȡ�ڵ�
SkillSpecNodePtr getSpecNode(const QString& nodeId);
//����id�Ͳ�������ȡ�ڵ����
SkillSpecNodeParamPtr getSpecNodeParam(const QString& nodeId, const QString& paramName);
//����id��ȡö��
SkillSpecEnumPtr getSpecEnum(const QString& enumId);
//����id��ȡ�ڵ�
SkillSpecLimitPtr getSpecNodeLimit(const QString& nodeId);
//���ݽڵ�id��ȡ������
QString getSpecNodeName(const QString& id);
//���ݽڵ�id��ȡ��ڵ�����
int getSpecNodeType(const QString& id);
//���ݽڵ�id��ȡ�����
int getSpecNodeCode(const QString& id);
//���ݽڵ�id��ȡ�俪�ŷ�Χ
int getSpecNodePublic(const QString& id);
//�ڵ㰴����������
bool compareNodesLessThan(SkillSpecNodePtr lhs, SkillSpecNodePtr rhs);
//ͨ��enum.nodetype��ȡicon·��
QString getIconName(const QString& nodeId);
//ͨ���ڵ����ͺͿ����Ի�ȡ�б�
void getSpecNodeListByType(QList<SkillSpecNodePtr>& list, int nodeType, int publicType);
//��ȡָ�����ֵ
int getSpecActionCode(const QString& nodeId);