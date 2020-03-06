/************************************************************************/
/* 
@file:Dict.h
@author:LRiver
@desc:string dictionary for i18n
*/
/************************************************************************/

#pragma once
#include <QObject>
#include <QString>

class Dict
{
public:
    QString DEFAULT_UNSAVED_PATH = QObject::tr("UnSaved");// QStringLiteral("/δ����");    // LogicParam������
    QString PROG_NAME = QObject::tr("SkillEditor");// QStringLiteral("���ܱ༭��");    // LogicParam������
    QString TXT_NEW_FILE = QObject::tr("New File");//QStringLiteral("�½��ļ�");    // LogicParam������
    QString TXT_OPEN_FILE = QObject::tr("Open File");//QStringLiteral("���ļ�");    // LogicParam������
    QString TXT_SAVE_FILE_FAILED = QObject::tr("Failed to write file:\n%1");//QStringLiteral("д���ļ�ʧ��\n%1");    // LogicParam������
    QString TXT_OPEN_FILE_FAILED = QObject::tr("Failed to open file:\n%1");//QStringLiteral("���ļ�ʧ��\n%1");    // LogicParam������
    QString TXT_SAVE_FILE_SUCCESS = QObject::tr("Write file successfully");//QStringLiteral("д���ļ��ɹ�");    // LogicParam������
    QString TXT_OPEN_FILE_SUCCESS = QObject::tr("Open file successfully.");//QStringLiteral("���ļ��ɹ�");    // LogicParam������
    QString TXT_ASK_SAVE_MODIFIED = QObject::tr("Do you need to save changes?");//QStringLiteral("�Ƿ񱣴��޸�?");    // LogicParam������
    QString TXT_EXCEED_INFO_MAX_COUNT = QObject::tr("Remarks cannot exceed %1!");//QStringLiteral("�Ƿ񱣴��޸�?");    // LogicParam������
    QString TXT_CHECK_IS_REF = QObject::tr("Is Ref");//QStringLiteral("�Ƿ񱣴��޸�?");    // LogicParam������

    QString TXT_SKILL_INST_SAME_ID = QObject::tr("Same Id is NOT allowed!");//QStringLiteral("ID�������ظ�");    // LogicParam������
    QString TXT_SKILL_INST_DELETE_SCRIPT = QObject::tr("Do you need delete script?");//QStringLiteral("�Ƿ���Ҫɾ���ű��ļ�?");    // LogicParam������
    QString TXT_SKILL_INST_ISCLIENT_ERROR = QObject::tr("Only -1/0/1 available!");//QStringLiteral("ID�������ظ�");    // LogicParam������

    QString TXT_ADD_CHILD_NODE_FAILED = QObject::tr("Add child node failed.\nNode type error.");//QStringLiteral("�Ƿ񱣴��޸�?");    // LogicParam������
    QString TXT_MOVE_NODE_FAILED = QObject::tr("Move node failed.\nNode type error.");//QStringLiteral("�Ƿ񱣴��޸�?");    // LogicParam������
    QString TXT_PASTE_NODE_FAILED = QObject::tr("Paste node failed.\nNode type error.");//QStringLiteral("�Ƿ񱣴��޸�?");    // LogicParam������

    QString TXT_ALL_SAVED = QObject::tr("All Saved!");//QStringLiteral("ȫ������!");    // LogicParam������

    QString TXT_LOAD_CONFIG_FAILED = QObject::tr("load config file error.");
    QString TXT_SETTING_DIALOG_TITLE = QObject::tr("Settings");
    QString TXT_SETTING_DIALOG_ASK_SAVED = QObject::tr("User Settings changed, apply?");
};
