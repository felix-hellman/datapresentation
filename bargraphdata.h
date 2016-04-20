#ifndef BARGRAPHDATA_H
#define BARGRAPHDATA_H

#include <vector>
#include <string>
#include "qcustomplot.h"
#include "graphdata.h"

class BarGraphData : public GraphData
{
private:
    std::vector<double> y;
    std::vector<double> ticks;
    std::vector<std::string> labels;
    std::string title;
    std::string filePath;
    QCPBars * graph;
    QCustomPlot * window;
    double max;

public:
    BarGraphData(QCustomPlot * window,std::string filePath);
    ~BarGraphData();
    void readFile();
    void update();

    void setTitle(std::string title);
    void setFilePath(std::string filePath);
    void setGraph(QCustomPlot *graphPointer);
    void setColor(QColor color);
    void setRandomColor();

    std::string getTitle() const;
    std::string getFilePath() const;

    double getMax() const;
    double getMin() const;
    double getSize() const;

};
#endif // BARGRAPHDATA_H
