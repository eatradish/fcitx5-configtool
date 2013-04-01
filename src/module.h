/***************************************************************************
 *   Copyright (C) 2011~2011 by CSSlayer                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#ifndef MODULE_H
#define MODULE_H

// KDE
#include <KCModule>

// Fcitx
#include <fcitx-utils/utarray.h>
#include <fcitx/addon.h>

class QFile;

namespace Ui
{

class Module;
}

namespace Fcitx
{

class ConfigPage;

class UIPage;


class IMPage;

class SkinPage;

class ConfigWidget;

class AddonSelector;

class Module : public KCModule
{
    Q_OBJECT

public:
    /**
    * Constructor.
    *
    * @param parent Parent widget of the module
    * @param args Arguments for the module
    */
    Module(QWidget *parent, const QVariantList &args = QVariantList());

    /**
    * Destructor.
    */
    ~Module();

    /**
    * Overloading the KCModule load() function.
    */
    void load();

    /**
    * Overloading the KCModule save() function.
    */
    void save();

    /**
    * Overloading the KCModule defaults() function.
    */
    void defaults();

    FcitxAddon* findAddonByName(const QString& name);

    SkinPage* skinPage() { return m_skinPage; }

private:
    /**
    * UI
    */
    Ui::Module *ui;

    /**
    * Addon Selector
    */
    AddonSelector* addonSelector;

    /**
    * addon array
    */
    UT_array* m_addons;

    ConfigPage* m_configPage;
    SkinPage* m_skinPage;
    IMPage* m_imPage;
    UIPage* m_uiPage;
    QString m_arg;
};

}

#endif // MODULE_H
