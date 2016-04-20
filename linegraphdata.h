#ifndef LINEGRAPH_H
#define LINEGRAPH_H

#include <vector>
#include <QMainWindow>
#include "qcustomplot.h"
#include "graphdata.h"

class LineGraphData : public GraphData
{
    private:
std::vector<double> x;
std::vector<double> y;
std::string title;
std::string filePath;
QCPGraph * graph;
QCustomPlot * window;
QColor color;
double maxValue;
double minValue;

    public:
LineGraphData(QCustomPlot * window, std::string filepath);
~LineGraphData();

/**
 * @brief readFile
 * Imports values from file
 */
void readFile();
/**
 * @brief update
 * Updates the values from member values to graph
 */
void update();

void setTitle(std::string title);
void setFilePath(std::string filePath);
/**
 * @brief setGraph
 * Used to move a graph from one window to another, not used in GUI
 * @param graphPointer
 */
void setGraph(QCustomPlot * graphPointer);
void setRandomColor();
void setColor(QColor color);

std::string getTitle() const;
std::string getFilePath() const;

void setPen(int r, int g, int b, int width);

/**
 * @brief generateData
 * Old testfunction to generate some random data to plot
 */
void generateData();
/**
 * @brief calculateMPA
 * Calculate moving point average and put result in member vector
 * @param MPA
 */
void calculateMPA(int MPA);

double getMax() const;
double getMin() const;
double getSize() const;


QCPGraph * getGraph() const;


};
#endif // LINEGRAPH_H
