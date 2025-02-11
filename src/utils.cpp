#include <iostream>
#include <cmath>

#include <raylib.h>

#include "utils.h"
#include "algo.h"

Point::Point(Point* point) {
    this->x = point->x;
    this->y = point->y;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point::Point(std::pair<int, int> pair) {
    this->x = pair.first;
    this->y = pair.second;
}

bool Point::operator<(Point* otherPoint) {
    if (this->x < otherPoint->x) {
        return true;
    }
    else {
        return this->y < otherPoint->y;
    }
}

bool Point::operator>(Point* otherPoint) {
    if (this->x > otherPoint->x) {
        return true;
    }
    else {
        return this->y > otherPoint->y;
    }
}

// Polygon

void Polygon::addPoint(Point* p) {
    vertices.push_back(p);
}

void Polygon::draw(GraphicsInterface* graphics, char color) {
    if (!graphics->getAnimateValue()) {
        BeginDrawing();
    }

    for (int i = 0; i < vertices.size(); ++i) {
        int j = (i + 1) % vertices.size();
        ddaLine(graphics, vertices[i], vertices[j], color);
    }

    if (!graphics->getAnimateValue()) {
        EndDrawing();
    }
}

void Polygon::fill(GraphicsInterface* graphics, char color) {
    scanLineFill(graphics, vertices, color);
}

void Polygon::translate(std::pair<int, int> offset) {
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i]->x += offset.first;
        vertices[i]->y += offset.second;
    }
}

void Polygon::scale(std::pair<float, float> scale) {
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i]->x *= scale.first;
        vertices[i]->y *= scale.second;
    }
}

void Polygon::rotate(int rotation) {
    double rotation_radians = rotation * M_PI / 180.0;
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i]->x = (verticesCopy[i]->x) * std::cos(rotation_radians) - (verticesCopy[i]->y) * std::sin(rotation_radians);
        vertices[i]->y = (verticesCopy[i]->x) * std::cos(rotation_radians) + (verticesCopy[i]->y) * std::sin(rotation_radians);

        // std::cout << vertices[i]->x << " " << vertices[i]->y << "\n";

    }
}

void Polygon::copyVertices() {
    verticesCopy.clear();
    for (Point* vertex : vertices) {
        verticesCopy.push_back(new Point(vertex));
    }
}

void Polygon::resetVertices() {
    vertices.clear();
    for (Point* vertex : verticesCopy) {
        vertices.push_back(vertex);
    }
}