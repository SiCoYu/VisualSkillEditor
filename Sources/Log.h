/************************************************************************/
/* 
@file:Log.h
@author:LRiver.2019.10.25
@desc:Log
*/
/************************************************************************/

#pragma once
#include "stdafx.h"
//��ʼ��
bool LogInit(const QString & path);
//�ͷ�
void LogRelease();
//��־����
void LogHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
