#include "SysVarConfigTableWidget.h"

#include <QHBoxLayout>
#include <QHeaderView>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>

SysVarConfigTableWidget::SysVarConfigTableWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *hl = new QHBoxLayout(this);
    hl->setContentsMargins(0, 0, 0, 0);
    _table = new QTableWidget();
    hl->addWidget(_table);

    QStringList tableColumnHeaders;
    tableColumnHeaders << "Index" << "SubIndex" << "Name" << "Type";
    _table->setColumnCount(4);
    _table->setHorizontalHeaderLabels(tableColumnHeaders);
    _table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void SysVarConfigTableWidget::LoadDatas(QList<Group> vars)
{
    _table->clearContents();
    _groupRowsMap.clear();
    QList<int> rows;

    for (auto &group : vars)
    {
        int groupRow = _table->rowCount();
        int column = _table->columnCount();
        _table->insertRow(groupRow);
        group.row = groupRow;

        _table->setCellWidget(groupRow, 0, createGroupRowWidget(group.Name, groupRow));
        _table->setSpan(groupRow, 0, 1, column);

        rows.clear();

        for (auto &entry : group.entries)
        {
            int row = _table->rowCount();
            _table->insertRow(row);
            entry.row = row;
            rows.append(row);

            QTableWidgetItem *item = new QTableWidgetItem(entry.Index);
            _table->setItem(row, 0, item);

            item = new QTableWidgetItem(entry.SubIndex);
            _table->setItem(row, 1, item);

            item = new QTableWidgetItem(entry.Name);
            _table->setItem(row, 2, item);

            item = new QTableWidgetItem(entry.Type);
            _table->setItem(row, 3, item);
        }

        _groupRowsMap.insert(groupRow, rows);
    }

    _table->update();
}

QWidget *SysVarConfigTableWidget::createGroupRowWidget(QString groupName, int groupRow)
{
    QHBoxLayout *hl = new QHBoxLayout();
    hl->setContentsMargins(0, 0, 0, 0);
    QWidget *widget = new QWidget();
    widget->setLayout(hl);

    QPushButton *btn = new QPushButton();
    hl->addWidget(btn);
    btn->setText("-");
    btn->setMinimumWidth(40);
    btn->setMaximumWidth(40);
    btn->setStyleSheet("background: transparent; border: 0px");
    connect(btn, &QPushButton::clicked, this, [this,btn,groupRow](){
        if (btn->text() == "+")
        {
            btn->setText("-");
            this->showGroupRows(groupRow);
        }
        else
        {
            btn->setText("+");
            this->hideGroupRows(groupRow);
        }
    });

    QLabel *label = new QLabel();
    hl->addWidget(label);
    label->setText(groupName);

    QCheckBox *checkBox = new QCheckBox();
    hl->addWidget(checkBox);
    // checked...

    QSpacerItem *spacer = new QSpacerItem(100, 20, QSizePolicy::Policy::Expanding);
    hl->addSpacerItem(spacer);

    return widget;
}

void SysVarConfigTableWidget::hideGroupRows(int groupRow)
{
    if (_groupRowsMap.contains(groupRow))
    {
        for (auto row : _groupRowsMap.value(groupRow))
        {
            _table->setRowHidden(row, true);
        }
    }
}

void SysVarConfigTableWidget::showGroupRows(int groupRow)
{
    if (_groupRowsMap.contains(groupRow))
    {
        for (auto row : _groupRowsMap.value(groupRow))
        {
            _table->setRowHidden(row, false);
        }
    }
}
