#ifndef GRAPHDATAHANDLER_H
#define GRAPHDATAHANDLER_H

#include "bargraphdata.h"
#include "linegraphdata.h"
#include "qcustomplot.h"

class GraphDataHandler
{
private:
    int capacity;
    int capDelta;
    int size;
    GraphData ** arrayOfGraphs;
    void increaseCapacity();
    QColor colorWheel[8];
    int colorWheelIndex;

public:
    GraphDataHandler();
    ~GraphDataHandler();
    void addLineGraph(QCustomPlot * graphPointer,std::string filePath);
    void addBarGraph(QCustomPlot * graphPointer,std::string filePath);
    void moveGraph(QCustomPlot * targetGraphPointer, int graphIndex);
    void removeGraph(int graphIndex);
    void clear();
    void calculateMPALatest(int MPA);

    void update();
    void readFile();
    void readFileLatest();

    int getSize() const;
    GraphData * operator[](int index);
};


#endif // GRAPHDATAHANDLER_H
