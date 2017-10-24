/***************************************************************************
 *   Copyright (C) 2012~2012 by CSSlayer                                   *
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

#ifndef FONTBUTTON_H
#define FONTBUTTON_H

#include <QWidget>

namespace Ui {
class FontButton;
};

class FontButton : public QWidget {
    Q_OBJECT
public:
    explicit FontButton(QWidget *parent = 0);
    virtual ~FontButton();
    const QFont &font();
    QString fontName();
    static QFont parseFont(const QString &string);

public slots:
    void setFont(const QFont &font);
signals:
    void fontChanged(const QFont &font);
private slots:
    void selectFont();

private:
    Ui::FontButton *m_ui;
    QFont m_font;
};

#endif // FONTBUTTON_H