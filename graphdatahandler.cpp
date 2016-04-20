#include "graphdatahandler.h"

GraphDataHandler::GraphDataHandler()
{
    this->capDelta = 5;
    this->capacity = capDelta;
    this->size = 0;
    this->colorWheelIndex = 0;
    this->colorWheel[0] = QColor(255,0,0);
    this->colorWheel[1] = QColor(0,0,255);
    this->colorWheel[2] = QColor(0,255,0);
    this->colorWheel[3] = QColor(255,252,25);
    this->colorWheel[4] = QColor(0,178,255);
    this->colorWheel[5] = QColor(123,28,255);
    this->colorWheel[6] = QColor(2,255,64);
    this->colorWheel[7] = QColor(204,125,22);
    this->arrayOfGraphs = new GraphData*[capacity];
}
GraphDataHandler::~GraphDataHandler()
{
    for(int i = 0; i < this->size ;i++)
    {
        delete this->arrayOfGraphs[i];
    }
    delete[] this->arrayOfGraphs;
}
void GraphDataHandler::clear()
{
    for(int i = 0; i < this->size; i++)
    {
        //this->removeGraph(i);
        delete this->arrayOfGraphs[i];
    }
    delete[] this->arrayOfGraphs;
    this->capacity = 5;
    this->size = 0;
    this->colorWheelIndex = 0;
    this->arrayOfGraphs = new GraphData*[capacity];
}
void GraphDataHandler::increaseCapacity()
{
     GraphData **tmp = new GraphData*[capacity+capDelta];
     for(int i = 0; i < size; i++)
          tmp[i] = arrayOfGraphs[i];
     delete[] arrayOfGraphs;
     arrayOfGraphs = tmp;
     this->capacity = this->capacity + this->capDelta;
}

void GraphDataHandler::addLineGraph(QCustomPlot * graphPointer, std::string filePath)
{
    if(size == capacity)
        this->increaseCapacity();
    this->arrayOfGraphs[size++] = new LineGraphData(graphPointer,filePath);
    //this->arrayOfGraphs[size-1]->setRandomColor();
    this->arrayOfGraphs[size-1]->setColor(this->colorWheel[colorWheelIndex++]);
    colorWheelIndex = colorWheelIndex%8;
}
void GraphDataHandler::addBarGraph(QCustomPlot *graphPointer, std::string filePath)
{
    if(size == capacity)
        this->increaseCapacity();
    this->arrayOfGraphs[size++] = new BarGraphData(graphPointer,filePath);
    //this->arrayOfGraphs[size-1]->setRandomColor();
    this->arrayOfGraphs[size-1]->setColor(this->colorWheel[colorWheelIndex++]);
    colorWheelIndex = colorWheelIndex%8;
}
void GraphDataHandler::update()
{
    for(int i = 0; i < size; i++)
        this->arrayOfGraphs[i]->update();
}
void GraphDataHandler::readFile()
{
    for(int i = 0; i < size; i++)
        this->arrayOfGraphs[i]->readFile();
}
void GraphDataHandler::moveGraph(QCustomPlot * window, int graphIndex)
{
    arrayOfGraphs[graphIndex]->setGraph(window);
}
void GraphDataHandler::removeGraph(int graphIndex)
{
    arrayOfGraphs[graphIndex]->setGraph(nullptr);
}
int GraphDataHandler::getSize() const
{
    return this->size;
}
GraphData* GraphDataHandler::operator [](int index)
{
    return this->arrayOfGraphs[index];
}
void GraphDataHandler::calculateMPALatest(int MPA)
{
    LineGraphData * ptr = dynamic_cast<LineGraphData*>(this->arrayOfGraphs[size-1]);
    if(ptr != NULL)
        ptr->calculateMPA(MPA);
}
void GraphDataHandler::readFileLatest()
{
    this->arrayOfGraphs[size-1]->readFile();
}
