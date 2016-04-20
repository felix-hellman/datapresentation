#include "mainwindow.h"


void MainWindow::viewOne()
{
    ui->plot_1->move(0,0);
    ui->plot_1->resize(1200,600);
    ui->plot_1->show();
    ui->button_MPA->show();
    ui->line_MPA->show();
    ui->plot_2->hide();
    ui->plot_3->hide();
    ui->plot_4->hide();
    ui->button_line_1->show();
    ui->button_line_2->hide();
    ui->button_line_3->hide();
    ui->button_line_4->hide();
    ui->button_bar_1->show();
    ui->button_bar_2->hide();
    ui->button_bar_3->hide();
    ui->button_bar_4->hide();
    ui->button_save_1->show();
    ui->button_save_2->hide();
    ui->button_save_3->hide();
    ui->button_save_4->hide();
    ui->button_line_1->move(100,600);
    ui->button_bar_1->move(200,600);
    ui->button_save_1->move(300,600);
    ui->button_MPA->move(400,600);
    ui->line_MPA->move(500,600);
}
void MainWindow::viewTwo()
{
    ui->plot_1->resize(600,600);
    ui->plot_1->move(0,0);
    ui->plot_2->resize(600,600);
    ui->plot_2->move(600,0);
    ui->plot_1->show();
    ui->plot_2->show();
    ui->plot_3->hide();
    ui->plot_4->hide();
    ui->button_line_1->show();
    ui->button_line_2->show();
    ui->button_line_3->hide();
    ui->button_line_4->hide();
    ui->button_bar_1->show();
    ui->button_bar_2->show();
    ui->button_bar_3->hide();
    ui->button_bar_4->hide();
    ui->button_save_1->show();
    ui->button_save_2->show();
    ui->button_save_3->hide();
    ui->button_save_4->hide();
    ui->button_line_1->move(100,600);
    ui->button_bar_1->move(200,600);
    ui->button_save_1->move(300,600);
    ui->button_line_2->move(600+100,600);
    ui->button_bar_2->move(600+200,600);
    ui->button_save_2->move(600+300,600);
    ui->button_MPA->hide();
    ui->line_MPA->hide();
}
void MainWindow::viewThree()
{
    ui->plot_1->resize(400,400);
    ui->plot_2->resize(400,400);
    ui->plot_3->resize(400,400);
    ui->plot_1->move(0,0);
    ui->plot_2->move(400,0);
    ui->plot_3->move(800,0);
    ui->button_line_1->show();
    ui->button_line_2->show();
    ui->button_line_3->show();
    ui->button_line_4->hide();
    ui->button_bar_1->show();
    ui->button_bar_2->show();
    ui->button_bar_3->show();
    ui->button_bar_4->hide();
    ui->button_save_1->show();
    ui->button_save_2->show();
    ui->button_save_3->show();
    ui->button_save_4->hide();
    ui->plot_1->show();
    ui->plot_2->show();
    ui->plot_3->show();
    ui->plot_4->hide();
    ui->button_line_1->move(0,450);
    ui->button_bar_1->move(100,450);
    ui->button_save_1->move(200,450);
    ui->button_line_2->move(400,450);
    ui->button_bar_2->move(400+100,450);
    ui->button_save_2->move(400+200,450);
    ui->button_line_3->move(800,450);
    ui->button_bar_3->move(800+100,450);
    ui->button_save_3->move(800+200,450);
    ui->button_MPA->hide();
    ui->line_MPA->hide();
}
void MainWindow::viewFour()
{
    ui->plot_1->resize(300,300);
    ui->plot_2->resize(300,300);
    ui->plot_3->resize(300,300);
    ui->plot_4->resize(300,300);
    ui->plot_1->move(0,0);
    ui->plot_2->move(300,0);
    ui->plot_3->move(600,0);
    ui->plot_4->move(900,0);
    ui->plot_1->show();
    ui->plot_2->show();
    ui->plot_3->show();
    ui->plot_4->show();
    ui->button_line_1->show();
    ui->button_line_2->show();
    ui->button_line_3->show();
    ui->button_line_4->show();
    ui->button_bar_1->show();
    ui->button_bar_2->show();
    ui->button_bar_3->show();
    ui->button_bar_4->show();
    ui->button_save_1->show();
    ui->button_save_2->show();
    ui->button_save_3->show();
    ui->button_save_4->show();
    ui->button_line_1->move(0,350);
    ui->button_bar_1->move(100,350);
    ui->button_save_1->move(200,350);
    ui->button_line_2->move(300,350);
    ui->button_bar_2->move(300+100,350);
    ui->button_save_2->move(300+200,350);
    ui->button_line_3->move(600,350);
    ui->button_bar_3->move(600+100,350);
    ui->button_save_3->move(600+200,350);
    ui->button_line_4->move(900,350);
    ui->button_bar_4->move(900+100,350);
    ui->button_save_4->move(900+200,350);
    ui->button_MPA->hide();
    ui->line_MPA->hide();
}

void MainWindow::init()
{
    ui->plot_1->legend->setVisible(true);
    ui->plot_2->legend->setVisible(true);
    ui->plot_3->legend->setVisible(true);
    ui->plot_4->legend->setVisible(true);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    this->init();
    this->viewOne();
    f1 = new QFileDialog(parent);
    replot();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::replot()
{
    ui->plot_1->replot();
    ui->plot_2->replot();
    ui->plot_3->replot();
    ui->plot_4->replot();
}

void MainWindow::on_button_clear_clicked()
{
    this->graphHandler.clear();
    ui->plot_1->clearGraphs();
    ui->plot_1->clearPlottables();
    ui->plot_2->clearGraphs();
    ui->plot_2->clearPlottables();
    ui->plot_3->clearGraphs();
    ui->plot_3->clearPlottables();
    ui->plot_4->clearGraphs();
    ui->plot_4->clearPlottables();
    this->replot();
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction("This doesn't actually do anything");
    menu.addAction("Add a non-stupid graph");
    menu.exec(event->globalPos());
}



void MainWindow::on_button_view_1_clicked()
{

    this->viewOne();
}

void MainWindow::on_button_view_2_clicked()
{
    this->viewTwo();
}

void MainWindow::on_button_view_3_clicked()
{
    this->viewThree();
}

void MainWindow::on_button_view_4_clicked()
{
    this->viewFour();
}

void MainWindow::on_button_line_1_clicked()
{
    f1->open();
    QString test = f1->getOpenFileName();
    std::string filepath = test.toStdString();
    if(!filepath.empty())
    {
        graphHandler.addLineGraph(ui->plot_1,filepath);
        graphHandler.readFileLatest();
        graphHandler.update();
    }
    f1->close();
    this->replot();
}
void MainWindow::on_button_line_2_clicked()
{
    f1->open();
    QString test = f1->getOpenFileName();
    std::string filepath = test.toStdString();
    if(!filepath.empty())
    {
        graphHandler.addLineGraph(ui->plot_2,filepath);
        graphHandler.readFileLatest();
        graphHandler.update();
    }
    f1->close();
    this->replot();
}
void MainWindow::on_button_line_3_clicked()
{
    f1->open();
    QString test = f1->getOpenFileName();
    std::string filepath = test.toStdString();
    if(!filepath.empty())
    {
        graphHandler.addLineGraph(ui->plot_3,filepath);
        graphHandler.readFileLatest();
        graphHandler.update();
    }
    f1->close();
    this->replot();
}
void MainWindow::on_button_line_4_clicked()
{
    f1->open();
    QString test = f1->getOpenFileName();
    std::string filepath = test.toStdString();
    if(!filepath.empty())
    {
        graphHandler.addLineGraph(ui->plot_4,filepath);
        graphHandler.readFileLatest();
        graphHandler.update();
    }
    f1->close();
    this->replot();
}
void MainWindow::on_button_bar_1_clicked()
{
    f1->open();
    QString test = f1->getOpenFileName();
    std::string filepath = test.toStdString();
    if(!filepath.empty())
    {
        graphHandler.addBarGraph(ui->plot_1,filepath);
        graphHandler.readFileLatest();
        graphHandler.update();
    }
    f1->close();
    this->replot();
}
void MainWindow::on_button_bar_2_clicked()
{
    f1->open();
    QString test = f1->getOpenFileName();
    std::string filepath = test.toStdString();
    if(!filepath.empty())
    {
        graphHandler.addBarGraph(ui->plot_2,filepath);
        graphHandler.readFileLatest();
        graphHandler.update();
    }
    f1->close();
    this->replot();
}
void MainWindow::on_button_bar_3_clicked()
{
    f1->open();
    QString test = f1->getOpenFileName();
    std::string filepath = test.toStdString();
    if(!filepath.empty())
    {
        graphHandler.addBarGraph(ui->plot_3,filepath);
        graphHandler.readFileLatest();
        graphHandler.update();
    }
    f1->close();
    this->replot();
}
void MainWindow::on_button_bar_4_clicked()
{
    f1->open();
    QString test = f1->getOpenFileName();
    std::string filepath = test.toStdString();
    if(!filepath.empty())
    {
        graphHandler.addBarGraph(ui->plot_4,filepath);
        graphHandler.readFileLatest();
        graphHandler.update();
    }
    f1->close();
    this->replot();
}

void MainWindow::on_button_save_1_clicked()
{
    std::string filepath = "/home/felix/DataPresentation/Plots/";
    if(ui->Filename->text() != "")
        filepath += ui->Filename->text().toStdString();
    else
        filepath += "Noname";

    ui->plot_1->savePng(QString::fromStdString(filepath),1920,1080,1,-1);
}
void MainWindow::on_button_save_2_clicked()
{
    ui->plot_2->savePng("Testfile.png",1920,1080,1,-1);
}
void MainWindow::on_button_save_3_clicked()
{
    ui->plot_3->savePng("Testfile.png",1920,1080,1,-1);
}
void MainWindow::on_button_save_4_clicked()
{
    ui->plot_4->savePng("Testfile.png",1920,1080,1,-1);
}

void MainWindow::on_button_search_clicked()
{
    std::string filepath = "/home/felix/DataPresentation/SavedSearches/";
    if(ui->searchField->text() != "")
    {
        if(!goog.doSearch(ui->searchField->text().toStdString()))
        {
            if(ui->Filename->text() == "")
                filepath += "No name";
            else
                filepath += ui->Filename->text().toStdString();
            goog.saveToFile(filepath);
        }
        else
        {
            errorBox.setText("Something went wrong, probably qouta hit");
            errorBox.exec();
        }
    }
}

void MainWindow::on_button_MPA_clicked()
{
    if(!ui->line_MPA->text().isEmpty())
    {
        f1->open();
        QString test = f1->getOpenFileName();
        std::string filepath = test.toStdString();
        if(!filepath.empty())
        {
            graphHandler.addLineGraph(ui->plot_1,filepath);
            graphHandler.readFileLatest();
            graphHandler.calculateMPALatest(ui->line_MPA->text().toInt());
            graphHandler.update();
        }
        f1->close();
        this->replot();
    }
    else
    {
        errorBox.setText("Please enter a value for the MPA");
        errorBox.exec();
    }
}

void MainWindow::on_toggle_legend_clicked()
{
    if(ui->plot_1->legend->visible())
    {
        ui->plot_1->legend->setVisible(false);
        ui->plot_2->legend->setVisible(false);
        ui->plot_3->legend->setVisible(false);
        ui->plot_4->legend->setVisible(false);
        ui->toggle_legend->setText("Show Legend");
    }
    else
    {
        ui->plot_1->legend->setVisible(true);
        ui->plot_2->legend->setVisible(true);
        ui->plot_3->legend->setVisible(true);
        ui->plot_4->legend->setVisible(true);
        ui->toggle_legend->setText("Hide Legend");
    }
    this->replot();
}

void MainWindow::on_pushButton_clicked()
{
    QApplication::quit();
}
