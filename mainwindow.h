#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QtPrintSupport>
#include <qcustomplot.h>
#include <cstdlib>
#include <string>
#include "linegraphdata.h"
#include "graphdatahandler.h"
#include "googleparser.h"
#include "ui_mainwindow.h"
#include <QtPrintSupport>
#include <ctime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_clear_clicked();
    void contextMenuEvent(QContextMenuEvent *event);
    void init();
    void viewOne();
    void viewTwo();
    void viewThree();
    void viewFour();
    void replot();

    void on_button_view_1_clicked();
    void on_button_view_2_clicked();
    void on_button_view_3_clicked();
    void on_button_view_4_clicked();

    void on_button_line_1_clicked();
    void on_button_line_2_clicked();
    void on_button_line_3_clicked();
    void on_button_line_4_clicked();

    void on_button_bar_1_clicked();
    void on_button_bar_2_clicked();
    void on_button_bar_3_clicked();
    void on_button_bar_4_clicked();

    void on_button_save_1_clicked();
    void on_button_save_2_clicked();
    void on_button_save_3_clicked();
    void on_button_save_4_clicked();

    void on_button_search_clicked();
    void on_button_MPA_clicked();
    void on_toggle_legend_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    GraphDataHandler graphHandler;
    GoogleParser goog;
    QMessageBox errorBox;
    QFileDialog *f1;
};

#endif // MAINWINDOW_H
