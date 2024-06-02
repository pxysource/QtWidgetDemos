#ifndef SYSVARCONFIGTABLEWIDGET_H
#define SYSVARCONFIGTABLEWIDGET_H

#include <QTableWidget>
#include <QWidget>

class Entry
{
public:
    QString Index;
    QString SubIndex;
    QString Name;
    QString Type;

    int row;
};

class Group
{
public:
    QString Name;
    QList<Entry> entries;

    int row;
};

//class SysVarConfigTableWidget : public QTableWidget
class SysVarConfigTableWidget : public QWidget
{
public:
    explicit SysVarConfigTableWidget(QWidget *parent = nullptr);
    void LoadDatas(QList<Group> vars);

private:
    QTableWidget *_table;
    QMap<int, QList<int>> _groupRowsMap;

    QWidget *createGroupRowWidget(QString groupName, int groupRow);
    void hideGroupRows(int groupRow);
    void showGroupRows(int groupRow);
};

#endif // SYSVARCONFIGTABLEWIDGET_H
