#include "mainwindow.h"
#include "SysVarConfigTableWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    showSysVarConfigTableWidget();
}

MainWindow::~MainWindow()
{
}

void MainWindow::showSysVarConfigTableWidget()
{
    SysVarConfigTableWidget *widget = new SysVarConfigTableWidget();
    Group group1;
    group1.Name = "Group1";
    Entry entry1;
    entry1.Index = "0x201";
    entry1.SubIndex = "0";
    entry1.Name = "Var1";
    entry1.Type = "UINT32";
    group1.entries.append(entry1);
    Entry entry2;
    entry2.Index = "0x201";
    entry2.SubIndex = "1";
    entry2.Name = "Var2";
    entry2.Type = "UINT32";
    group1.entries.append(entry2);
    Entry entry3;
    entry3.Index = "0x201";
    entry3.SubIndex = "2";
    entry3.Name = "Var3";
    entry3.Type = "UINT32";
    group1.entries.append(entry3);

    Group group2;
    group2.Name = "group2";
    Entry entry4;
    entry4.Index = "0x202";
    entry4.SubIndex = "0";
    entry4.Name = "Var4";
    entry4.Type = "UINT16";
    group2.entries.append(entry4);
    Entry entry5;
    entry5.Index = "0x202";
    entry5.SubIndex = "1";
    entry5.Name = "Var5";
    entry5.Type = "UINT16";
    group2.entries.append(entry5);
    Entry entry6;
    entry6.Index = "0x202";
    entry6.SubIndex = "2";
    entry6.Name = "Var6";
    entry6.Type = "UINT16";
    group2.entries.append(entry6);

    Group group3;
    group3.Name = "group3";
    Entry entry7;
    entry7.Index = "0x203";
    entry7.SubIndex = "0";
    entry7.Name = "Var7";
    entry7.Type = "CHAR8";
    group3.entries.append(entry7);
    Entry entry8;
    entry8.Index = "0x203";
    entry8.SubIndex = "1";
    entry8.Name = "Var8";
    entry8.Type = "CHAR8";
    group3.entries.append(entry8);
    Entry entry9;
    entry9.Index = "0x203";
    entry9.SubIndex = "2";
    entry9.Name = "Var9";
    entry9.Type = "CHAR8";
    group3.entries.append(entry9);
    widget->LoadDatas({group1, group2, group3});

    this->setCentralWidget(widget);
}

