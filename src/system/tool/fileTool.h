#pragma once
#include "system/basic.h"
#include <QDataStream>
#include <QCryptographicHash>
#include <QFile>
namespace TIGER_FlieTool
{
    bool isFile(const QString &p_file);

    bool isDir(const QString &p_dir);

    QStringList scanfDir(const QString &p_dir);

    bool removeDir(const QString &p_dir);

    bool createDir(const QString &p_absDir);

    bool createFile(const QString &p_absFile);
    // 不存在则创建
    bool clearDir(const QString &p_absDir);

    bool renameDir(const QString &p_absOldDir, const QString &p_absNewDir);

    bool qCopyFile(const QString &p_fromAbsFile, const QString &p_toAbsFile, bool bCoverIfFileExists = true);

    bool qCopyDirectory(const QString &p_fromDir, const QString &p_toDir, bool bCoverIfFileExists = true);

    template <class T>
    bool saveStructToFile(const QString &p_file, const T &p_T)
    {
        if (!createFile(p_file))
        {
            myDebug << QObject::tr("创建%1失败").arg(p_file);
            return false;
        }

        QFile file(p_file);
        if (!file.open(QFile::WriteOnly))
        {
            myDebug << QObject::tr("保存%1失败:%2").arg(p_file).arg(file.errorString());
            return false;
        }
        bool isSucessful = (file.write((const char *)(&p_T), sizeof(p_T)) == sizeof(p_T));
        file.close();
        return isSucessful;
    }

    template <class T>
    bool loadStructFormFile(const QString &p_file, T &p_T)
    {
        if (!isFile(p_file))
        {
            myDebug << QObject::tr("加载%1文件失败:文件不存在").arg(p_file);
            return false;
        }
        QFile file(p_file);
        if (!file.open(QFile::ReadOnly))
        {
            myDebug << QObject::tr("打开%1文件失败:%2").arg(p_file).arg(file.errorString());
            return false;
        }
        bool isSucessful = (file.read((char *)(&p_T), sizeof(p_T)) == sizeof(p_T));
        file.close();
        return isSucessful;
    }

    template <typename T>
    bool loadFormStream(const QString &p_file, T &p_T)
    {
        if (!isFile(p_file))
        {
            myDebug << QObject::tr("加载%1文件失败:文件不存在").arg(p_file);
            return false;
        }
        QFile file(p_file);
        if (!file.open(QFile::ReadOnly))
        {
            myDebug << QObject::tr("打开%1文件失败:%2").arg(p_file).arg(file.errorString());
            return false;
        }
        QByteArray datas;
        QByteArray md5;

        {
            QDataStream out(&file);
            out.setVersion(QDataStream::Qt_5_15);
            out >> datas;
            out >> md5;
        }

        if (md5.isEmpty() || md5 != QCryptographicHash::hash(datas, QCryptographicHash::Md5))
        {
            myDebug << QObject::tr("文件%1已损坏").arg(p_file);
            return false;
        }

        QDataStream out(&datas, QIODevice::ReadOnly);
        out.setVersion(QDataStream::Qt_5_15);
        out >> p_T;
        return true;
    }

    template <typename T>
    bool saveFormStream(const QString &p_file, const T &p_T)
    {

        if (!createFile(p_file))
        {
            myDebug << QObject::tr("创建%1失败").arg(p_file);
            return false;
        }

        QByteArray datas;
        // 计算hash
        {
            QDataStream out(&datas, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_5_15);
            out << p_T;
        }

        QByteArray md5 = QCryptographicHash::hash(datas, QCryptographicHash::Md5);

        QFile file(p_file);
        if (!file.open(QFile::WriteOnly))
        {
            myDebug << QObject::tr("保存%1失败:%2").arg(p_file).arg(file.errorString());
            return false;
        }
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_5_15);
        out << datas;
        out << md5;
        file.close();
        return true;
    }
};