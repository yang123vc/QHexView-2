// copyright (c) 2019 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef QHEXVIEWWIDGET_H
#define QHEXVIEWWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QMenu>
#include <QShortcut>
#include <QFileDialog>
#include "qhexview.h"
#include "dialoggotoaddress.h"
#include "dialogdump.h"

#define KS_GOTOADDRESS          Qt::CTRL+Qt::Key_G
#define KS_DUMPTOFILE           Qt::CTRL+Qt::Key_D

namespace Ui {
class QHexViewWidget;
}

class QHexViewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QHexViewWidget(QWidget *parent = 0);
    ~QHexViewWidget();
    void setData(QIODevice *pDevice,QHexView::OPTIONS *pOptions=0);
    void reload();

private slots:

    void on_pushButtonGoTo_clicked();
    void on_checkBoxReadonly_toggled(bool checked);

    void _getState();
    void _goToAddress();
    void _dumpToFile();
    void _customContextMenu(const QPoint &pos);
    void _errorMessage(QString sText);
private:
    Ui::QHexViewWidget *ui;
};

#endif // QHEXVIEWWIDGET_H