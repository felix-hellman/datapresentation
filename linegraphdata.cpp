#include "linegraphdata.h"

LineGraphData::LineGraphData(QCustomPlot *window, std::string filepath)
{
    this->graph = window->addGraph();
    this->maxValue = 0;
    this->minValue = 0;
    this->filePath = filepath;
    this->window = window;
}
LineGraphData::~LineGraphData()
{

}

void LineGraphData::update()
{
    this->graph->setData(QVector<double>::fromStdVector(this->x),QVector<double>::fromStdVector(this->y));
    this->graph->setName(QString::fromStdString(this->title));
    this->graph->setPen(QPen(this->color,2));
    QVector<double> tickvector;
    for(int i = 0; i < this->getSize()/12; i++)
        tickvector << i*12;
    this->window->xAxis->setAutoTicks(false);
    this->window->xAxis->setTickVector(tickvector);
    this->window->xAxis->setOffset(12);
    this->window->xAxis->setRange(0,this->getSize());
    if(this->window->yAxis->range().upper < this->getMax())
        this->window->yAxis->setRange(this->getMin(),this->getMax());
}
void LineGraphData::setPen(int r, int g, int b, int width)
{
    this->graph->setPen(QPen(QColor(r,g,b,255),width));
}
void LineGraphData::readFile()
{
    QFile inputFile(QString::fromStdString(this->filePath));
    if(inputFile.open(QIODevice::ReadOnly))
    {
        if(!this->x.empty()) this->x.clear();
        if(!this->y.empty()) this->y.clear();
        QTextStream in(&inputFile);
        int max = 0;
        double input = 0;
        this->title = in.readLine().toStdString();
        max = in.readLine().toInt();
        for(int i = 0; i < max; i++)
        {
            input = in.readLine().toDouble();
            if(input == 10) input = 100;
            if(this->maxValue < input || i == 0) this->maxValue = input;
            if(this->minValue > input || i == 0) this->minValue = input;
            this->x.push_back(i);
            this->y.push_back(input);
        }
        inputFile.close();
    }
}
void LineGraphData::generateData()
{
    if(!this->x.empty()) this->x.clear();
    if(!this->y.empty()) this->y.clear();
    this->x.reserve(1000);
    this->y.reserve(1000);
    this->x.push_back(0);
    this->y.push_back(5);

    for(int i = 1; i < 1000;i++)
    {
        this->x.push_back(i);
        this->y.push_back(y[i-1]+rand()%10-4.5);
    }
}
void LineGraphData::calculateMPA(int MPA)
{
    this->readFile();
    double * arr = new double[this->x.size()];
    int val;
    this->title += " MPA " + std::to_string(MPA);
    for(unsigned int i = 0; i < this->x.size(); i++)
        arr[i] = 0;

    for(unsigned int x = 0; x < this->x.size(); x++)
    {
        if((int)(x - MPA) < 0) val = x;
        else val = MPA;
        if(val == 0) val = 1;
        for(int y = 0; y < val; y++)
        {
            arr[x] += this->y[x-y]/val;
        }
    }
    for(unsigned int i = 0; i < this->x.size(); i++)
    {
        this->y[i] = arr[i];
    }
    delete[] arr;
}
void LineGraphData::setTitle(std::string title){this->title = title;}
void LineGraphData::setFilePath(std::string filePath){this->filePath = filePath;}


void LineGraphData::setGraph(QCustomPlot *window)
{
    this->window->removeGraph(this->graph);
    this->window = window;
    this->graph = window->addGraph();
}
void LineGraphData::setRandomColor()
{
    this->color = QColor(rand()%255,rand()%255,0);
}
void LineGraphData::setColor(QColor color)
{
    this->color = color;
}

double LineGraphData::getMax() const {return this->maxValue;}
double LineGraphData::getMin() const {return this->minValue;}
double LineGraphData::getSize() const
{
    double max = this->x[0];
    for(auto i : this->x)
        if(max < this->x[i])
             max = this->x[i];
    return max;
}
QCPGraph * LineGraphData::getGraph() const
{
    return this->graph;
}
std::string LineGraphData::getTitle() const {return this->title;}
std::string LineGraphData::getFilePath() const {return this->filePath;}
