/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include <QStringList>
#include <QtDeclarative/qdeclarativeextensionplugin.h>
#include <QtDeclarative/qdeclarative.h>
#include <QDebug>

class MyPluginType : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue)
    Q_PROPERTY(int valueOnlyIn2 READ value WRITE setValue)

public:
    MyPluginType(QObject *parent=0) : QObject(parent)
    {
        qWarning("import2.1 worked");
    }

    int value() const { return v; }
    void setValue(int i) { v = i; }

private:
    int v;
};


class MyPlugin : public QDeclarativeExtensionPlugin
{
    Q_OBJECT
public:
    MyPlugin()
    {
        qWarning("plugin2.1 created");
    }

    void registerTypes(const char *uri)
    {
        Q_ASSERT(QLatin1String(uri) == "com.nokia.AutoTestQmlPluginType");
        qmlRegisterType<MyPluginType>(uri, 2, 1, "MyPluginType");
    }
};

#include "plugin.moc"

Q_EXPORT_PLUGIN2(plugin, MyPlugin);