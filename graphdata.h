#ifndef GRAPHDATA_H
#define GRAPHDATA_H

#include <string>
#include "qcustomplot.h"
#include <cstdlib>

class GraphData
{
private:

public:
    virtual void update() = 0;
    virtual void readFile() = 0;

    virtual ~GraphData() {}

    virtual void setFilePath(std::string filePath) = 0;
    virtual void setTitle(std::string filePath) = 0;
    virtual void setGraph(QCustomPlot * graphPointer) = 0;
    virtual void setRandomColor() = 0;
    virtual void setColor(QColor color) = 0;

    virtual double getSize() const = 0;
    virtual double getMax() const = 0;
    virtual double getMin() const = 0;

    virtual std::string getFilePath() const = 0;
    virtual std::string getTitle() const = 0;

};
#endif // GRAPHDATA_H
