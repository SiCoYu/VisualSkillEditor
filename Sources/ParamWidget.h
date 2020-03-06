#pragma once
#include "stdafx.h"
#include "define.h"
#include "SkillInst.h"
#include "SkillScript.h"
#include "SkillSpec.h"

class CheckCombo;

///////////////////////////////////////////////////////////////////////////
struct ParamWidgetRowInfo
{
    enum WidgetType
    {
        TYPE_COMBO,
        TYPE_SPIN,
        TYPE_DOUBLESPIN,
        TYPE_EDIT,
    };

    //������Ϣ
    int                         _widgetType = ParamWidgetRowInfo::TYPE_COMBO;
    QWidget*                    _inputWidget = nullptr;
    QComboBox*                  _refCombo = nullptr;
    QPushButton*                _revertButton = nullptr;

    //������Ϣ
    SkillScriptNodeParamPtr     _paramPtr = SkillScriptNodeParamPtr();
    SkillSpecNodeParamPtr       _argPtr = SkillSpecNodeParamPtr();
};
using ParamWidgetRowPtr = QSharedPointer<ParamWidgetRowInfo>;

///////////////////////////////////////////////////////////////////////////
class ParamWidget : public QWidget
{
    Q_OBJECT

public:
    ParamWidget(QWidget *parent);

public:
    void loadView(SkillScriptNode* node);
    void clearView();

private slots:
    //////////////////////////////////////////////////////////////////////
    //�����ؼ����͵�signal
    void onNodeTypeComboCurrentIndexChanged(int index);
    void onActionTypeComboCurrentIndexChanged(int index);
    void onArgComboCurrentIndexChanged(int index);
    void onArgRefComboCurrentIndexChanged(int state);
    void onArgCheckedComboCurrentIndexChanged(int index, bool isChecked);
    void onArgSpinValueChanged(int value);
    void onArgDSpinValueChanged(double value);
    void onArgEditTxtEditingFinished();
    void onArgRevertButtonClicked();

private:
    //////////////////////////////////////////////////////////////////////
    //�����-�ڵ�����
    void addNodeTypeRow();
    //���CombolBox��ѡ��
    void fillNodeTypeComboItems(QComboBox * cbValue, int nodeType, int publicType);
    //����CombolBox��ǰ��
    void setNodeTypeComboItem(QComboBox * cbValue, int nodeType);
    //���CombolBox��ѡ��
    void fillActionTypeComboItems(QComboBox * cbValue, int nodeType, int publicType);
    //����CombolBox��ǰ��
    void setActionTypeComboItem(QComboBox * cbValue, int nodeType);

    //�����-�ڵ����
    void addNodeArgRows();
    //ɾ����-�ڵ����
    void clearNodeArgRows();
    //�����-����
    void addNodeSpinRow(SkillScriptNodeParamPtr paramPtr, SkillSpecNodeParamPtr argPtr);
    //�����-������
    void addNodeDSpinRow(SkillScriptNodeParamPtr paramPtr, SkillSpecNodeParamPtr argPtr);
    //�����-�ı�
    void addNodeEditRow(SkillScriptNodeParamPtr paramPtr, SkillSpecNodeParamPtr argPtr);

    //�����-ö��
    void addNodeEnumRow(SkillScriptNodeParamPtr paramPtr, SkillSpecNodeParamPtr argPtr);
    //���CombolBox��ѡ��
    void fillArgComboItems(QComboBox * cbValue, SkillSpecNodeParamPtr argPtr);
    //����CombolBox��ǰ��
    void setArgComboItem(QComboBox * cbValue, SkillScriptNodeParamPtr paramPtr);

    //�����-��ѡö��
    void addNodeCheckedEnumRow(SkillScriptNodeParamPtr paramPtr, SkillSpecNodeParamPtr argPtr);
    //���CheckedCombolBox��ѡ��
    void fillArgCheckedComboItems(CheckCombo * cbValue, SkillSpecNodeParamPtr argPtr);
    //����CheckedCombolBox��ǰ��
    void setArgCheckedComboItem(CheckCombo * cbValue, SkillScriptNodeParamPtr paramPtr);

    //�������CombolBox��ѡ��
    void fillArgRefItems(QComboBox * cbValue, SkillSpecNodeParamPtr argPtr);
    //��������CombolBox��ǰ��
    void setArgRefItem(QComboBox * cbValue, SkillScriptNodeParamPtr paramPtr);

    //�����
    void addRowWidget(QLabel* lbName, QWidget* nodeWidget, QComboBox* cbRef, QPushButton* pbRevert);

private:
    //��ȡ�����
    ParamWidgetRowPtr getRowByInputWidget(QWidget* combo);
    //��ȡ����������
    ParamWidgetRowPtr getRowByRefCombo(QWidget* checkbox);
    //��ȡ��ť
    ParamWidgetRowPtr getRowByRevertButton(QPushButton* button);
    
private:
    SkillScriptNode *               _node;
    QFormLayout *                   _layout;
    SkillSpecNodePtr                _curSpecNode;

    QComboBox *                     _nodeTypeCombo;
    QComboBox *                     _actionTypeCombo;
    QList<ParamWidgetRowPtr>        _argRows;
};
