//Romans_Prokopjevs_201RDB381

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>


struct Point {
    double x;
    double y;
};

struct Line {
    Point start;
    Point end;

    Line (Point startPoint, Point endPoint) {
        /* Construct a point with beginning and the end. */
        start = startPoint;
        end = endPoint;
    }

    double lineLength() {
        /* Calculate a line length applying linear algebra. */
        return sqrt(  // Euclidean distance
                pow(end.x - start.x, 2) +
                pow(end.y - start.y, 2)
            );
    }
};

double diagonalLength(const Line _l1, const Line _l2){
    /* Find the sum of two vectors represented as lines. */
    return sqrt(
            pow(abs(_l1.start.x - _l2.end.x), 2) +
            pow(abs(_l1.start.y - _l2.end.y), 2)
    );
};


struct Quadrilateral {
    std::vector<Line> sides;

    // Constructor to initialize the quadrilateral with four lines
    Quadrilateral(const Line _l1, const Line _l2, const Line _l3, const Line _l4) {
        /* Construct a quadrilateral using four lines. */
        sides.push_back(_l1);
        sides.push_back(_l2);
        sides.push_back(_l3);
        sides.push_back(_l4);
    }

    bool isSquare() {
        /* Check if the quadraliteral is a square. */
        // Precision for loss during division
        double precision = 0.0002;
        // Rule No.1: sqares have sides equal length
        double sideLength = sides[0].lineLength();
        for (Line side : sides) {
            double sideLengthDiff = abs(side.lineLength() - sideLength);
            if (sideLengthDiff > precision){
                std::cerr << "Side length difference is too high: "
                          << sideLengthDiff << std::endl;
                return false;
            }
        }
        // Rule No.2: sqares have diagonals of equal length
        double diagLength1 = diagonalLength(sides[0], sides[1]);
        double diagLength2 = diagonalLength(sides[2], sides[3]);
        double diagLengthDiff = abs(diagLength1 - diagLength2);
        if (diagLengthDiff > precision){
            std::cerr << "Diagonal difference is too high: "
                      << diagLengthDiff << std::endl;
            return false;
        }
        return true;
    }

    double getArea() {
        /* Find the area if it is a square. */
        if (isSquare()){
            return 2 * sides[0].lineLength();
        }
        // If not square then -1 is a default area
        return -1;
    }
};


std::vector<Quadrilateral> readQuadrilaterals(std::vector<double> coords){
    /* Generate quadrilaterals out of the array of coordinates. */
    std::vector<Quadrilateral> res;
    for (int i = 0; i < coords.size() - 15; i+=16){
        // Create points
        Point p1 = {coords[i   ], coords[i+1 ]};
        Point p2 = {coords[i+2 ], coords[i+3 ]};
        Point p3 = {coords[i+4 ], coords[i+5 ]};
        Point p4 = {coords[i+6 ], coords[i+7 ]};
        Point p5 = {coords[i+8 ], coords[i+9 ]};
        Point p6 = {coords[i+10], coords[i+11]};
        Point p7 = {coords[i+12], coords[i+13]};
        Point p8 = {coords[i+14], coords[i+15]};
        // Create a quadraliteral
        Quadrilateral quad = Quadrilateral(
            Line(p1, p2),
            Line(p3, p4),
            Line(p5, p6),
            Line(p7, p8)
        );
        // Add it to the reslts vector
        res.push_back(quad);
    }
    return res;
}


std::vector<double> findAreas(std::vector<Quadrilateral> quads){
    /* Find areas of valid quadrilaterals. */
    std::vector<double> res;
    for (Quadrilateral quad : quads) {
        res.push_back(quad.getArea());
    }
    return res;
}

double findMaxNum(std::vector<double> numbers){
    /* Find maximal value number in the vector. */
    int max = numbers[0];
    for (const int num : numbers) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}


int main() {
    /* Validate quadliterals in various datasets. */
    //
    //      File No.1: `points.txt`
    //
    std::string fn1 = "points.txt";
    std::vector<double> coords1;
    // Open the text file
    std::ifstream file1(fn1);
    if (!file1.is_open()) {
        std::cerr << "Error opening " << fn1 << std::endl;
        return 1;
    }
    // Read the text file line by line compiling numbers into a vector
    std::string line;
    while (std::getline(file1, line)) {
        std::istringstream iss(line);
        int number;
        while (iss >> number) {
            coords1.push_back(static_cast<double>(number));
        }
    }
    std::cerr << fn1 << " length is: " << coords1.size() << std::endl;
    // Assemble coords into points
    std::vector<Quadrilateral> quads1 = readQuadrilaterals(coords1);
    // Find the areas
    std::vector<double> areas1 = findAreas(quads1);
    // Find the maximal value in the first set
    double maxArea1 = findMaxNum(areas1);
    std::cerr << "Max area in the " << fn1
              << " is " << maxArea1 << std::endl;
    //
    //      File No.2: `lines.csv`
    //
    // Open the CSV file
    std::string fn2 = "lines.csv";
    std::vector<double> coords2;
    const char delimiter = ',';

    std::ifstream file2(fn2);
    if (!file2.is_open()) {
        std::cerr << "Error opening " << fn2 << std::endl;
        return 1;
    }
    // Read the CSV file line by line
    while (std::getline(file2, line)) {
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, delimiter)) {
            coords2.push_back(std::stoi(cell));
        }
    }
    std::cerr << fn2 << " length is: " << coords2.size() << std::endl;
    // Assemble coords into points
    std::vector<Quadrilateral> quads2 = readQuadrilaterals(coords2);
    // Find the areas
    std::vector<double> areas2 = findAreas(quads2);
    // Find the maximal value in the first set
    double maxArea2 = findMaxNum(areas2);
    std::cerr << "Max area in the " << fn2
              << " is " << maxArea2 << std::endl;
    // Close all the files
    file1.close();
    return 0;
}