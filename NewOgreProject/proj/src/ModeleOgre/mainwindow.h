#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ogrewidget.h"
#include "appwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    OgreWidget *myOgre;
    AppWidget *myApp;


private slots:
    void initWindow();


};

#endif // MAINWINDOW_H
