#include <iostream>
#include <unordered_map>
#include <climits>
#include <cmath>
#include <algorithm>

class Vertex {
    public:
    int x_pos, y_pos;

    Vertex (int x, int y) 
    : x_pos(x)
    , y_pos(y)
    {}

    bool operator>(Vertex v) {
        return (y_pos > v.y_pos);
    }
};

struct Edge {
public:
    Vertex start, end;
    double slope, constant;
    int y_max, y_min, x_min;

    Edge(Vertex v1, Vertex v2)
    : start(v1)
    , end(v2) { 
        if (v1.x_pos != v2.x_pos)
            slope = double(v2.y_pos - v1.y_pos)/double(v2.x_pos - v1.x_pos);
        else
            slope = INT_MAX;

        if (v1 > v2) {
            y_max = v1.y_pos;
            y_min = v2.y_pos;
        }
        else {
            y_max = v2.y_pos;
            y_min = v1.y_pos;
        }

        constant =  start.y_pos - (start.x_pos * slope);
    }

    double calcXPos(int y) const {
        if (slope == INT_MAX)
            return (start.x_pos);
        return double(y - constant)/slope;
    }

};

double error_correction(const double x) {
    return std::fabs(round(x) - x) < 1e-6 ? round(x) : x; 
}


int count_visible_pixels(std::vector<std::pair<double, double>>& line) {
    std::sort(line.begin(), line.end());
    int res = 0;

    if (!line.empty()) {
        for (int i = 0; i < line.size()-1; i++) {
            auto [leftUpper, leftLower] = line[i];
            auto [rightUpper, rightLower] = line[i+1];

            int left = static_cast<int>(std::ceil(std::max(leftUpper, leftLower)));
            int right = static_cast<int>(std::floor(std::min(rightUpper, rightLower)));

            int toRes = right-left;
            if (toRes > 0)
                res += right - left;
            i++;
        }
    }

    return res;
}

int sweep_line(int max_y, int min_y, std::vector<Edge>& edges) {
    std::unordered_map<int, std::vector<std::pair<double, double>>> map;
    int res = 0;
    for (const Edge& edge: edges) {
        if (edge.start.y_pos == edge.end.y_pos)
            continue;
        for (int i = edge.y_max; i > edge.y_min; i--) {
            map[i].push_back(std::pair(error_correction(edge.calcXPos(i)), error_correction(edge.calcXPos(i-1))));
        } 
    }

    for (int y = max_y; y > min_y; y--) {
        int kres = count_visible_pixels(map[y]);
        res += kres;
    }
    return res;
}

int main() {
    int numTests;
    while(std::cin >> numTests && numTests != 0) {
        std::vector<Vertex> vertices;
        std::vector<Edge> edges;
        int maxY = 0, minY = 200;

        while (numTests--) {
            int x, y;
            std::cin >> x >> y;
            x += 100;
            y += 100;
            Vertex tempVertex = Vertex(x,y);
            vertices.push_back(tempVertex);
            
            if (y > maxY) maxY = y;
            if (y < minY) minY = y;
        }
        
        for (int i = 1; i < vertices.size(); i++) {
                Vertex v1 = vertices[i-1], v2 = vertices[i];
                Edge tempEdge = Edge(v1, v2);
                edges.push_back(tempEdge);
                if (i == vertices.size() - 1) {
                    Edge tempEdgeT = Edge(vertices[i], vertices[0]);
                    edges.push_back(tempEdgeT);
                
            }
        }
        
        std::cout << sweep_line(maxY, minY, edges) << '\n';
    }

    return 0;
}