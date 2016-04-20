#include "bargraphdata.h"

BarGraphData::BarGraphData(QCustomPlot * window, std::string filePath)
{
    this->graph = new QCPBars(window->xAxis,window->yAxis);
    this->window = window;
    this->filePath = filePath;
}
BarGraphData::~BarGraphData()
{

}

void BarGraphData::update()
{
    QVector<QString> qs;
    for(auto i = 0; i < (int)labels.size(); i++)
        qs.push_back(QString::fromStdString(this->labels[i]));

    window->addPlottable(graph);
    window->xAxis->setAutoTicks(false);
    window->xAxis->setAutoTickLabels(false);
    window->xAxis->setTickVector(QVector<double>::fromStdVector(this->ticks));
    window->xAxis->setTickVectorLabels(qs);
    window->xAxis->grid()->setVisible(true);

    graph->setData(QVector<double>::fromStdVector(this->ticks),QVector<double>::fromStdVector(this->y));
    graph->setName(QString::fromStdString(this->title));
    graph->setWidth(1/(double)ticks.size());
    graph->setPen(Qt::NoPen);
    //graph->setBrush(QColor(120,120,0,160));
    if(this->window->yAxis->range().upper < this->getMax())
        this->window->yAxis->setRange(0,this->getMax());
    if(this->window->xAxis->range().upper < this->ticks.size())
        this->window->xAxis->setRange(0,this->ticks.size()+1);
    this->window->rescaleAxes();
}
void BarGraphData::readFile()
{
    QFile inputFile(QString::fromStdString(this->filePath));
    if(inputFile.open(QIODevice::ReadOnly))
    {
       this->y.clear();
       this->labels.clear();
       this->ticks.clear();
       QTextStream in(&inputFile);
       int limit = 0, inputInt = 0;
       std::string inputString;
       this->title = in.readLine().toStdString();
       limit = in.readLine().toInt();
       for(int i = 0; i < limit; i++)
       {
           inputString = in.readLine().toStdString();
           inputInt = in.readLine().toInt();
           this->y.push_back(inputInt);
           if(i == 0)
                max = inputInt;
           if(inputInt > max)
                max = inputInt;
           this->labels.push_back(inputString);
           this->ticks.push_back(i+1);
       }
       inputFile.close();
    }
}

void BarGraphData::setRandomColor()
{
    graph->setBrush(QColor(rand()%255,rand()%255,0,160));
}
void BarGraphData::setColor(QColor color)
{
    graph->setBrush(color);
}
void BarGraphData::setTitle(std::string title)
{
    this->title = title;
}
void BarGraphData::setFilePath(std::string filePath)
{
    this->filePath = filePath;
}
void BarGraphData::setGraph(QCustomPlot * graphPointer)
{
    this->graph = new QCPBars(graphPointer->xAxis,graphPointer->yAxis);
}

std::string BarGraphData::getTitle() const
{
    return this->title;
}
std::string BarGraphData::getFilePath() const
{
    return this->filePath;
}
double BarGraphData::getMin() const
{
    return 0;
}
double BarGraphData::getMax() const
{
    return this->max;
}
double BarGraphData::getSize() const
{
    return this->y.size();
}
