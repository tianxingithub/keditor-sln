#pragma once
#include <QString>
#include "QMap"

//! ���ڵ�ļ�ֵ��������ֵ
class Data
{
public:
	Data();
	~Data();
public:
	//! �Ѷ���
	//���ڵ�ļ�ֵ
	QMap<QString , QMap<QString , QString >*>* rootMapOut;

	//! ���ڵ�ļ�ֵ
	QMap<QString, QPair<QList<QList<QString>>, QList<QList<QString>>>*>* rootMap;
	
	//! ���ڵ������ֵ
	QList< QPair<QList<QList<QString>>, QList<QList<QString>>>*>* rootList;

	//! ���ڵ��˳��
	QList<QString>* rootOrder;
	
	//! ���ڵ��Ӧ����ע
	QList<QString>* rootOrder_notes;

	//! �Ѷ���
	//���ڵ����Ե�˳��
	QMap<QString, QList<QString >*>* orderOut; 

	//! �򿪵��ļ�����
	QString filename;

public:
	//<QString, QMap<QString, QString >*>* getRootMap
};

