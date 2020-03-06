#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SkillEditor.h"
#include "define.h"
#include "TableRow.h"
#include "SkillInst.h"
#include "SkillScript.h"

class SkillEditor : public QMainWindow
{
    Q_OBJECT

public:
    SkillEditor(QWidget *parent = Q_NULLPTR);

public:
    bool loadWorkspace();

private slots :
    //����Action������
    void doNewInstFile();
    void doOpenInstFile();
    bool doSaveInstFile();
    bool doSaveInstFileAs();
    void doOpenGfxFile();
    bool doSaveGfxFile();
    bool doSaveGfxFileAs();
    void doNewScriptFile();
    void doOpenScriptFile();
    bool doSaveScriptFile();
    bool doSaveScriptFileAs();
    void doSelectScriptFile();
    bool doSaveAll();
    bool doSettings();
    bool doExit();
    bool doAddSkill();
    bool doDeleteSkill();
    bool doAddChildNode();
    bool doAddPrevNode();
    bool doAddNextNode();
    bool doMoveNodeUp();
    bool doMoveNodeDown();
    bool doMoveNodeParent();
    bool doMoveNodeChild();
    bool doDeleteNode();
    bool doCopyNode();
    bool doCutNode();
    bool doPasteNode();
    void doSkillHelp();
    void doEditorHelp();
    void doScriptHelp();
    void doShowIcons();
    void doSerialText();
    void doAbout();

protected:
    //�����¼�
    bool eventFilter(QObject *object, QEvent *event);

private slots:
    ////////////////////////////////////////////////////////////////////
    //�����������ݲ㷢�͵��ź�
    void onSkillInstChanged(const SkillInst& pool, SkillNotifyReason reason);
    void onSkillInstDataChanged(const SkillInstData& cfg, SkillNotifyReason reason);
    void onSkillScriptChanged(const SkillScript& inst, SkillNotifyReason reason);
    void onSkillScriptNodeChanged(const SkillScriptNode& node, SkillNotifyReason reason);
    void onSkillScriptNodeParamChanged(const SkillScriptNodeParam& param, SkillNotifyReason reason);

private slots:
    ////////////////////////////////////////////////////////////////////
    //��������UI���淢�͵��ź�
    void onTableInstItemChanged(QTableWidgetItem * item);
    void onTableInstSelectionChanged(const QItemSelection & selected, const QItemSelection & deselected);
    void onTableInstParamItemChanged(QTableWidgetItem * item);
    void onTableInstParamItemSelectionChanged();
    void onTreeScriptItemSelectionChanged();
    void onEditNodeRemarkTextChanged();
    void onEditRefRemarkTextChanged();
    void onTreeScriptItemExpanded(QTreeWidgetItem *item);
    void onTreeScriptItemCollapsed(QTreeWidgetItem *item);

    //��ʱ������
    void onTimerOut();

private:
    ////////////////////////////////////////////////////////////////////
    //UI������²���
    void initActions();
    
    //TableInst��������
    void loadTableInst(const SkillInst& table);
    void clearTableInst();
    int addRow2TableInst(const SkillInstData& cfg);
    void removeRow4TableInst(const SkillInstData& cfg);

    //TableInstParam��������
    void loadTableInstParam(const SkillInstData& cfg);
    void clearTableInstParam();
    void addRow2TableInstParam(const SkillInstData& cfg);
    void removeRow4TableInstParam(const SkillInstData& cfg);

    //TreeScript���������
    void loadTreeScript(const SkillScript & inst);
    void clearTreeScript();
    void selectTreeScriptNode(SkillScriptNode& node, bool notifyTree = true);
    void unselectScriptNodes();

    //WidgetParam���ڽ������
    void loadWidgetParam(SkillScriptNode& node);
    void clearWidgetParam();

    //EditRemark���ڽ������
    void clearNodeRemark();
    void loadNodeRemark(const QString& txt);
    void clearRefRemark();
    void loadRefRemark(const QString& txt);

private:
    //���ò���
    void readSettings();
    void writeSettings();

private:
    //��ȡ����SkillInst�ļ���ַ
    QString getSaveInstFilePath();
    //��ȡ��SkillInst�ļ���ַ
    QString getOpenInstFilePath();
    //��ȡ����SkillGfx�ļ���ַ
    QString getSaveGfxFilePath();
    //��ȡ��SkillGfx�ļ���ַ
    QString getOpenGfxFilePath();
    //��ȡ����Skill Script�ļ���ַ
    QString getSaveScriptFilePath();
    //��ȡ��Skill Script�ļ���ַ
    QString getOpenScriptFilePath();

private:
    //����SkillInst�ļ�
    bool loadInstFileAs(const QString &filePath);
    //����SkillInst�ļ�
    bool saveInstFileAs(const QString &filePath);
    //����SkillGfx�ļ�
    bool loadGfxFileAs(const QString &filePath);
    //����SkillGfx�ļ�
    bool saveGfxFileAs(const QString &filePath);
    //����Skill Script�ļ�
    bool loadScriptFileAs(const QString &filePath);
    //����Skill Script�ļ�
    bool saveScriptFileAs(const QString &filePath);
    //����Skill Script�ļ�
    void loadScriptFile(const SkillInstData& cfg);
    ////////////////////////////////////////////////////////////////////

private:
    //���±���
    void updateWindowTitle();
    //��ȡSkillInst.txt�ļ�Ŀ¼
    QString getSkillInstDir();
    //��ȡSkillGfx.txt�ļ�Ŀ¼
    QString getSkillGfxDir();
    //��ȡSkill Script�ļ�Ŀ¼
    QString getSkillScriptDir();
    //��ȡSkill Script�ļ����Ŀ¼
    QString getSkillScriptRelativeDir();

private:
    Ui::SkillEditorClass        _ui;
    QMenu*                      _treeCtxMenu;
    QMenu*                      _tableCtxMenu;
    QTimer*                     _timer;

    QList<TableRowPtr>          _skillTableRows;
    QList<TableRowPtr>          _paramTableRows;
};

////////////////////////////////////////////////////////////////////
//���б��а�����ȡ
TableRowPtr getTableRowByIdx(const QList<TableRowPtr>& list, int rowIdx);
//���б��а�id��ȡ
TableRowPtr getTableRowById(const QList<TableRowPtr>& list, int id);
//���б��а�id��
int getTableRowIdxById(const QList<TableRowPtr>& list, int id);
//����selection����ʾ�б�����ȡ��
void getTableRowBySelection(const QList<TableRowPtr>& srcList, QModelIndexList& indexesList, QList<TableRowPtr>& list);

//����������Ч������
void clearAllInvalidSkillActions();
//���µ�ǰʵ��������
void syncCurSkillAction(SkillInstDataPtr instDataPtr);
