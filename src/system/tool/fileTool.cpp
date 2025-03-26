#include "fileTool.h"
#include <QDir>
#include <QFileInfo>
namespace TIGER_FlieTool
{
    bool isFile(const QString &p_file)
    {
        QFileInfo info(p_file);
        return info.isFile();
    }

    bool isDir(const QString &p_dir)
    {
        QFileInfo info(p_dir);
        return info.isDir();
    }

    QStringList scanfDir(const QString &p_dir)
    {
        QFileInfo info(p_dir);
        QStringList dirs;
        if (!info.isDir())
        {
            return dirs;
        }
        QFileInfoList folderList = QDir(p_dir).entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name);
        for (const auto &folder : folderList)
        {
            dirs.append(folder.absoluteFilePath());
        }
        return dirs;
    }

    bool removeDir(const QString &p_dir)
    {
        if (!isDir(p_dir))
        {
            return true;
        }
        return QDir(p_dir).removeRecursively();
    }

    bool createDir(const QString &p_absDir)
    {
        if (isDir(p_absDir))
        {
            return true;
        }
        return QDir().mkpath(p_absDir);
    }

    bool createFile(const QString &p_absFile)
    {
        QFileInfo info(p_absFile);
        if (createDir(info.absolutePath()))
        {
            QFile file(p_absFile);
            if (!file.open(QFile::WriteOnly))
            {
                return false;
            }
            file.close();
            return true;
        }
        return false;
    }

    bool clearDir(const QString &p_absDir)
    {
        return removeDir(p_absDir) && createDir(p_absDir);
    }

    bool renameDir(const QString &p_absOldDir, const QString &p_absNewDir)
    {
        if (isDir(p_absOldDir) && (!isDir(p_absNewDir)))
        {
            return QDir(p_absOldDir).rename(p_absOldDir, p_absNewDir);
        }
        return false;
    }

    bool qCopyFile(const QString &p_fromAbsFile, const QString &p_toAbsFile, bool bCoverIfFileExists)
    {
        if (!isFile(p_fromAbsFile))
        {
            myDebug << QObject::tr("拷贝文件错误:文件不存在.");
            return false;
        }

        QFileInfo toAbsFileInfo(p_toAbsFile);
        if (toAbsFileInfo.isFile())
        {
            if (bCoverIfFileExists)
            {
                QFile::remove(p_toAbsFile);
            }
            else
            {
                return true;
            }
        }
        else
        {
            if (!createDir(toAbsFileInfo.absolutePath()))
            {
                myDebug << QObject::tr("拷贝文件错误:创建目录失败.");
                return false;
            }
        }
        return QFile::copy(p_fromAbsFile, p_toAbsFile);
    }

    bool qCopyDirectory(const QString &p_fromDir, const QString &p_toDir, bool bCoverIfFileExists)
    {
        if (!isDir(p_fromDir))
        {
            myDebug << QObject::tr("拷贝文件夹错误：文件夹不存在");
            return false;
        }
        if (!isDir(p_toDir))
        {
            if (!createDir(p_toDir))
            {
                myDebug << QObject::tr("拷贝文件夹错误：目标文件夹无法创建");
                return false;
            }
        }
        QDir toDir(p_toDir);
        QFileInfoList fileInfoList = QDir(p_fromDir).entryInfoList();
        foreach (QFileInfo fileInfo, fileInfoList)
        {
            if (fileInfo.fileName() == "." || fileInfo.fileName() == "..")
            {
                continue;
            }
            // 拷贝子目录
            if (fileInfo.isDir())
            {
                // 递归调用拷贝
                if (!qCopyDirectory(fileInfo.filePath(), toDir.filePath(fileInfo.fileName()), true))
                    return false;
            }
            // 拷贝子文件
            else
            {
                if (bCoverIfFileExists && toDir.exists(fileInfo.fileName()))
                {
                    toDir.remove(fileInfo.fileName());
                }
                if (!QFile::copy(fileInfo.filePath(), toDir.filePath(fileInfo.fileName())))
                {
                    return false;
                }
            }
        }
        return true;
    }
};